%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbolTable/symbol_table.h"
#include "zsharp.tab.h"

int line_num = 1;
extern FILE* output_file;
extern void yyerror(const char *s);

void print_token(const char* token_name, const char* value) {
    fprintf(output_file, "TOKEN: %-15s \tVALUE: %s\n", token_name, value);
}
%}

%option noyywrap
%option yylineno

IDENTIFIER    [a-zA-Z_][a-zA-Z0-9_]*
VSTRING       \`([^`\$]|(\$\{[^}]+\}))*\`
STRING        \"([^\"\\]|\\.)*\" 
FLOAT         [0-9]+\.[0-9]+([eE][+-]?[0-9]+)?
INTEGER       [0-9]+
NUMBER        {INTEGER}|{FLOAT}
OPERATOR      [-+*/=<>!&|]
DELIMITER     [,\(\)\[\]\{\}\\]
SLC           "//".*   
MLC           "/*"([^*]|\*+[^*/])*\*+"/"       
WS            [ \t\r\n]

%%

{WS}+          { if (strchr(yytext, '\n')) line_num++; } 

{SLC}           { print_token("SLC", yytext); }
{MLC}           { print_token("MLC", yytext);
                  for(int i = 0; yytext[i] != '\0'; i++) 
                      if(yytext[i] == '\n') line_num++;
                }

"bet"           { print_token("VARIABLE", yytext); return VARIABLE; }
"fr"            { print_token("CONST", yytext); return CONST; }
"era"           { print_token("FUNCTION", yytext); return FUNCTION; }
"vibeCheck"     { print_token("IF", yytext); return IF; }
"aint"          { print_token("ELSE_IF", yytext); return ELSE_IF; }
"meh"           { print_token("ELSE", yytext); return ELSE; }
"loopin"        { print_token("FOR", yytext); return FOR; }
"yeet"          { print_token("RETURN", yytext); return RETURN; }
"spill_tea"     { print_token("PRINT", yytext); return PRINT; }
"noCap"         { print_token("TRUE", yytext); return TRUE_VAL; }
"cap"           { print_token("FALSE", yytext); return FALSE_VAL; }
"squad"         { print_token("ARRAY", yytext); return ARRAY; }
"ghost"         { print_token("BREAK", yytext); return BREAK; }
"skip"          { print_token("CONTINUE", yytext); return CONTINUE; }
"slidein"       { print_token("INCLUDE", yytext); return INCLUDE; }
"clout"         { print_token("CLASS", yytext); return CLASS; }
"levelUp"       { print_token("EXTENDS", yytext); return EXTENDS; }
"npc"           { print_token("NULL", yytext); return NULL_VAL; }
"test"          { print_token("TRY", yytext); return TRY; }
"caughtIn4k"    { print_token("CATCH", yytext); return CATCH; }
"slayy"         { print_token("SUCCESS", yytext); return SUCCESS; }
"lowkey"        { print_token("PRIVATE", yytext); return PRIVATE; }
"highkey"       { print_token("PUBLIC", yytext); return PUBLIC; }
"OG"            { print_token("MAIN", yytext); return MAIN; }
"checkIt"       { print_token("SCANF", yytext); return SCANF; }

{NUMBER}        { yylval.number_val = atof(yytext);  return NUMBER; }
{STRING}        { print_token("STRING", yytext); yylval.string_val = strdup(yytext); return STRING_LIT; }
{VSTRING}       { print_token("VSTRING", yytext); yylval.string_val = strdup(yytext); return VSTRING_LIT; }
{IDENTIFIER}    { print_token("IDENTIFIER", yytext); yylval.string_val = strdup(yytext); return IDENTIFIER; }

"+"             { print_token("PLUS", yytext); return PLUS; }
"-"             { print_token("MINUS", yytext); return MINUS; }
"*"             { print_token("MULTIPLY", yytext); return MULTIPLY; }
"/"             { print_token("DIVIDE", yytext); return DIVIDE; }
"="             { print_token("ASSIGN", yytext); return ASSIGN; }
"=="            { print_token("EQ", yytext); return EQ; }
"!="            { print_token("NEQ", yytext); return NEQ; }
"<"             { print_token("LT", yytext); return LT; }
"<="            { print_token("LTE", yytext); return LTE; }
">"             { print_token("GT", yytext); return GT; }
">="            { print_token("GTE", yytext); return GTE; }
"&&"            { print_token("AND", yytext); return AND; }
"||"            { print_token("OR", yytext); return OR; }
"!"             { print_token("NOT", yytext); return NOT; }

"#"             { print_token("FOR_SEP", yytext); return FOR_SEP; }

[\(\)\[\]\{\},] { print_token("DELIMITER", yytext); return yytext[0]; }

.               { fprintf(stderr, "Error: Unexpected character '%s' at line %d\n", yytext, line_num); }

%%
