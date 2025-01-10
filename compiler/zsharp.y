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

// Initializing Symbol Table
SymbolTable* sym_table;

%}

%union {
    float number_val;
    char* string_val;
    ExprValue expr_val;
}

// Type declarations
%type <expr_val> expression numeric_expression string_expression
%type <expr_val> for_init for_condition for_increment
%type <number_val> boolean_expression
%type <string_val> variable_declaration

// Token declarations
%token VARIABLE CONST FUNCTION IF ELSE_IF ELSE FOR RETURN PRINT
%token TRUE_VAL FALSE_VAL ARRAY BREAK CONTINUE INCLUDE CLASS EXTENDS
%token NULL_VAL TRY CATCH SUCCESS PRIVATE PUBLIC MAIN SCANF
%token FOR_SEP
%token <number_val> NUMBER
%token <string_val> STRING_LIT VSTRING_LIT IDENTIFIER
%token PLUS MINUS MULTIPLY DIVIDE ASSIGN EQ NEQ LT LTE GT GTE AND OR NOT

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
    ;

include_stmt
    : INCLUDE STRING_LIT {
        fprintf(output_file, "Import detected with path: %s\n", $2);
    }
    ;

break_stmt
    : BREAK {
        fprintf(output_file, "Break statement detected\n");
    }
    ;

continue_stmt
    : CONTINUE {
        fprintf(output_file, "Continue statement detected\n");
    }
    ;

class_declaration
    : CLASS IDENTIFIER opt_extends '{' class_body '}' {
        fprintf(output_file, "\nClass declaration detected: %s\n\n", $2);
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
    : FUNCTION IDENTIFIER '(' parameter_list ')' '{' statements '}' {
        fprintf(output_file, "\nFunction declaration detected: %s\n\n", $2);
        func_count++;
    }
    | FUNCTION MAIN '(' parameter_list ')' '{' statements '}' {
        fprintf(output_file, "\nMAIN Function declaration detected\n\n");
        func_count++;
        main_count++;
        if(main_count > 1) {
            fprintf(output_file, "Error: Multiple main functions detected\n");
            exit(1);
        }
    }
    ;

parameter_list
    : /* empty */
    | IDENTIFIER
    | parameter_list ',' IDENTIFIER
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
        if (!insert_symbol(sym_table, $2, type, val)) {
            fprintf(stderr, "Error: Variable '%s' redeclared at line %d\n", $2, yylineno);
            if (type == TYPE_STRING) {
                free(val.string_val);
            }
            yyerror("Redeclaration of variable");
            YYERROR;
        }
        
        var_count++;
        fprintf(output_file, "Variable declaration detected: %s\n", $2);
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

        if (!insert_symbol(sym_table, $2, type, val)) {
            fprintf(stderr, "Error: Constant '%s' redeclared at line %d\n", $2, yylineno);
            if (type == TYPE_STRING) {
                free(val.string_val);
            }
            yyerror("Redeclaration of constant");
            YYERROR;
        }
        var_count++;
        fprintf(output_file, "Constant declaration detected: %s\n", $2);
    }
    | ARRAY IDENTIFIER ASSIGN '[' expression_list ']' {
        $$ = $2;
        fprintf(output_file, "Array declaration detected: %s\n", $2);
        var_count++;
    }
    ;

print_stmt
    : PRINT expression {
        fprintf(output_file, "Print statement detected: ");
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
            fprintf(output_file, "Single If statement Detected\n");
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
            fprintf(output_file, "If-Else statement Detected\n"); 
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
            fprintf(output_file, "If-ElseIf statement Detected\n"); 
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
            fprintf(output_file, "If-ElseIf-Else statement Detected\n"); 
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
            fprintf(output_file, "Else-if block Detected\n"); 
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
            fprintf(output_file, "Additional else-if block Detected\n"); 
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
            fprintf(output_file, "For loop detected \n\n");
        }
    ;

for_init
    : variable_declaration 
    | expression { 
        $$ = $1; 
    }
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
    : TRY '{' statements '}' CATCH '{' statements '}'
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
    | boolean_expression { 
        $$.type = TYPE_NUMBER;
        $$.value.number_val = $1;
    }
    | IDENTIFIER ASSIGN expression {
        Symbol* sym = lookup_symbol(sym_table, $1);
        if (!sym) {
            VarValue val;
            if ($3.type == TYPE_NUMBER) {
                val.number_val = $3.value.number_val;
                insert_symbol(sym_table, $1, TYPE_NUMBER, val);
            } else if ($3.type == TYPE_STRING) {
                val.string_val = strdup($3.value.string_val);
                insert_symbol(sym_table, $1, TYPE_STRING, val);
            }
        } else {
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
            yyerror("Division by zero");
            YYERROR;
        }
        $$.type = TYPE_NUMBER;
        $$.value.number_val = $1.value.number_val / $3.value.number_val;
        fprintf(output_file, "Division: %f / %f = %f\n", 
                $1.value.number_val, $3.value.number_val, $$.value.number_val);
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
            insert_symbol(sym_table, $1, TYPE_NUMBER, val);
            
            fprintf(output_file, "Warning: Undefined variable '%s' at line %d, initializing with 0\n", 
                   $1, yylineno);
        } else {
            if (sym->type != TYPE_NUMBER) {
                yyerror("Type mismatch: expected number");
                YYERROR;
            }
            $$.type = TYPE_NUMBER;
            $$.value.number_val = sym->value.number_val;
            fprintf(output_file, "Using variable %s with value %f\n", $1, $$.value.number_val);
        

        }
    }
    | IDENTIFIER '[' numeric_expression ']' {
        // TODO: Implement array access
        $$.type = TYPE_NUMBER;
        $$.value.number_val = 0;
        fprintf(output_file, "Array access: %s[%f]\n", $1, $3.value.number_val);
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
    : expression
    | expression_list ',' expression
    ;

argument_list
    : /* empty */
    | expression
    | argument_list ',' expression
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
    fprintf(output_file, "Variables: %d\n", var_count);
    
    print_symbol_table(output_file, sym_table);

    fprintf(output_file, "Functions: %d\n", func_count);
    fprintf(output_file, "Classes: %d\n", class_count);

    free_symbol_table(sym_table);
    fclose(input_file);
    fclose(output_file);
    return 0;
} 