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


/* Substitute the variable and function names.  */
#define yyparse         ibexparse
#define yylex           ibexlex
#define yyerror         ibexerror
#define yydebug         ibexdebug
#define yynerrs         ibexnerrs
#define yylval          ibexlval
#define yychar          ibexchar

/* First part of user prologue.  */
#line 1 "parser/parser.yc"

//============================================================================
//                                  I B E X                                   
// File        : Yacc/Bison input for Ibex parser
// Author      : Gilles Chabert
// Copyright   : IMT Atlantique (France)
// License     : See the LICENSE file
// Created     : Jun 12, 2012
// Last Update : Nov 03, 2019
//===========================================================================

#include "ibex_P_Struct.h"

using namespace ibex;
using namespace parser;
using namespace std;


#line 97 "/home/research/optimizeripopt/src/parser/parser.tab.cc"

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

#include "parser.tab.hh"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TK_CHOCO = 3,                   /* TK_CHOCO  */
  YYSYMBOL_TK_CONSTANT = 4,                /* TK_CONSTANT  */
  YYSYMBOL_TK_NEW_SYMBOL = 5,              /* TK_NEW_SYMBOL  */
  YYSYMBOL_TK_FUNC_SYMBOL = 6,             /* TK_FUNC_SYMBOL  */
  YYSYMBOL_TK_EXPR_TMP_SYMBOL = 7,         /* TK_EXPR_TMP_SYMBOL  */
  YYSYMBOL_TK_ENTITY = 8,                  /* TK_ENTITY  */
  YYSYMBOL_TK_ITERATOR = 9,                /* TK_ITERATOR  */
  YYSYMBOL_TK_UNARY_OP = 10,               /* TK_UNARY_OP  */
  YYSYMBOL_TK_BINARY_OP = 11,              /* TK_BINARY_OP  */
  YYSYMBOL_TK_STRING = 12,                 /* TK_STRING  */
  YYSYMBOL_TK_INT_CST = 13,                /* TK_INT_CST  */
  YYSYMBOL_TK_FLOAT = 14,                  /* TK_FLOAT  */
  YYSYMBOL_TK_PI = 15,                     /* TK_PI  */
  YYSYMBOL_TK_INFINITY = 16,               /* TK_INFINITY  */
  YYSYMBOL_TK_BOOL = 17,                   /* TK_BOOL  */
  YYSYMBOL_TK_PARAM = 18,                  /* TK_PARAM  */
  YYSYMBOL_TK_CONST = 19,                  /* TK_CONST  */
  YYSYMBOL_TK_VARS = 20,                   /* TK_VARS  */
  YYSYMBOL_TK_FUNCTION = 21,               /* TK_FUNCTION  */
  YYSYMBOL_TK_DIFF = 22,                   /* TK_DIFF  */
  YYSYMBOL_TK_MIN = 23,                    /* TK_MIN  */
  YYSYMBOL_TK_MAX = 24,                    /* TK_MAX  */
  YYSYMBOL_TK_INF = 25,                    /* TK_INF  */
  YYSYMBOL_TK_MID = 26,                    /* TK_MID  */
  YYSYMBOL_TK_SUP = 27,                    /* TK_SUP  */
  YYSYMBOL_TK_SIGN = 28,                   /* TK_SIGN  */
  YYSYMBOL_TK_ABS = 29,                    /* TK_ABS  */
  YYSYMBOL_TK_SUM = 30,                    /* TK_SUM  */
  YYSYMBOL_TK_SQRT = 31,                   /* TK_SQRT  */
  YYSYMBOL_TK_SQR = 32,                    /* TK_SQR  */
  YYSYMBOL_TK_POW = 33,                    /* TK_POW  */
  YYSYMBOL_TK_EXPO = 34,                   /* TK_EXPO  */
  YYSYMBOL_TK_LOG = 35,                    /* TK_LOG  */
  YYSYMBOL_TK_COS = 36,                    /* TK_COS  */
  YYSYMBOL_TK_SIN = 37,                    /* TK_SIN  */
  YYSYMBOL_TK_TAN = 38,                    /* TK_TAN  */
  YYSYMBOL_TK_ACOS = 39,                   /* TK_ACOS  */
  YYSYMBOL_TK_ASIN = 40,                   /* TK_ASIN  */
  YYSYMBOL_TK_ATAN = 41,                   /* TK_ATAN  */
  YYSYMBOL_TK_ATAN2 = 42,                  /* TK_ATAN2  */
  YYSYMBOL_TK_COSH = 43,                   /* TK_COSH  */
  YYSYMBOL_TK_SINH = 44,                   /* TK_SINH  */
  YYSYMBOL_TK_TANH = 45,                   /* TK_TANH  */
  YYSYMBOL_TK_ACOSH = 46,                  /* TK_ACOSH  */
  YYSYMBOL_TK_ASINH = 47,                  /* TK_ASINH  */
  YYSYMBOL_TK_ATANH = 48,                  /* TK_ATANH  */
  YYSYMBOL_TK_FLOOR = 49,                  /* TK_FLOOR  */
  YYSYMBOL_TK_CEIL = 50,                   /* TK_CEIL  */
  YYSYMBOL_TK_INTEGER = 51,                /* TK_INTEGER  */
  YYSYMBOL_TK_LEQ = 52,                    /* TK_LEQ  */
  YYSYMBOL_TK_GEQ = 53,                    /* TK_GEQ  */
  YYSYMBOL_TK_EQU = 54,                    /* TK_EQU  */
  YYSYMBOL_TK_ASSIGN = 55,                 /* TK_ASSIGN  */
  YYSYMBOL_TK_CHI = 56,                    /* TK_CHI  */
  YYSYMBOL_TK_BEGIN = 57,                  /* TK_BEGIN  */
  YYSYMBOL_TK_END = 58,                    /* TK_END  */
  YYSYMBOL_TK_FOR = 59,                    /* TK_FOR  */
  YYSYMBOL_TK_FROM = 60,                   /* TK_FROM  */
  YYSYMBOL_TK_TO = 61,                     /* TK_TO  */
  YYSYMBOL_TK_RETURN = 62,                 /* TK_RETURN  */
  YYSYMBOL_TK_CTRS = 63,                   /* TK_CTRS  */
  YYSYMBOL_TK_MINIMIZE = 64,               /* TK_MINIMIZE  */
  YYSYMBOL_TK_IN = 65,                     /* TK_IN  */
  YYSYMBOL_TK_INT = 66,                    /* TK_INT  */
  YYSYMBOL_67_ = 67,                       /* '<'  */
  YYSYMBOL_68_ = 68,                       /* '>'  */
  YYSYMBOL_69_ = 69,                       /* '+'  */
  YYSYMBOL_70_ = 70,                       /* '-'  */
  YYSYMBOL_TK_UNION = 71,                  /* TK_UNION  */
  YYSYMBOL_72_ = 72,                       /* '*'  */
  YYSYMBOL_73_ = 73,                       /* '/'  */
  YYSYMBOL_TK_INTERSEC = 74,               /* TK_INTERSEC  */
  YYSYMBOL_75_ = 75,                       /* '^'  */
  YYSYMBOL_76_ = 76,                       /* '\''  */
  YYSYMBOL_77_ = 77,                       /* '['  */
  YYSYMBOL_78_ = 78,                       /* '('  */
  YYSYMBOL_79_ = 79,                       /* ';'  */
  YYSYMBOL_80_ = 80,                       /* ','  */
  YYSYMBOL_81_ = 81,                       /* ']'  */
  YYSYMBOL_82_ = 82,                       /* ')'  */
  YYSYMBOL_83_ = 83,                       /* ':'  */
  YYSYMBOL_YYACCEPT = 84,                  /* $accept  */
  YYSYMBOL_program = 85,                   /* program  */
  YYSYMBOL_86_1 = 86,                      /* $@1  */
  YYSYMBOL_87_2 = 87,                      /* $@2  */
  YYSYMBOL_system_or_func = 88,            /* system_or_func  */
  YYSYMBOL_choco_ctr = 89,                 /* choco_ctr  */
  YYSYMBOL_decl_opt_cst = 90,              /* decl_opt_cst  */
  YYSYMBOL_decl_cst_list = 91,             /* decl_cst_list  */
  YYSYMBOL_decl_cst = 92,                  /* decl_cst  */
  YYSYMBOL_decl_var_integer = 93,          /* decl_var_integer  */
  YYSYMBOL_equ_or_in = 94,                 /* equ_or_in  */
  YYSYMBOL_decl_var_list = 95,             /* decl_var_list  */
  YYSYMBOL_decl_var = 96,                  /* decl_var  */
  YYSYMBOL_dimension = 97,                 /* dimension  */
  YYSYMBOL_interval = 98,                  /* interval  */
  YYSYMBOL_decl_opt_fncs = 99,             /* decl_opt_fncs  */
  YYSYMBOL_function = 100,                 /* function  */
  YYSYMBOL_101_3 = 101,                    /* $@3  */
  YYSYMBOL_semicolon_opt = 102,            /* semicolon_opt  */
  YYSYMBOL_fnc_inpt_list = 103,            /* fnc_inpt_list  */
  YYSYMBOL_fnc_input = 104,                /* fnc_input  */
  YYSYMBOL_fnc_code = 105,                 /* fnc_code  */
  YYSYMBOL_fnc_assign = 106,               /* fnc_assign  */
  YYSYMBOL_decl_opt_goal = 107,            /* decl_opt_goal  */
  YYSYMBOL_decl_opt_ctrs = 108,            /* decl_opt_ctrs  */
  YYSYMBOL_109_4 = 109,                    /* $@4  */
  YYSYMBOL_ctr_blk_list = 110,             /* ctr_blk_list  */
  YYSYMBOL_ctr_blk_list1 = 111,            /* ctr_blk_list1  */
  YYSYMBOL_ctr_blk_list2 = 112,            /* ctr_blk_list2  */
  YYSYMBOL_ctr_loop = 113,                 /* ctr_loop  */
  YYSYMBOL_114_5 = 114,                    /* $@5  */
  YYSYMBOL_ctr = 115,                      /* ctr  */
  YYSYMBOL_expr = 116,                     /* expr  */
  YYSYMBOL_117_6 = 117,                    /* $@6  */
  YYSYMBOL_expr_row = 118,                 /* expr_row  */
  YYSYMBOL_expr_col = 119,                 /* expr_col  */
  YYSYMBOL_expr_index = 120                /* expr_index  */
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
typedef yytype_int16 yy_state_t;

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1026

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  84
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  133
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  345

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   323


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
       2,     2,     2,     2,     2,     2,     2,     2,     2,    76,
      78,    82,    72,    69,    80,    70,     2,    73,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    83,    79,
      67,     2,    68,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    77,     2,    81,    75,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    71,    74
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    94,    94,    94,    98,    98,   104,   108,   111,   118,
     119,   120,   123,   124,   127,   133,   142,   142,   144,   144,
     146,   147,   148,   151,   153,   156,   164,   165,   167,   171,
     179,   180,   183,   183,   194,   194,   196,   197,   200,   204,
     205,   208,   210,   217,   218,   225,   226,   226,   229,   232,
     233,   236,   237,   238,   242,   243,   245,   250,   249,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   274,   275,
     276,   277,   278,   279,   281,   280,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   312,   313,   314,   315,   316,   317,   318,   320,   321,
     322,   323,   324,   325,   326,   327,   329,   330,   331,   332,
     333,   334,   335,   336,   337,   338,   339,   343,   344,   348,
     349,   353,   354,   355
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
  "\"end of file\"", "error", "\"invalid token\"", "TK_CHOCO",
  "TK_CONSTANT", "TK_NEW_SYMBOL", "TK_FUNC_SYMBOL", "TK_EXPR_TMP_SYMBOL",
  "TK_ENTITY", "TK_ITERATOR", "TK_UNARY_OP", "TK_BINARY_OP", "TK_STRING",
  "TK_INT_CST", "TK_FLOAT", "TK_PI", "TK_INFINITY", "TK_BOOL", "TK_PARAM",
  "TK_CONST", "TK_VARS", "TK_FUNCTION", "TK_DIFF", "TK_MIN", "TK_MAX",
  "TK_INF", "TK_MID", "TK_SUP", "TK_SIGN", "TK_ABS", "TK_SUM", "TK_SQRT",
  "TK_SQR", "TK_POW", "TK_EXPO", "TK_LOG", "TK_COS", "TK_SIN", "TK_TAN",
  "TK_ACOS", "TK_ASIN", "TK_ATAN", "TK_ATAN2", "TK_COSH", "TK_SINH",
  "TK_TANH", "TK_ACOSH", "TK_ASINH", "TK_ATANH", "TK_FLOOR", "TK_CEIL",
  "TK_INTEGER", "TK_LEQ", "TK_GEQ", "TK_EQU", "TK_ASSIGN", "TK_CHI",
  "TK_BEGIN", "TK_END", "TK_FOR", "TK_FROM", "TK_TO", "TK_RETURN",
  "TK_CTRS", "TK_MINIMIZE", "TK_IN", "TK_INT", "'<'", "'>'", "'+'", "'-'",
  "TK_UNION", "'*'", "'/'", "TK_INTERSEC", "'^'", "'\\''", "'['", "'('",
  "';'", "','", "']'", "')'", "':'", "$accept", "program", "$@1", "$@2",
  "system_or_func", "choco_ctr", "decl_opt_cst", "decl_cst_list",
  "decl_cst", "decl_var_integer", "equ_or_in", "decl_var_list", "decl_var",
  "dimension", "interval", "decl_opt_fncs", "function", "$@3",
  "semicolon_opt", "fnc_inpt_list", "fnc_input", "fnc_code", "fnc_assign",
  "decl_opt_goal", "decl_opt_ctrs", "$@4", "ctr_blk_list", "ctr_blk_list1",
  "ctr_blk_list2", "ctr_loop", "$@5", "ctr", "expr", "$@6", "expr_row",
  "expr_col", "expr_index", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-232)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-36)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      94,    87,    74,   363,  -232,     6,  -232,  -232,    47,    52,
    -232,  -232,  -232,    68,    71,  -232,  -232,  -232,  -232,    85,
     100,   107,   120,   129,   134,   140,   145,   146,   148,   176,
     177,   182,   185,   198,   199,   200,   201,   203,   204,   206,
     210,   217,   222,   223,   224,   225,   226,   258,   266,   268,
     128,   513,   513,   513,   513,   438,  -232,  -232,  -232,    46,
     269,  -232,  -232,    89,   272,   346,   275,  -232,    -7,   513,
     513,   513,   513,   513,   513,   513,   513,   513,   513,   513,
     513,   350,   513,   513,   513,   513,   513,   513,   513,   513,
     513,   513,   513,   513,   513,   513,   513,   513,   513,   513,
     513,   513,   513,   513,   302,   513,    75,    96,    96,   841,
     276,    30,    55,   -21,   363,  -232,  -232,   363,   513,   513,
     513,   513,   513,   513,   513,   513,   513,   513,   513,  -232,
     283,   283,   513,    31,   272,     6,   352,  -232,  -232,  -232,
     948,   265,   110,   170,   853,   865,   113,   126,   171,   495,
     523,   534,   545,   556,   305,   567,   578,   877,   589,   600,
     611,   622,   633,   644,   655,   666,   889,   677,   688,   699,
     710,   721,   732,   743,   754,   765,   901,   513,   189,   513,
     513,  -232,   513,   513,  -232,   513,  -232,   513,  -232,  -232,
    -232,  -232,  -232,   948,   948,   948,   948,   948,   948,    96,
      96,    45,    45,    39,  -232,   111,   281,   190,   348,  -232,
    -232,   513,    31,  -232,   272,    60,  -232,   358,  -232,  -232,
    -232,   513,  -232,  -232,  -232,  -232,  -232,  -232,  -232,  -232,
     513,  -232,  -232,   513,  -232,  -232,  -232,  -232,  -232,  -232,
    -232,  -232,   513,  -232,  -232,  -232,  -232,  -232,  -232,  -232,
    -232,  -232,   513,   127,   -13,   423,   948,   948,   948,   948,
     513,  -232,   283,  -232,   287,   948,   513,    53,   352,   352,
     297,   776,   144,   787,   798,   913,   513,  -232,  -232,   948,
     298,   513,   948,  -232,   513,  -232,   300,  -232,   -11,  -232,
     376,  -232,   513,  -232,  -232,   513,   159,  -232,   831,   948,
     513,   513,   319,   272,   193,  -232,   925,   809,  -232,  -232,
     948,   937,    32,  -232,  -232,   376,  -232,  -232,  -232,   363,
    -232,   325,   363,  -232,     4,   513,   326,  -232,   357,   362,
     373,   513,   349,   820,  -232,  -232,   513,   513,   937,  -232,
    -232,   948,   948,   377,  -232
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     9,     0,     1,    10,    31,   113,     0,     0,
     112,   110,   111,     0,     0,   119,   116,   117,   118,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     5,   120,     8,    35,
      35,    56,    53,     0,    26,     0,     0,    12,     7,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   101,    77,     0,
       0,     0,     0,     0,    34,    49,    34,    50,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    80,
       0,     0,     0,     0,    26,    11,     0,    32,     3,    30,
      67,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    66,     0,     0,   102,     0,   108,     0,   109,    54,
      51,    55,    52,    60,    61,    59,    64,    62,    63,    68,
      70,    69,    71,   104,   131,   132,     0,     0,     0,    18,
      19,     0,     0,    13,    26,     0,    20,     0,   114,   115,
     125,     0,   124,    73,    72,   121,   122,   123,    79,    78,
       0,    81,    82,     0,    84,    85,    86,    87,    88,    89,
      90,    91,     0,    92,    93,    94,    95,    96,    97,    98,
      99,    65,     0,     0,     0,     0,   130,   128,   127,   129,
       0,   105,     0,   106,    27,    14,     0,    23,    31,     0,
       0,     0,     0,     0,     0,     0,     0,   103,    29,   133,
       0,     0,    15,    17,     0,    16,     0,    21,    43,    22,
       0,   126,     0,    83,    76,     0,     0,   107,     0,    24,
       0,     0,    45,    26,     0,    37,     0,     0,    57,    28,
      25,    35,    46,     6,    38,     0,    40,    74,   100,     0,
      44,     0,     0,    36,     0,     0,     0,    48,     0,     0,
       0,     0,     0,     0,    58,    47,     0,     0,    35,    39,
      75,    42,    41,     0,    33
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -232,  -232,  -232,  -232,  -232,  -232,  -232,  -232,   296,  -232,
     227,  -232,   -92,  -128,  -232,   166,  -232,  -232,   -55,  -232,
     121,  -232,  -232,  -232,  -232,  -232,  -231,  -232,  -232,    10,
    -232,   -25,   -51,  -232,   -58,  -232,  -124
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,     2,     3,   138,    56,     6,    66,    67,   286,
     211,   215,   216,   133,    57,    68,   139,   217,   115,   304,
     305,   324,   332,   302,   313,   322,    58,    59,    60,    61,
     319,    62,    63,   325,   112,   113,   206
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     106,   107,   108,   109,   111,   117,   212,   207,   329,   330,
     137,    64,   142,   136,   137,   146,   147,   148,   140,   141,
     143,   144,   145,   145,   145,   149,   150,   151,   152,   153,
     110,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   301,   178,   277,   124,   125,   187,   126,
     127,   188,   128,   129,   130,   131,   331,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,    65,   205,
     205,   208,   118,   119,   120,   209,   267,     4,   326,   190,
     -35,   328,   192,     5,    -2,   121,   210,   122,   123,   124,
     125,    69,   126,   127,   283,   128,   129,   130,   131,   182,
     183,   116,   184,    -2,    -2,    -2,   130,   131,   284,   285,
     128,   129,   130,   131,   189,   114,   253,   191,   254,   255,
      70,   256,   257,   104,   258,   185,   259,   186,   280,   268,
     269,   118,   119,   120,   124,   125,    71,   126,   127,    72,
     128,   129,   130,   131,   121,   179,   122,   123,   124,   125,
     265,   126,   127,    73,   128,   129,   130,   131,   126,   127,
     271,   128,   129,   130,   131,   314,   287,   289,    74,   272,
     124,   125,   273,   126,   127,    75,   128,   129,   130,   131,
     185,   274,   219,   185,   260,   222,   124,   125,    76,   126,
     127,   275,   128,   129,   130,   131,   185,    77,   223,   279,
     276,   205,    78,   124,   125,   282,   126,   127,    79,   128,
     129,   130,   131,    80,    81,   296,    82,   292,   124,   125,
     298,   126,   127,   299,   128,   129,   130,   131,   308,   124,
     125,   306,   126,   127,   307,   128,   129,   130,   131,   310,
     311,   185,   220,   224,    83,    84,   320,   321,   124,   125,
      85,   126,   127,    86,   128,   129,   130,   131,   182,   183,
     262,   184,   263,   315,   333,   316,    87,    88,    89,    90,
     338,    91,    92,   343,    93,   341,   342,     7,    94,     9,
      10,    11,    12,    13,    14,    95,    15,    16,    17,    18,
      96,    97,    98,    99,   100,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,   124,   125,   101,   126,   127,    49,
     128,   129,   130,   131,   102,   183,   103,   218,   116,   132,
      51,   134,    52,    53,   135,   154,   177,   214,   181,   230,
      54,   105,   261,   270,   281,   300,   204,     7,     8,     9,
      10,    11,    12,    13,    14,   290,    15,    16,    17,    18,
     297,   303,   312,   327,   334,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,   335,   336,   124,   125,    49,
     126,   127,    50,   128,   129,   130,   131,   337,   339,   264,
      51,   213,    52,    53,   288,   344,   323,     0,     0,   266,
      54,    55,     7,     8,     9,    10,    11,    12,    13,    14,
       0,    15,    16,    17,    18,     0,     0,     0,     0,     0,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
       0,     0,   124,   125,    49,   126,   127,     0,   128,   129,
     130,   131,     0,     0,   278,    51,     0,    52,    53,     0,
       0,     0,     0,     0,     0,    54,    55,     7,     0,     9,
      10,    11,    12,    13,    14,     0,    15,    16,    17,    18,
       0,     0,     0,     0,     0,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,   124,   125,     0,   126,   127,    49,
     128,   129,   130,   131,     0,     0,     0,   225,     0,     0,
      51,     0,    52,    53,     0,     0,     0,     0,     0,     0,
      54,   105,   124,   125,     0,   126,   127,     0,   128,   129,
     130,   131,     0,   124,   125,   226,   126,   127,     0,   128,
     129,   130,   131,     0,   124,   125,   227,   126,   127,     0,
     128,   129,   130,   131,     0,   124,   125,   228,   126,   127,
       0,   128,   129,   130,   131,     0,   124,   125,   229,   126,
     127,     0,   128,   129,   130,   131,     0,   124,   125,   231,
     126,   127,     0,   128,   129,   130,   131,     0,   124,   125,
     232,   126,   127,     0,   128,   129,   130,   131,     0,   124,
     125,   234,   126,   127,     0,   128,   129,   130,   131,     0,
     124,   125,   235,   126,   127,     0,   128,   129,   130,   131,
       0,   124,   125,   236,   126,   127,     0,   128,   129,   130,
     131,     0,   124,   125,   237,   126,   127,     0,   128,   129,
     130,   131,     0,   124,   125,   238,   126,   127,     0,   128,
     129,   130,   131,     0,   124,   125,   239,   126,   127,     0,
     128,   129,   130,   131,     0,   124,   125,   240,   126,   127,
       0,   128,   129,   130,   131,     0,   124,   125,   241,   126,
     127,     0,   128,   129,   130,   131,     0,   124,   125,   243,
     126,   127,     0,   128,   129,   130,   131,     0,   124,   125,
     244,   126,   127,     0,   128,   129,   130,   131,     0,   124,
     125,   245,   126,   127,     0,   128,   129,   130,   131,     0,
     124,   125,   246,   126,   127,     0,   128,   129,   130,   131,
       0,   124,   125,   247,   126,   127,     0,   128,   129,   130,
     131,     0,   124,   125,   248,   126,   127,     0,   128,   129,
     130,   131,     0,   124,   125,   249,   126,   127,     0,   128,
     129,   130,   131,     0,   124,   125,   250,   126,   127,     0,
     128,   129,   130,   131,     0,   124,   125,   251,   126,   127,
       0,   128,   129,   130,   131,     0,   124,   125,   291,   126,
     127,     0,   128,   129,   130,   131,     0,   124,   125,   293,
     126,   127,     0,   128,   129,   130,   131,     0,   124,   125,
     294,   126,   127,     0,   128,   129,   130,   131,     0,   124,
     125,   318,   126,   127,     0,   128,   129,   130,   131,     0,
     124,   125,   340,   126,   127,     0,   128,   129,   130,   131,
     124,   125,   309,   126,   127,     0,   128,   129,   130,   131,
       0,   180,   124,   125,     0,   126,   127,     0,   128,   129,
     130,   131,     0,   221,   124,   125,     0,   126,   127,     0,
     128,   129,   130,   131,     0,   183,   124,   125,     0,   126,
     127,     0,   128,   129,   130,   131,     0,   233,   124,   125,
       0,   126,   127,     0,   128,   129,   130,   131,     0,   242,
     124,   125,     0,   126,   127,     0,   128,   129,   130,   131,
       0,   252,   124,   125,     0,   126,   127,     0,   128,   129,
     130,   131,     0,   295,   124,   125,     0,   126,   127,     0,
     128,   129,   130,   131,     0,   317,   124,   125,     0,   126,
     127,     0,   128,   129,   130,   131,   116,   124,   125,     0,
     126,   127,     0,   128,   129,   130,   131
};

static const yytype_int16 yycheck[] =
{
      51,    52,    53,    54,    55,    60,   134,   131,     4,     5,
      21,     5,    70,    20,    21,    73,    74,    75,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      55,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,    64,   105,    68,    69,    70,    79,    72,
      73,    82,    75,    76,    77,    78,    62,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,    72,   130,
     131,   132,    52,    53,    54,    54,   214,     0,   319,   114,
      58,   322,   117,    19,     0,    65,    65,    67,    68,    69,
      70,    54,    72,    73,    51,    75,    76,    77,    78,    79,
      80,    79,    82,    19,    20,    21,    77,    78,    65,    66,
      75,    76,    77,    78,   114,    79,   177,   117,   179,   180,
      78,   182,   183,     5,   185,    80,   187,    82,   262,    79,
      80,    52,    53,    54,    69,    70,    78,    72,    73,    78,
      75,    76,    77,    78,    65,    80,    67,    68,    69,    70,
     211,    72,    73,    78,    75,    76,    77,    78,    72,    73,
     221,    75,    76,    77,    78,   303,   268,   269,    78,   230,
      69,    70,   233,    72,    73,    78,    75,    76,    77,    78,
      80,   242,    82,    80,    83,    82,    69,    70,    78,    72,
      73,   252,    75,    76,    77,    78,    80,    78,    82,   260,
      83,   262,    78,    69,    70,   266,    72,    73,    78,    75,
      76,    77,    78,    78,    78,   276,    78,    83,    69,    70,
     281,    72,    73,   284,    75,    76,    77,    78,    79,    69,
      70,   292,    72,    73,   295,    75,    76,    77,    78,   300,
     301,    80,    82,    82,    78,    78,   311,   312,    69,    70,
      78,    72,    73,    78,    75,    76,    77,    78,    79,    80,
      80,    82,    82,    80,   325,    82,    78,    78,    78,    78,
     331,    78,    78,   338,    78,   336,   337,     4,    78,     6,
       7,     8,     9,    10,    11,    78,    13,    14,    15,    16,
      78,    78,    78,    78,    78,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    69,    70,    78,    72,    73,    56,
      75,    76,    77,    78,    78,    80,    78,    82,    79,    77,
      67,     5,    69,    70,    79,     5,    54,     5,    82,    54,
      77,    78,    81,     5,    77,    65,    83,     4,     5,     6,
       7,     8,     9,    10,    11,    78,    13,    14,    15,    16,
      82,     5,    63,    58,    58,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    58,    54,    69,    70,    56,
      72,    73,    59,    75,    76,    77,    78,    54,    79,    81,
      67,   135,    69,    70,   268,    58,   315,    -1,    -1,   212,
      77,    78,     4,     5,     6,     7,     8,     9,    10,    11,
      -1,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      -1,    -1,    69,    70,    56,    72,    73,    -1,    75,    76,
      77,    78,    -1,    -1,    81,    67,    -1,    69,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    77,    78,     4,    -1,     6,
       7,     8,     9,    10,    11,    -1,    13,    14,    15,    16,
      -1,    -1,    -1,    -1,    -1,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    69,    70,    -1,    72,    73,    56,
      75,    76,    77,    78,    -1,    -1,    -1,    82,    -1,    -1,
      67,    -1,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,
      77,    78,    69,    70,    -1,    72,    73,    -1,    75,    76,
      77,    78,    -1,    69,    70,    82,    72,    73,    -1,    75,
      76,    77,    78,    -1,    69,    70,    82,    72,    73,    -1,
      75,    76,    77,    78,    -1,    69,    70,    82,    72,    73,
      -1,    75,    76,    77,    78,    -1,    69,    70,    82,    72,
      73,    -1,    75,    76,    77,    78,    -1,    69,    70,    82,
      72,    73,    -1,    75,    76,    77,    78,    -1,    69,    70,
      82,    72,    73,    -1,    75,    76,    77,    78,    -1,    69,
      70,    82,    72,    73,    -1,    75,    76,    77,    78,    -1,
      69,    70,    82,    72,    73,    -1,    75,    76,    77,    78,
      -1,    69,    70,    82,    72,    73,    -1,    75,    76,    77,
      78,    -1,    69,    70,    82,    72,    73,    -1,    75,    76,
      77,    78,    -1,    69,    70,    82,    72,    73,    -1,    75,
      76,    77,    78,    -1,    69,    70,    82,    72,    73,    -1,
      75,    76,    77,    78,    -1,    69,    70,    82,    72,    73,
      -1,    75,    76,    77,    78,    -1,    69,    70,    82,    72,
      73,    -1,    75,    76,    77,    78,    -1,    69,    70,    82,
      72,    73,    -1,    75,    76,    77,    78,    -1,    69,    70,
      82,    72,    73,    -1,    75,    76,    77,    78,    -1,    69,
      70,    82,    72,    73,    -1,    75,    76,    77,    78,    -1,
      69,    70,    82,    72,    73,    -1,    75,    76,    77,    78,
      -1,    69,    70,    82,    72,    73,    -1,    75,    76,    77,
      78,    -1,    69,    70,    82,    72,    73,    -1,    75,    76,
      77,    78,    -1,    69,    70,    82,    72,    73,    -1,    75,
      76,    77,    78,    -1,    69,    70,    82,    72,    73,    -1,
      75,    76,    77,    78,    -1,    69,    70,    82,    72,    73,
      -1,    75,    76,    77,    78,    -1,    69,    70,    82,    72,
      73,    -1,    75,    76,    77,    78,    -1,    69,    70,    82,
      72,    73,    -1,    75,    76,    77,    78,    -1,    69,    70,
      82,    72,    73,    -1,    75,    76,    77,    78,    -1,    69,
      70,    82,    72,    73,    -1,    75,    76,    77,    78,    -1,
      69,    70,    82,    72,    73,    -1,    75,    76,    77,    78,
      69,    70,    81,    72,    73,    -1,    75,    76,    77,    78,
      -1,    80,    69,    70,    -1,    72,    73,    -1,    75,    76,
      77,    78,    -1,    80,    69,    70,    -1,    72,    73,    -1,
      75,    76,    77,    78,    -1,    80,    69,    70,    -1,    72,
      73,    -1,    75,    76,    77,    78,    -1,    80,    69,    70,
      -1,    72,    73,    -1,    75,    76,    77,    78,    -1,    80,
      69,    70,    -1,    72,    73,    -1,    75,    76,    77,    78,
      -1,    80,    69,    70,    -1,    72,    73,    -1,    75,    76,
      77,    78,    -1,    80,    69,    70,    -1,    72,    73,    -1,
      75,    76,    77,    78,    -1,    80,    69,    70,    -1,    72,
      73,    -1,    75,    76,    77,    78,    79,    69,    70,    -1,
      72,    73,    -1,    75,    76,    77,    78
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    85,    86,    87,     0,    19,    90,     4,     5,     6,
       7,     8,     9,    10,    11,    13,    14,    15,    16,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    56,
      59,    67,    69,    70,    77,    78,    89,    98,   110,   111,
     112,   113,   115,   116,     5,    72,    91,    92,    99,    54,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,     5,    78,   116,   116,   116,   116,
     115,   116,   118,   119,    79,   102,    79,   102,    52,    53,
      54,    65,    67,    68,    69,    70,    72,    73,    75,    76,
      77,    78,    77,    97,     5,    79,    20,    21,    88,   100,
     116,   116,   118,   116,   116,   116,   118,   118,   118,   116,
     116,   116,   116,   116,     5,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,    54,   116,    80,
      80,    82,    79,    80,    82,    80,    82,    79,    82,   113,
     115,   113,   115,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,    83,   116,   120,   120,   116,    54,
      65,    94,    97,    92,     5,    95,    96,   101,    82,    82,
      82,    80,    82,    82,    82,    82,    82,    82,    82,    82,
      54,    82,    82,    80,    82,    82,    82,    82,    82,    82,
      82,    82,    80,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    80,   116,   116,   116,   116,   116,   116,   116,
      83,    81,    80,    82,    81,   116,    94,    97,    79,    80,
       5,   116,   116,   116,   116,   116,    83,    68,    81,   116,
     120,    77,   116,    51,    65,    66,    93,    96,    99,    96,
      78,    82,    83,    82,    82,    80,   116,    82,   116,   116,
      65,    64,   107,     5,   103,   104,   116,   116,    79,    81,
     116,   116,    63,   108,    97,    80,    82,    80,    82,   114,
     102,   102,   109,   104,   105,   117,   110,    58,   110,     4,
       5,    62,   106,   116,    58,    58,    54,    54,   116,    79,
      82,   116,   116,   102,    58
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    84,    86,    85,    87,    85,    88,    88,    89,    90,
      90,    90,    91,    91,    92,    92,    93,    93,    94,    94,
      95,    95,    95,    96,    96,    96,    97,    97,    97,    98,
      99,    99,   101,   100,   102,   102,   103,   103,   104,   105,
     105,   106,   106,   107,   107,   108,   109,   108,   108,   110,
     110,   111,   111,   111,   112,   112,   112,   114,   113,   115,
     115,   115,   115,   115,   115,   115,   115,   115,   116,   116,
     116,   116,   116,   116,   117,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   118,   118,   119,
     119,   120,   120,   120
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     4,     0,     2,     6,     0,     1,     0,
       1,     3,     1,     3,     4,     5,     1,     1,     1,     1,
       1,     3,     3,     2,     4,     5,     0,     3,     6,     5,
       2,     0,     0,    11,     1,     0,     3,     1,     2,     3,
       0,     3,     3,     0,     3,     0,     0,     4,     3,     2,
       2,     3,     3,     1,     3,     3,     1,     0,    10,     3,
       3,     3,     3,     3,     3,     4,     3,     3,     3,     3,
       3,     3,     4,     4,     0,    11,     6,     2,     4,     4,
       2,     4,     4,     6,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       8,     2,     3,     5,     3,     4,     4,     6,     3,     3,
       1,     1,     1,     1,     4,     4,     1,     1,     1,     1,
       1,     4,     4,     4,     4,     4,     6,     3,     3,     3,
       3,     1,     1,     3
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
  case 2: /* $@1: %empty  */
#line 94 "parser/parser.yc"
                                                { pstruct->begin(); }
#line 1567 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 3: /* program: $@1 decl_opt_cst decl_opt_fncs system_or_func  */
#line 97 "parser/parser.yc"
                                                { pstruct->end(); }
#line 1573 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 4: /* $@2: %empty  */
#line 98 "parser/parser.yc"
                                                { pstruct->begin(); 
                                                  pstruct->scope().push(); /* new scope for temporary symbols */}
#line 1580 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 5: /* program: $@2 choco_ctr  */
#line 100 "parser/parser.yc"
                                                { pstruct->scope().pop();
                                                  pstruct->end(); }
#line 1587 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 8: /* choco_ctr: ctr_blk_list  */
#line 111 "parser/parser.yc"
                                                { pstruct->source.ctrs=new P_ConstraintList((yyvsp[0].constraints)); }
#line 1593 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 14: /* decl_cst: TK_NEW_SYMBOL dimension equ_or_in expr  */
#line 128 "parser/parser.yc"
                                                { Domain* d=new Domain(*(yyvsp[-2].dim));
                                                  init_symbol_domain((yyvsp[-3].str), *d, (yyvsp[0].expression)->_2domain());
                                                  pstruct->scope().add_cst((yyvsp[-3].str), *d, false); 
                                                  delete d;
                                                  free((yyvsp[-3].str)); delete (yyvsp[-2].dim); delete (yyvsp[0].expression); }
#line 1603 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 15: /* decl_cst: '*' TK_NEW_SYMBOL dimension equ_or_in expr  */
#line 134 "parser/parser.yc"
                                                { Domain* d=new Domain(*(yyvsp[-2].dim));
                                                  init_symbol_domain((yyvsp[-3].str), *d, (yyvsp[0].expression)->_2domain());
                                                  pstruct->source.mutable_constants.insert_new((yyvsp[-3].str),d);
                                                  pstruct->scope().add_cst((yyvsp[-3].str), *d, true); 
                                                  // note: d will be deleted by ~System().
                                                  free((yyvsp[-3].str)); delete (yyvsp[-2].dim); delete (yyvsp[0].expression); }
#line 1614 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 23: /* decl_var: TK_NEW_SYMBOL dimension  */
#line 151 "parser/parser.yc"
                                                { pstruct->scope().add_var((yyvsp[-1].str),(yyvsp[0].dim));  
		                                          free((yyvsp[-1].str)); delete (yyvsp[0].dim); }
#line 1621 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 24: /* decl_var: TK_NEW_SYMBOL dimension TK_IN expr  */
#line 154 "parser/parser.yc"
                                                    { pstruct->scope().add_var((yyvsp[-3].str),(yyvsp[-2].dim),(yyvsp[0].expression)->_2domain()); 
						                          free((yyvsp[-3].str)); delete (yyvsp[-2].dim); delete (yyvsp[0].expression); }
#line 1628 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 25: /* decl_var: TK_NEW_SYMBOL dimension decl_var_integer TK_IN expr  */
#line 157 "parser/parser.yc"
                                                                    { pstruct->scope().add_int_var((yyvsp[-4].str),(yyvsp[-3].dim),(yyvsp[0].expression)->_2domain()); 
						                          free((yyvsp[-4].str)); delete (yyvsp[-3].dim); delete (yyvsp[0].expression); }
#line 1635 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 26: /* dimension: %empty  */
#line 164 "parser/parser.yc"
                                                { (yyval.dim)=new Dim(); }
#line 1641 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 27: /* dimension: '[' expr ']'  */
#line 165 "parser/parser.yc"
                                                { (yyval.dim)=new Dim(Dim::col_vec((yyvsp[-1].expression)->_2int())); 
                                                  delete (yyvsp[-1].expression);  }
#line 1648 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 28: /* dimension: '[' expr ']' '[' expr ']'  */
#line 167 "parser/parser.yc"
                                                { (yyval.dim)=new Dim(Dim::matrix((yyvsp[-4].expression)->_2int(),(yyvsp[-1].expression)->_2int())); 
                                                  delete (yyvsp[-4].expression); delete (yyvsp[-1].expression); }
#line 1655 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 29: /* interval: '[' expr ',' expr ']'  */
#line 171 "parser/parser.yc"
                                                { (yyval.itv)=new Interval((yyvsp[-3].expression)->_2dbl(true), (yyvsp[-1].expression)->_2dbl(false)); 
                                                  delete (yyvsp[-3].expression); delete (yyvsp[-1].expression); }
#line 1662 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 32: /* $@3: %empty  */
#line 183 "parser/parser.yc"
                                                { pstruct->begin_function(); }
#line 1668 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 33: /* function: TK_FUNCTION $@3 TK_NEW_SYMBOL '(' fnc_inpt_list ')' fnc_code TK_RETURN expr semicolon_opt TK_END  */
#line 188 "parser/parser.yc"
                                                { 
                                                  pstruct->end_function((yyvsp[-8].str),*(yyvsp[-2].expression));        
                                                  free((yyvsp[-8].str)); delete (yyvsp[-2].expression);
                                                 }
#line 1677 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 38: /* fnc_input: TK_NEW_SYMBOL dimension  */
#line 200 "parser/parser.yc"
                                                { pstruct->scope().add_var((yyvsp[-1].str),(yyvsp[0].dim));
                                                  free((yyvsp[-1].str)); delete (yyvsp[0].dim); }
#line 1684 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 41: /* fnc_assign: TK_NEW_SYMBOL TK_EQU expr  */
#line 208 "parser/parser.yc"
                                                { /* TODO: if this tmp symbol is not used, the generated expr will never be deleted */
                                                  pstruct->scope().add_expr_tmp_symbol((yyvsp[-2].str),&(yyvsp[0].expression)->generate()); free((yyvsp[-2].str)); delete (yyvsp[0].expression); }
#line 1691 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 42: /* fnc_assign: TK_CONSTANT TK_EQU expr  */
#line 210 "parser/parser.yc"
                                                { cerr << "Warning: line " << ibex_lineno << ", local variable " << (yyvsp[-2].str) << " shadows the constant of the same name\n"; 
                                                  pstruct->scope().add_expr_tmp_symbol((yyvsp[-2].str),&(yyvsp[0].expression)->generate()); free((yyvsp[-2].str)); delete (yyvsp[0].expression); }
#line 1698 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 43: /* decl_opt_goal: %empty  */
#line 217 "parser/parser.yc"
                                                { pstruct->source.goal = NULL; }
#line 1704 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 44: /* decl_opt_goal: TK_MINIMIZE expr semicolon_opt  */
#line 218 "parser/parser.yc"
                                                { pstruct->source.goal = (yyvsp[-1].expression); }
#line 1710 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 46: /* $@4: %empty  */
#line 226 "parser/parser.yc"
                                                { pstruct->scope().push(); /* new scope for temporary symbols */ }
#line 1716 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 47: /* decl_opt_ctrs: TK_CTRS $@4 ctr_blk_list TK_END  */
#line 227 "parser/parser.yc"
                                                { pstruct->source.ctrs=new P_ConstraintList((yyvsp[-1].constraints));
                                                  pstruct->scope().pop(); }
#line 1723 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 48: /* decl_opt_ctrs: TK_CTRS semicolon_opt TK_END  */
#line 229 "parser/parser.yc"
                                                { pstruct->source.ctrs=new P_ConstraintList(new vector<P_NumConstraint*>()); }
#line 1729 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 49: /* ctr_blk_list: ctr_blk_list1 semicolon_opt  */
#line 232 "parser/parser.yc"
                                                { (yyval.constraints) = (yyvsp[-1].constraints); }
#line 1735 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 50: /* ctr_blk_list: ctr_blk_list2 semicolon_opt  */
#line 233 "parser/parser.yc"
                                                { (yyval.constraints) = (yyvsp[-1].constraints); }
#line 1741 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 51: /* ctr_blk_list1: ctr_blk_list1 ';' ctr  */
#line 236 "parser/parser.yc"
                                                { (yyvsp[-2].constraints)->push_back((yyvsp[0].constraint)); (yyval.constraints) = (yyvsp[-2].constraints); }
#line 1747 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 52: /* ctr_blk_list1: ctr_blk_list2 semicolon_opt ctr  */
#line 237 "parser/parser.yc"
                                                            { (yyvsp[-2].constraints)->push_back((yyvsp[0].constraint)); (yyval.constraints) = (yyvsp[-2].constraints); }
#line 1753 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 53: /* ctr_blk_list1: ctr  */
#line 238 "parser/parser.yc"
                                                { (yyval.constraints) = new vector<P_NumConstraint*>();
                                                  (yyval.constraints)->push_back((yyvsp[0].constraint)); }
#line 1760 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 54: /* ctr_blk_list2: ctr_blk_list1 ';' ctr_loop  */
#line 242 "parser/parser.yc"
                                                { (yyvsp[-2].constraints)->push_back((yyvsp[0].constraint)); (yyval.constraints) = (yyvsp[-2].constraints); }
#line 1766 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 55: /* ctr_blk_list2: ctr_blk_list2 semicolon_opt ctr_loop  */
#line 244 "parser/parser.yc"
                                                            { (yyvsp[-2].constraints)->push_back((yyvsp[0].constraint)); (yyval.constraints) = (yyvsp[-2].constraints); }
#line 1772 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 56: /* ctr_blk_list2: ctr_loop  */
#line 245 "parser/parser.yc"
                                                { (yyval.constraints) = new vector<P_NumConstraint*>();
                                                  (yyval.constraints)->push_back((yyvsp[0].constraint)); }
#line 1779 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 57: /* $@5: %empty  */
#line 250 "parser/parser.yc"
                                                { pstruct->scope().push();
                                                  pstruct->scope().add_iterator((yyvsp[-5].str)); }
#line 1786 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 58: /* ctr_loop: TK_FOR TK_NEW_SYMBOL TK_EQU expr ':' expr ';' $@5 ctr_blk_list TK_END  */
#line 253 "parser/parser.yc"
                                                { (yyval.constraint) = new P_ConstraintLoop((yyvsp[-8].str), (yyvsp[-6].expression), (yyvsp[-4].expression), (yyvsp[-1].constraints)); 
                                                  pstruct->scope().pop();
                                                  free((yyvsp[-8].str)); }
#line 1794 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 59: /* ctr: expr TK_EQU expr  */
#line 258 "parser/parser.yc"
                                                { (yyval.constraint) = new P_OneConstraint((yyvsp[-2].expression),EQ,(yyvsp[0].expression)); }
#line 1800 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 60: /* ctr: expr TK_LEQ expr  */
#line 259 "parser/parser.yc"
                                                { (yyval.constraint) = new P_OneConstraint((yyvsp[-2].expression),LEQ,(yyvsp[0].expression)); }
#line 1806 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 61: /* ctr: expr TK_GEQ expr  */
#line 260 "parser/parser.yc"
                                                { (yyval.constraint) = new P_OneConstraint((yyvsp[-2].expression),GEQ,(yyvsp[0].expression)); }
#line 1812 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 62: /* ctr: expr '<' expr  */
#line 261 "parser/parser.yc"
                                                { (yyval.constraint) = new P_OneConstraint((yyvsp[-2].expression),LT,(yyvsp[0].expression)); }
#line 1818 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 63: /* ctr: expr '>' expr  */
#line 262 "parser/parser.yc"
                                                { (yyval.constraint) = new P_OneConstraint((yyvsp[-2].expression),GT,(yyvsp[0].expression)); }
#line 1824 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 64: /* ctr: expr TK_IN expr  */
#line 263 "parser/parser.yc"
                                                { (yyval.constraint) = new P_ThickEquality((yyvsp[-2].expression),(yyvsp[0].expression)->_2itv()); delete (yyvsp[0].expression); }
#line 1830 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 65: /* ctr: TK_INTEGER '(' expr ')'  */
#line 264 "parser/parser.yc"
                                                { (yyval.constraint) = new P_OneConstraint(saw((yyvsp[-1].expression)),EQ,NULL); }
#line 1836 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 66: /* ctr: '(' ctr ')'  */
#line 265 "parser/parser.yc"
                                                { (yyval.constraint) = (yyvsp[-1].constraint); }
#line 1842 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 67: /* ctr: TK_NEW_SYMBOL TK_EQU expr  */
#line 266 "parser/parser.yc"
                                                { (yyval.constraint) = new P_TmpSymbolDecl((yyvsp[-2].str),(yyvsp[0].expression)); 
                                                  pstruct->scope().add_expr_tmp_symbol((yyvsp[-2].str)); free((yyvsp[-2].str)); }
#line 1849 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 68: /* expr: expr '+' expr  */
#line 274 "parser/parser.yc"
                                                { (yyval.expression) = *(yyvsp[-2].expression) + *(yyvsp[0].expression);     }
#line 1855 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 69: /* expr: expr '*' expr  */
#line 275 "parser/parser.yc"
                                                { (yyval.expression) = *(yyvsp[-2].expression) * *(yyvsp[0].expression);     }
#line 1861 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 70: /* expr: expr '-' expr  */
#line 276 "parser/parser.yc"
                                                { (yyval.expression) = *(yyvsp[-2].expression) - *(yyvsp[0].expression);     }
#line 1867 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 71: /* expr: expr '/' expr  */
#line 277 "parser/parser.yc"
                                                { (yyval.expression) = *(yyvsp[-2].expression) / *(yyvsp[0].expression);     }
#line 1873 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 72: /* expr: TK_MAX '(' expr_row ')'  */
#line 278 "parser/parser.yc"
                                                { (yyval.expression) = max((yyvsp[-1].expressions)); delete (yyvsp[-1].expressions); }
#line 1879 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 73: /* expr: TK_MIN '(' expr_row ')'  */
#line 279 "parser/parser.yc"
                                                { (yyval.expression) = min((yyvsp[-1].expressions)); delete (yyvsp[-1].expressions); }
#line 1885 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 74: /* $@6: %empty  */
#line 281 "parser/parser.yc"
                                                { pstruct->scope().push();
                                                  pstruct->scope().add_iterator((yyvsp[-5].str)); }
#line 1892 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 75: /* expr: TK_SUM '(' TK_NEW_SYMBOL TK_EQU expr ':' expr ',' $@6 expr ')'  */
#line 283 "parser/parser.yc"
                                                { (yyval.expression) = sum((yyvsp[-1].expression), (yyvsp[-8].str), (yyvsp[-6].expression), (yyvsp[-4].expression));
                                                  pstruct->scope().pop();
                                                  free((yyvsp[-8].str)); }
#line 1900 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 76: /* expr: TK_ATAN2 '(' expr ',' expr ')'  */
#line 286 "parser/parser.yc"
                                                { (yyval.expression) = atan2((yyvsp[-3].expression),(yyvsp[-1].expression));  }
#line 1906 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 77: /* expr: '-' expr  */
#line 287 "parser/parser.yc"
                                                { (yyval.expression) = -*(yyvsp[0].expression);          }
#line 1912 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 78: /* expr: TK_ABS '(' expr ')'  */
#line 288 "parser/parser.yc"
                                                { (yyval.expression) = abs  ((yyvsp[-1].expression));     }
#line 1918 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 79: /* expr: TK_SIGN '(' expr ')'  */
#line 289 "parser/parser.yc"
                                                { (yyval.expression) = sign ((yyvsp[-1].expression));     }
#line 1924 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 80: /* expr: expr '\''  */
#line 290 "parser/parser.yc"
                                                    { (yyval.expression) = transpose((yyvsp[-1].expression)); }
#line 1930 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 81: /* expr: TK_SQRT '(' expr ')'  */
#line 291 "parser/parser.yc"
                                                { (yyval.expression) = sqrt ((yyvsp[-1].expression));     }
#line 1936 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 82: /* expr: TK_SQR '(' expr ')'  */
#line 292 "parser/parser.yc"
                                                { (yyval.expression) = sqr ((yyvsp[-1].expression));      }
#line 1942 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 83: /* expr: TK_POW '(' expr ',' expr ')'  */
#line 293 "parser/parser.yc"
                                                { (yyval.expression) = pow((yyvsp[-3].expression), (yyvsp[-1].expression));   }
#line 1948 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 84: /* expr: TK_EXPO '(' expr ')'  */
#line 294 "parser/parser.yc"
                                                { (yyval.expression) = exp  ((yyvsp[-1].expression));     }
#line 1954 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 85: /* expr: TK_LOG '(' expr ')'  */
#line 295 "parser/parser.yc"
                                                { (yyval.expression) = log  ((yyvsp[-1].expression));     }
#line 1960 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 86: /* expr: TK_COS '(' expr ')'  */
#line 296 "parser/parser.yc"
                                                { (yyval.expression) = cos  ((yyvsp[-1].expression));     }
#line 1966 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 87: /* expr: TK_SIN '(' expr ')'  */
#line 297 "parser/parser.yc"
                                                { (yyval.expression) = sin  ((yyvsp[-1].expression));     }
#line 1972 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 88: /* expr: TK_TAN '(' expr ')'  */
#line 298 "parser/parser.yc"
                                                { (yyval.expression) = tan  ((yyvsp[-1].expression));     }
#line 1978 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 89: /* expr: TK_ACOS '(' expr ')'  */
#line 299 "parser/parser.yc"
                                                { (yyval.expression) = acos ((yyvsp[-1].expression));     }
#line 1984 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 90: /* expr: TK_ASIN '(' expr ')'  */
#line 300 "parser/parser.yc"
                                                { (yyval.expression) = asin ((yyvsp[-1].expression));     }
#line 1990 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 91: /* expr: TK_ATAN '(' expr ')'  */
#line 301 "parser/parser.yc"
                                                { (yyval.expression) = atan ((yyvsp[-1].expression));     }
#line 1996 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 92: /* expr: TK_COSH '(' expr ')'  */
#line 302 "parser/parser.yc"
                                                { (yyval.expression) = cosh ((yyvsp[-1].expression));     }
#line 2002 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 93: /* expr: TK_SINH '(' expr ')'  */
#line 303 "parser/parser.yc"
                                                { (yyval.expression) = sinh ((yyvsp[-1].expression));     }
#line 2008 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 94: /* expr: TK_TANH '(' expr ')'  */
#line 304 "parser/parser.yc"
                                                { (yyval.expression) = tanh ((yyvsp[-1].expression));     }
#line 2014 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 95: /* expr: TK_ACOSH '(' expr ')'  */
#line 305 "parser/parser.yc"
                                                { (yyval.expression) = acosh((yyvsp[-1].expression));     }
#line 2020 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 96: /* expr: TK_ASINH '(' expr ')'  */
#line 306 "parser/parser.yc"
                                                { (yyval.expression) = asinh((yyvsp[-1].expression));     }
#line 2026 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 97: /* expr: TK_ATANH '(' expr ')'  */
#line 307 "parser/parser.yc"
                                                { (yyval.expression) = atanh((yyvsp[-1].expression));     }
#line 2032 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 98: /* expr: TK_FLOOR '(' expr ')'  */
#line 308 "parser/parser.yc"
                                                { (yyval.expression) = floor((yyvsp[-1].expression));     }
#line 2038 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 99: /* expr: TK_CEIL '(' expr ')'  */
#line 309 "parser/parser.yc"
                                                { (yyval.expression) = ceil((yyvsp[-1].expression));      }
#line 2044 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 100: /* expr: TK_CHI '(' expr ',' expr ',' expr ')'  */
#line 311 "parser/parser.yc"
                                                { (yyval.expression) = chi((yyvsp[-5].expression),(yyvsp[-3].expression),(yyvsp[-1].expression)); }
#line 2050 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 101: /* expr: '+' expr  */
#line 312 "parser/parser.yc"
                                                { (yyval.expression) = (yyvsp[0].expression); }
#line 2056 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 102: /* expr: '(' expr ')'  */
#line 313 "parser/parser.yc"
                                                    { (yyval.expression) = (yyvsp[-1].expression); }
#line 2062 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 103: /* expr: '<' expr ',' expr '>'  */
#line 314 "parser/parser.yc"
                                                { (yyval.expression) = new P_ExprConstant(ball((yyvsp[-3].expression)->_2domain(),(yyvsp[-1].expression)->_2dbl(false))); }
#line 2068 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 104: /* expr: expr '^' expr  */
#line 315 "parser/parser.yc"
                                                { (yyval.expression) = pow((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2074 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 105: /* expr: expr '[' expr_index ']'  */
#line 316 "parser/parser.yc"
                                                { (yyval.expression) = expr_with_index((yyvsp[-3].expression),(yyvsp[-1].expression),false);  }
#line 2080 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 106: /* expr: expr '(' expr_index ')'  */
#line 317 "parser/parser.yc"
                                                { (yyval.expression) = expr_with_index((yyvsp[-3].expression),(yyvsp[-1].expression),true); }
#line 2086 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 107: /* expr: expr '(' expr_index ',' expr_index ')'  */
#line 319 "parser/parser.yc"
                                                { (yyval.expression) = expr_with_index((yyvsp[-5].expression),(yyvsp[-3].expression),(yyvsp[-1].expression),true); }
#line 2092 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 108: /* expr: '(' expr_row ')'  */
#line 320 "parser/parser.yc"
                                                { (yyval.expression) = row_vec((yyvsp[-1].expressions)); delete (yyvsp[-1].expressions); }
#line 2098 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 109: /* expr: '(' expr_col ')'  */
#line 321 "parser/parser.yc"
                                                { (yyval.expression) = col_vec((yyvsp[-1].expressions)); delete (yyvsp[-1].expressions); }
#line 2104 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 110: /* expr: TK_ENTITY  */
#line 322 "parser/parser.yc"
                                                { (yyval.expression) = new P_ExprVarSymbol((yyvsp[0].str)); free((yyvsp[0].str)); /* cannot happen inside a function expr */}
#line 2110 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 111: /* expr: TK_ITERATOR  */
#line 323 "parser/parser.yc"
                                                { (yyval.expression) = new P_ExprIter((yyvsp[0].str)); free((yyvsp[0].str)); }
#line 2116 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 112: /* expr: TK_EXPR_TMP_SYMBOL  */
#line 324 "parser/parser.yc"
                                                { (yyval.expression) = new P_ExprTmpSymbol((yyvsp[0].str)); free((yyvsp[0].str)); /* not this (we do **not** build DAG with P_ExprNodes!) ---> &pstruct->scope().get_tmp_expr_node($1); */ }
#line 2122 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 113: /* expr: TK_CONSTANT  */
#line 325 "parser/parser.yc"
                                                { (yyval.expression) = new P_ExprCstSymbol((yyvsp[0].str)); free((yyvsp[0].str)); }
#line 2128 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 114: /* expr: TK_FUNC_SYMBOL '(' expr ')'  */
#line 326 "parser/parser.yc"
                                                { (yyval.expression) = apply(pstruct->scope().get_func((yyvsp[-3].str)), *(yyvsp[-1].expression)); free((yyvsp[-3].str)); }
#line 2134 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 115: /* expr: TK_FUNC_SYMBOL '(' expr_row ')'  */
#line 327 "parser/parser.yc"
                                                { (yyval.expression) = apply(pstruct->scope().get_func((yyvsp[-3].str)), *(yyvsp[-1].expressions)); free((yyvsp[-3].str)); delete (yyvsp[-1].expressions); }
#line 2140 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 116: /* expr: TK_FLOAT  */
#line 329 "parser/parser.yc"
                                                { (yyval.expression) = new P_ExprConstant((yyvsp[0].real)); }
#line 2146 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 117: /* expr: TK_PI  */
#line 330 "parser/parser.yc"
                                                { (yyval.expression) = new P_ExprConstant(Interval::pi()); }
#line 2152 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 118: /* expr: TK_INFINITY  */
#line 331 "parser/parser.yc"
                                                { (yyval.expression) = dbl_infinity(); }
#line 2158 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 119: /* expr: TK_INT_CST  */
#line 332 "parser/parser.yc"
                                                { (yyval.expression) = new P_ExprConstant((yyvsp[0].itg)); }
#line 2164 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 120: /* expr: interval  */
#line 333 "parser/parser.yc"
                                                { (yyval.expression) = new P_ExprConstant(*(yyvsp[0].itv)); delete (yyvsp[0].itv); }
#line 2170 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 121: /* expr: TK_INF '(' expr ')'  */
#line 334 "parser/parser.yc"
                                                { (yyval.expression) = inf((yyvsp[-1].expression)); }
#line 2176 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 122: /* expr: TK_MID '(' expr ')'  */
#line 335 "parser/parser.yc"
                                                { (yyval.expression) = mid((yyvsp[-1].expression)); }
#line 2182 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 123: /* expr: TK_SUP '(' expr ')'  */
#line 336 "parser/parser.yc"
                                                { (yyval.expression) = sup((yyvsp[-1].expression)); }
#line 2188 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 124: /* expr: TK_DIFF '(' expr_row ')'  */
#line 337 "parser/parser.yc"
                                                { (yyval.expression) = diff((yyvsp[-1].expressions)); delete (yyvsp[-1].expressions); }
#line 2194 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 125: /* expr: TK_UNARY_OP '(' expr ')'  */
#line 338 "parser/parser.yc"
                                                { (yyval.expression) = new P_ExprGenericUnaryOp((yyvsp[-3].str),*(yyvsp[-1].expression)); free((yyvsp[-3].str)); }
#line 2200 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 126: /* expr: TK_BINARY_OP '(' expr ',' expr ')'  */
#line 340 "parser/parser.yc"
                                                { (yyval.expression) = new P_ExprGenericBinaryOp((yyvsp[-5].str),*(yyvsp[-3].expression),*(yyvsp[-1].expression)); free((yyvsp[-5].str)); }
#line 2206 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 127: /* expr_row: expr_row ',' expr  */
#line 343 "parser/parser.yc"
                                                { (yyvsp[-2].expressions)->push_back((yyvsp[0].expression)); (yyval.expressions)=(yyvsp[-2].expressions); }
#line 2212 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 128: /* expr_row: expr ',' expr  */
#line 344 "parser/parser.yc"
                                                { (yyval.expressions) = new vector<const P_ExprNode*>(); 
                                                  (yyval.expressions)->push_back((yyvsp[-2].expression)); (yyval.expressions)->push_back((yyvsp[0].expression)); }
#line 2219 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 129: /* expr_col: expr_col ';' expr  */
#line 348 "parser/parser.yc"
                                                { (yyvsp[-2].expressions)->push_back((yyvsp[0].expression)); (yyval.expressions)=(yyvsp[-2].expressions); }
#line 2225 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 130: /* expr_col: expr ';' expr  */
#line 349 "parser/parser.yc"
                                                { (yyval.expressions) = new vector<const P_ExprNode*>(); 
                                                  (yyval.expressions)->push_back((yyvsp[-2].expression)); (yyval.expressions)->push_back((yyvsp[0].expression)); }
#line 2232 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 131: /* expr_index: ':'  */
#line 353 "parser/parser.yc"
                                                { (yyval.expression) = index_all(); }
#line 2238 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 132: /* expr_index: expr  */
#line 354 "parser/parser.yc"
                                                    { (yyval.expression) = index((yyvsp[0].expression)); }
#line 2244 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;

  case 133: /* expr_index: expr ':' expr  */
#line 355 "parser/parser.yc"
                                                { (yyval.expression) = index_range((yyvsp[-2].expression),(yyvsp[0].expression)); }
#line 2250 "/home/research/optimizeripopt/src/parser/parser.tab.cc"
    break;


#line 2254 "/home/research/optimizeripopt/src/parser/parser.tab.cc"

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

