%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table.h" 

extern int yylex();
extern int yylineno;
extern char* yytext;
extern FILE* yyin;

void yyerror(const char *s);
FILE* output_file;

// Stat
int var_count = 0;
int func_count = 0;
int main_count = 0;
int class_count = 0;

// Function call handling
ExprValue args[10];
int arg_count = 0;

// Initializing Symbol Table
SymbolTable* sym_table;
FunctionTable* func_table;

// To store function definitions
typedef struct {
    char* name;
    char** params; 
    int param_count;
    ExprValue return_expr; 
} FunctionDef;

// Array to store function definitions
FunctionDef function_defs[100];
int function_count = 0;

// Helper function to find function definition
FunctionDef* find_function_def(const char* name) {
    for (int i = 0; i < function_count; i++) {
        if (strcmp(function_defs[i].name, name) == 0) {
            return &function_defs[i];
        }
    }
    return NULL;
}

%}

%union {
    float number_val;
    char* string_val;
    ExprValue expr_val;
    struct {
        char** param_names;
        int param_count;
    } param_list;
}

// Type declarations
%type <expr_val> expression numeric_expression string_expression
%type <expr_val> for_init for_condition for_increment
%type <number_val> boolean_expression
%type <string_val> variable_declaration
%type <expr_val> function_call
%type <param_list> parameter_list

// Token declarations
%token VARIABLE CONST FUNCTION IF ELSE_IF ELSE FOR RETURN PRINT
%token TRUE_VAL FALSE_VAL ARRAY BREAK CONTINUE INCLUDE CLASS EXTENDS
%token NULL_VAL TRY CATCH SUCCESS PRIVATE PUBLIC MAIN SCANF
%token FOR_SEP
%token <number_val> NUMBER
%token <string_val> STRING_LIT VSTRING_LIT IDENTIFIER
%token PLUS MINUS MULTIPLY DIVIDE ASSIGN EQ NEQ LT LTE GT GTE AND OR NOT
%token SLC MLC

// Operator precedence
%left OR
%left AND
%left EQ NEQ
%left LT LTE GT GTE
%left PLUS MINUS
%left MULTIPLY DIVIDE
%right NOT
%right ASSIGN

%%

program
    : statements
    ;

statements
    : statement
    | statements statement
    ;

statement
    : include_stmt
    | class_declaration
    | function_declaration
    | variable_declaration
    | expression_stmt
    | if_statement
    | for_statement
    | try_catch_stmt
    | print_stmt
    | return_stmt
    | break_stmt
    | continue_stmt
    | comment_stmt
    | scanf_stmt
    ;

include_stmt
    : INCLUDE STRING_LIT {
        fprintf(output_file, "→ Import detected with path: %s\n", $2);
    }
    ;

break_stmt
    : BREAK {
        fprintf(output_file, "→ Break statement detected\n");
    }
    ;

continue_stmt
    : CONTINUE {
        fprintf(output_file, "→ Continue statement detected\n");
    }
    ;

class_declaration
    : CLASS IDENTIFIER opt_extends '{' class_body '}' {
        fprintf(output_file, "\n→ Class declaration detected: %s\n\n", $2);
        class_count++;
    }
    ;

opt_extends
    : EXTENDS IDENTIFIER
    | /* empty */
    ;

class_body
    : class_member
    | class_body class_member
    ;

class_member
    : access_modifier variable_declaration
    | access_modifier function_declaration
    ;

access_modifier
    : PUBLIC
    | PRIVATE
    ;

function_declaration
    : FUNCTION IDENTIFIER '(' parameter_list ')' '{' statements RETURN expression '}' {
        fprintf(output_file, "\n→ Function declaration detected: %s\n\n", $2);
        
        // Store the function definition
        if (function_count < 100) {
            function_defs[function_count].name = strdup($2);
            function_defs[function_count].params = $4.param_names;
            function_defs[function_count].param_count = $4.param_count;
            function_defs[function_count].return_expr = $9;
            
            // Store in function table
            store_function_result(func_table, $2, 0.0);  // Initialize with 0
            
            function_count++;
        }
        
        func_count++;
    }
    | FUNCTION MAIN '(' parameter_list ')' '{' statements '}' {
        fprintf(output_file, "\n→ MAIN Function declaration detected\n\n");
        
        // Store main function
        if (function_count < 100) {
            function_defs[function_count].name = strdup("OG");
            function_defs[function_count].params = $4.param_names;
            function_defs[function_count].param_count = $4.param_count;
            
            // Store in function table
            store_function_result(func_table, "OG", 0.0);
            
            function_count++;
        }
        
        func_count++;
        main_count++;
        if(main_count > 1) {
            fprintf(stderr, "Error: Multiple main functions detected\n");
            YYERROR;
        }
    }
    ;

parameter_list
    : /* empty */ {
        $$.param_count = 0;
        $$.param_names = NULL;
    }
    | IDENTIFIER {
        $$.param_count = 1;
        $$.param_names = malloc(sizeof(char*));
        $$.param_names[0] = strdup($1);
    }
    | parameter_list ',' IDENTIFIER {
        $$.param_count = $1.param_count + 1;
        $$.param_names = realloc($1.param_names, $$.param_count * sizeof(char*));
        $$.param_names[$$.param_count - 1] = strdup($3);
    }
    ;

variable_declaration
    : VARIABLE IDENTIFIER ASSIGN expression {
        VarValue val;
        VarType type;
        
        // Numeric expression
        if ($4.type == TYPE_NUMBER) {
            type = TYPE_NUMBER;
            val.number_val = $4.value.number_val;
        }
        // String expression
        else if ($4.type == TYPE_STRING) {
            type = TYPE_STRING;
            val.string_val = strdup($4.value.string_val);
        }
        else {
            yyerror("Invalid expression type");
            YYERROR;
        }

        // Inserting into symbol table
        if (!insert_symbol(sym_table, $2, type, val, false)) {
            fprintf(stderr, "Error: Variable '%s' redeclared at line %d\n", $2, yylineno);
            if (type == TYPE_STRING) {
                free(val.string_val);
            }
            yyerror("Redeclaration of variable");
            YYERROR;
        }
        
        var_count++;
        fprintf(output_file, "→ Variable declaration detected: %s\n", $2);
    }
    | ARRAY IDENTIFIER ASSIGN '[' expression_list ']' {
        // Create array and store elements
        ArrayValue* arr = malloc(sizeof(ArrayValue));
        arr->size = arg_count;
        arr->elements = malloc(arr->size * sizeof(ExprValue));
        
        // Copy expressions from args array
        for(int i = 0; i < arr->size; i++) {
            arr->elements[i] = args[i];
            fprintf(output_file, "Array element %d: %f\n", i, args[i].value.number_val);
        }

        VarValue val;
        val.array_val = arr;

        // Insert as TYPE_ARRAY
        if (!insert_symbol(sym_table, $2, TYPE_ARRAY, val, false)) {
            fprintf(stderr, "Error: Array '%s' redeclared at line %d\n", $2, yylineno);
            free(arr->elements);
            free(arr);
            YYERROR;
        }
        
        fprintf(output_file, "→ Array declaration: %s with %d elements\n", $2, arr->size);
        var_count++;
        $$ = $2; 
    }
    | CONST IDENTIFIER ASSIGN expression {
        VarValue val;
        VarType type;
        
        if ($4.type == TYPE_NUMBER) {
            type = TYPE_NUMBER;
            val.number_val = $4.value.number_val;
        }
        else if ($4.type == TYPE_STRING) {
            type = TYPE_STRING;
            val.string_val = strdup($4.value.string_val);
        }
        else {
            yyerror("Invalid expression type for constant");
            YYERROR;
        }

        // Insert as constant
        if (!insert_symbol(sym_table, $2, type, val, true)) {
            fprintf(stderr, "Error: Constant '%s' redeclared at line %d\n", $2, yylineno);
            if (type == TYPE_STRING) {
                free(val.string_val);
            }
            yyerror("Redeclaration of constant");
            YYERROR;
        }
        var_count++;
        fprintf(output_file, "→ Constant declaration detected: %s\n", $2);
    }
    ;

print_stmt
    : PRINT expression {
        fprintf(output_file, "→ Print statement detected: ");
        if ($2.type == TYPE_NUMBER) {
            fprintf(output_file, "%f\n", $2.value.number_val);
        }
        else if ($2.type == TYPE_STRING) {
            fprintf(output_file, "\"%s\"\n", $2.value.string_val);
        }
    }
    ;


if_statement
    : IF '(' boolean_expression ')' '{' statements '}' 
        { 
            fprintf(output_file, "→ Single If statement Detected\n");
            fprintf(output_file, "++++ Single If Block Execution ++++\n");
            if ($3) {
                fprintf(output_file, "Condition evaluated to true\n");
            } else {
                fprintf(output_file, "Condition evaluated to false\n");
            }
            fprintf(output_file, "++++ Single If Block Execution Stop ++++\n");
        }
    | IF '(' boolean_expression ')' '{' statements '}' ELSE '{' statements '}' 
        { 
            fprintf(output_file, "→ If-Else statement Detected\n"); 
            fprintf(output_file, "++++ If Block Execution ++++\n"); 
            if ($3) {
                fprintf(output_file, "Condition evaluated to true\n");
            } else {
                fprintf(output_file, "Condition evaluated to false\n");
            }
            fprintf(output_file, "++++ If Block Execution Stop ++++\n");
            fprintf(output_file, "++++ Else Block Execution ++++\n");
        }
    | IF '(' boolean_expression ')' '{' statements '}' else_if_list 
        { 
            fprintf(output_file, "→ If-ElseIf statement Detected\n"); 
            fprintf(output_file, "++++ If Block Execution ++++\n"); 
            if ($3) {
                fprintf(output_file, "If condition evaluated to true\n");
            } else {
                fprintf(output_file, "If condition evaluated to false\n");
            }
            fprintf(output_file, "++++ If Block Execution Stop ++++\n");
        }
    | IF '(' boolean_expression ')' '{'statements '}' else_if_list ELSE '{' statements '}'  
        { 
            fprintf(output_file, "→ If-ElseIf-Else statement Detected\n"); 
            fprintf(output_file, "++++ If Block Execution ++++\n"); 
            if ($3) {
                fprintf(output_file, "If condition evaluated to true\n");
            } else {
                fprintf(output_file, "If condition evaluated to false\n");
            }
            fprintf(output_file, "++++ If Block Execution Stop ++++\n");
            fprintf(output_file, "++++ Else Block Execution ++++\n");
        }
    ;

else_if_list
    : ELSE_IF '(' boolean_expression ')' '{' statements '}' 
        { 
            fprintf(output_file, "→ Else-if block Detected\n"); 
            fprintf(output_file, "++++ Else-if Block Execution ++++\n"); 
            if ($3) {
                fprintf(output_file, "Else-if condition evaluated to true\n");
            } else {
                fprintf(output_file, "Else-if condition evaluated to false\n");
            }
            fprintf(output_file, "++++ Else-if Block Execution Stop ++++\n");
        }
    | else_if_list ELSE_IF '(' boolean_expression ')' '{' statements '}' 
        { 
            fprintf(output_file, "→ Additional else-if block Detected\n"); 
            fprintf(output_file, "++++ Additional Else-if Block Execution ++++\n"); 
            if ($4) {
                fprintf(output_file, "Additional else-if condition evaluated to true\n");
            } else {
                fprintf(output_file, "Additional else-if condition evaluated to false\n");
            }
            fprintf(output_file, "++++ Additional Else-if Block Execution Stop ++++\n");
        }
    ;


for_statement
    : FOR '(' for_init FOR_SEP for_condition FOR_SEP for_increment ')' '{' statements '}' 
        { 
            fprintf(output_file, "→ For loop detected \n\n");
        }
    ;

for_init
    : /* empty */ { 
        $$.type = TYPE_NUMBER;
        $$.value.number_val = 0;
    }
    | variable_declaration 
    ;

for_condition
    : boolean_expression 
    | /* empty */ { 
        $$.type = TYPE_NUMBER;
        $$.value.number_val = 1000000;
    }
    ;

for_increment
    : expression
    | /* empty */ { 
        $$.type = TYPE_NUMBER;
        $$.value.number_val = 1;
    }
    ;

try_catch_stmt
    : TRY '{' statements '}' CATCH '(' IDENTIFIER ')' '{' statements '}'
        {
            fprintf(output_file, "→ Try-catch block detected\n");
        }   
    ;

return_stmt
    : RETURN expression
    ;

expression_stmt
    : expression
    ;

expression
    : numeric_expression { $$ = $1; }
    | string_expression { $$ = $1; }
    | IDENTIFIER {
        Symbol* sym = lookup_symbol(sym_table, $1);
        if (!sym) {

            yyerror("Undefined variable");
            YYERROR;
        }
        
        switch (sym->type) {
            case TYPE_NUMBER:
                $$.type = TYPE_NUMBER;
                $$.value.number_val = sym->value.number_val;
                break;
            case TYPE_STRING:
                $$.type = TYPE_STRING;
                $$.value.string_val = strdup(sym->value.string_val);
                break;
            case TYPE_ARRAY:
                yyerror("Cannot print array directly");
                YYERROR;
                break;
            default:
                yyerror("Unsupported type for printing");
                YYERROR;
        }
    }
    | boolean_expression { 
        $$.type = TYPE_NUMBER;
        $$.value.number_val = $1;
    }
    | function_call { $$ = $1; }
    | IDENTIFIER ASSIGN expression {
        Symbol* sym = lookup_symbol(sym_table, $1);
        if (!sym) {
            VarValue val;
            if ($3.type == TYPE_NUMBER) {
                val.number_val = $3.value.number_val;
                insert_symbol(sym_table, $1, TYPE_NUMBER, val, false);
            } else if ($3.type == TYPE_STRING) {
                val.string_val = strdup($3.value.string_val);
                insert_symbol(sym_table, $1, TYPE_STRING, val, false);
            }
        } else {
            // Checking if trying to reassign a constant
            if (sym->is_constant) {
                fprintf(stderr, "Error: Cannot reassign constant '%s' at line %d\n", $1, yylineno);
                yyerror("Constant reassignment");
                YYERROR;
            }
            
            if (sym->type != $3.type) {
                yyerror("Type mismatch in assignment");
                YYERROR;
            }
            if (sym->type == TYPE_NUMBER) {
                sym->value.number_val = $3.value.number_val;
            } else if (sym->type == TYPE_STRING) {
                free(sym->value.string_val);
                sym->value.string_val = strdup($3.value.string_val);
            }
        }
        $$ = $3;
        if ($3.type == TYPE_NUMBER) {
            fprintf(output_file, "Assignment: %s = %f\n", $1, $3.value.number_val);
        }
        else if ($3.type == TYPE_STRING) {
            fprintf(output_file, "Assignment: %s = \"%s\"\n", $1, $3.value.string_val);
        }
    }
    ;

numeric_expression
    : NUMBER { 
        $$.type = TYPE_NUMBER;
        $$.value.number_val = $1;
    }
    | numeric_expression PLUS numeric_expression { 
        $$.type = TYPE_NUMBER;
        $$.value.number_val = $1.value.number_val + $3.value.number_val;
        fprintf(output_file, "Addition: %f + %f = %f\n", 
                $1.value.number_val, $3.value.number_val, $$.value.number_val);
    }
    | numeric_expression MINUS numeric_expression { 
        $$.type = TYPE_NUMBER;
        $$.value.number_val = $1.value.number_val - $3.value.number_val;
        fprintf(output_file, "Subtraction: %f - %f = %f\n", 
                $1.value.number_val, $3.value.number_val, $$.value.number_val);
    }
    | numeric_expression MULTIPLY numeric_expression { 
        $$.type = TYPE_NUMBER;
        $$.value.number_val = $1.value.number_val * $3.value.number_val;
        fprintf(output_file, "Multiplication: %f * %f = %f\n", 
                $1.value.number_val, $3.value.number_val, $$.value.number_val);
    }
    | numeric_expression DIVIDE numeric_expression { 
        if ($3.value.number_val == 0) {
            fprintf(output_file, "Error: Division by zero detected\n");
        }
        else {
            $$.type = TYPE_NUMBER;
            $$.value.number_val = $1.value.number_val / $3.value.number_val;
            fprintf(output_file, "Division: %f / %f = %f\n", 
                    $1.value.number_val, $3.value.number_val, $$.value.number_val);
        }
    }
    | '(' numeric_expression ')' { $$ = $2; }
    | IDENTIFIER {
        Symbol* sym = lookup_symbol(sym_table, $1);
        if (!sym) {
            // Instead of error, initializing with 0
            $$.type = TYPE_NUMBER;
            $$.value.number_val = 0;

            VarValue val;
            val.number_val = 0;
            insert_symbol(sym_table, $1, TYPE_NUMBER, val, false);
            
            fprintf(output_file, "Warning: Undefined variable '%s' at line %d, initializing with 0\n", 
                   $1, yylineno);
        } else {
            if (sym->type == TYPE_NUMBER) {
                $$.type = TYPE_NUMBER;
                $$.value.number_val = sym->value.number_val;
                fprintf(output_file, "Using variable %s with value %f\n", $1, $$.value.number_val);
            } else if (sym->type == TYPE_STRING) {
                $$.type = TYPE_STRING;
                $$.value.string_val = strdup(sym->value.string_val);
                fprintf(output_file, "Using string variable %s with value \"%s\"\n", $1, $$.value.string_val);
            } else {
                yyerror("Type mismatch: expected number or string");
                YYERROR;
            }
        }
    }
    | IDENTIFIER '[' numeric_expression ']' {
        Symbol* sym = lookup_symbol(sym_table, $1);
        if (!sym) {
            fprintf(stderr, "Error: Undefined variable '%s' at line %d\n", $1, yylineno);
            yyerror("Undefined variable");
            YYERROR;
        }
        
        int index = (int)$3.value.number_val;
        
        // Handling string indexing
        if (sym->type == TYPE_STRING) {
            if (index < 0 || index >= strlen(sym->value.string_val)) {
                fprintf(stderr, "Error: String index out of bounds for '%s' at line %d\n", $1, yylineno);
                yyerror("Index out of bounds");
                YYERROR;
            }
            $$.type = TYPE_NUMBER;
            $$.value.number_val = (float)sym->value.string_val[index+1];
            fprintf(output_file, "String index access: %s[%d] = '%c' (ASCII: %f)\n", 
                    $1, index, (char)$$.value.number_val, $$.value.number_val);
        }
        // Handling array indexing
        else if (sym->type == TYPE_ARRAY) {
            ArrayValue* arr = sym->value.array_val;
            if (index < 0 || index >= arr->size) {
                fprintf(stderr, "Error: Array index out of bounds for '%s' at line %d\n", $1, yylineno);
                yyerror("Index out of bounds");
                YYERROR;
            }
            $$ = arr->elements[index];
            fprintf(output_file, "Array access: %s[%d] = %f\n", 
                    $1, index, $$.value.number_val);
        }
        else {
            fprintf(stderr, "Error: '%s' is not indexable at line %d\n", $1, yylineno);
            yyerror("Not an indexable type");
            YYERROR;
        }
    }
    ;

string_expression
    : STRING_LIT { 
        $$.type = TYPE_STRING;
        $$.value.string_val = strdup($1);
    }
    | VSTRING_LIT {
        $$.type = TYPE_STRING;
        $$.value.string_val = strdup($1);
    }
    | string_expression PLUS string_expression {
        $$.type = TYPE_STRING;
        $$.value.string_val = malloc(strlen($1.value.string_val) + strlen($3.value.string_val) + 1);
        strcpy($$.value.string_val, $1.value.string_val);
        strcat($$.value.string_val, $3.value.string_val);
        free($1.value.string_val);
        free($3.value.string_val);
    }
    ;

expression_list
    : expression {
        args[0] = $1;
        arg_count = 1;
        fprintf(output_file, "First array element: %f\n", $1.value.number_val);
    }
    | expression_list ',' expression {
        if (arg_count < 10) {
            args[arg_count] = $3;
            fprintf(output_file, "Additional array element: %f\n", $3.value.number_val);
            arg_count++;
        } else {
            yyerror("Too many array elements");
            YYERROR;
        }
    }
    ;

argument_list
    : /* empty */ {
        fprintf(output_file, "Empty argument list\n");
        arg_count = 0;
    }
    | expression {
        fprintf(output_file, "Single argument: ");
        if ($1.type == TYPE_NUMBER) {
            fprintf(output_file, "%f\n", $1.value.number_val);
            args[0] = $1;
            arg_count = 1;
        }
    }
    | argument_list ',' expression {
        fprintf(output_file, "Additional argument: ");
        if ($3.type == TYPE_NUMBER) {
            fprintf(output_file, "%f\n", $3.value.number_val);
            args[arg_count] = $3;
            arg_count++;
        }
    }
    ;

boolean_expression
    : numeric_expression { 
        $$ = ($1.type == TYPE_NUMBER && $1.value.number_val != 0) ? 1 : 0;
    }
    | numeric_expression GT numeric_expression { 
        $$ = ($1.value.number_val > $3.value.number_val) ? 1 : 0;
    }
    | numeric_expression GTE numeric_expression { 
        $$ = ($1.value.number_val >= $3.value.number_val) ? 1 : 0;
    }
    | numeric_expression LT numeric_expression { 
        $$ = ($1.value.number_val < $3.value.number_val) ? 1 : 0;
    }
    | numeric_expression LTE numeric_expression { 
        $$ = ($1.value.number_val <= $3.value.number_val) ? 1 : 0;
    }
    | numeric_expression EQ numeric_expression { 
        $$ = ($1.value.number_val == $3.value.number_val) ? 1 : 0;
    }
    | numeric_expression NEQ numeric_expression { 
        $$ = ($1.value.number_val != $3.value.number_val) ? 1 : 0;
    }
    | boolean_expression AND boolean_expression { 
        $$ = ($1 && $3) ? 1 : 0;
    }
    | boolean_expression OR boolean_expression { 
        $$ = ($1 || $3) ? 1 : 0;
    }
    | NOT boolean_expression { 
        $$ = !$2 ? 1 : 0;
    }
    | TRUE_VAL { 
        $$ = 1;
    }
    | FALSE_VAL { 
        $$ = 0;
    }
    | '(' boolean_expression ')' { 
        $$ = $2;
    }
    ;

function_call
    : IDENTIFIER '(' argument_list ')' {
        fprintf(output_file, "→ Function call detected: %s\n", $1);
        
        FunctionDef* func = find_function_def($1);
        if (func != NULL) {
            // Checking parameter count
            if (func->param_count != arg_count) {
                fprintf(stderr, "Error at line %d: Function '%s' expects %d arguments but got %d\n", 
                    yylineno, $1, func->param_count, arg_count);
                yyerror("Function argument count mismatch");
                YYERROR;
            }

            // Storing original symbol values
            VarValue* original_values = malloc(func->param_count * sizeof(VarValue));
            Symbol** original_symbols = malloc(func->param_count * sizeof(Symbol*));
            
            for (int i = 0; i < func->param_count && i < arg_count; i++) {
                VarValue val;
                val.number_val = args[i].value.number_val;
                
                // Storing original value if parameter exists
                Symbol* sym = lookup_symbol(sym_table, func->params[i]);
                if (sym) {
                    original_symbols[i] = sym;
                    original_values[i] = sym->value;
                } else {
                    original_symbols[i] = NULL;
                }
                
                // Setting new parameter value
                insert_symbol(sym_table, func->params[i], TYPE_NUMBER, val, false);
                fprintf(output_file, "Parameter %s = %f\n", func->params[i], val.number_val);
            }

            // Resetting original symbol values
            for (int i = 0; i < func->param_count; i++) {
                if (original_symbols[i]) {
                    insert_symbol(sym_table, original_symbols[i]->name, original_symbols[i]->type, original_values[i], original_symbols[i]->is_constant);
                }
            }

            $$ = func->return_expr;  
        } else {
            fprintf(output_file, "Warning: Unknown function %s\n", $1);
            $$.type = TYPE_NUMBER;
            $$.value.number_val = 0;
        }
    }
    ;

comment_stmt
    : SLC {
        fprintf(output_file, "\n\nSingle-line comment at line %d: %s\n\n", yylineno, yytext);
    }
    | MLC {
        fprintf(output_file, "\n\nMulti-line comment starting at line %d: %s\n\n", yylineno, yytext);
    }
    ;

scanf_stmt
    : SCANF '(' IDENTIFIER ')' {
        Symbol* sym = lookup_symbol(sym_table, $3);
        if (!sym) {
            // If variable doesn't exist, creating it
            VarValue val;
            val.number_val = 0;  // init
            if (!insert_symbol(sym_table, $3, TYPE_NUMBER, val, false)) {
                fprintf(stderr, "Error: Cannot create variable '%s' at line %d\n", $3, yylineno);
                YYERROR;
            }
        }
        
        float value;
        fprintf(output_file, "Reading input for %s: ", $3);
        printf("Reading input for %s: ", $3);
        if (scanf("%f", &value) == 1) {
            // Updating symbol value
            if (sym->type == TYPE_NUMBER) {
                sym->value.number_val = value;
                fprintf(output_file, "Successfully read value: %f\n", value);
            } else {
                fprintf(stderr, "Error: Variable '%s' is not a number at line %d\n", $3, yylineno);
                YYERROR;
            }
        } else {
            fprintf(stderr, "Error: Invalid input for variable '%s' at line %d\n", $3, yylineno);
            YYERROR;
        }
    }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s at line %d\n", s, yylineno);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    // Initializing Symbol Table with a prime number size 
    // for better distribution in hash table
    sym_table = init_symbol_table(101);
    func_table = init_function_table();

    FILE *input_file = fopen(argv[1], "r");
    if (!input_file) {
        printf("Cannot open input file %s\n", argv[1]);
        return 1;
    }
    yyin = input_file;

    output_file = fopen(argv[2], "w");
    if (!output_file) {
        printf("Cannot open output file %s\n", argv[2]);
        return 1;
    }

    fprintf(output_file, "++++ Starting the parser +++++\n\n");

    yyparse();

    fprintf(output_file, "\n++++ Counts +++++\n");
    fprintf(output_file, "\nVariables: %d\n\n", var_count);
    
    print_symbol_table(output_file, sym_table);

    fprintf(output_file, "\nFunctions: %d\n\n", func_count);
    for (int i = 0; i < function_count; i++) {
        fprintf(output_file, "Function: %s (Parameters: %d)\n", 
            function_defs[i].name, 
            function_defs[i].param_count);
    }

    fprintf(output_file, "\nClasses: %d\n\n", class_count);

    free_symbol_table(sym_table);
    free_function_table(func_table);
    fclose(input_file);
    fclose(output_file);
    return 0;
} 