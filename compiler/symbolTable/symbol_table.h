// symbol_table.h

#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <stdbool.h>
#include <stdio.h>
// Structure for array values
typedef struct {
    struct ExprValue* elements;  // Using ExprValue instead of VarValue
    int size;
} ArrayValue;

// Enumeration for variable types
typedef enum {
    TYPE_NUMBER,
    TYPE_STRING,
    TYPE_ARRAY
} VarType;

// Forward declare ExprValue before using it
typedef struct ExprValue {
    VarType type;
    union {
        float number_val;
        char* string_val;
    } value;
} ExprValue;

// Union to store different types of variable values
typedef union {
    float number_val;
    char* string_val;
    ArrayValue* array_val;
} VarValue;

// Structure for a symbol
typedef struct Symbol {
    char* name;             // Variable name
    VarType type;           // Variable type
    VarValue value;         // Variable value
    bool is_constant;      // Flag to mark constant variables
    struct Symbol* next;    // Pointer for linked list (for separate chaining)
} Symbol;

// Structure for the Symbol Table (Hash Table)
typedef struct {
    Symbol** buckets;       // Array of pointers to Symbols (linked lists)
    int size;               // Number of buckets
} SymbolTable;

// Structure for storing function results
typedef struct {
    char* func_name;
    float result;
    bool is_set;  // To check if result has been set
} FunctionResult;

// Function table
typedef struct {
    FunctionResult results[100];  // Static array of 100 function results
    int count;  // Number of functions stored
} FunctionTable;

// Function declarations for function table operations
FunctionTable* init_function_table();
void store_function_result(FunctionTable* table, const char* func_name, float result);
float get_function_result(FunctionTable* table, const char* func_name, bool* found);

// Initialize the symbol table
SymbolTable* init_symbol_table(int size);

// Insert a new symbol into the table
// Returns true if insertion is successful, false if symbol already exists
bool insert_symbol(SymbolTable* table, const char* name, VarType type, VarValue value, bool is_constant);

// Lookup a symbol by name
// Returns pointer to Symbol if found, NULL otherwise
Symbol* lookup_symbol(SymbolTable* table, const char* name);

// Print the symbol table
void print_symbol_table(FILE* file, SymbolTable* table);

// Cleanup the symbol table
void free_symbol_table(SymbolTable* table);

#endif // SYMBOL_TABLE_H
