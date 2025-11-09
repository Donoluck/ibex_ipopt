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

#ifndef YY_IBEX_HOME_RESEARCH_OPTIMIZERIPOPT_SRC_PARSER_PARSER_TAB_HH_INCLUDED
# define YY_IBEX_HOME_RESEARCH_OPTIMIZERIPOPT_SRC_PARSER_PARSER_TAB_HH_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int ibexdebug;
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
    TK_CHOCO = 258,                /* TK_CHOCO  */
    TK_CONSTANT = 259,             /* TK_CONSTANT  */
    TK_NEW_SYMBOL = 260,           /* TK_NEW_SYMBOL  */
    TK_FUNC_SYMBOL = 261,          /* TK_FUNC_SYMBOL  */
    TK_EXPR_TMP_SYMBOL = 262,      /* TK_EXPR_TMP_SYMBOL  */
    TK_ENTITY = 263,               /* TK_ENTITY  */
    TK_ITERATOR = 264,             /* TK_ITERATOR  */
    TK_UNARY_OP = 265,             /* TK_UNARY_OP  */
    TK_BINARY_OP = 266,            /* TK_BINARY_OP  */
    TK_STRING = 267,               /* TK_STRING  */
    TK_INT_CST = 268,              /* TK_INT_CST  */
    TK_FLOAT = 269,                /* TK_FLOAT  */
    TK_PI = 270,                   /* TK_PI  */
    TK_INFINITY = 271,             /* TK_INFINITY  */
    TK_BOOL = 272,                 /* TK_BOOL  */
    TK_PARAM = 273,                /* TK_PARAM  */
    TK_CONST = 274,                /* TK_CONST  */
    TK_VARS = 275,                 /* TK_VARS  */
    TK_FUNCTION = 276,             /* TK_FUNCTION  */
    TK_DIFF = 277,                 /* TK_DIFF  */
    TK_MIN = 278,                  /* TK_MIN  */
    TK_MAX = 279,                  /* TK_MAX  */
    TK_INF = 280,                  /* TK_INF  */
    TK_MID = 281,                  /* TK_MID  */
    TK_SUP = 282,                  /* TK_SUP  */
    TK_SIGN = 283,                 /* TK_SIGN  */
    TK_ABS = 284,                  /* TK_ABS  */
    TK_SUM = 285,                  /* TK_SUM  */
    TK_SQRT = 286,                 /* TK_SQRT  */
    TK_SQR = 287,                  /* TK_SQR  */
    TK_POW = 288,                  /* TK_POW  */
    TK_EXPO = 289,                 /* TK_EXPO  */
    TK_LOG = 290,                  /* TK_LOG  */
    TK_COS = 291,                  /* TK_COS  */
    TK_SIN = 292,                  /* TK_SIN  */
    TK_TAN = 293,                  /* TK_TAN  */
    TK_ACOS = 294,                 /* TK_ACOS  */
    TK_ASIN = 295,                 /* TK_ASIN  */
    TK_ATAN = 296,                 /* TK_ATAN  */
    TK_ATAN2 = 297,                /* TK_ATAN2  */
    TK_COSH = 298,                 /* TK_COSH  */
    TK_SINH = 299,                 /* TK_SINH  */
    TK_TANH = 300,                 /* TK_TANH  */
    TK_ACOSH = 301,                /* TK_ACOSH  */
    TK_ASINH = 302,                /* TK_ASINH  */
    TK_ATANH = 303,                /* TK_ATANH  */
    TK_FLOOR = 304,                /* TK_FLOOR  */
    TK_CEIL = 305,                 /* TK_CEIL  */
    TK_INTEGER = 306,              /* TK_INTEGER  */
    TK_LEQ = 307,                  /* TK_LEQ  */
    TK_GEQ = 308,                  /* TK_GEQ  */
    TK_EQU = 309,                  /* TK_EQU  */
    TK_ASSIGN = 310,               /* TK_ASSIGN  */
    TK_CHI = 311,                  /* TK_CHI  */
    TK_BEGIN = 312,                /* TK_BEGIN  */
    TK_END = 313,                  /* TK_END  */
    TK_FOR = 314,                  /* TK_FOR  */
    TK_FROM = 315,                 /* TK_FROM  */
    TK_TO = 316,                   /* TK_TO  */
    TK_RETURN = 317,               /* TK_RETURN  */
    TK_CTRS = 318,                 /* TK_CTRS  */
    TK_MINIMIZE = 319,             /* TK_MINIMIZE  */
    TK_IN = 320,                   /* TK_IN  */
    TK_INT = 321,                  /* TK_INT  */
    TK_UNION = 322,                /* TK_UNION  */
    TK_INTERSEC = 323              /* TK_INTERSEC  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 20 "parser/parser.yc"

  char*     str;
  int       itg;
  double    real;
  
  ibex::Interval* itv;
  
  ibex::Dim*      dim;
  
  ibex::parser::P_NumConstraint*                constraint;
  std::vector<ibex::parser::P_NumConstraint*>*  constraints;

  const ibex::parser::P_ExprNode*               expression;
  std::vector<const ibex::parser::P_ExprNode*>* expressions;


#line 149 "/home/research/optimizeripopt/src/parser/parser.tab.hh"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE ibexlval;


int ibexparse (void);


#endif /* !YY_IBEX_HOME_RESEARCH_OPTIMIZERIPOPT_SRC_PARSER_PARSER_TAB_HH_INCLUDED  */
