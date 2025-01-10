/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_INTERMEDIATE_ZSHARP_TAB_H_INCLUDED
# define YY_YY_INTERMEDIATE_ZSHARP_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    VARIABLE = 258,                /* VARIABLE  */
    CONST = 259,                   /* CONST  */
    FUNCTION = 260,                /* FUNCTION  */
    IF = 261,                      /* IF  */
    ELSE_IF = 262,                 /* ELSE_IF  */
    ELSE = 263,                    /* ELSE  */
    FOR = 264,                     /* FOR  */
    RETURN = 265,                  /* RETURN  */
    PRINT = 266,                   /* PRINT  */
    TRUE_VAL = 267,                /* TRUE_VAL  */
    FALSE_VAL = 268,               /* FALSE_VAL  */
    ARRAY = 269,                   /* ARRAY  */
    BREAK = 270,                   /* BREAK  */
    CONTINUE = 271,                /* CONTINUE  */
    INCLUDE = 272,                 /* INCLUDE  */
    CLASS = 273,                   /* CLASS  */
    EXTENDS = 274,                 /* EXTENDS  */
    NULL_VAL = 275,                /* NULL_VAL  */
    TRY = 276,                     /* TRY  */
    CATCH = 277,                   /* CATCH  */
    SUCCESS = 278,                 /* SUCCESS  */
    PRIVATE = 279,                 /* PRIVATE  */
    PUBLIC = 280,                  /* PUBLIC  */
    MAIN = 281,                    /* MAIN  */
    SCANF = 282,                   /* SCANF  */
    FOR_SEP = 283,                 /* FOR_SEP  */
    NUMBER = 284,                  /* NUMBER  */
    STRING_LIT = 285,              /* STRING_LIT  */
    VSTRING_LIT = 286,             /* VSTRING_LIT  */
    IDENTIFIER = 287,              /* IDENTIFIER  */
    PLUS = 288,                    /* PLUS  */
    MINUS = 289,                   /* MINUS  */
    MULTIPLY = 290,                /* MULTIPLY  */
    DIVIDE = 291,                  /* DIVIDE  */
    ASSIGN = 292,                  /* ASSIGN  */
    EQ = 293,                      /* EQ  */
    NEQ = 294,                     /* NEQ  */
    LT = 295,                      /* LT  */
    LTE = 296,                     /* LTE  */
    GT = 297,                      /* GT  */
    GTE = 298,                     /* GTE  */
    AND = 299,                     /* AND  */
    OR = 300,                      /* OR  */
    NOT = 301                      /* NOT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 26 "compiler/zsharp.y"

    float number_val;
    char* string_val;
    ExprValue expr_val;

#line 116 "intermediate/zsharp.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_INTERMEDIATE_ZSHARP_TAB_H_INCLUDED  */
