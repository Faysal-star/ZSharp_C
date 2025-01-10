// symbol_table.c

#include "symbol_table.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Simple hash function (djb2 by Dan Bernstein)
static unsigned long hash(const char* str, int size) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    return hash % size;
}

// Initialize the symbol table with a given number of buckets
SymbolTable* init_symbol_table(int size) {
    SymbolTable* table = malloc(sizeof(SymbolTable));
    if (!table) {
        fprintf(stderr, "Error: Memory allocation failed for SymbolTable\n");
        exit(1);
    }
    table->size = size;
    table->buckets = calloc(size, sizeof(Symbol*));
    if (!table->buckets) {
        fprintf(stderr, "Error: Memory allocation failed for SymbolTable buckets\n");
        free(table);
        exit(1);
    }
    return table;
}

// Insert a new symbol into the table
bool insert_symbol(SymbolTable* table, const char* name, VarType type, VarValue value) {
    unsigned long index = hash(name, table->size);
    Symbol* current = table->buckets[index];
    
    // Check for redeclaration
    while (current) {
        if (strcmp(current->name, name) == 0) {
            return false; // Symbol already exists
        }
        current = current->next;
    }
    
    // Create a new symbol
    Symbol* new_symbol = malloc(sizeof(Symbol));
    if (!new_symbol) {
        fprintf(stderr, "Error: Memory allocation failed for new Symbol\n");
        exit(1);
    }
    new_symbol->name = strdup(name);
    new_symbol->type = type;
    
    // Assign value based on type
    switch (type) {
        case TYPE_NUMBER:
            new_symbol->value.number_val = value.number_val;
            break;
        case TYPE_STRING:
            new_symbol->value.string_val = strdup(value.string_val);
            break;
        // Handle other types as needed
        default:
            fprintf(stderr, "Error: Unsupported variable type for '%s'\n", name);
            free(new_symbol->name);
            free(new_symbol);
            return false;
    }
    
    // Insert at the beginning of the linked list
    new_symbol->next = table->buckets[index];
    table->buckets[index] = new_symbol;
    
    return true;
}

// Lookup a symbol by name
Symbol* lookup_symbol(SymbolTable* table, const char* name) {
    unsigned long index = hash(name, table->size);
    Symbol* current = table->buckets[index];
    
    while (current) {
        if (strcmp(current->name, name) == 0) {
            return current; // Found
        }
        current = current->next;
    }
    
    return NULL; // Not found
}

// Print the symbol table
void print_symbol_table(FILE* file, SymbolTable* table) {
    for (int i = 0; i < table->size; ++i) {
        Symbol* current = table->buckets[i];
        while (current) {
            if (current->type == TYPE_NUMBER) {
                fprintf(file, "Symbol: %-15s Type: %-10s Value: %-10.2f\n", 
                    current->name, "Number", current->value.number_val);
            } else if (current->type == TYPE_STRING) {
                fprintf(file, "Symbol: %-15s Type: %-10s Value: %-10s\n",
                    current->name, "String", current->value.string_val);
            }
            current = current->next;
        }
    }
}

// Free all memory allocated for the symbol table
void free_symbol_table(SymbolTable* table) {
    for (int i = 0; i < table->size; ++i) {
        Symbol* current = table->buckets[i];
        while (current) {
            Symbol* temp = current;
            current = current->next;
            free(temp->name);
            if (temp->type == TYPE_STRING) {
                free(temp->value.string_val);
            }
            free(temp);
        }
    }
    free(table->buckets);
    free(table);
}
