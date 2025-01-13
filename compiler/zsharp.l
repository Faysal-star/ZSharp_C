%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"
#include "zsharp.tab.h"

int line_num = 1;
extern FILE* output_file;
extern void yyerror(const char *s);

void print_token(const char* token_name, const char* value) {
    fprintf(output_file, "\n\nFound: %-15s \tVALUE: %s\n\n", token_name, value);
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

{SLC}           { return SLC; }
{MLC}           { return MLC; }

"bet"           { return VARIABLE; }
"fr"            { return CONST; }
"era"           { return FUNCTION; }
"vibeCheck"     { return IF; }
"aint"          { return ELSE_IF; }
"meh"           { return ELSE; }
"loopin"        { return FOR; }
"yeet"          { return RETURN; }
"spill_tea"     { return PRINT; }
"noCap"         { return TRUE_VAL; }
"cap"           { return FALSE_VAL; }
"squad"         { return ARRAY; }
"ghost"         { return BREAK; }
"skip"          { return CONTINUE; }
"slidein"       { return INCLUDE; }
"clout"         { return CLASS; }
"levelUp"       { return EXTENDS; }
"npc"           { return NULL_VAL; }
"test"          { return TRY; }
"caughtIn4k"    { return CATCH; }
"slayy"         { return SUCCESS; }
"lowkey"        { return PRIVATE; }
"highkey"       { return PUBLIC; }
"OG"            { return MAIN; }
"checkIt"       { return SCANF; }

{NUMBER}        { yylval.number_val = atof(yytext);  return NUMBER; }
{STRING}        { yylval.string_val = strdup(yytext); return STRING_LIT; }
{VSTRING}       { yylval.string_val = strdup(yytext); return VSTRING_LIT; }
{IDENTIFIER}    { yylval.string_val = strdup(yytext); return IDENTIFIER; }

"+"             { return PLUS; }
"-"             { return MINUS; }
"*"             { return MULTIPLY; }
"/"             { return DIVIDE; }
"="             { return ASSIGN; }
"=="            { return EQ; }
"!="            { return NEQ; }
"<"             { return LT; }
"<="            { return LTE; }
">"             { return GT; }
">="            { return GTE; }
"&&"            { return AND; }
"||"            { return OR; }
"!"             { return NOT; }

"#"             { return FOR_SEP; }

[\(\)\[\]\{\},] { return yytext[0]; }

.               { fprintf(stderr, "Error: Unexpected character '%s' at line %d\n", yytext, line_num); }

%%
