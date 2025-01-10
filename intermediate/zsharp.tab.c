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

// Initializing Symbol Table
SymbolTable* sym_table;


#line 96 "intermediate/zsharp.tab.c"

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
  YYSYMBOL_47_ = 47,                       /* '{'  */
  YYSYMBOL_48_ = 48,                       /* '}'  */
  YYSYMBOL_49_ = 49,                       /* '('  */
  YYSYMBOL_50_ = 50,                       /* ')'  */
  YYSYMBOL_51_ = 51,                       /* ','  */
  YYSYMBOL_52_ = 52,                       /* '['  */
  YYSYMBOL_53_ = 53,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 54,                  /* $accept  */
  YYSYMBOL_program = 55,                   /* program  */
  YYSYMBOL_statements = 56,                /* statements  */
  YYSYMBOL_statement = 57,                 /* statement  */
  YYSYMBOL_include_stmt = 58,              /* include_stmt  */
  YYSYMBOL_break_stmt = 59,                /* break_stmt  */
  YYSYMBOL_continue_stmt = 60,             /* continue_stmt  */
  YYSYMBOL_class_declaration = 61,         /* class_declaration  */
  YYSYMBOL_opt_extends = 62,               /* opt_extends  */
  YYSYMBOL_class_body = 63,                /* class_body  */
  YYSYMBOL_class_member = 64,              /* class_member  */
  YYSYMBOL_access_modifier = 65,           /* access_modifier  */
  YYSYMBOL_function_declaration = 66,      /* function_declaration  */
  YYSYMBOL_parameter_list = 67,            /* parameter_list  */
  YYSYMBOL_variable_declaration = 68,      /* variable_declaration  */
  YYSYMBOL_print_stmt = 69,                /* print_stmt  */
  YYSYMBOL_if_statement = 70,              /* if_statement  */
  YYSYMBOL_else_if_list = 71,              /* else_if_list  */
  YYSYMBOL_for_statement = 72,             /* for_statement  */
  YYSYMBOL_for_init = 73,                  /* for_init  */
  YYSYMBOL_for_condition = 74,             /* for_condition  */
  YYSYMBOL_for_increment = 75,             /* for_increment  */
  YYSYMBOL_try_catch_stmt = 76,            /* try_catch_stmt  */
  YYSYMBOL_return_stmt = 77,               /* return_stmt  */
  YYSYMBOL_expression_stmt = 78,           /* expression_stmt  */
  YYSYMBOL_expression = 79,                /* expression  */
  YYSYMBOL_numeric_expression = 80,        /* numeric_expression  */
  YYSYMBOL_string_expression = 81,         /* string_expression  */
  YYSYMBOL_expression_list = 82,           /* expression_list  */
  YYSYMBOL_boolean_expression = 83         /* boolean_expression  */
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
#define YYFINAL  60
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   688

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  181

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   301


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
      49,    50,     2,     2,    51,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    52,     2,    53,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    47,     2,    48,     2,     2,     2,     2,
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
      45,    46
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    60,    60,    64,    65,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    84,    90,    96,
     102,   109,   110,   114,   115,   119,   120,   124,   125,   129,
     133,   145,   146,   147,   151,   183,   211,   219,   232,   243,
     255,   266,   281,   292,   307,   314,   315,   321,   322,   329,
     330,   337,   341,   345,   349,   350,   351,   355,   390,   394,
     400,   406,   412,   422,   423,   448,   457,   461,   465,   476,
     477,   487,   490,   493,   496,   499,   502,   505,   508,   511,
     514,   517,   520,   523
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
  "'{'", "'}'", "'('", "')'", "','", "'['", "']'", "$accept", "program",
  "statements", "statement", "include_stmt", "break_stmt", "continue_stmt",
  "class_declaration", "opt_extends", "class_body", "class_member",
  "access_modifier", "function_declaration", "parameter_list",
  "variable_declaration", "print_stmt", "if_statement", "else_if_list",
  "for_statement", "for_init", "for_condition", "for_increment",
  "try_catch_stmt", "return_stmt", "expression_stmt", "expression",
  "numeric_expression", "string_expression", "expression_list",
  "boolean_expression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-50)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-72)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     624,   -26,    -7,    36,   -34,   -11,    69,    69,   -50,   -50,
      -2,   -50,   -50,     4,    21,    23,   -50,   -50,   -50,   -25,
      74,    74,    80,   624,   -50,   -50,   -50,   -50,   -50,   -50,
     -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,   643,    28,
      60,    37,    47,    39,    58,    74,    10,   -50,   -50,    79,
     -50,    92,   624,    69,   -21,    67,   155,   -50,   625,   -13,
     -50,   -50,   -21,   -21,   -21,   -21,   -21,   -21,   -21,   -21,
     -21,   -21,   106,    74,    74,    69,    69,    93,    93,    52,
     -50,   110,   -50,    88,   113,    96,   154,   -50,   -21,   -17,
     -50,   -50,   119,   119,   -50,   -50,    98,    98,    98,    98,
      98,    98,   -50,   -50,   103,   -50,   -50,   -50,   111,   123,
     105,    74,    69,   -50,   152,   160,    43,   -50,   140,   167,
     145,   624,   180,    60,   -50,    20,   -50,   -50,   -15,   -50,
      61,   162,   624,   -50,   624,   201,    69,    69,   -50,   -50,
     -50,   -50,   -50,   624,   248,   295,   171,   151,   -50,   -50,
     342,   -50,   -50,   172,   176,   173,   177,   -50,    74,   624,
     178,   179,   624,    64,   389,    74,   624,   436,   181,   -50,
      85,   483,   -50,   624,   182,   -50,   530,   624,   -50,   577,
     -50
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,    81,    82,
       0,    18,    19,     0,     0,     0,    58,    66,    67,    64,
       0,     0,     0,     2,     3,     5,    15,    16,     6,     7,
       8,    13,    10,    11,    12,    14,     9,    53,    54,    55,
      56,     0,     0,     0,     0,     0,     0,    52,    37,     0,
      17,    22,     0,     0,     0,    64,    71,    80,    71,     0,
       1,     4,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    31,    31,     0,
      45,     0,    46,     0,     0,     0,     0,    57,     0,     0,
      63,    83,    59,    60,    61,    62,    76,    77,    74,    75,
      72,    73,    68,    78,    79,    34,    35,    32,     0,     0,
       0,    48,     0,    21,     0,     0,     0,    65,     0,     0,
       0,     0,     0,    47,    69,     0,    28,    27,     0,    23,
       0,     0,     0,    33,     0,     0,    50,     0,    36,    20,
      24,    26,    25,     0,     0,     0,    38,     0,    49,    70,
       0,    30,    29,     0,     0,    40,     0,    51,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    39,
       0,     0,    44,     0,     0,    41,     0,     0,    42,     0,
      43
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -50,   -50,   -49,   -23,   -50,   -50,   -50,   -50,   -50,   -50,
      97,   -50,    90,   156,   -39,   -50,   -50,   -50,   -50,   -50,
     -50,   -50,   -50,   -50,   -50,    14,   -19,   163,   -50,   -16
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    22,    23,    24,    25,    26,    27,    28,    85,   128,
     129,   130,    29,   108,    30,    31,    32,   155,    33,    81,
     122,   147,    34,    35,    36,    37,    38,    39,   125,    40
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      61,    56,    58,    86,    57,    59,    41,    80,    16,   126,
     127,    55,    53,     1,     2,    45,    62,    63,    64,    65,
      47,    48,     8,     9,    10,    42,    56,    54,    88,    79,
      49,    73,    74,   139,    50,    89,   117,    91,    46,    16,
      17,    18,    19,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,    51,    56,    56,    20,   103,   104,    21,
      82,    72,    43,    61,     1,     2,     3,    87,    44,   116,
      52,   137,   135,   138,    75,    10,    62,    63,    64,    65,
      60,     8,     9,   144,    76,   145,     8,     9,    77,   105,
     106,   142,    56,    90,   150,   123,    73,    74,    16,    17,
      18,    19,   110,    16,    73,    74,    55,    78,    73,    74,
     164,    84,    61,   167,   168,    20,    83,   171,    21,    54,
      20,    61,    61,    21,   176,   107,   124,    61,   179,    73,
      74,    62,    63,    64,    65,   174,    17,    18,   111,    56,
     112,    61,   163,   114,    61,   113,    56,    73,    61,   170,
     148,   149,   121,    61,    64,    65,    61,     1,     2,     3,
       4,   118,   119,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,   120,   119,    15,   126,   127,   153,   154,
     160,   161,   131,    16,    17,    18,    19,   132,    62,    63,
      64,    65,   134,    66,    67,    68,    69,    70,    71,   133,
      20,   156,   115,    21,     1,     2,     3,     4,   136,   143,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
     141,   158,    15,   159,   162,   140,   166,   165,   173,   177,
      16,    17,    18,    19,   109,   102,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    20,     0,   146,
      21,     1,     2,     3,     4,     0,     0,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,     0,     0,    15,
       0,     0,     0,     0,     0,     0,     0,    16,    17,    18,
      19,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    20,     0,   151,    21,     1,     2,
       3,     4,     0,     0,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,     0,     0,    15,     0,     0,     0,
       0,     0,     0,     0,    16,    17,    18,    19,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    20,     0,   152,    21,     1,     2,     3,     4,     0,
       0,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,     0,     0,    15,     0,     0,     0,     0,     0,     0,
       0,    16,    17,    18,    19,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    20,     0,
     157,    21,     1,     2,     3,     4,     0,     0,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,     0,     0,
      15,     0,     0,     0,     0,     0,     0,     0,    16,    17,
      18,    19,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    20,     0,   169,    21,     1,
       2,     3,     4,     0,     0,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,     0,     0,    15,     0,     0,
       0,     0,     0,     0,     0,    16,    17,    18,    19,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    20,     0,   172,    21,     1,     2,     3,     4,
       0,     0,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,     0,     0,    15,     0,     0,     0,     0,     0,
       0,     0,    16,    17,    18,    19,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    20,
       0,   175,    21,     1,     2,     3,     4,     0,     0,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,     0,
       0,    15,     0,     0,     0,     0,     0,     0,     0,    16,
      17,    18,    19,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    20,     0,   178,    21,
       1,     2,     3,     4,     0,     0,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,     0,     0,    15,     0,
       0,     0,     0,     0,     0,     0,    16,    17,    18,    19,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    20,     0,   180,    21,     1,     2,     3,
       4,     0,     0,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,     0,     0,    15,     0,     0,     0,     0,
       0,     0,     0,    16,    17,    18,    19,     0,    62,    63,
      64,    65,     0,    66,    67,    68,    69,    70,    71,     0,
      20,     0,     0,    21,     0,    90,    62,    63,    64,    65,
       0,    66,    67,    68,    69,    70,    71,   -71,   -71
};

static const yytype_int16 yycheck[] =
{
      23,    20,    21,    52,    20,    21,    32,    46,    29,    24,
      25,    32,    37,     3,     4,    49,    33,    34,    35,    36,
       6,     7,    12,    13,    14,    32,    45,    52,    49,    45,
      32,    44,    45,    48,    30,    54,    53,    50,    49,    29,
      30,    31,    32,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    32,    73,    74,    46,    73,    74,    49,
      46,    33,    26,    86,     3,     4,     5,    53,    32,    88,
      47,    51,   121,    53,    37,    14,    33,    34,    35,    36,
       0,    12,    13,   132,    37,   134,    12,    13,    49,    75,
      76,   130,   111,    50,   143,   111,    44,    45,    29,    30,
      31,    32,    50,    29,    44,    45,    32,    49,    44,    45,
     159,    19,   135,   162,    50,    46,    37,   166,    49,    52,
      46,   144,   145,    49,   173,    32,   112,   150,   177,    44,
      45,    33,    34,    35,    36,    50,    30,    31,    28,   158,
      52,   164,   158,    47,   167,    32,   165,    44,   171,   165,
     136,   137,    47,   176,    35,    36,   179,     3,     4,     5,
       6,    50,    51,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    50,    51,    21,    24,    25,     7,     8,
       7,     8,    22,    29,    30,    31,    32,    47,    33,    34,
      35,    36,    47,    38,    39,    40,    41,    42,    43,    32,
      46,    50,    48,    49,     3,     4,     5,     6,    28,    47,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
     130,    49,    21,    47,    47,   128,    47,    49,    47,    47,
      29,    30,    31,    32,    78,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,    48,
      49,     3,     4,     5,     6,    -1,    -1,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    -1,    -1,    21,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    -1,    48,    49,     3,     4,
       5,     6,    -1,    -1,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    -1,    -1,    21,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    -1,    48,    49,     3,     4,     5,     6,    -1,
      -1,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    -1,    21,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,
      48,    49,     3,     4,     5,     6,    -1,    -1,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    -1,    -1,
      21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    -1,    48,    49,     3,
       4,     5,     6,    -1,    -1,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    -1,    -1,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    -1,    48,    49,     3,     4,     5,     6,
      -1,    -1,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    -1,    -1,    21,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,
      -1,    48,    49,     3,     4,     5,     6,    -1,    -1,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    -1,
      -1,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,    48,    49,
       3,     4,     5,     6,    -1,    -1,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    -1,    -1,    21,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    -1,    48,    49,     3,     4,     5,
       6,    -1,    -1,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    -1,    -1,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    29,    30,    31,    32,    -1,    33,    34,
      35,    36,    -1,    38,    39,    40,    41,    42,    43,    -1,
      46,    -1,    -1,    49,    -1,    50,    33,    34,    35,    36,
      -1,    38,    39,    40,    41,    42,    43,    44,    45
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    21,    29,    30,    31,    32,
      46,    49,    55,    56,    57,    58,    59,    60,    61,    66,
      68,    69,    70,    72,    76,    77,    78,    79,    80,    81,
      83,    32,    32,    26,    32,    49,    49,    79,    79,    32,
      30,    32,    47,    37,    52,    32,    80,    83,    80,    83,
       0,    57,    33,    34,    35,    36,    38,    39,    40,    41,
      42,    43,    33,    44,    45,    37,    37,    49,    49,    83,
      68,    73,    79,    37,    19,    62,    56,    79,    49,    80,
      50,    50,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    81,    83,    83,    79,    79,    32,    67,    67,
      50,    28,    52,    32,    47,    48,    80,    53,    50,    51,
      50,    47,    74,    83,    79,    82,    24,    25,    63,    64,
      65,    22,    47,    32,    47,    56,    28,    51,    53,    48,
      64,    66,    68,    47,    56,    56,    48,    75,    79,    79,
      56,    48,    48,     7,     8,    71,    50,    48,    49,    47,
       7,     8,    47,    83,    56,    49,    47,    56,    50,    48,
      83,    56,    48,    47,    50,    48,    56,    47,    48,    56,
      48
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    54,    55,    56,    56,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    58,    59,    60,
      61,    62,    62,    63,    63,    64,    64,    65,    65,    66,
      66,    67,    67,    67,    68,    68,    68,    69,    70,    70,
      70,    70,    71,    71,    72,    73,    73,    74,    74,    75,
      75,    76,    77,    78,    79,    79,    79,    79,    80,    80,
      80,    80,    80,    80,    80,    80,    81,    81,    81,    82,
      82,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     1,
       6,     2,     0,     1,     2,     2,     2,     1,     1,     8,
       8,     0,     1,     3,     4,     4,     6,     2,     7,    11,
       8,    12,     7,     8,    11,     1,     1,     1,     0,     1,
       0,     8,     2,     1,     1,     1,     1,     3,     1,     3,
       3,     3,     3,     3,     1,     4,     1,     1,     3,     1,
       3,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     1,     1,     3
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
  case 17: /* include_stmt: INCLUDE STRING_LIT  */
#line 84 "compiler/zsharp.y"
                         {
        fprintf(output_file, "Import detected with path: %s\n", (yyvsp[0].string_val));
    }
#line 1391 "intermediate/zsharp.tab.c"
    break;

  case 18: /* break_stmt: BREAK  */
#line 90 "compiler/zsharp.y"
            {
        fprintf(output_file, "Break statement detected\n");
    }
#line 1399 "intermediate/zsharp.tab.c"
    break;

  case 19: /* continue_stmt: CONTINUE  */
#line 96 "compiler/zsharp.y"
               {
        fprintf(output_file, "Continue statement detected\n");
    }
#line 1407 "intermediate/zsharp.tab.c"
    break;

  case 20: /* class_declaration: CLASS IDENTIFIER opt_extends '{' class_body '}'  */
#line 102 "compiler/zsharp.y"
                                                      {
        fprintf(output_file, "\nClass declaration detected: %s\n\n", (yyvsp[-4].string_val));
        class_count++;
    }
#line 1416 "intermediate/zsharp.tab.c"
    break;

  case 29: /* function_declaration: FUNCTION IDENTIFIER '(' parameter_list ')' '{' statements '}'  */
#line 129 "compiler/zsharp.y"
                                                                    {
        fprintf(output_file, "\nFunction declaration detected: %s\n\n", (yyvsp[-6].string_val));
        func_count++;
    }
#line 1425 "intermediate/zsharp.tab.c"
    break;

  case 30: /* function_declaration: FUNCTION MAIN '(' parameter_list ')' '{' statements '}'  */
#line 133 "compiler/zsharp.y"
                                                              {
        fprintf(output_file, "\nMAIN Function declaration detected\n\n");
        func_count++;
        main_count++;
        if(main_count > 1) {
            fprintf(output_file, "Error: Multiple main functions detected\n");
            exit(1);
        }
    }
#line 1439 "intermediate/zsharp.tab.c"
    break;

  case 34: /* variable_declaration: VARIABLE IDENTIFIER ASSIGN expression  */
#line 151 "compiler/zsharp.y"
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
        if (!insert_symbol(sym_table, (yyvsp[-2].string_val), type, val)) {
            fprintf(stderr, "Error: Variable '%s' redeclared at line %d\n", (yyvsp[-2].string_val), yylineno);
            if (type == TYPE_STRING) {
                free(val.string_val);
            }
            yyerror("Redeclaration of variable");
            YYERROR;
        }
        
        var_count++;
        fprintf(output_file, "Variable declaration detected: %s\n", (yyvsp[-2].string_val));
    }
#line 1476 "intermediate/zsharp.tab.c"
    break;

  case 35: /* variable_declaration: CONST IDENTIFIER ASSIGN expression  */
#line 183 "compiler/zsharp.y"
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

        if (!insert_symbol(sym_table, (yyvsp[-2].string_val), type, val)) {
            fprintf(stderr, "Error: Constant '%s' redeclared at line %d\n", (yyvsp[-2].string_val), yylineno);
            if (type == TYPE_STRING) {
                free(val.string_val);
            }
            yyerror("Redeclaration of constant");
            YYERROR;
        }
        var_count++;
        fprintf(output_file, "Constant declaration detected: %s\n", (yyvsp[-2].string_val));
    }
#line 1509 "intermediate/zsharp.tab.c"
    break;

  case 36: /* variable_declaration: ARRAY IDENTIFIER ASSIGN '[' expression_list ']'  */
#line 211 "compiler/zsharp.y"
                                                      {
        (yyval.string_val) = (yyvsp[-4].string_val);
        fprintf(output_file, "Array declaration detected: %s\n", (yyvsp[-4].string_val));
        var_count++;
    }
#line 1519 "intermediate/zsharp.tab.c"
    break;

  case 37: /* print_stmt: PRINT expression  */
#line 219 "compiler/zsharp.y"
                       {
        fprintf(output_file, "Print statement detected: ");
        if ((yyvsp[0].expr_val).type == TYPE_NUMBER) {
            fprintf(output_file, "%f\n", (yyvsp[0].expr_val).value.number_val);
        }
        else if ((yyvsp[0].expr_val).type == TYPE_STRING) {
            fprintf(output_file, "\"%s\"\n", (yyvsp[0].expr_val).value.string_val);
        }
    }
#line 1533 "intermediate/zsharp.tab.c"
    break;

  case 38: /* if_statement: IF '(' boolean_expression ')' '{' statements '}'  */
#line 233 "compiler/zsharp.y"
        { 
            fprintf(output_file, "Single If statement Detected\n");
            fprintf(output_file, "++++ Single If Block Execution ++++\n");
            if ((yyvsp[-4].number_val)) {
                fprintf(output_file, "Condition evaluated to true\n");
            } else {
                fprintf(output_file, "Condition evaluated to false\n");
            }
            fprintf(output_file, "++++ Single If Block Execution Stop ++++\n");
        }
#line 1548 "intermediate/zsharp.tab.c"
    break;

  case 39: /* if_statement: IF '(' boolean_expression ')' '{' statements '}' ELSE '{' statements '}'  */
#line 244 "compiler/zsharp.y"
        { 
            fprintf(output_file, "If-Else statement Detected\n"); 
            fprintf(output_file, "++++ If Block Execution ++++\n"); 
            if ((yyvsp[-8].number_val)) {
                fprintf(output_file, "Condition evaluated to true\n");
            } else {
                fprintf(output_file, "Condition evaluated to false\n");
            }
            fprintf(output_file, "++++ If Block Execution Stop ++++\n");
            fprintf(output_file, "++++ Else Block Execution ++++\n");
        }
#line 1564 "intermediate/zsharp.tab.c"
    break;

  case 40: /* if_statement: IF '(' boolean_expression ')' '{' statements '}' else_if_list  */
#line 256 "compiler/zsharp.y"
        { 
            fprintf(output_file, "If-ElseIf statement Detected\n"); 
            fprintf(output_file, "++++ If Block Execution ++++\n"); 
            if ((yyvsp[-5].number_val)) {
                fprintf(output_file, "If condition evaluated to true\n");
            } else {
                fprintf(output_file, "If condition evaluated to false\n");
            }
            fprintf(output_file, "++++ If Block Execution Stop ++++\n");
        }
#line 1579 "intermediate/zsharp.tab.c"
    break;

  case 41: /* if_statement: IF '(' boolean_expression ')' '{' statements '}' else_if_list ELSE '{' statements '}'  */
#line 267 "compiler/zsharp.y"
        { 
            fprintf(output_file, "If-ElseIf-Else statement Detected\n"); 
            fprintf(output_file, "++++ If Block Execution ++++\n"); 
            if ((yyvsp[-9].number_val)) {
                fprintf(output_file, "If condition evaluated to true\n");
            } else {
                fprintf(output_file, "If condition evaluated to false\n");
            }
            fprintf(output_file, "++++ If Block Execution Stop ++++\n");
            fprintf(output_file, "++++ Else Block Execution ++++\n");
        }
#line 1595 "intermediate/zsharp.tab.c"
    break;

  case 42: /* else_if_list: ELSE_IF '(' boolean_expression ')' '{' statements '}'  */
#line 282 "compiler/zsharp.y"
        { 
            fprintf(output_file, "Else-if block Detected\n"); 
            fprintf(output_file, "++++ Else-if Block Execution ++++\n"); 
            if ((yyvsp[-4].number_val)) {
                fprintf(output_file, "Else-if condition evaluated to true\n");
            } else {
                fprintf(output_file, "Else-if condition evaluated to false\n");
            }
            fprintf(output_file, "++++ Else-if Block Execution Stop ++++\n");
        }
#line 1610 "intermediate/zsharp.tab.c"
    break;

  case 43: /* else_if_list: else_if_list ELSE_IF '(' boolean_expression ')' '{' statements '}'  */
#line 293 "compiler/zsharp.y"
        { 
            fprintf(output_file, "Additional else-if block Detected\n"); 
            fprintf(output_file, "++++ Additional Else-if Block Execution ++++\n"); 
            if ((yyvsp[-4].number_val)) {
                fprintf(output_file, "Additional else-if condition evaluated to true\n");
            } else {
                fprintf(output_file, "Additional else-if condition evaluated to false\n");
            }
            fprintf(output_file, "++++ Additional Else-if Block Execution Stop ++++\n");
        }
#line 1625 "intermediate/zsharp.tab.c"
    break;

  case 44: /* for_statement: FOR '(' for_init FOR_SEP for_condition FOR_SEP for_increment ')' '{' statements '}'  */
#line 308 "compiler/zsharp.y"
        { 
            fprintf(output_file, "For loop detected \n\n");
        }
#line 1633 "intermediate/zsharp.tab.c"
    break;

  case 46: /* for_init: expression  */
#line 315 "compiler/zsharp.y"
                 { 
        (yyval.expr_val) = (yyvsp[0].expr_val); 
    }
#line 1641 "intermediate/zsharp.tab.c"
    break;

  case 48: /* for_condition: %empty  */
#line 322 "compiler/zsharp.y"
                  { 
        (yyval.expr_val).type = TYPE_NUMBER;
        (yyval.expr_val).value.number_val = 1000000;
    }
#line 1650 "intermediate/zsharp.tab.c"
    break;

  case 50: /* for_increment: %empty  */
#line 330 "compiler/zsharp.y"
                  { 
        (yyval.expr_val).type = TYPE_NUMBER;
        (yyval.expr_val).value.number_val = 1;
    }
#line 1659 "intermediate/zsharp.tab.c"
    break;

  case 54: /* expression: numeric_expression  */
#line 349 "compiler/zsharp.y"
                         { (yyval.expr_val) = (yyvsp[0].expr_val); }
#line 1665 "intermediate/zsharp.tab.c"
    break;

  case 55: /* expression: string_expression  */
#line 350 "compiler/zsharp.y"
                        { (yyval.expr_val) = (yyvsp[0].expr_val); }
#line 1671 "intermediate/zsharp.tab.c"
    break;

  case 56: /* expression: boolean_expression  */
#line 351 "compiler/zsharp.y"
                         { 
        (yyval.expr_val).type = TYPE_NUMBER;
        (yyval.expr_val).value.number_val = (yyvsp[0].number_val);
    }
#line 1680 "intermediate/zsharp.tab.c"
    break;

  case 57: /* expression: IDENTIFIER ASSIGN expression  */
#line 355 "compiler/zsharp.y"
                                   {
        Symbol* sym = lookup_symbol(sym_table, (yyvsp[-2].string_val));
        if (!sym) {
            VarValue val;
            if ((yyvsp[0].expr_val).type == TYPE_NUMBER) {
                val.number_val = (yyvsp[0].expr_val).value.number_val;
                insert_symbol(sym_table, (yyvsp[-2].string_val), TYPE_NUMBER, val);
            } else if ((yyvsp[0].expr_val).type == TYPE_STRING) {
                val.string_val = strdup((yyvsp[0].expr_val).value.string_val);
                insert_symbol(sym_table, (yyvsp[-2].string_val), TYPE_STRING, val);
            }
        } else {
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
#line 1717 "intermediate/zsharp.tab.c"
    break;

  case 58: /* numeric_expression: NUMBER  */
#line 390 "compiler/zsharp.y"
             { 
        (yyval.expr_val).type = TYPE_NUMBER;
        (yyval.expr_val).value.number_val = (yyvsp[0].number_val);
    }
#line 1726 "intermediate/zsharp.tab.c"
    break;

  case 59: /* numeric_expression: numeric_expression PLUS numeric_expression  */
#line 394 "compiler/zsharp.y"
                                                 { 
        (yyval.expr_val).type = TYPE_NUMBER;
        (yyval.expr_val).value.number_val = (yyvsp[-2].expr_val).value.number_val + (yyvsp[0].expr_val).value.number_val;
        fprintf(output_file, "Addition: %f + %f = %f\n", 
                (yyvsp[-2].expr_val).value.number_val, (yyvsp[0].expr_val).value.number_val, (yyval.expr_val).value.number_val);
    }
#line 1737 "intermediate/zsharp.tab.c"
    break;

  case 60: /* numeric_expression: numeric_expression MINUS numeric_expression  */
#line 400 "compiler/zsharp.y"
                                                  { 
        (yyval.expr_val).type = TYPE_NUMBER;
        (yyval.expr_val).value.number_val = (yyvsp[-2].expr_val).value.number_val - (yyvsp[0].expr_val).value.number_val;
        fprintf(output_file, "Subtraction: %f - %f = %f\n", 
                (yyvsp[-2].expr_val).value.number_val, (yyvsp[0].expr_val).value.number_val, (yyval.expr_val).value.number_val);
    }
#line 1748 "intermediate/zsharp.tab.c"
    break;

  case 61: /* numeric_expression: numeric_expression MULTIPLY numeric_expression  */
#line 406 "compiler/zsharp.y"
                                                     { 
        (yyval.expr_val).type = TYPE_NUMBER;
        (yyval.expr_val).value.number_val = (yyvsp[-2].expr_val).value.number_val * (yyvsp[0].expr_val).value.number_val;
        fprintf(output_file, "Multiplication: %f * %f = %f\n", 
                (yyvsp[-2].expr_val).value.number_val, (yyvsp[0].expr_val).value.number_val, (yyval.expr_val).value.number_val);
    }
#line 1759 "intermediate/zsharp.tab.c"
    break;

  case 62: /* numeric_expression: numeric_expression DIVIDE numeric_expression  */
#line 412 "compiler/zsharp.y"
                                                   { 
        if ((yyvsp[0].expr_val).value.number_val == 0) {
            yyerror("Division by zero");
            YYERROR;
        }
        (yyval.expr_val).type = TYPE_NUMBER;
        (yyval.expr_val).value.number_val = (yyvsp[-2].expr_val).value.number_val / (yyvsp[0].expr_val).value.number_val;
        fprintf(output_file, "Division: %f / %f = %f\n", 
                (yyvsp[-2].expr_val).value.number_val, (yyvsp[0].expr_val).value.number_val, (yyval.expr_val).value.number_val);
    }
#line 1774 "intermediate/zsharp.tab.c"
    break;

  case 63: /* numeric_expression: '(' numeric_expression ')'  */
#line 422 "compiler/zsharp.y"
                                 { (yyval.expr_val) = (yyvsp[-1].expr_val); }
#line 1780 "intermediate/zsharp.tab.c"
    break;

  case 64: /* numeric_expression: IDENTIFIER  */
#line 423 "compiler/zsharp.y"
                 {
        Symbol* sym = lookup_symbol(sym_table, (yyvsp[0].string_val));
        if (!sym) {
            // Instead of error, initializing with 0
            (yyval.expr_val).type = TYPE_NUMBER;
            (yyval.expr_val).value.number_val = 0;

            VarValue val;
            val.number_val = 0;
            insert_symbol(sym_table, (yyvsp[0].string_val), TYPE_NUMBER, val);
            
            fprintf(output_file, "Warning: Undefined variable '%s' at line %d, initializing with 0\n", 
                   (yyvsp[0].string_val), yylineno);
        } else {
            if (sym->type != TYPE_NUMBER) {
                yyerror("Type mismatch: expected number");
                YYERROR;
            }
            (yyval.expr_val).type = TYPE_NUMBER;
            (yyval.expr_val).value.number_val = sym->value.number_val;
            fprintf(output_file, "Using variable %s with value %f\n", (yyvsp[0].string_val), (yyval.expr_val).value.number_val);
        

        }
    }
#line 1810 "intermediate/zsharp.tab.c"
    break;

  case 65: /* numeric_expression: IDENTIFIER '[' numeric_expression ']'  */
#line 448 "compiler/zsharp.y"
                                            {
        // TODO: Implement array access
        (yyval.expr_val).type = TYPE_NUMBER;
        (yyval.expr_val).value.number_val = 0;
        fprintf(output_file, "Array access: %s[%f]\n", (yyvsp[-3].string_val), (yyvsp[-1].expr_val).value.number_val);
    }
#line 1821 "intermediate/zsharp.tab.c"
    break;

  case 66: /* string_expression: STRING_LIT  */
#line 457 "compiler/zsharp.y"
                 { 
        (yyval.expr_val).type = TYPE_STRING;
        (yyval.expr_val).value.string_val = strdup((yyvsp[0].string_val));
    }
#line 1830 "intermediate/zsharp.tab.c"
    break;

  case 67: /* string_expression: VSTRING_LIT  */
#line 461 "compiler/zsharp.y"
                  {
        (yyval.expr_val).type = TYPE_STRING;
        (yyval.expr_val).value.string_val = strdup((yyvsp[0].string_val));
    }
#line 1839 "intermediate/zsharp.tab.c"
    break;

  case 68: /* string_expression: string_expression PLUS string_expression  */
#line 465 "compiler/zsharp.y"
                                               {
        (yyval.expr_val).type = TYPE_STRING;
        (yyval.expr_val).value.string_val = malloc(strlen((yyvsp[-2].expr_val).value.string_val) + strlen((yyvsp[0].expr_val).value.string_val) + 1);
        strcpy((yyval.expr_val).value.string_val, (yyvsp[-2].expr_val).value.string_val);
        strcat((yyval.expr_val).value.string_val, (yyvsp[0].expr_val).value.string_val);
        free((yyvsp[-2].expr_val).value.string_val);
        free((yyvsp[0].expr_val).value.string_val);
    }
#line 1852 "intermediate/zsharp.tab.c"
    break;

  case 71: /* boolean_expression: numeric_expression  */
#line 487 "compiler/zsharp.y"
                         { 
        (yyval.number_val) = ((yyvsp[0].expr_val).type == TYPE_NUMBER && (yyvsp[0].expr_val).value.number_val != 0) ? 1 : 0;
    }
#line 1860 "intermediate/zsharp.tab.c"
    break;

  case 72: /* boolean_expression: numeric_expression GT numeric_expression  */
#line 490 "compiler/zsharp.y"
                                               { 
        (yyval.number_val) = ((yyvsp[-2].expr_val).value.number_val > (yyvsp[0].expr_val).value.number_val) ? 1 : 0;
    }
#line 1868 "intermediate/zsharp.tab.c"
    break;

  case 73: /* boolean_expression: numeric_expression GTE numeric_expression  */
#line 493 "compiler/zsharp.y"
                                                { 
        (yyval.number_val) = ((yyvsp[-2].expr_val).value.number_val >= (yyvsp[0].expr_val).value.number_val) ? 1 : 0;
    }
#line 1876 "intermediate/zsharp.tab.c"
    break;

  case 74: /* boolean_expression: numeric_expression LT numeric_expression  */
#line 496 "compiler/zsharp.y"
                                               { 
        (yyval.number_val) = ((yyvsp[-2].expr_val).value.number_val < (yyvsp[0].expr_val).value.number_val) ? 1 : 0;
    }
#line 1884 "intermediate/zsharp.tab.c"
    break;

  case 75: /* boolean_expression: numeric_expression LTE numeric_expression  */
#line 499 "compiler/zsharp.y"
                                                { 
        (yyval.number_val) = ((yyvsp[-2].expr_val).value.number_val <= (yyvsp[0].expr_val).value.number_val) ? 1 : 0;
    }
#line 1892 "intermediate/zsharp.tab.c"
    break;

  case 76: /* boolean_expression: numeric_expression EQ numeric_expression  */
#line 502 "compiler/zsharp.y"
                                               { 
        (yyval.number_val) = ((yyvsp[-2].expr_val).value.number_val == (yyvsp[0].expr_val).value.number_val) ? 1 : 0;
    }
#line 1900 "intermediate/zsharp.tab.c"
    break;

  case 77: /* boolean_expression: numeric_expression NEQ numeric_expression  */
#line 505 "compiler/zsharp.y"
                                                { 
        (yyval.number_val) = ((yyvsp[-2].expr_val).value.number_val != (yyvsp[0].expr_val).value.number_val) ? 1 : 0;
    }
#line 1908 "intermediate/zsharp.tab.c"
    break;

  case 78: /* boolean_expression: boolean_expression AND boolean_expression  */
#line 508 "compiler/zsharp.y"
                                                { 
        (yyval.number_val) = ((yyvsp[-2].number_val) && (yyvsp[0].number_val)) ? 1 : 0;
    }
#line 1916 "intermediate/zsharp.tab.c"
    break;

  case 79: /* boolean_expression: boolean_expression OR boolean_expression  */
#line 511 "compiler/zsharp.y"
                                               { 
        (yyval.number_val) = ((yyvsp[-2].number_val) || (yyvsp[0].number_val)) ? 1 : 0;
    }
#line 1924 "intermediate/zsharp.tab.c"
    break;

  case 80: /* boolean_expression: NOT boolean_expression  */
#line 514 "compiler/zsharp.y"
                             { 
        (yyval.number_val) = !(yyvsp[0].number_val) ? 1 : 0;
    }
#line 1932 "intermediate/zsharp.tab.c"
    break;

  case 81: /* boolean_expression: TRUE_VAL  */
#line 517 "compiler/zsharp.y"
               { 
        (yyval.number_val) = 1;
    }
#line 1940 "intermediate/zsharp.tab.c"
    break;

  case 82: /* boolean_expression: FALSE_VAL  */
#line 520 "compiler/zsharp.y"
                { 
        (yyval.number_val) = 0;
    }
#line 1948 "intermediate/zsharp.tab.c"
    break;

  case 83: /* boolean_expression: '(' boolean_expression ')'  */
#line 523 "compiler/zsharp.y"
                                 { 
        (yyval.number_val) = (yyvsp[-1].number_val);
    }
#line 1956 "intermediate/zsharp.tab.c"
    break;


#line 1960 "intermediate/zsharp.tab.c"

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

#line 528 "compiler/zsharp.y"


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
