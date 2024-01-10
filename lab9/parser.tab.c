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
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>

extern int yylineno;

#line 78 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ASSIGNMENT_OPERATOR = 3,        /* ASSIGNMENT_OPERATOR  */
  YYSYMBOL_ARITHMETIC_OPERATOR = 4,        /* ARITHMETIC_OPERATOR  */
  YYSYMBOL_LOGICAL_OPERATOR = 5,           /* LOGICAL_OPERATOR  */
  YYSYMBOL_RELATIONAL_OPERATOR = 6,        /* RELATIONAL_OPERATOR  */
  YYSYMBOL_ACCESS_OPERATOR = 7,            /* ACCESS_OPERATOR  */
  YYSYMBOL_ARROW = 8,                      /* ARROW  */
  YYSYMBOL_SEMICOLON = 9,                  /* SEMICOLON  */
  YYSYMBOL_COLON = 10,                     /* COLON  */
  YYSYMBOL_COMMA = 11,                     /* COMMA  */
  YYSYMBOL_LEFT_PARENTHESIS = 12,          /* LEFT_PARENTHESIS  */
  YYSYMBOL_RIGHT_PARENTHESIS = 13,         /* RIGHT_PARENTHESIS  */
  YYSYMBOL_LEFT_BRACKET = 14,              /* LEFT_BRACKET  */
  YYSYMBOL_RIGHT_BRACKET = 15,             /* RIGHT_BRACKET  */
  YYSYMBOL_LEFT_BRACE = 16,                /* LEFT_BRACE  */
  YYSYMBOL_RIGHT_BRACE = 17,               /* RIGHT_BRACE  */
  YYSYMBOL_INT_TYPE = 18,                  /* INT_TYPE  */
  YYSYMBOL_STR_TYPE = 19,                  /* STR_TYPE  */
  YYSYMBOL_NULL_TYPE = 20,                 /* NULL_TYPE  */
  YYSYMBOL_VAR = 21,                       /* VAR  */
  YYSYMBOL_CONST = 22,                     /* CONST  */
  YYSYMBOL_IF = 23,                        /* IF  */
  YYSYMBOL_ELSE = 24,                      /* ELSE  */
  YYSYMBOL_WHILE = 25,                     /* WHILE  */
  YYSYMBOL_READ = 26,                      /* READ  */
  YYSYMBOL_WRITE = 27,                     /* WRITE  */
  YYSYMBOL_FN = 28,                        /* FN  */
  YYSYMBOL_RETURN = 29,                    /* RETURN  */
  YYSYMBOL_ID = 30,                        /* ID  */
  YYSYMBOL_INT = 31,                       /* INT  */
  YYSYMBOL_STR = 32,                       /* STR  */
  YYSYMBOL_YYACCEPT = 33,                  /* $accept  */
  YYSYMBOL_start = 34,                     /* start  */
  YYSYMBOL_basic_type = 35,                /* basic_type  */
  YYSYMBOL_array_type = 36,                /* array_type  */
  YYSYMBOL_type = 37,                      /* type  */
  YYSYMBOL_array_elem = 38,                /* array_elem  */
  YYSYMBOL_array_elems = 39,               /* array_elems  */
  YYSYMBOL_array = 40,                     /* array  */
  YYSYMBOL_lvalue = 41,                    /* lvalue  */
  YYSYMBOL_rvalue = 42,                    /* rvalue  */
  YYSYMBOL_term = 43,                      /* term  */
  YYSYMBOL_expression_op = 44,             /* expression_op  */
  YYSYMBOL_expression = 45,                /* expression  */
  YYSYMBOL_condition = 46,                 /* condition  */
  YYSYMBOL_var_declaration = 47,           /* var_declaration  */
  YYSYMBOL_const_declaration = 48,         /* const_declaration  */
  YYSYMBOL_if_stmt = 49,                   /* if_stmt  */
  YYSYMBOL_else_stmt = 50,                 /* else_stmt  */
  YYSYMBOL_while_stmt = 51,                /* while_stmt  */
  YYSYMBOL_flow_stmt = 52,                 /* flow_stmt  */
  YYSYMBOL_read_stmt = 53,                 /* read_stmt  */
  YYSYMBOL_write_stmt = 54,                /* write_stmt  */
  YYSYMBOL_io_stmt = 55,                   /* io_stmt  */
  YYSYMBOL_assignment_stmt = 56,           /* assignment_stmt  */
  YYSYMBOL_return_stmt = 57,               /* return_stmt  */
  YYSYMBOL_call_stmt = 58,                 /* call_stmt  */
  YYSYMBOL_stmt = 59,                      /* stmt  */
  YYSYMBOL_stmt_list = 60,                 /* stmt_list  */
  YYSYMBOL_stmt_block = 61,                /* stmt_block  */
  YYSYMBOL_function = 62,                  /* function  */
  YYSYMBOL_param = 63,                     /* param  */
  YYSYMBOL_params = 64,                    /* params  */
  YYSYMBOL_arg = 65,                       /* arg  */
  YYSYMBOL_args = 66                       /* args  */
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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   100

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  33
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  62
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  120

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   287


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
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    22,    22,    23,    27,    28,    29,    31,    33,    34,
      38,    40,    41,    43,    44,    47,    48,    49,    51,    52,
      53,    54,    57,    59,    60,    61,    63,    64,    67,    71,
      73,    77,    79,    80,    82,    84,    85,    89,    91,    93,
      94,    98,   100,   102,   103,   106,   107,   108,   109,   110,
     111,   112,   114,   115,   117,   120,   121,   124,   126,   127,
     130,   132,   133
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
  "\"end of file\"", "error", "\"invalid token\"", "ASSIGNMENT_OPERATOR",
  "ARITHMETIC_OPERATOR", "LOGICAL_OPERATOR", "RELATIONAL_OPERATOR",
  "ACCESS_OPERATOR", "ARROW", "SEMICOLON", "COLON", "COMMA",
  "LEFT_PARENTHESIS", "RIGHT_PARENTHESIS", "LEFT_BRACKET", "RIGHT_BRACKET",
  "LEFT_BRACE", "RIGHT_BRACE", "INT_TYPE", "STR_TYPE", "NULL_TYPE", "VAR",
  "CONST", "IF", "ELSE", "WHILE", "READ", "WRITE", "FN", "RETURN", "ID",
  "INT", "STR", "$accept", "start", "basic_type", "array_type", "type",
  "array_elem", "array_elems", "array", "lvalue", "rvalue", "term",
  "expression_op", "expression", "condition", "var_declaration",
  "const_declaration", "if_stmt", "else_stmt", "while_stmt", "flow_stmt",
  "read_stmt", "write_stmt", "io_stmt", "assignment_stmt", "return_stmt",
  "call_stmt", "stmt", "stmt_list", "stmt_block", "function", "param",
  "params", "arg", "args", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-37)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -20,   -17,    10,   -20,     9,   -37,   -37,    -4,    14,    19,
      23,    17,    35,    35,    15,    31,    35,   -37,   -37,   -37,
     -37,   -37,    24,   -37,   -37,    35,    43,    21,   -37,    24,
      29,    32,    33,    49,    53,    34,     6,     6,     5,    63,
      58,    59,   -37,   -37,   -37,   -37,   -37,    60,    61,    62,
      69,    21,    64,   -37,    65,    72,    73,     6,     6,   -37,
       1,     4,   -37,   -37,   -37,   -37,   -37,   -37,    52,   -37,
      54,    -7,     6,     6,   -37,   -37,   -37,   -37,   -37,   -37,
     -37,   -37,   -37,    35,    35,    52,    66,    74,   -37,    75,
      70,    52,   -37,   -37,   -37,     6,   -37,   -37,   -37,    78,
      77,    76,    52,   -37,   -37,    24,    24,     6,   -37,   -37,
       6,   -37,   -37,    68,   -37,   -37,   -37,    24,   -37,   -37
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     0,     1,     3,     0,     0,     0,
      58,     0,     0,     0,     0,     0,     0,     4,     5,     6,
       8,     9,     0,    57,    59,     0,     0,    53,    56,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    15,     0,
       0,     0,    35,    36,    51,    39,    40,     0,     0,     0,
       0,    53,     0,    55,     0,     0,     0,     0,     0,    37,
       0,    15,    18,    19,    20,    21,    22,    26,    38,    42,
       0,     0,     0,     0,    45,    46,    48,    47,    49,    50,
      52,    54,     7,     0,     0,    28,     0,     0,    14,    11,
       0,    10,    23,    24,    25,     0,    16,    44,    60,    61,
       0,     0,    41,    29,    30,     0,     0,     0,    13,    27,
       0,    43,    17,    33,    34,    12,    62,     0,    31,    32
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -37,    90,   -37,   -37,   -11,   -37,   -13,   -37,   -24,    25,
     -36,   -37,   -32,    37,   -37,   -37,   -37,   -37,   -37,   -37,
     -37,   -37,   -37,   -37,   -37,   -37,   -37,    45,   -29,   -37,
     -37,    84,   -37,   -10
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,    20,    21,    22,    89,    90,    64,    65,    66,
      67,    95,    85,    86,    40,    41,    42,   118,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    28,     3,
      10,    11,    99,   100
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      53,    69,    23,    39,    68,    26,    97,    60,     1,     8,
       5,    70,    70,     4,    29,    60,    88,    71,    72,    72,
      60,     7,    12,    61,    62,    63,     9,    39,    91,    13,
      15,    61,    62,    63,    14,    98,    61,    62,    63,    25,
      27,   102,    31,    32,    33,     9,    34,    35,    36,    16,
      37,    38,    30,    17,    18,    19,    92,    93,    94,   109,
      54,    57,    55,    56,    59,    58,    73,    74,    75,    76,
      77,    78,   103,   104,    98,    91,   113,   114,    79,   105,
      82,    81,    83,    84,    96,   108,   107,   106,   119,   110,
     111,   112,   117,     6,   115,    87,    80,   101,    24,     0,
     116
};

static const yytype_int8 yycheck[] =
{
      29,    37,    13,    27,    36,    16,    13,    14,    28,    13,
       0,     7,     7,    30,    25,    14,    15,    12,    14,    14,
      14,    12,     8,    30,    31,    32,    30,    51,    60,    10,
      13,    30,    31,    32,    11,    71,    30,    31,    32,     8,
      16,    73,    21,    22,    23,    30,    25,    26,    27,    14,
      29,    30,     9,    18,    19,    20,     4,     5,     6,    95,
      31,    12,    30,    30,    30,    12,     3,     9,     9,     9,
       9,     9,    83,    84,   110,   107,   105,   106,     9,    13,
      15,    17,    10,    10,    30,    15,    11,    13,   117,    11,
      13,    15,    24,     3,   107,    58,    51,    72,    14,    -1,
     110
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    28,    34,    62,    30,     0,    34,    12,    13,    30,
      63,    64,     8,    10,    11,    13,    14,    18,    19,    20,
      35,    36,    37,    37,    64,     8,    37,    16,    61,    37,
       9,    21,    22,    23,    25,    26,    27,    29,    30,    41,
      47,    48,    49,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    31,    30,    30,    12,    12,    30,
      14,    30,    31,    32,    40,    41,    42,    43,    45,    43,
       7,    12,    14,     3,     9,     9,     9,     9,     9,     9,
      60,    17,    15,    10,    10,    45,    46,    46,    15,    38,
      39,    45,     4,     5,     6,    44,    30,    13,    43,    65,
      66,    42,    45,    37,    37,    13,    13,    11,    15,    43,
      11,    13,    15,    61,    61,    39,    66,    24,    50,    61
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    33,    34,    34,    35,    35,    35,    36,    37,    37,
      38,    39,    39,    40,    40,    41,    41,    41,    42,    42,
      42,    42,    43,    44,    44,    44,    45,    45,    46,    47,
      48,    49,    50,    50,    51,    52,    52,    53,    54,    55,
      55,    56,    57,    58,    58,    59,    59,    59,    59,    59,
      59,    59,    60,    60,    61,    62,    62,    63,    64,    64,
      65,    66,    66
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     5,     1,     1,
       1,     1,     3,     3,     2,     1,     3,     4,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     4,
       4,     6,     2,     0,     5,     1,     1,     2,     2,     1,
       1,     3,     2,     4,     3,     2,     2,     2,     2,     2,
       2,     1,     2,     0,     3,     8,     7,     3,     1,     3,
       1,     1,     3
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
  case 2: /* start: function  */
#line 22 "parser.y"
                                                { printf("start -> function\n"); }
#line 1208 "parser.tab.c"
    break;

  case 3: /* start: function start  */
#line 23 "parser.y"
                                                { printf("start -> function start\n"); }
#line 1214 "parser.tab.c"
    break;

  case 4: /* basic_type: INT_TYPE  */
#line 27 "parser.y"
                                                { printf("basic_type -> int\n"); }
#line 1220 "parser.tab.c"
    break;

  case 5: /* basic_type: STR_TYPE  */
#line 28 "parser.y"
                                                { printf("basic_type -> str\n"); }
#line 1226 "parser.tab.c"
    break;

  case 6: /* basic_type: NULL_TYPE  */
#line 29 "parser.y"
                                                { printf("basic_type -> null\n"); }
#line 1232 "parser.tab.c"
    break;

  case 7: /* array_type: LEFT_BRACKET type SEMICOLON INT RIGHT_BRACKET  */
#line 31 "parser.y"
                                                            { printf("array_type -> [ type ; %d ]\n", (yyvsp[-1].value)); }
#line 1238 "parser.tab.c"
    break;

  case 8: /* type: basic_type  */
#line 33 "parser.y"
                                                { printf("type -> array_type\n"); }
#line 1244 "parser.tab.c"
    break;

  case 9: /* type: array_type  */
#line 34 "parser.y"
                                                { printf("type -> array_type\n"); }
#line 1250 "parser.tab.c"
    break;

  case 10: /* array_elem: expression  */
#line 38 "parser.y"
                                                { printf("array_elem -> expression\n"); }
#line 1256 "parser.tab.c"
    break;

  case 11: /* array_elems: array_elem  */
#line 40 "parser.y"
                                                { printf("array_elems -> array_elem\n"); }
#line 1262 "parser.tab.c"
    break;

  case 12: /* array_elems: array_elem COMMA array_elems  */
#line 41 "parser.y"
                                                { printf("array_elems -> array_elem , array_elems\n"); }
#line 1268 "parser.tab.c"
    break;

  case 13: /* array: LEFT_BRACKET array_elems RIGHT_BRACKET  */
#line 43 "parser.y"
                                                { printf("array -> [ array_elems ]\n"); }
#line 1274 "parser.tab.c"
    break;

  case 14: /* array: LEFT_BRACKET RIGHT_BRACKET  */
#line 44 "parser.y"
                                                { printf("array -> [ array_type ]\n"); }
#line 1280 "parser.tab.c"
    break;

  case 15: /* lvalue: ID  */
#line 47 "parser.y"
                                                { printf("lvalue -> %s\n", (yyvsp[0].text)); }
#line 1286 "parser.tab.c"
    break;

  case 16: /* lvalue: ID ACCESS_OPERATOR ID  */
#line 48 "parser.y"
                                                { printf("lvalue -> %s . %s\n", (yyvsp[-2].text), (yyvsp[0].text)); }
#line 1292 "parser.tab.c"
    break;

  case 17: /* lvalue: ID LEFT_BRACKET rvalue RIGHT_BRACKET  */
#line 49 "parser.y"
                                                { printf("lvalue -> %s[rvalue]\n", (yyvsp[-3].text)); }
#line 1298 "parser.tab.c"
    break;

  case 18: /* rvalue: INT  */
#line 51 "parser.y"
                                                { printf("rvalue -> %d\n", (yyvsp[0].value)); }
#line 1304 "parser.tab.c"
    break;

  case 19: /* rvalue: STR  */
#line 52 "parser.y"
                                                { printf("rvalue -> %s\n", (yyvsp[0].value)); }
#line 1310 "parser.tab.c"
    break;

  case 20: /* rvalue: array  */
#line 53 "parser.y"
                                                { printf("rvalue -> array\n"); }
#line 1316 "parser.tab.c"
    break;

  case 21: /* rvalue: lvalue  */
#line 54 "parser.y"
                                                { printf("rvalue -> array\n"); }
#line 1322 "parser.tab.c"
    break;

  case 22: /* term: rvalue  */
#line 57 "parser.y"
                                                { printf("term -> rvalue\n"); }
#line 1328 "parser.tab.c"
    break;

  case 23: /* expression_op: ARITHMETIC_OPERATOR  */
#line 59 "parser.y"
                                                { printf("expression_op -> %s\n", (yyvsp[0].text)); }
#line 1334 "parser.tab.c"
    break;

  case 24: /* expression_op: LOGICAL_OPERATOR  */
#line 60 "parser.y"
                                                { printf("expression_op -> %s\n", (yyvsp[0].text)); }
#line 1340 "parser.tab.c"
    break;

  case 25: /* expression_op: RELATIONAL_OPERATOR  */
#line 61 "parser.y"
                                                { printf("expression_op -> %s\n", (yyvsp[0].text)); }
#line 1346 "parser.tab.c"
    break;

  case 26: /* expression: term  */
#line 63 "parser.y"
                                                { printf("expression -> term\n"); }
#line 1352 "parser.tab.c"
    break;

  case 27: /* expression: expression expression_op term  */
#line 64 "parser.y"
                                                { printf("expression -> expression expression_op term\n"); }
#line 1358 "parser.tab.c"
    break;

  case 28: /* condition: expression  */
#line 67 "parser.y"
                                                { printf("condition -> expression\n"); }
#line 1364 "parser.tab.c"
    break;

  case 29: /* var_declaration: VAR ID COLON type  */
#line 71 "parser.y"
                                                { printf("var_declaration -> var %s: type\n", (yyvsp[-2].text)); }
#line 1370 "parser.tab.c"
    break;

  case 30: /* const_declaration: CONST ID COLON type  */
#line 73 "parser.y"
                                                { printf("const_declaration -> const %s: type\n", (yyvsp[-2].text)); }
#line 1376 "parser.tab.c"
    break;

  case 31: /* if_stmt: IF LEFT_PARENTHESIS condition RIGHT_PARENTHESIS stmt_block else_stmt  */
#line 77 "parser.y"
                                                                                { printf("if_stmt -> if ( condition ) stmt_block else_stmt\n"); }
#line 1382 "parser.tab.c"
    break;

  case 32: /* else_stmt: ELSE stmt_block  */
#line 79 "parser.y"
                                                { printf("else_stmt -> else stmt_block\n"); }
#line 1388 "parser.tab.c"
    break;

  case 33: /* else_stmt: %empty  */
#line 80 "parser.y"
                                                { printf("else_stmt -> EPSILON\n"); }
#line 1394 "parser.tab.c"
    break;

  case 34: /* while_stmt: WHILE LEFT_PARENTHESIS condition RIGHT_PARENTHESIS stmt_block  */
#line 82 "parser.y"
                                                                                { printf("while_stmt -> while ( condition ) stmt_block\n"); }
#line 1400 "parser.tab.c"
    break;

  case 35: /* flow_stmt: if_stmt  */
#line 84 "parser.y"
                                                { printf("flow_stmt -> if_stmt\n"); }
#line 1406 "parser.tab.c"
    break;

  case 36: /* flow_stmt: while_stmt  */
#line 85 "parser.y"
                                                { printf("flow_stmt -> while_stmt\n"); }
#line 1412 "parser.tab.c"
    break;

  case 37: /* read_stmt: READ ID  */
#line 89 "parser.y"
                                                { printf("read_stmt -> read %s\n", (yyvsp[0].text)); }
#line 1418 "parser.tab.c"
    break;

  case 38: /* write_stmt: WRITE expression  */
#line 91 "parser.y"
                                                { printf("write_stmt -> write expression\n"); }
#line 1424 "parser.tab.c"
    break;

  case 39: /* io_stmt: read_stmt  */
#line 93 "parser.y"
                                                { printf("io_stmt -> read_stmt\n"); }
#line 1430 "parser.tab.c"
    break;

  case 40: /* io_stmt: write_stmt  */
#line 94 "parser.y"
                                                { printf("io_stmt -> write_stmt\n"); }
#line 1436 "parser.tab.c"
    break;

  case 41: /* assignment_stmt: lvalue ASSIGNMENT_OPERATOR expression  */
#line 98 "parser.y"
                                                            { printf("assignment_stmt -> lvalue %s expression\n", (yyvsp[-1].text)); }
#line 1442 "parser.tab.c"
    break;

  case 42: /* return_stmt: RETURN term  */
#line 100 "parser.y"
                                                            { printf("return_stmt -> return term\n"); }
#line 1448 "parser.tab.c"
    break;

  case 43: /* call_stmt: ID LEFT_PARENTHESIS args RIGHT_PARENTHESIS  */
#line 102 "parser.y"
                                                            { printf("call_stmt -> %s ( args )\n", (yyvsp[-3].text)); }
#line 1454 "parser.tab.c"
    break;

  case 44: /* call_stmt: ID LEFT_PARENTHESIS RIGHT_PARENTHESIS  */
#line 103 "parser.y"
                                                            { printf("call_stmt -> %s ( )\n", (yyvsp[-2].text)); }
#line 1460 "parser.tab.c"
    break;

  case 45: /* stmt: var_declaration SEMICOLON  */
#line 106 "parser.y"
                                                { printf("stmt -> var_declaration ;\n"); }
#line 1466 "parser.tab.c"
    break;

  case 46: /* stmt: const_declaration SEMICOLON  */
#line 107 "parser.y"
                                                { printf("stmt -> const_declaration ;\n"); }
#line 1472 "parser.tab.c"
    break;

  case 47: /* stmt: assignment_stmt SEMICOLON  */
#line 108 "parser.y"
                                                { printf("stmt -> assignment_stmt ;\n"); }
#line 1478 "parser.tab.c"
    break;

  case 48: /* stmt: io_stmt SEMICOLON  */
#line 109 "parser.y"
                                                { printf("stmt -> io_stmt ;\n"); }
#line 1484 "parser.tab.c"
    break;

  case 49: /* stmt: return_stmt SEMICOLON  */
#line 110 "parser.y"
                                                { printf("stmt -> return_stmt ;\n"); }
#line 1490 "parser.tab.c"
    break;

  case 50: /* stmt: call_stmt SEMICOLON  */
#line 111 "parser.y"
                                                { printf("stmt -> call_stmt ;\n"); }
#line 1496 "parser.tab.c"
    break;

  case 51: /* stmt: flow_stmt  */
#line 112 "parser.y"
                                                { printf("stmt -> flow_stmt ;\n"); }
#line 1502 "parser.tab.c"
    break;

  case 52: /* stmt_list: stmt stmt_list  */
#line 114 "parser.y"
                                                { printf("stmt_list -> stmt stmt_list\n"); }
#line 1508 "parser.tab.c"
    break;

  case 53: /* stmt_list: %empty  */
#line 115 "parser.y"
                                                { printf("stmt_list -> EPSILON\n"); }
#line 1514 "parser.tab.c"
    break;

  case 54: /* stmt_block: LEFT_BRACE stmt_list RIGHT_BRACE  */
#line 117 "parser.y"
                                                { printf("stmt_block -> { stmt_list }\n"); }
#line 1520 "parser.tab.c"
    break;

  case 55: /* function: FN ID LEFT_PARENTHESIS params RIGHT_PARENTHESIS ARROW type stmt_block  */
#line 120 "parser.y"
                                                                                    { printf("function -> fn %s ( params ) -> type stmt_block\n", (yyvsp[-6].text)); }
#line 1526 "parser.tab.c"
    break;

  case 56: /* function: FN ID LEFT_PARENTHESIS RIGHT_PARENTHESIS ARROW type stmt_block  */
#line 121 "parser.y"
                                                                                    { printf("function -> fn %s ( ) -> type stmt_block\n", (yyvsp[-5].text)); }
#line 1532 "parser.tab.c"
    break;

  case 57: /* param: ID COLON type  */
#line 124 "parser.y"
                                                { printf("param -> %s : type\n", (yyvsp[-2].text)); }
#line 1538 "parser.tab.c"
    break;

  case 58: /* params: param  */
#line 126 "parser.y"
                                                { printf("params -> param\n"); }
#line 1544 "parser.tab.c"
    break;

  case 59: /* params: param COMMA params  */
#line 127 "parser.y"
                                                { printf("params -> param , param\n"); }
#line 1550 "parser.tab.c"
    break;

  case 60: /* arg: term  */
#line 130 "parser.y"
                                                { printf("arg -> term\n"); }
#line 1556 "parser.tab.c"
    break;

  case 61: /* args: arg  */
#line 132 "parser.y"
                                                { printf("args -> arg\n"); }
#line 1562 "parser.tab.c"
    break;

  case 62: /* args: arg COMMA args  */
#line 133 "parser.y"
                                                { printf("args -> arg , args\n"); }
#line 1568 "parser.tab.c"
    break;


#line 1572 "parser.tab.c"

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

#line 136 "parser.y"


int yyerror(const char* msg) {
    fprintf(stderr, "Syntax error at line %d: %s\n", yylineno, msg);
}

int main() {
    yyparse();
    return 0;
}
