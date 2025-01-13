/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "compiler/zsharp.y"

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


#line 123 "intermediate/zsharp.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "zsharp.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_VARIABLE = 3,                   /* VARIABLE  */
  YYSYMBOL_CONST = 4,                      /* CONST  */
  YYSYMBOL_FUNCTION = 5,                   /* FUNCTION  */
  YYSYMBOL_IF = 6,                         /* IF  */
  YYSYMBOL_ELSE_IF = 7,                    /* ELSE_IF  */
  YYSYMBOL_ELSE = 8,                       /* ELSE  */
  YYSYMBOL_FOR = 9,                        /* FOR  */
  YYSYMBOL_RETURN = 10,                    /* RETURN  */
  YYSYMBOL_PRINT = 11,                     /* PRINT  */
  YYSYMBOL_TRUE_VAL = 12,                  /* TRUE_VAL  */
  YYSYMBOL_FALSE_VAL = 13,                 /* FALSE_VAL  */
  YYSYMBOL_ARRAY = 14,                     /* ARRAY  */
  YYSYMBOL_BREAK = 15,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 16,                  /* CONTINUE  */
  YYSYMBOL_INCLUDE = 17,                   /* INCLUDE  */
  YYSYMBOL_CLASS = 18,                     /* CLASS  */
  YYSYMBOL_EXTENDS = 19,                   /* EXTENDS  */
  YYSYMBOL_NULL_VAL = 20,                  /* NULL_VAL  */
  YYSYMBOL_TRY = 21,                       /* TRY  */
  YYSYMBOL_CATCH = 22,                     /* CATCH  */
  YYSYMBOL_SUCCESS = 23,                   /* SUCCESS  */
  YYSYMBOL_PRIVATE = 24,                   /* PRIVATE  */
  YYSYMBOL_PUBLIC = 25,                    /* PUBLIC  */
  YYSYMBOL_MAIN = 26,                      /* MAIN  */
  YYSYMBOL_SCANF = 27,                     /* SCANF  */
  YYSYMBOL_FOR_SEP = 28,                   /* FOR_SEP  */
  YYSYMBOL_NUMBER = 29,                    /* NUMBER  */
  YYSYMBOL_STRING_LIT = 30,                /* STRING_LIT  */
  YYSYMBOL_VSTRING_LIT = 31,               /* VSTRING_LIT  */
  YYSYMBOL_IDENTIFIER = 32,                /* IDENTIFIER  */
  YYSYMBOL_PLUS = 33,                      /* PLUS  */
  YYSYMBOL_MINUS = 34,                     /* MINUS  */
  YYSYMBOL_MULTIPLY = 35,                  /* MULTIPLY  */
  YYSYMBOL_DIVIDE = 36,                    /* DIVIDE  */
  YYSYMBOL_ASSIGN = 37,                    /* ASSIGN  */
  YYSYMBOL_EQ = 38,                        /* EQ  */
  YYSYMBOL_NEQ = 39,                       /* NEQ  */
  YYSYMBOL_LT = 40,                        /* LT  */
  YYSYMBOL_LTE = 41,                       /* LTE  */
  YYSYMBOL_GT = 42,                        /* GT  */
  YYSYMBOL_GTE = 43,                       /* GTE  */
  YYSYMBOL_AND = 44,                       /* AND  */
  YYSYMBOL_OR = 45,                        /* OR  */
  YYSYMBOL_NOT = 46,                       /* NOT  */
  YYSYMBOL_SLC = 47,                       /* SLC  */
  YYSYMBOL_MLC = 48,                       /* MLC  */
  YYSYMBOL_49_ = 49,                       /* '{'  */
  YYSYMBOL_50_ = 50,                       /* '}'  */
  YYSYMBOL_51_ = 51,                       /* '('  */
  YYSYMBOL_52_ = 52,                       /* ')'  */
  YYSYMBOL_53_ = 53,                       /* ','  */
  YYSYMBOL_54_ = 54,                       /* '['  */
  YYSYMBOL_55_ = 55,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 56,                  /* $accept  */
  YYSYMBOL_program = 57,                   /* program  */
  YYSYMBOL_statements = 58,                /* statements  */
  YYSYMBOL_statement = 59,                 /* statement  */
  YYSYMBOL_include_stmt = 60,              /* include_stmt  */
  YYSYMBOL_break_stmt = 61,                /* break_stmt  */
  YYSYMBOL_continue_stmt = 62,             /* continue_stmt  */
  YYSYMBOL_class_declaration = 63,         /* class_declaration  */
  YYSYMBOL_opt_extends = 64,               /* opt_extends  */
  YYSYMBOL_class_body = 65,                /* class_body  */
  YYSYMBOL_class_member = 66,              /* class_member  */
  YYSYMBOL_access_modifier = 67,           /* access_modifier  */
  YYSYMBOL_function_declaration = 68,      /* function_declaration  */
  YYSYMBOL_parameter_list = 69,            /* parameter_list  */
  YYSYMBOL_variable_declaration = 70,      /* variable_declaration  */
  YYSYMBOL_print_stmt = 71,                /* print_stmt  */
  YYSYMBOL_if_statement = 72,              /* if_statement  */
  YYSYMBOL_else_if_list = 73,              /* else_if_list  */
  YYSYMBOL_for_statement = 74,             /* for_statement  */
  YYSYMBOL_for_init = 75,                  /* for_init  */
  YYSYMBOL_for_condition = 76,             /* for_condition  */
  YYSYMBOL_for_increment = 77,             /* for_increment  */
  YYSYMBOL_try_catch_stmt = 78,            /* try_catch_stmt  */
  YYSYMBOL_return_stmt = 79,               /* return_stmt  */
  YYSYMBOL_expression_stmt = 80,           /* expression_stmt  */
  YYSYMBOL_expression = 81,                /* expression  */
  YYSYMBOL_numeric_expression = 82,        /* numeric_expression  */
  YYSYMBOL_string_expression = 83,         /* string_expression  */
  YYSYMBOL_expression_list = 84,           /* expression_list  */
  YYSYMBOL_argument_list = 85,             /* argument_list  */
  YYSYMBOL_boolean_expression = 86,        /* boolean_expression  */
  YYSYMBOL_function_call = 87,             /* function_call  */
  YYSYMBOL_comment_stmt = 88,              /* comment_stmt  */
  YYSYMBOL_scanf_stmt = 89                 /* scanf_stmt  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  68
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   728

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  94
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  200

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   303


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      51,    52,     2,     2,    53,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    54,     2,    55,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    49,     2,    50,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    94,    94,    98,    99,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   120,
     126,   132,   138,   145,   146,   150,   151,   155,   156,   160,
     161,   165,   183,   208,   212,   217,   225,   257,   284,   316,
     329,   340,   352,   363,   378,   389,   404,   411,   415,   419,
     420,   427,   428,   435,   442,   446,   450,   451,   452,   478,
     482,   483,   524,   528,   534,   540,   546,   557,   558,   586,
     629,   633,   637,   648,   653,   666,   670,   678,   689,   692,
     695,   698,   701,   704,   707,   710,   713,   716,   719,   722,
     725,   731,   783,   786,   792
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "VARIABLE", "CONST",
  "FUNCTION", "IF", "ELSE_IF", "ELSE", "FOR", "RETURN", "PRINT",
  "TRUE_VAL", "FALSE_VAL", "ARRAY", "BREAK", "CONTINUE", "INCLUDE",
  "CLASS", "EXTENDS", "NULL_VAL", "TRY", "CATCH", "SUCCESS", "PRIVATE",
  "PUBLIC", "MAIN", "SCANF", "FOR_SEP", "NUMBER", "STRING_LIT",
  "VSTRING_LIT", "IDENTIFIER", "PLUS", "MINUS", "MULTIPLY", "DIVIDE",
  "ASSIGN", "EQ", "NEQ", "LT", "LTE", "GT", "GTE", "AND", "OR", "NOT",
  "SLC", "MLC", "'{'", "'}'", "'('", "')'", "','", "'['", "']'", "$accept",
  "program", "statements", "statement", "include_stmt", "break_stmt",
  "continue_stmt", "class_declaration", "opt_extends", "class_body",
  "class_member", "access_modifier", "function_declaration",
  "parameter_list", "variable_declaration", "print_stmt", "if_statement",
  "else_if_list", "for_statement", "for_init", "for_condition",
  "for_increment", "try_catch_stmt", "return_stmt", "expression_stmt",
  "expression", "numeric_expression", "string_expression",
  "expression_list", "argument_list", "boolean_expression",
  "function_call", "comment_stmt", "scanf_stmt", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-53)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-79)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     613,   -29,   -25,    38,   -38,   -33,    -3,    -3,   -53,   -53,
      -2,   -53,   -53,    30,    41,    31,    44,   -53,   -53,   -53,
      76,    56,   -53,   -53,    56,   100,   613,   -53,   -53,   -53,
     -53,   -53,   -53,   -53,   -53,   -53,   -53,   -53,   -53,   -53,
     -53,   683,    73,    42,   -53,   -53,   -53,    71,    87,    88,
      90,    56,    35,   -53,   -53,   106,   -53,   135,   613,   124,
      -3,    -3,   -10,   113,   173,   -53,   663,   -12,   -53,   -53,
     -10,   -10,   -10,   -10,   -10,   -10,   -10,   -10,   -10,   -10,
      59,    56,    56,    -3,    -3,   136,   136,    27,   -53,   142,
     117,   141,   130,   172,   122,   -53,   -53,    51,   -10,   -19,
     -53,   -53,    93,    93,   -53,   -53,   112,   112,   112,   112,
     112,   112,   -53,   -53,   147,   -53,   -53,   -53,    82,    85,
     143,    56,    -3,   -53,   125,   174,   -53,   -53,    -3,    11,
     -53,   145,   163,   148,   613,   170,    42,   -53,    28,   -53,
     -53,   -13,   -53,    20,   149,   -53,   613,   -53,   613,   221,
      -3,    -3,   -53,   -53,   -53,   -53,   -53,   178,   270,   662,
     144,   165,   -53,   -53,   169,   -53,    -3,   154,   179,   153,
     180,   191,   193,    56,   613,   190,   195,   613,   613,   -53,
      32,   319,    56,   613,   368,   417,   196,   -53,    47,   466,
     -53,   -53,   613,   197,   -53,   515,   613,   -53,   564,   -53
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,    88,    89,
       0,    20,    21,     0,     0,     0,     0,    62,    70,    71,
      58,     0,    92,    93,     0,     0,     2,     3,     5,    15,
      16,     6,     7,     8,    13,    10,    11,    12,    14,     9,
      55,    56,    57,    59,    60,    17,    18,     0,     0,     0,
       0,     0,    47,    54,    39,     0,    19,    24,     0,     0,
       0,    75,     0,    68,    78,    87,    78,     0,     1,     4,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    33,     0,    48,     0,
       0,     0,     0,     0,     0,    61,    76,     0,     0,     0,
      67,    90,    63,    64,    65,    66,    83,    84,    81,    82,
      79,    80,    72,    85,    86,    36,    38,    34,     0,     0,
       0,    50,     0,    23,     0,     0,    94,    91,     0,     0,
      69,     0,     0,     0,     0,     0,    49,    73,     0,    30,
      29,     0,    25,     0,     0,    77,     0,    35,     0,     0,
      52,     0,    37,    22,    26,    28,    27,     0,     0,     0,
      40,     0,    51,    74,     0,    32,     0,     0,     0,    42,
       0,     0,    54,     0,     0,     0,     0,     0,     0,    31,
       0,     0,     0,     0,     0,     0,     0,    41,     0,     0,
      46,    53,     0,     0,    43,     0,     0,    44,     0,    45
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -53,   -53,   -52,   -26,   -53,   -53,   -53,   -53,   -53,   -53,
     108,   -53,   104,   168,   -50,   -53,   -53,   -53,   -53,   -53,
     -53,   -53,   -53,   -53,   -53,    14,   -20,   175,   -53,   -53,
     -16,   -53,   -53,   -53
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    25,    26,    27,    28,    29,    30,    31,    92,   141,
     142,   143,    32,   118,    33,    34,    35,   169,    36,    89,
     135,   161,    37,    38,    39,    40,    41,    42,   138,    97,
      43,    44,    45,    46
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      69,    64,    88,    47,    66,    65,    93,    48,    67,     8,
       9,   139,   140,    51,    70,    71,    72,    73,    52,    17,
      53,    54,    63,     1,     2,     3,    17,    18,    19,    20,
      55,    64,    81,    82,    10,    87,   130,   153,     1,     2,
     101,    98,    99,    21,    70,    71,    72,    73,    24,    10,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
      56,    64,    64,   100,    49,   113,   114,    69,     8,     9,
      50,    81,    82,    57,    95,    96,    81,    82,   129,   120,
      58,   151,   149,   152,   186,    17,    81,    82,    63,    18,
      19,    81,    82,   156,   158,    59,   159,   115,   116,   193,
      68,    64,    21,   127,   128,   136,    80,    24,    83,   -68,
     -68,   -68,   -68,    60,   -68,   -68,   -68,   -68,   -68,   -68,
     -68,   -68,   181,    69,    84,   184,   185,    61,    72,    73,
      62,   189,    69,    69,   131,   132,   137,   133,   132,    85,
     195,    86,   145,    90,   198,    70,    71,    72,    73,   139,
     140,   167,   168,    64,    91,    69,    94,   180,    69,    69,
     175,   176,    64,    69,   162,   163,   188,    62,   117,    69,
     121,   122,    69,   123,   126,     1,     2,     3,     4,   124,
     172,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    81,   134,    15,   146,   147,   144,   148,   150,    16,
     157,    17,    18,    19,    20,   173,    70,    71,    72,    73,
     164,    74,    75,    76,    77,    78,    79,   170,    21,    22,
      23,   171,   125,    24,     1,     2,     3,     4,   174,   177,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
     178,   182,    15,   179,   183,   192,   196,   155,    16,   154,
      17,    18,    19,    20,   119,   112,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    21,    22,    23,
       0,   160,    24,     1,     2,     3,     4,     0,     0,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,     0,
       0,    15,     0,     0,     0,     0,     0,    16,     0,    17,
      18,    19,    20,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    21,    22,    23,     0,
     165,    24,     1,     2,     3,     4,     0,     0,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,     0,     0,
      15,     0,     0,     0,     0,     0,    16,     0,    17,    18,
      19,    20,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    21,    22,    23,     0,   187,
      24,     1,     2,     3,     4,     0,     0,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,     0,     0,    15,
       0,     0,     0,     0,     0,    16,     0,    17,    18,    19,
      20,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    21,    22,    23,     0,   190,    24,
       1,     2,     3,     4,     0,     0,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,     0,     0,    15,     0,
       0,     0,     0,     0,    16,     0,    17,    18,    19,    20,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    21,    22,    23,     0,   191,    24,     1,
       2,     3,     4,     0,     0,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,     0,     0,    15,     0,     0,
       0,     0,     0,    16,     0,    17,    18,    19,    20,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    21,    22,    23,     0,   194,    24,     1,     2,
       3,     4,     0,     0,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,     0,     0,    15,     0,     0,     0,
       0,     0,    16,     0,    17,    18,    19,    20,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    21,    22,    23,     0,   197,    24,     1,     2,     3,
       4,     0,     0,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,     0,     0,    15,     0,     0,     0,     0,
       0,    16,     0,    17,    18,    19,    20,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      21,    22,    23,     0,   199,    24,     1,     2,     3,     4,
       0,     0,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,     0,     0,    15,     0,     0,     0,     0,     0,
      16,     0,    17,    18,    19,    20,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    21,
      22,    23,     0,     0,    24,     1,     2,     3,     4,     0,
       0,     5,   166,     7,     8,     9,    10,    11,    12,    13,
      14,     0,     0,    15,     0,     0,     0,     0,     0,    16,
       0,    17,    18,    19,    20,     0,    70,    71,    72,    73,
       0,    74,    75,    76,    77,    78,    79,     0,    21,    22,
      23,     0,     0,    24,     0,   100,    70,    71,    72,    73,
       0,    74,    75,    76,    77,    78,    79,   -78,   -78
};

static const yytype_int16 yycheck[] =
{
      26,    21,    52,    32,    24,    21,    58,    32,    24,    12,
      13,    24,    25,    51,    33,    34,    35,    36,    51,    29,
       6,     7,    32,     3,     4,     5,    29,    30,    31,    32,
      32,    51,    44,    45,    14,    51,    55,    50,     3,     4,
      52,    51,    62,    46,    33,    34,    35,    36,    51,    14,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      30,    81,    82,    52,    26,    81,    82,    93,    12,    13,
      32,    44,    45,    32,    60,    61,    44,    45,    98,    52,
      49,    53,   134,    55,    52,    29,    44,    45,    32,    30,
      31,    44,    45,   143,   146,    51,   148,    83,    84,    52,
       0,   121,    46,    52,    53,   121,    33,    51,    37,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,   174,   149,    37,   177,   178,    51,    35,    36,
      54,   183,   158,   159,    52,    53,   122,    52,    53,    51,
     192,    51,   128,    37,   196,    33,    34,    35,    36,    24,
      25,     7,     8,   173,    19,   181,    32,   173,   184,   185,
       7,     8,   182,   189,   150,   151,   182,    54,    32,   195,
      28,    54,   198,    32,    52,     3,     4,     5,     6,    49,
     166,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    44,    49,    21,    49,    32,    22,    49,    28,    27,
      51,    29,    30,    31,    32,    51,    33,    34,    35,    36,
      32,    38,    39,    40,    41,    42,    43,    52,    46,    47,
      48,    52,    50,    51,     3,     4,     5,     6,    49,    49,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      49,    51,    21,    50,    49,    49,    49,   143,    27,   141,
      29,    30,    31,    32,    86,    80,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,
      -1,    50,    51,     3,     4,     5,     6,    -1,    -1,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    -1,
      -1,    21,    -1,    -1,    -1,    -1,    -1,    27,    -1,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,    -1,
      50,    51,     3,     4,     5,     6,    -1,    -1,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    -1,    -1,
      21,    -1,    -1,    -1,    -1,    -1,    27,    -1,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    47,    48,    -1,    50,
      51,     3,     4,     5,     6,    -1,    -1,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    -1,    -1,    21,
      -1,    -1,    -1,    -1,    -1,    27,    -1,    29,    30,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    47,    48,    -1,    50,    51,
       3,     4,     5,     6,    -1,    -1,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    -1,    -1,    21,    -1,
      -1,    -1,    -1,    -1,    27,    -1,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    47,    48,    -1,    50,    51,     3,
       4,     5,     6,    -1,    -1,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    -1,    -1,    21,    -1,    -1,
      -1,    -1,    -1,    27,    -1,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    47,    48,    -1,    50,    51,     3,     4,
       5,     6,    -1,    -1,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    -1,    -1,    21,    -1,    -1,    -1,
      -1,    -1,    27,    -1,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    47,    48,    -1,    50,    51,     3,     4,     5,
       6,    -1,    -1,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    -1,    -1,    21,    -1,    -1,    -1,    -1,
      -1,    27,    -1,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    47,    48,    -1,    50,    51,     3,     4,     5,     6,
      -1,    -1,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    -1,    -1,    21,    -1,    -1,    -1,    -1,    -1,
      27,    -1,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,
      47,    48,    -1,    -1,    51,     3,     4,     5,     6,    -1,
      -1,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    -1,    21,    -1,    -1,    -1,    -1,    -1,    27,
      -1,    29,    30,    31,    32,    -1,    33,    34,    35,    36,
      -1,    38,    39,    40,    41,    42,    43,    -1,    46,    47,
      48,    -1,    -1,    51,    -1,    52,    33,    34,    35,    36,
      -1,    38,    39,    40,    41,    42,    43,    44,    45
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    21,    27,    29,    30,    31,
      32,    46,    47,    48,    51,    57,    58,    59,    60,    61,
      62,    63,    68,    70,    71,    72,    74,    78,    79,    80,
      81,    82,    83,    86,    87,    88,    89,    32,    32,    26,
      32,    51,    51,    81,    81,    32,    30,    32,    49,    51,
      37,    51,    54,    32,    82,    86,    82,    86,     0,    59,
      33,    34,    35,    36,    38,    39,    40,    41,    42,    43,
      33,    44,    45,    37,    37,    51,    51,    86,    70,    75,
      37,    19,    64,    58,    32,    81,    81,    85,    51,    82,
      52,    52,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    83,    86,    86,    81,    81,    32,    69,    69,
      52,    28,    54,    32,    49,    50,    52,    52,    53,    82,
      55,    52,    53,    52,    49,    76,    86,    81,    84,    24,
      25,    65,    66,    67,    22,    81,    49,    32,    49,    58,
      28,    53,    55,    50,    66,    68,    70,    51,    58,    58,
      50,    77,    81,    81,    32,    50,    10,     7,     8,    73,
      52,    52,    81,    51,    49,     7,     8,    49,    49,    50,
      86,    58,    51,    49,    58,    58,    52,    50,    86,    58,
      50,    50,    49,    52,    50,    58,    49,    50,    58,    50
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    56,    57,    58,    58,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    60,
      61,    62,    63,    64,    64,    65,    65,    66,    66,    67,
      67,    68,    68,    69,    69,    69,    70,    70,    70,    71,
      72,    72,    72,    72,    73,    73,    74,    75,    75,    76,
      76,    77,    77,    78,    79,    80,    81,    81,    81,    81,
      81,    81,    82,    82,    82,    82,    82,    82,    82,    82,
      83,    83,    83,    84,    84,    85,    85,    85,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    87,    88,    88,    89
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     1,     6,     2,     0,     1,     2,     2,     2,     1,
       1,    10,     8,     0,     1,     3,     4,     6,     4,     2,
       7,    11,     8,    12,     7,     8,    11,     0,     1,     1,
       0,     1,     0,    11,     2,     1,     1,     1,     1,     1,
       1,     3,     1,     3,     3,     3,     3,     3,     1,     4,
       1,     1,     3,     1,     3,     0,     1,     3,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     1,     1,
       3,     4,     1,     1,     4
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 19: /* include_stmt: INCLUDE STRING_LIT  */
#line 120 "compiler/zsharp.y"
                         {
        fprintf(output_file, "→ Import detected with path: %s\n", (yyvsp[0].string_val));
    }
#line 1441 "intermediate/zsharp.tab.c"
    break;

  case 20: /* break_stmt: BREAK  */
#line 126 "compiler/zsharp.y"
            {
        fprintf(output_file, "→ Break statement detected\n");
    }
#line 1449 "intermediate/zsharp.tab.c"
    break;

  case 21: /* continue_stmt: CONTINUE  */
#line 132 "compiler/zsharp.y"
               {
        fprintf(output_file, "→ Continue statement detected\n");
    }
#line 1457 "intermediate/zsharp.tab.c"
    break;

  case 22: /* class_declaration: CLASS IDENTIFIER opt_extends '{' class_body '}'  */
#line 138 "compiler/zsharp.y"
                                                      {
        fprintf(output_file, "\n→ Class declaration detected: %s\n\n", (yyvsp[-4].string_val));
        class_count++;
    }
#line 1466 "intermediate/zsharp.tab.c"
    break;

  case 31: /* function_declaration: FUNCTION IDENTIFIER '(' parameter_list ')' '{' statements RETURN expression '}'  */
#line 165 "compiler/zsharp.y"
                                                                                      {
        fprintf(output_file, "\n→ Function declaration detected: %s\n\n", (yyvsp[-8].string_val));
        
        // Store the function definition
        if (function_count < 100) {
            function_defs[function_count].name = strdup((yyvsp[-8].string_val));
            function_defs[function_count].params = (yyvsp[-6].param_list).param_names;
            function_defs[function_count].param_count = (yyvsp[-6].param_list).param_count;
            function_defs[function_count].return_expr = (yyvsp[-1].expr_val);
            
            // Store in function table
            store_function_result(func_table, (yyvsp[-8].string_val), 0.0);  // Initialize with 0
            
            function_count++;
        }
        
        func_count++;
    }
#line 1489 "intermediate/zsharp.tab.c"
    break;

  case 32: /* function_declaration: FUNCTION MAIN '(' parameter_list ')' '{' statements '}'  */
#line 183 "compiler/zsharp.y"
                                                              {
        fprintf(output_file, "\n→ MAIN Function declaration detected\n\n");
        
        // Store main function
        if (function_count < 100) {
            function_defs[function_count].name = strdup("OG");
            function_defs[function_count].params = (yyvsp[-4].param_list).param_names;
            function_defs[function_count].param_count = (yyvsp[-4].param_list).param_count;
            
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
#line 1516 "intermediate/zsharp.tab.c"
    break;

  case 33: /* parameter_list: %empty  */
#line 208 "compiler/zsharp.y"
                  {
        (yyval.param_list).param_count = 0;
        (yyval.param_list).param_names = NULL;
    }
#line 1525 "intermediate/zsharp.tab.c"
    break;

  case 34: /* parameter_list: IDENTIFIER  */
#line 212 "compiler/zsharp.y"
                 {
        (yyval.param_list).param_count = 1;
        (yyval.param_list).param_names = malloc(sizeof(char*));
        (yyval.param_list).param_names[0] = strdup((yyvsp[0].string_val));
    }
#line 1535 "intermediate/zsharp.tab.c"
    break;

  case 35: /* parameter_list: parameter_list ',' IDENTIFIER  */
#line 217 "compiler/zsharp.y"
                                    {
        (yyval.param_list).param_count = (yyvsp[-2].param_list).param_count + 1;
        (yyval.param_list).param_names = realloc((yyvsp[-2].param_list).param_names, (yyval.param_list).param_count * sizeof(char*));
        (yyval.param_list).param_names[(yyval.param_list).param_count - 1] = strdup((yyvsp[0].string_val));
    }
#line 1545 "intermediate/zsharp.tab.c"
    break;

  case 36: /* variable_declaration: VARIABLE IDENTIFIER ASSIGN expression  */
#line 225 "compiler/zsharp.y"
                                            {
        VarValue val;
        VarType type;
        
        // Numeric expression
        if ((yyvsp[0].expr_val).type == TYPE_NUMBER) {
            type = TYPE_NUMBER;
            val.number_val = (yyvsp[0].expr_val).value.number_val;
        }
        // String expression
        else if ((yyvsp[0].expr_val).type == TYPE_STRING) {
            type = TYPE_STRING;
            val.string_val = strdup((yyvsp[0].expr_val).value.string_val);
        }
        else {
            yyerror("Invalid expression type");
            YYERROR;
        }

        // Inserting into symbol table
        if (!insert_symbol(sym_table, (yyvsp[-2].string_val), type, val, false)) {
            fprintf(stderr, "Error: Variable '%s' redeclared at line %d\n", (yyvsp[-2].string_val), yylineno);
            if (type == TYPE_STRING) {
                free(val.string_val);
            }
            yyerror("Redeclaration of variable");
            YYERROR;
        }
        
        var_count++;
        fprintf(output_file, "→ Variable declaration detected: %s\n", (yyvsp[-2].string_val));
    }
#line 1582 "intermediate/zsharp.tab.c"
    break;

  case 37: /* variable_declaration: ARRAY IDENTIFIER ASSIGN '[' expression_list ']'  */
#line 257 "compiler/zsharp.y"
                                                      {
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
        if (!insert_symbol(sym_table, (yyvsp[-4].string_val), TYPE_ARRAY, val, false)) {
            fprintf(stderr, "Error: Array '%s' redeclared at line %d\n", (yyvsp[-4].string_val), yylineno);
            free(arr->elements);
            free(arr);
            YYERROR;
        }
        
        fprintf(output_file, "→ Array declaration: %s with %d elements\n", (yyvsp[-4].string_val), arr->size);
        var_count++;
        (yyval.string_val) = (yyvsp[-4].string_val); 
    }
#line 1614 "intermediate/zsharp.tab.c"
    break;

  case 38: /* variable_declaration: CONST IDENTIFIER ASSIGN expression  */
#line 284 "compiler/zsharp.y"
                                         {
        VarValue val;
        VarType type;
        
        if ((yyvsp[0].expr_val).type == TYPE_NUMBER) {
            type = TYPE_NUMBER;
            val.number_val = (yyvsp[0].expr_val).value.number_val;
        }
        else if ((yyvsp[0].expr_val).type == TYPE_STRING) {
            type = TYPE_STRING;
            val.string_val = strdup((yyvsp[0].expr_val).value.string_val);
        }
        else {
            yyerror("Invalid expression type for constant");
            YYERROR;
        }

        // Insert as constant
        if (!insert_symbol(sym_table, (yyvsp[-2].string_val), type, val, true)) {
            fprintf(stderr, "Error: Constant '%s' redeclared at line %d\n", (yyvsp[-2].string_val), yylineno);
            if (type == TYPE_STRING) {
                free(val.string_val);
            }
            yyerror("Redeclaration of constant");
            YYERROR;
        }
        var_count++;
        fprintf(output_file, "→ Constant declaration detected: %s\n", (yyvsp[-2].string_val));
    }
#line 1648 "intermediate/zsharp.tab.c"
    break;

  case 39: /* print_stmt: PRINT expression  */
#line 316 "compiler/zsharp.y"
                       {
        fprintf(output_file, "→ Print statement detected: ");
        if ((yyvsp[0].expr_val).type == TYPE_NUMBER) {
            fprintf(output_file, "%f\n", (yyvsp[0].expr_val).value.number_val);
        }
        else if ((yyvsp[0].expr_val).type == TYPE_STRING) {
            fprintf(output_file, "\"%s\"\n", (yyvsp[0].expr_val).value.string_val);
        }
    }
#line 1662 "intermediate/zsharp.tab.c"
    break;

  case 40: /* if_statement: IF '(' boolean_expression ')' '{' statements '}'  */
#line 330 "compiler/zsharp.y"
        { 
            fprintf(output_file, "→ Single If statement Detected\n");
            fprintf(output_file, "++++ Single If Block Execution ++++\n");
            if ((yyvsp[-4].number_val)) {
                fprintf(output_file, "Condition evaluated to true\n");
            } else {
                fprintf(output_file, "Condition evaluated to false\n");
            }
            fprintf(output_file, "++++ Single If Block Execution Stop ++++\n");
        }
#line 1677 "intermediate/zsharp.tab.c"
    break;

  case 41: /* if_statement: IF '(' boolean_expression ')' '{' statements '}' ELSE '{' statements '}'  */
#line 341 "compiler/zsharp.y"
        { 
            fprintf(output_file, "→ If-Else statement Detected\n"); 
            fprintf(output_file, "++++ If Block Execution ++++\n"); 
            if ((yyvsp[-8].number_val)) {
                fprintf(output_file, "Condition evaluated to true\n");
            } else {
                fprintf(output_file, "Condition evaluated to false\n");
            }
            fprintf(output_file, "++++ If Block Execution Stop ++++\n");
            fprintf(output_file, "++++ Else Block Execution ++++\n");
        }
#line 1693 "intermediate/zsharp.tab.c"
    break;

  case 42: /* if_statement: IF '(' boolean_expression ')' '{' statements '}' else_if_list  */
#line 353 "compiler/zsharp.y"
        { 
            fprintf(output_file, "→ If-ElseIf statement Detected\n"); 
            fprintf(output_file, "++++ If Block Execution ++++\n"); 
            if ((yyvsp[-5].number_val)) {
                fprintf(output_file, "If condition evaluated to true\n");
            } else {
                fprintf(output_file, "If condition evaluated to false\n");
            }
            fprintf(output_file, "++++ If Block Execution Stop ++++\n");
        }
#line 1708 "intermediate/zsharp.tab.c"
    break;

  case 43: /* if_statement: IF '(' boolean_expression ')' '{' statements '}' else_if_list ELSE '{' statements '}'  */
#line 364 "compiler/zsharp.y"
        { 
            fprintf(output_file, "→ If-ElseIf-Else statement Detected\n"); 
            fprintf(output_file, "++++ If Block Execution ++++\n"); 
            if ((yyvsp[-9].number_val)) {
                fprintf(output_file, "If condition evaluated to true\n");
            } else {
                fprintf(output_file, "If condition evaluated to false\n");
            }
            fprintf(output_file, "++++ If Block Execution Stop ++++\n");
            fprintf(output_file, "++++ Else Block Execution ++++\n");
        }
#line 1724 "intermediate/zsharp.tab.c"
    break;

  case 44: /* else_if_list: ELSE_IF '(' boolean_expression ')' '{' statements '}'  */
#line 379 "compiler/zsharp.y"
        { 
            fprintf(output_file, "→ Else-if block Detected\n"); 
            fprintf(output_file, "++++ Else-if Block Execution ++++\n"); 
            if ((yyvsp[-4].number_val)) {
                fprintf(output_file, "Else-if condition evaluated to true\n");
            } else {
                fprintf(output_file, "Else-if condition evaluated to false\n");
            }
            fprintf(output_file, "++++ Else-if Block Execution Stop ++++\n");
        }
#line 1739 "intermediate/zsharp.tab.c"
    break;

  case 45: /* else_if_list: else_if_list ELSE_IF '(' boolean_expression ')' '{' statements '}'  */
#line 390 "compiler/zsharp.y"
        { 
            fprintf(output_file, "→ Additional else-if block Detected\n"); 
            fprintf(output_file, "++++ Additional Else-if Block Execution ++++\n"); 
            if ((yyvsp[-4].number_val)) {
                fprintf(output_file, "Additional else-if condition evaluated to true\n");
            } else {
                fprintf(output_file, "Additional else-if condition evaluated to false\n");
            }
            fprintf(output_file, "++++ Additional Else-if Block Execution Stop ++++\n");
        }
#line 1754 "intermediate/zsharp.tab.c"
    break;

  case 46: /* for_statement: FOR '(' for_init FOR_SEP for_condition FOR_SEP for_increment ')' '{' statements '}'  */
#line 405 "compiler/zsharp.y"
        { 
            fprintf(output_file, "→ For loop detected \n\n");
        }
#line 1762 "intermediate/zsharp.tab.c"
    break;

  case 47: /* for_init: %empty  */
#line 411 "compiler/zsharp.y"
                  { 
        (yyval.expr_val).type = TYPE_NUMBER;
        (yyval.expr_val).value.number_val = 0;
    }
#line 1771 "intermediate/zsharp.tab.c"
    break;

  case 50: /* for_condition: %empty  */
#line 420 "compiler/zsharp.y"
                  { 
        (yyval.expr_val).type = TYPE_NUMBER;
        (yyval.expr_val).value.number_val = 1000000;
    }
#line 1780 "intermediate/zsharp.tab.c"
    break;

  case 52: /* for_increment: %empty  */
#line 428 "compiler/zsharp.y"
                  { 
        (yyval.expr_val).type = TYPE_NUMBER;
        (yyval.expr_val).value.number_val = 1;
    }
#line 1789 "intermediate/zsharp.tab.c"
    break;

  case 53: /* try_catch_stmt: TRY '{' statements '}' CATCH '(' IDENTIFIER ')' '{' statements '}'  */
#line 436 "compiler/zsharp.y"
        {
            fprintf(output_file, "→ Try-catch block detected\n");
        }
#line 1797 "intermediate/zsharp.tab.c"
    break;

  case 56: /* expression: numeric_expression  */
#line 450 "compiler/zsharp.y"
                         { (yyval.expr_val) = (yyvsp[0].expr_val); }
#line 1803 "intermediate/zsharp.tab.c"
    break;

  case 57: /* expression: string_expression  */
#line 451 "compiler/zsharp.y"
                        { (yyval.expr_val) = (yyvsp[0].expr_val); }
#line 1809 "intermediate/zsharp.tab.c"
    break;

  case 58: /* expression: IDENTIFIER  */
#line 452 "compiler/zsharp.y"
                 {
        Symbol* sym = lookup_symbol(sym_table, (yyvsp[0].string_val));
        if (!sym) {

            yyerror("Undefined variable");
            YYERROR;
        }
        
        switch (sym->type) {
            case TYPE_NUMBER:
                (yyval.expr_val).type = TYPE_NUMBER;
                (yyval.expr_val).value.number_val = sym->value.number_val;
                break;
            case TYPE_STRING:
                (yyval.expr_val).type = TYPE_STRING;
                (yyval.expr_val).value.string_val = strdup(sym->value.string_val);
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
#line 1840 "intermediate/zsharp.tab.c"
    break;

  case 59: /* expression: boolean_expression  */
#line 478 "compiler/zsharp.y"
                         { 
        (yyval.expr_val).type = TYPE_NUMBER;
        (yyval.expr_val).value.number_val = (yyvsp[0].number_val);
    }
#line 1849 "intermediate/zsharp.tab.c"
    break;

  case 60: /* expression: function_call  */
#line 482 "compiler/zsharp.y"
                    { (yyval.expr_val) = (yyvsp[0].expr_val); }
#line 1855 "intermediate/zsharp.tab.c"
    break;

  case 61: /* expression: IDENTIFIER ASSIGN expression  */
#line 483 "compiler/zsharp.y"
                                   {
        Symbol* sym = lookup_symbol(sym_table, (yyvsp[-2].string_val));
        if (!sym) {
            VarValue val;
            if ((yyvsp[0].expr_val).type == TYPE_NUMBER) {
                val.number_val = (yyvsp[0].expr_val).value.number_val;
                insert_symbol(sym_table, (yyvsp[-2].string_val), TYPE_NUMBER, val, false);
            } else if ((yyvsp[0].expr_val).type == TYPE_STRING) {
                val.string_val = strdup((yyvsp[0].expr_val).value.string_val);
                insert_symbol(sym_table, (yyvsp[-2].string_val), TYPE_STRING, val, false);
            }
        } else {
            // Checking if trying to reassign a constant
            if (sym->is_constant) {
                fprintf(stderr, "Error: Cannot reassign constant '%s' at line %d\n", (yyvsp[-2].string_val), yylineno);
                yyerror("Constant reassignment");
                YYERROR;
            }
            
            if (sym->type != (yyvsp[0].expr_val).type) {
                yyerror("Type mismatch in assignment");
                YYERROR;
            }
            if (sym->type == TYPE_NUMBER) {
                sym->value.number_val = (yyvsp[0].expr_val).value.number_val;
            } else if (sym->type == TYPE_STRING) {
                free(sym->value.string_val);
                sym->value.string_val = strdup((yyvsp[0].expr_val).value.string_val);
            }
        }
        (yyval.expr_val) = (yyvsp[0].expr_val);
        if ((yyvsp[0].expr_val).type == TYPE_NUMBER) {
            fprintf(output_file, "Assignment: %s = %f\n", (yyvsp[-2].string_val), (yyvsp[0].expr_val).value.number_val);
        }
        else if ((yyvsp[0].expr_val).type == TYPE_STRING) {
            fprintf(output_file, "Assignment: %s = \"%s\"\n", (yyvsp[-2].string_val), (yyvsp[0].expr_val).value.string_val);
        }
    }
#line 1898 "intermediate/zsharp.tab.c"
    break;

  case 62: /* numeric_expression: NUMBER  */
#line 524 "compiler/zsharp.y"
             { 
        (yyval.expr_val).type = TYPE_NUMBER;
        (yyval.expr_val).value.number_val = (yyvsp[0].number_val);
    }
#line 1907 "intermediate/zsharp.tab.c"
    break;

  case 63: /* numeric_expression: numeric_expression PLUS numeric_expression  */
#line 528 "compiler/zsharp.y"
                                                 { 
        (yyval.expr_val).type = TYPE_NUMBER;
        (yyval.expr_val).value.number_val = (yyvsp[-2].expr_val).value.number_val + (yyvsp[0].expr_val).value.number_val;
        fprintf(output_file, "Addition: %f + %f = %f\n", 
                (yyvsp[-2].expr_val).value.number_val, (yyvsp[0].expr_val).value.number_val, (yyval.expr_val).value.number_val);
    }
#line 1918 "intermediate/zsharp.tab.c"
    break;

  case 64: /* numeric_expression: numeric_expression MINUS numeric_expression  */
#line 534 "compiler/zsharp.y"
                                                  { 
        (yyval.expr_val).type = TYPE_NUMBER;
        (yyval.expr_val).value.number_val = (yyvsp[-2].expr_val).value.number_val - (yyvsp[0].expr_val).value.number_val;
        fprintf(output_file, "Subtraction: %f - %f = %f\n", 
                (yyvsp[-2].expr_val).value.number_val, (yyvsp[0].expr_val).value.number_val, (yyval.expr_val).value.number_val);
    }
#line 1929 "intermediate/zsharp.tab.c"
    break;

  case 65: /* numeric_expression: numeric_expression MULTIPLY numeric_expression  */
#line 540 "compiler/zsharp.y"
                                                     { 
        (yyval.expr_val).type = TYPE_NUMBER;
        (yyval.expr_val).value.number_val = (yyvsp[-2].expr_val).value.number_val * (yyvsp[0].expr_val).value.number_val;
        fprintf(output_file, "Multiplication: %f * %f = %f\n", 
                (yyvsp[-2].expr_val).value.number_val, (yyvsp[0].expr_val).value.number_val, (yyval.expr_val).value.number_val);
    }
#line 1940 "intermediate/zsharp.tab.c"
    break;

  case 66: /* numeric_expression: numeric_expression DIVIDE numeric_expression  */
#line 546 "compiler/zsharp.y"
                                                   { 
        if ((yyvsp[0].expr_val).value.number_val == 0) {
            fprintf(output_file, "Error: Division by zero detected\n");
        }
        else {
            (yyval.expr_val).type = TYPE_NUMBER;
            (yyval.expr_val).value.number_val = (yyvsp[-2].expr_val).value.number_val / (yyvsp[0].expr_val).value.number_val;
            fprintf(output_file, "Division: %f / %f = %f\n", 
                    (yyvsp[-2].expr_val).value.number_val, (yyvsp[0].expr_val).value.number_val, (yyval.expr_val).value.number_val);
        }
    }
#line 1956 "intermediate/zsharp.tab.c"
    break;

  case 67: /* numeric_expression: '(' numeric_expression ')'  */
#line 557 "compiler/zsharp.y"
                                 { (yyval.expr_val) = (yyvsp[-1].expr_val); }
#line 1962 "intermediate/zsharp.tab.c"
    break;

  case 68: /* numeric_expression: IDENTIFIER  */
#line 558 "compiler/zsharp.y"
                 {
        Symbol* sym = lookup_symbol(sym_table, (yyvsp[0].string_val));
        if (!sym) {
            // Instead of error, initializing with 0
            (yyval.expr_val).type = TYPE_NUMBER;
            (yyval.expr_val).value.number_val = 0;

            VarValue val;
            val.number_val = 0;
            insert_symbol(sym_table, (yyvsp[0].string_val), TYPE_NUMBER, val, false);
            
            fprintf(output_file, "Warning: Undefined variable '%s' at line %d, initializing with 0\n", 
                   (yyvsp[0].string_val), yylineno);
        } else {
            if (sym->type == TYPE_NUMBER) {
                (yyval.expr_val).type = TYPE_NUMBER;
                (yyval.expr_val).value.number_val = sym->value.number_val;
                fprintf(output_file, "Using variable %s with value %f\n", (yyvsp[0].string_val), (yyval.expr_val).value.number_val);
            } else if (sym->type == TYPE_STRING) {
                (yyval.expr_val).type = TYPE_STRING;
                (yyval.expr_val).value.string_val = strdup(sym->value.string_val);
                fprintf(output_file, "Using string variable %s with value \"%s\"\n", (yyvsp[0].string_val), (yyval.expr_val).value.string_val);
            } else {
                yyerror("Type mismatch: expected number or string");
                YYERROR;
            }
        }
    }
#line 1995 "intermediate/zsharp.tab.c"
    break;

  case 69: /* numeric_expression: IDENTIFIER '[' numeric_expression ']'  */
#line 586 "compiler/zsharp.y"
                                            {
        Symbol* sym = lookup_symbol(sym_table, (yyvsp[-3].string_val));
        if (!sym) {
            fprintf(stderr, "Error: Undefined variable '%s' at line %d\n", (yyvsp[-3].string_val), yylineno);
            yyerror("Undefined variable");
            YYERROR;
        }
        
        int index = (int)(yyvsp[-1].expr_val).value.number_val;
        
        // Handling string indexing
        if (sym->type == TYPE_STRING) {
            if (index < 0 || index >= strlen(sym->value.string_val)) {
                fprintf(stderr, "Error: String index out of bounds for '%s' at line %d\n", (yyvsp[-3].string_val), yylineno);
                yyerror("Index out of bounds");
                YYERROR;
            }
            (yyval.expr_val).type = TYPE_NUMBER;
            (yyval.expr_val).value.number_val = (float)sym->value.string_val[index+1];
            fprintf(output_file, "String index access: %s[%d] = '%c' (ASCII: %f)\n", 
                    (yyvsp[-3].string_val), index, (char)(yyval.expr_val).value.number_val, (yyval.expr_val).value.number_val);
        }
        // Handling array indexing
        else if (sym->type == TYPE_ARRAY) {
            ArrayValue* arr = sym->value.array_val;
            if (index < 0 || index >= arr->size) {
                fprintf(stderr, "Error: Array index out of bounds for '%s' at line %d\n", (yyvsp[-3].string_val), yylineno);
                yyerror("Index out of bounds");
                YYERROR;
            }
            (yyval.expr_val) = arr->elements[index];
            fprintf(output_file, "Array access: %s[%d] = %f\n", 
                    (yyvsp[-3].string_val), index, (yyval.expr_val).value.number_val);
        }
        else {
            fprintf(stderr, "Error: '%s' is not indexable at line %d\n", (yyvsp[-3].string_val), yylineno);
            yyerror("Not an indexable type");
            YYERROR;
        }
    }
#line 2040 "intermediate/zsharp.tab.c"
    break;

  case 70: /* string_expression: STRING_LIT  */
#line 629 "compiler/zsharp.y"
                 { 
        (yyval.expr_val).type = TYPE_STRING;
        (yyval.expr_val).value.string_val = strdup((yyvsp[0].string_val));
    }
#line 2049 "intermediate/zsharp.tab.c"
    break;

  case 71: /* string_expression: VSTRING_LIT  */
#line 633 "compiler/zsharp.y"
                  {
        (yyval.expr_val).type = TYPE_STRING;
        (yyval.expr_val).value.string_val = strdup((yyvsp[0].string_val));
    }
#line 2058 "intermediate/zsharp.tab.c"
    break;

  case 72: /* string_expression: string_expression PLUS string_expression  */
#line 637 "compiler/zsharp.y"
                                               {
        (yyval.expr_val).type = TYPE_STRING;
        (yyval.expr_val).value.string_val = malloc(strlen((yyvsp[-2].expr_val).value.string_val) + strlen((yyvsp[0].expr_val).value.string_val) + 1);
        strcpy((yyval.expr_val).value.string_val, (yyvsp[-2].expr_val).value.string_val);
        strcat((yyval.expr_val).value.string_val, (yyvsp[0].expr_val).value.string_val);
        free((yyvsp[-2].expr_val).value.string_val);
        free((yyvsp[0].expr_val).value.string_val);
    }
#line 2071 "intermediate/zsharp.tab.c"
    break;

  case 73: /* expression_list: expression  */
#line 648 "compiler/zsharp.y"
                 {
        args[0] = (yyvsp[0].expr_val);
        arg_count = 1;
        fprintf(output_file, "First array element: %f\n", (yyvsp[0].expr_val).value.number_val);
    }
#line 2081 "intermediate/zsharp.tab.c"
    break;

  case 74: /* expression_list: expression_list ',' expression  */
#line 653 "compiler/zsharp.y"
                                     {
        if (arg_count < 10) {
            args[arg_count] = (yyvsp[0].expr_val);
            fprintf(output_file, "Additional array element: %f\n", (yyvsp[0].expr_val).value.number_val);
            arg_count++;
        } else {
            yyerror("Too many array elements");
            YYERROR;
        }
    }
#line 2096 "intermediate/zsharp.tab.c"
    break;

  case 75: /* argument_list: %empty  */
#line 666 "compiler/zsharp.y"
                  {
        fprintf(output_file, "Empty argument list\n");
        arg_count = 0;
    }
#line 2105 "intermediate/zsharp.tab.c"
    break;

  case 76: /* argument_list: expression  */
#line 670 "compiler/zsharp.y"
                 {
        fprintf(output_file, "Single argument: ");
        if ((yyvsp[0].expr_val).type == TYPE_NUMBER) {
            fprintf(output_file, "%f\n", (yyvsp[0].expr_val).value.number_val);
            args[0] = (yyvsp[0].expr_val);
            arg_count = 1;
        }
    }
#line 2118 "intermediate/zsharp.tab.c"
    break;

  case 77: /* argument_list: argument_list ',' expression  */
#line 678 "compiler/zsharp.y"
                                   {
        fprintf(output_file, "Additional argument: ");
        if ((yyvsp[0].expr_val).type == TYPE_NUMBER) {
            fprintf(output_file, "%f\n", (yyvsp[0].expr_val).value.number_val);
            args[arg_count] = (yyvsp[0].expr_val);
            arg_count++;
        }
    }
#line 2131 "intermediate/zsharp.tab.c"
    break;

  case 78: /* boolean_expression: numeric_expression  */
#line 689 "compiler/zsharp.y"
                         { 
        (yyval.number_val) = ((yyvsp[0].expr_val).type == TYPE_NUMBER && (yyvsp[0].expr_val).value.number_val != 0) ? 1 : 0;
    }
#line 2139 "intermediate/zsharp.tab.c"
    break;

  case 79: /* boolean_expression: numeric_expression GT numeric_expression  */
#line 692 "compiler/zsharp.y"
                                               { 
        (yyval.number_val) = ((yyvsp[-2].expr_val).value.number_val > (yyvsp[0].expr_val).value.number_val) ? 1 : 0;
    }
#line 2147 "intermediate/zsharp.tab.c"
    break;

  case 80: /* boolean_expression: numeric_expression GTE numeric_expression  */
#line 695 "compiler/zsharp.y"
                                                { 
        (yyval.number_val) = ((yyvsp[-2].expr_val).value.number_val >= (yyvsp[0].expr_val).value.number_val) ? 1 : 0;
    }
#line 2155 "intermediate/zsharp.tab.c"
    break;

  case 81: /* boolean_expression: numeric_expression LT numeric_expression  */
#line 698 "compiler/zsharp.y"
                                               { 
        (yyval.number_val) = ((yyvsp[-2].expr_val).value.number_val < (yyvsp[0].expr_val).value.number_val) ? 1 : 0;
    }
#line 2163 "intermediate/zsharp.tab.c"
    break;

  case 82: /* boolean_expression: numeric_expression LTE numeric_expression  */
#line 701 "compiler/zsharp.y"
                                                { 
        (yyval.number_val) = ((yyvsp[-2].expr_val).value.number_val <= (yyvsp[0].expr_val).value.number_val) ? 1 : 0;
    }
#line 2171 "intermediate/zsharp.tab.c"
    break;

  case 83: /* boolean_expression: numeric_expression EQ numeric_expression  */
#line 704 "compiler/zsharp.y"
                                               { 
        (yyval.number_val) = ((yyvsp[-2].expr_val).value.number_val == (yyvsp[0].expr_val).value.number_val) ? 1 : 0;
    }
#line 2179 "intermediate/zsharp.tab.c"
    break;

  case 84: /* boolean_expression: numeric_expression NEQ numeric_expression  */
#line 707 "compiler/zsharp.y"
                                                { 
        (yyval.number_val) = ((yyvsp[-2].expr_val).value.number_val != (yyvsp[0].expr_val).value.number_val) ? 1 : 0;
    }
#line 2187 "intermediate/zsharp.tab.c"
    break;

  case 85: /* boolean_expression: boolean_expression AND boolean_expression  */
#line 710 "compiler/zsharp.y"
                                                { 
        (yyval.number_val) = ((yyvsp[-2].number_val) && (yyvsp[0].number_val)) ? 1 : 0;
    }
#line 2195 "intermediate/zsharp.tab.c"
    break;

  case 86: /* boolean_expression: boolean_expression OR boolean_expression  */
#line 713 "compiler/zsharp.y"
                                               { 
        (yyval.number_val) = ((yyvsp[-2].number_val) || (yyvsp[0].number_val)) ? 1 : 0;
    }
#line 2203 "intermediate/zsharp.tab.c"
    break;

  case 87: /* boolean_expression: NOT boolean_expression  */
#line 716 "compiler/zsharp.y"
                             { 
        (yyval.number_val) = !(yyvsp[0].number_val) ? 1 : 0;
    }
#line 2211 "intermediate/zsharp.tab.c"
    break;

  case 88: /* boolean_expression: TRUE_VAL  */
#line 719 "compiler/zsharp.y"
               { 
        (yyval.number_val) = 1;
    }
#line 2219 "intermediate/zsharp.tab.c"
    break;

  case 89: /* boolean_expression: FALSE_VAL  */
#line 722 "compiler/zsharp.y"
                { 
        (yyval.number_val) = 0;
    }
#line 2227 "intermediate/zsharp.tab.c"
    break;

  case 90: /* boolean_expression: '(' boolean_expression ')'  */
#line 725 "compiler/zsharp.y"
                                 { 
        (yyval.number_val) = (yyvsp[-1].number_val);
    }
#line 2235 "intermediate/zsharp.tab.c"
    break;

  case 91: /* function_call: IDENTIFIER '(' argument_list ')'  */
#line 731 "compiler/zsharp.y"
                                       {
        fprintf(output_file, "→ Function call detected: %s\n", (yyvsp[-3].string_val));
        
        FunctionDef* func = find_function_def((yyvsp[-3].string_val));
        if (func != NULL) {
            // Checking parameter count
            if (func->param_count != arg_count) {
                fprintf(stderr, "Error at line %d: Function '%s' expects %d arguments but got %d\n", 
                    yylineno, (yyvsp[-3].string_val), func->param_count, arg_count);
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

            (yyval.expr_val) = func->return_expr;  
        } else {
            fprintf(output_file, "Warning: Unknown function %s\n", (yyvsp[-3].string_val));
            (yyval.expr_val).type = TYPE_NUMBER;
            (yyval.expr_val).value.number_val = 0;
        }
    }
#line 2289 "intermediate/zsharp.tab.c"
    break;

  case 92: /* comment_stmt: SLC  */
#line 783 "compiler/zsharp.y"
          {
        fprintf(output_file, "\n\nSingle-line comment at line %d: %s\n\n", yylineno, yytext);
    }
#line 2297 "intermediate/zsharp.tab.c"
    break;

  case 93: /* comment_stmt: MLC  */
#line 786 "compiler/zsharp.y"
          {
        fprintf(output_file, "\n\nMulti-line comment starting at line %d: %s\n\n", yylineno, yytext);
    }
#line 2305 "intermediate/zsharp.tab.c"
    break;

  case 94: /* scanf_stmt: SCANF '(' IDENTIFIER ')'  */
#line 792 "compiler/zsharp.y"
                               {
        Symbol* sym = lookup_symbol(sym_table, (yyvsp[-1].string_val));
        if (!sym) {
            // If variable doesn't exist, creating it
            VarValue val;
            val.number_val = 0;  // init
            if (!insert_symbol(sym_table, (yyvsp[-1].string_val), TYPE_NUMBER, val, false)) {
                fprintf(stderr, "Error: Cannot create variable '%s' at line %d\n", (yyvsp[-1].string_val), yylineno);
                YYERROR;
            }
        }
        
        float value;
        fprintf(output_file, "Reading input for %s: ", (yyvsp[-1].string_val));
        printf("Reading input for %s: ", (yyvsp[-1].string_val));
        if (scanf("%f", &value) == 1) {
            // Updating symbol value
            if (sym->type == TYPE_NUMBER) {
                sym->value.number_val = value;
                fprintf(output_file, "Successfully read value: %f\n", value);
            } else {
                fprintf(stderr, "Error: Variable '%s' is not a number at line %d\n", (yyvsp[-1].string_val), yylineno);
                YYERROR;
            }
        } else {
            fprintf(stderr, "Error: Invalid input for variable '%s' at line %d\n", (yyvsp[-1].string_val), yylineno);
            YYERROR;
        }
    }
#line 2339 "intermediate/zsharp.tab.c"
    break;


#line 2343 "intermediate/zsharp.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 823 "compiler/zsharp.y"


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
