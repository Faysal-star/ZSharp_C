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
bool insert_symbol(SymbolTable* table, const char* name, VarType type, VarValue value, bool is_constant) {
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
    new_symbol->is_constant = is_constant;  // Set the constant flag
    
    // Assign value based on type
    switch (type) {
        case TYPE_NUMBER:
            new_symbol->value.number_val = value.number_val;
            break;
        case TYPE_STRING:
            new_symbol->value.string_val = strdup(value.string_val);
            break;
        case TYPE_ARRAY:
            new_symbol->value.array_val = value.array_val;
            break;
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
            const char* const_str = current->is_constant ? "(const) " : "";
            switch (current->type) {
                case TYPE_NUMBER:
                    fprintf(file, "Symbol: %-15s Type: %-10s %sValue: %-10.2f\n", 
                        current->name, "Number", const_str, current->value.number_val);
                    break;
                case TYPE_STRING:
                    fprintf(file, "Symbol: %-15s Type: %-10s %sValue: %-10s\n",
                        current->name, "String", const_str, current->value.string_val);
                    break;
                case TYPE_ARRAY:
                    fprintf(file, "Symbol: %-15s Type: %-10s %sSize: %-10d\n",
                        current->name, "Array", const_str, current->value.array_val->size);
                    break;
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
            
            switch (temp->type) {
                case TYPE_STRING:
                    free(temp->value.string_val);
                    break;
                case TYPE_ARRAY:
                    free(temp->value.array_val->elements);
                    free(temp->value.array_val);
                    break;
            }
            
            free(temp);
        }
    }
    free(table->buckets);
    free(table);
}

FunctionTable* init_function_table() {
    FunctionTable* table = (FunctionTable*)malloc(sizeof(FunctionTable));
    table->count = 0;
    for (int i = 0; i < 100; i++) {
        table->results[i].func_name = NULL;
        table->results[i].is_set = false;
    }
    return table;
}

void store_function_result(FunctionTable* table, const char* func_name, float result) {
    // First try to find existing entry
    for (int i = 0; i < table->count; i++) {
        if (table->results[i].func_name && strcmp(table->results[i].func_name, func_name) == 0) {
            table->results[i].result = result;
            table->results[i].is_set = true;
            return;
        }
    }
    
    // If not found and space available, create new entry
    if (table->count < 100) {
        table->results[table->count].func_name = strdup(func_name);
        table->results[table->count].result = result;
        table->results[table->count].is_set = true;
        table->count++;
    }
}

float get_function_result(FunctionTable* table, const char* func_name, bool* found) {
    for (int i = 0; i < table->count; i++) {
        if (table->results[i].func_name && strcmp(table->results[i].func_name, func_name) == 0) {
            *found = table->results[i].is_set;
            return table->results[i].result;
        }
    }
    *found = false;
    return 0;
}

void free_function_table(FunctionTable* table) {
    if (!table) return;
    for (int i = 0; i < table->count; i++) {
        if (table->results[i].func_name) {
            free(table->results[i].func_name);
        }
    }
    free(table);
}
