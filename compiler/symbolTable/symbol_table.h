// symbol_table.h

#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <stdbool.h>
#include <stdio.h>
// Enumeration for variable types
typedef enum {
    TYPE_NUMBER,
    TYPE_STRING,
    // Add more types as needed
} VarType;

// Union to store different types of variable values
typedef union {
    float number_val;
    char* string_val;
} VarValue;

// Structure for a symbol
typedef struct Symbol {
    char* name;             // Variable name
    VarType type;           // Variable type
    VarValue value;         // Variable value
    struct Symbol* next;    // Pointer for linked list (for separate chaining)
} Symbol;

// Structure for the Symbol Table (Hash Table)
typedef struct {
    Symbol** buckets;       // Array of pointers to Symbols (linked lists)
    int size;               // Number of buckets
} SymbolTable;

// Add to the VarValue union
typedef struct {
    VarType type;
    union {
        float number_val;
        char* string_val;
    } value;
} ExprValue;

// Initialize the symbol table
SymbolTable* init_symbol_table(int size);

// Insert a new symbol into the table
// Returns true if insertion is successful, false if symbol already exists
bool insert_symbol(SymbolTable* table, const char* name, VarType type, VarValue value);

// Lookup a symbol by name
// Returns pointer to Symbol if found, NULL otherwise
Symbol* lookup_symbol(SymbolTable* table, const char* name);

// Print the symbol table
void print_symbol_table(FILE* file, SymbolTable* table);

// Cleanup the symbol table
void free_symbol_table(SymbolTable* table);

#endif // SYMBOL_TABLE_H
