/* A Bison parser, made by GNU Bison 3.7.6.  */

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
#define YYBISON 30706

/* Bison version string.  */
#define YYBISON_VERSION "3.7.6"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "c-grammar.y"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "node.h"
#include "hash.h"
#include "var.h"
#include "command.h"

Node *root;

/* 属性操作类型 */
Node *createNode(int name, int num, ...);
Node *set_index(int value);
Node *set_content(int value);
void freeNode(Node *p);
int exeNode(Node *p, int signal);

int yylexeNode(void);
void yyerror(char *s);
void hash_init(HashNode * table[], int size);
void printTree(Node *node);

extern char* yytext;
extern int col;
extern FILE* yyin;
extern FILE* yyout;
extern int yylineno;
extern int yylex(void);
extern HashNode *var_local[HASHSIZE];
extern HashNode *var_local_SorA[HASHSIZE];	/* whether it is scalar or array */
extern HashNode *var_local_GorP[HASHSIZE];	/* general local or param */
extern HashNode *var_global_SorA[HASHSIZE];	/* general local or param *
/*int var[26]; [> 变量数组 <]*/


#line 108 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    CONSTANT = 258,                /* CONSTANT  */
    INT = 259,                     /* INT  */
    VOID = 260,                    /* VOID  */
    IDENTIFIER = 261,              /* IDENTIFIER  */
    STRING_LITERAL = 262,          /* STRING_LITERAL  */
    SIZEOF = 263,                  /* SIZEOF  */
    PTR_OP = 264,                  /* PTR_OP  */
    INC_OP = 265,                  /* INC_OP  */
    DEC_OP = 266,                  /* DEC_OP  */
    LEFT_OP = 267,                 /* LEFT_OP  */
    RIGHT_OP = 268,                /* RIGHT_OP  */
    LE_OP = 269,                   /* LE_OP  */
    GE_OP = 270,                   /* GE_OP  */
    EQ_OP = 271,                   /* EQ_OP  */
    NE_OP = 272,                   /* NE_OP  */
    AND_OP = 273,                  /* AND_OP  */
    OR_OP = 274,                   /* OR_OP  */
    MUL_ASSIGN = 275,              /* MUL_ASSIGN  */
    DIV_ASSIGN = 276,              /* DIV_ASSIGN  */
    MOD_ASSIGN = 277,              /* MOD_ASSIGN  */
    ADD_ASSIGN = 278,              /* ADD_ASSIGN  */
    SUB_ASSIGN = 279,              /* SUB_ASSIGN  */
    LEFT_ASSIGN = 280,             /* LEFT_ASSIGN  */
    RIGHT_ASSIGN = 281,            /* RIGHT_ASSIGN  */
    AND_ASSIGN = 282,              /* AND_ASSIGN  */
    XOR_ASSIGN = 283,              /* XOR_ASSIGN  */
    OR_ASSIGN = 284,               /* OR_ASSIGN  */
    TYPE_NAME = 285,               /* TYPE_NAME  */
    TYPEDEF = 286,                 /* TYPEDEF  */
    EXTERN = 287,                  /* EXTERN  */
    STATIC = 288,                  /* STATIC  */
    AUTO = 289,                    /* AUTO  */
    REGISTER = 290,                /* REGISTER  */
    INLINE = 291,                  /* INLINE  */
    RESTRICT = 292,                /* RESTRICT  */
    CHAR = 293,                    /* CHAR  */
    SHORT = 294,                   /* SHORT  */
    LONG = 295,                    /* LONG  */
    SIGNED = 296,                  /* SIGNED  */
    UNSIGNED = 297,                /* UNSIGNED  */
    FLOAT = 298,                   /* FLOAT  */
    DOUBLE = 299,                  /* DOUBLE  */
    CONST = 300,                   /* CONST  */
    VOLATILE = 301,                /* VOLATILE  */
    BOOL = 302,                    /* BOOL  */
    COMPLEX = 303,                 /* COMPLEX  */
    IMAGINARY = 304,               /* IMAGINARY  */
    STRUCT = 305,                  /* STRUCT  */
    UNION = 306,                   /* UNION  */
    ENUM = 307,                    /* ENUM  */
    ELLIPSIS = 308,                /* ELLIPSIS  */
    CASE = 309,                    /* CASE  */
    DEFAULT = 310,                 /* DEFAULT  */
    IF = 311,                      /* IF  */
    ELSE = 312,                    /* ELSE  */
    SWITCH = 313,                  /* SWITCH  */
    WHILE = 314,                   /* WHILE  */
    DO = 315,                      /* DO  */
    FOR = 316,                     /* FOR  */
    GOTO = 317,                    /* GOTO  */
    CONTINUE = 318,                /* CONTINUE  */
    BREAK = 319,                   /* BREAK  */
    RETURN = 320,                  /* RETURN  */
    PARAM = 321,                   /* PARAM  */
    FUNC = 322,                    /* FUNC  */
    VAR = 323,                     /* VAR  */
    CALL = 324,                    /* CALL  */
    GLOBAL_VAR = 325,              /* GLOBAL_VAR  */
    LOWER_THAN_ELSE = 326          /* LOWER_THAN_ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define CONSTANT 258
#define INT 259
#define VOID 260
#define IDENTIFIER 261
#define STRING_LITERAL 262
#define SIZEOF 263
#define PTR_OP 264
#define INC_OP 265
#define DEC_OP 266
#define LEFT_OP 267
#define RIGHT_OP 268
#define LE_OP 269
#define GE_OP 270
#define EQ_OP 271
#define NE_OP 272
#define AND_OP 273
#define OR_OP 274
#define MUL_ASSIGN 275
#define DIV_ASSIGN 276
#define MOD_ASSIGN 277
#define ADD_ASSIGN 278
#define SUB_ASSIGN 279
#define LEFT_ASSIGN 280
#define RIGHT_ASSIGN 281
#define AND_ASSIGN 282
#define XOR_ASSIGN 283
#define OR_ASSIGN 284
#define TYPE_NAME 285
#define TYPEDEF 286
#define EXTERN 287
#define STATIC 288
#define AUTO 289
#define REGISTER 290
#define INLINE 291
#define RESTRICT 292
#define CHAR 293
#define SHORT 294
#define LONG 295
#define SIGNED 296
#define UNSIGNED 297
#define FLOAT 298
#define DOUBLE 299
#define CONST 300
#define VOLATILE 301
#define BOOL 302
#define COMPLEX 303
#define IMAGINARY 304
#define STRUCT 305
#define UNION 306
#define ENUM 307
#define ELLIPSIS 308
#define CASE 309
#define DEFAULT 310
#define IF 311
#define ELSE 312
#define SWITCH 313
#define WHILE 314
#define DO 315
#define FOR 316
#define GOTO 317
#define CONTINUE 318
#define BREAK 319
#define RETURN 320
#define PARAM 321
#define FUNC 322
#define VAR 323
#define CALL 324
#define GLOBAL_VAR 325
#define LOWER_THAN_ELSE 326

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 38 "c-grammar.y"

    int iValue;
    int sIndex;
    Node *nPtr;

#line 309 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_CONSTANT = 3,                   /* CONSTANT  */
  YYSYMBOL_INT = 4,                        /* INT  */
  YYSYMBOL_VOID = 5,                       /* VOID  */
  YYSYMBOL_IDENTIFIER = 6,                 /* IDENTIFIER  */
  YYSYMBOL_STRING_LITERAL = 7,             /* STRING_LITERAL  */
  YYSYMBOL_SIZEOF = 8,                     /* SIZEOF  */
  YYSYMBOL_PTR_OP = 9,                     /* PTR_OP  */
  YYSYMBOL_INC_OP = 10,                    /* INC_OP  */
  YYSYMBOL_DEC_OP = 11,                    /* DEC_OP  */
  YYSYMBOL_LEFT_OP = 12,                   /* LEFT_OP  */
  YYSYMBOL_RIGHT_OP = 13,                  /* RIGHT_OP  */
  YYSYMBOL_LE_OP = 14,                     /* LE_OP  */
  YYSYMBOL_GE_OP = 15,                     /* GE_OP  */
  YYSYMBOL_EQ_OP = 16,                     /* EQ_OP  */
  YYSYMBOL_NE_OP = 17,                     /* NE_OP  */
  YYSYMBOL_AND_OP = 18,                    /* AND_OP  */
  YYSYMBOL_OR_OP = 19,                     /* OR_OP  */
  YYSYMBOL_MUL_ASSIGN = 20,                /* MUL_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 21,                /* DIV_ASSIGN  */
  YYSYMBOL_MOD_ASSIGN = 22,                /* MOD_ASSIGN  */
  YYSYMBOL_ADD_ASSIGN = 23,                /* ADD_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 24,                /* SUB_ASSIGN  */
  YYSYMBOL_LEFT_ASSIGN = 25,               /* LEFT_ASSIGN  */
  YYSYMBOL_RIGHT_ASSIGN = 26,              /* RIGHT_ASSIGN  */
  YYSYMBOL_AND_ASSIGN = 27,                /* AND_ASSIGN  */
  YYSYMBOL_XOR_ASSIGN = 28,                /* XOR_ASSIGN  */
  YYSYMBOL_OR_ASSIGN = 29,                 /* OR_ASSIGN  */
  YYSYMBOL_TYPE_NAME = 30,                 /* TYPE_NAME  */
  YYSYMBOL_TYPEDEF = 31,                   /* TYPEDEF  */
  YYSYMBOL_EXTERN = 32,                    /* EXTERN  */
  YYSYMBOL_STATIC = 33,                    /* STATIC  */
  YYSYMBOL_AUTO = 34,                      /* AUTO  */
  YYSYMBOL_REGISTER = 35,                  /* REGISTER  */
  YYSYMBOL_INLINE = 36,                    /* INLINE  */
  YYSYMBOL_RESTRICT = 37,                  /* RESTRICT  */
  YYSYMBOL_CHAR = 38,                      /* CHAR  */
  YYSYMBOL_SHORT = 39,                     /* SHORT  */
  YYSYMBOL_LONG = 40,                      /* LONG  */
  YYSYMBOL_SIGNED = 41,                    /* SIGNED  */
  YYSYMBOL_UNSIGNED = 42,                  /* UNSIGNED  */
  YYSYMBOL_FLOAT = 43,                     /* FLOAT  */
  YYSYMBOL_DOUBLE = 44,                    /* DOUBLE  */
  YYSYMBOL_CONST = 45,                     /* CONST  */
  YYSYMBOL_VOLATILE = 46,                  /* VOLATILE  */
  YYSYMBOL_BOOL = 47,                      /* BOOL  */
  YYSYMBOL_COMPLEX = 48,                   /* COMPLEX  */
  YYSYMBOL_IMAGINARY = 49,                 /* IMAGINARY  */
  YYSYMBOL_STRUCT = 50,                    /* STRUCT  */
  YYSYMBOL_UNION = 51,                     /* UNION  */
  YYSYMBOL_ENUM = 52,                      /* ENUM  */
  YYSYMBOL_ELLIPSIS = 53,                  /* ELLIPSIS  */
  YYSYMBOL_CASE = 54,                      /* CASE  */
  YYSYMBOL_DEFAULT = 55,                   /* DEFAULT  */
  YYSYMBOL_IF = 56,                        /* IF  */
  YYSYMBOL_ELSE = 57,                      /* ELSE  */
  YYSYMBOL_SWITCH = 58,                    /* SWITCH  */
  YYSYMBOL_WHILE = 59,                     /* WHILE  */
  YYSYMBOL_DO = 60,                        /* DO  */
  YYSYMBOL_FOR = 61,                       /* FOR  */
  YYSYMBOL_GOTO = 62,                      /* GOTO  */
  YYSYMBOL_CONTINUE = 63,                  /* CONTINUE  */
  YYSYMBOL_BREAK = 64,                     /* BREAK  */
  YYSYMBOL_RETURN = 65,                    /* RETURN  */
  YYSYMBOL_PARAM = 66,                     /* PARAM  */
  YYSYMBOL_FUNC = 67,                      /* FUNC  */
  YYSYMBOL_VAR = 68,                       /* VAR  */
  YYSYMBOL_CALL = 69,                      /* CALL  */
  YYSYMBOL_GLOBAL_VAR = 70,                /* GLOBAL_VAR  */
  YYSYMBOL_LOWER_THAN_ELSE = 71,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_72_ = 72,                       /* ';'  */
  YYSYMBOL_73_ = 73,                       /* '['  */
  YYSYMBOL_74_ = 74,                       /* ']'  */
  YYSYMBOL_75_ = 75,                       /* '('  */
  YYSYMBOL_76_ = 76,                       /* ')'  */
  YYSYMBOL_77_ = 77,                       /* ','  */
  YYSYMBOL_78_ = 78,                       /* '{'  */
  YYSYMBOL_79_ = 79,                       /* '}'  */
  YYSYMBOL_80_ = 80,                       /* '='  */
  YYSYMBOL_81_ = 81,                       /* '<'  */
  YYSYMBOL_82_ = 82,                       /* '>'  */
  YYSYMBOL_83_ = 83,                       /* '+'  */
  YYSYMBOL_84_ = 84,                       /* '-'  */
  YYSYMBOL_85_ = 85,                       /* '*'  */
  YYSYMBOL_86_ = 86,                       /* '/'  */
  YYSYMBOL_YYACCEPT = 87,                  /* $accept  */
  YYSYMBOL_program = 88,                   /* program  */
  YYSYMBOL_declaration_list = 89,          /* declaration_list  */
  YYSYMBOL_declaration = 90,               /* declaration  */
  YYSYMBOL_var_declaration = 91,           /* var_declaration  */
  YYSYMBOL_type_specifier = 92,            /* type_specifier  */
  YYSYMBOL_fun_declaration = 93,           /* fun_declaration  */
  YYSYMBOL_params = 94,                    /* params  */
  YYSYMBOL_params_list = 95,               /* params_list  */
  YYSYMBOL_param = 96,                     /* param  */
  YYSYMBOL_compound_stmt = 97,             /* compound_stmt  */
  YYSYMBOL_local_declarations = 98,        /* local_declarations  */
  YYSYMBOL_statement_list = 99,            /* statement_list  */
  YYSYMBOL_statement = 100,                /* statement  */
  YYSYMBOL_expression_stmt = 101,          /* expression_stmt  */
  YYSYMBOL_selection_stmt = 102,           /* selection_stmt  */
  YYSYMBOL_iteration_stmt = 103,           /* iteration_stmt  */
  YYSYMBOL_return_stmt = 104,              /* return_stmt  */
  YYSYMBOL_expression = 105,               /* expression  */
  YYSYMBOL_var = 106,                      /* var  */
  YYSYMBOL_simple_expression = 107,        /* simple_expression  */
  YYSYMBOL_relop = 108,                    /* relop  */
  YYSYMBOL_additive_expression = 109,      /* additive_expression  */
  YYSYMBOL_addop = 110,                    /* addop  */
  YYSYMBOL_term = 111,                     /* term  */
  YYSYMBOL_mulop = 112,                    /* mulop  */
  YYSYMBOL_factor = 113,                   /* factor  */
  YYSYMBOL_call = 114,                     /* call  */
  YYSYMBOL_args = 115,                     /* args  */
  YYSYMBOL_arg_list = 116                  /* arg_list  */
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

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   506

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  87
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  92
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  152

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   326


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
      75,    76,    85,    83,    77,    84,     2,    86,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    72,
      81,    80,    82,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    73,     2,    74,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    78,     2,    79,     2,     2,     2,     2,
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
      65,    66,    67,    68,    69,    70,    71
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    77,    77,    81,    82,    86,    90,    94,   101,   108,
     116,   117,   121,   128,   133,   134,   138,   139,   140,   148,
     155,   162,   167,   175,   177,   185,   186,   190,   191,   195,
     196,   197,   198,   199,   203,   204,   208,   209,   211,   216,
     221,   226,   231,   236,   241,   249,   250,   254,   259,   267,
     268,   269,   274,   282,   286,   290,   291,   300,   304,   305,
     310,   318,   319,   320,   321,   322,   323,   327,   331,   335,
     340,   348,   349,   353,   357,   358,   363,   371,   372,   376,
     377,   378,   379,   383,   389,   394,   399,   407,   408,   412,
     413,   414,   419
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
  "\"end of file\"", "error", "\"invalid token\"", "CONSTANT", "INT",
  "VOID", "IDENTIFIER", "STRING_LITERAL", "SIZEOF", "PTR_OP", "INC_OP",
  "DEC_OP", "LEFT_OP", "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP",
  "AND_OP", "OR_OP", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN",
  "ADD_ASSIGN", "SUB_ASSIGN", "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN",
  "XOR_ASSIGN", "OR_ASSIGN", "TYPE_NAME", "TYPEDEF", "EXTERN", "STATIC",
  "AUTO", "REGISTER", "INLINE", "RESTRICT", "CHAR", "SHORT", "LONG",
  "SIGNED", "UNSIGNED", "FLOAT", "DOUBLE", "CONST", "VOLATILE", "BOOL",
  "COMPLEX", "IMAGINARY", "STRUCT", "UNION", "ENUM", "ELLIPSIS", "CASE",
  "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE", "DO", "FOR", "GOTO",
  "CONTINUE", "BREAK", "RETURN", "PARAM", "FUNC", "VAR", "CALL",
  "GLOBAL_VAR", "LOWER_THAN_ELSE", "';'", "'['", "']'", "'('", "')'",
  "','", "'{'", "'}'", "'='", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'",
  "$accept", "program", "declaration_list", "declaration",
  "var_declaration", "type_specifier", "fun_declaration", "params",
  "params_list", "param", "compound_stmt", "local_declarations",
  "statement_list", "statement", "expression_stmt", "selection_stmt",
  "iteration_stmt", "return_stmt", "expression", "var",
  "simple_expression", "relop", "additive_expression", "addop", "term",
  "mulop", "factor", "call", "args", "arg_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,    59,    91,    93,    40,    41,    44,   123,   125,
      61,    60,    62,    43,    45,    42,    47
};
#endif

#define YYPACT_NINF (-69)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-89)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      66,   -69,   -69,   -69,    35,    66,   -69,   -69,     3,   -69,
     -69,    47,   -69,   -69,   -51,    38,   -69,     4,   328,   -69,
     -69,    85,    54,    -5,   424,   -69,     0,    21,    26,   -12,
      17,   -69,    59,   -69,   -69,   -69,   -69,   -69,   -69,   -69,
      18,    22,   -69,    40,   114,   -69,   -69,    29,    51,    27,
      64,     2,   -69,   -69,   -69,   -69,   -69,   -69,   -69,    43,
      23,    59,    44,   343,   151,   343,    59,    63,   245,   -69,
      67,   424,    65,   -69,    59,    43,   -69,   -69,   152,   168,
      43,   -69,   -69,   169,    70,   -69,    60,   -69,    47,    47,
     -69,   131,   342,   -69,    74,   148,    69,    11,    94,   289,
      84,   -69,    91,    92,   -69,   -69,   -69,   -69,   165,   -69,
     239,   -69,   256,   -69,   -69,   -69,   -69,   -69,    87,   -69,
     -69,    59,   -69,    59,    59,   -69,   -69,   -69,   343,   343,
     116,   371,   372,   343,   -69,   -69,   -69,   -69,   -69,   -69,
     343,   396,   119,   424,   -69,   -69,   -69,   343,   395,   -69,
     424,   -69
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    10,    11,    26,     0,     2,     4,     5,     0,     6,
      13,    28,     1,     3,     0,     0,    25,     0,     0,     9,
       7,     0,     0,     0,    24,    82,     0,     0,     0,     0,
       0,    35,     0,    23,    30,    27,    29,    31,    32,    33,
       0,    80,    54,     0,     0,    74,    81,     0,    11,     0,
       0,     0,    17,    61,    64,    65,    66,    62,    63,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    52,    49,
       0,     0,     0,    34,     0,     0,    71,    72,     0,     0,
       0,    77,    78,     0,     0,    22,     0,    12,     0,     0,
      80,     0,     0,    90,    85,     0,     0,     0,    39,     0,
       0,    47,     0,     0,    51,    50,    79,    53,     0,    60,
       0,    70,     0,    75,    76,    73,     8,    21,     0,    18,
      16,     0,    84,     0,     0,    56,    86,    83,     0,     0,
       0,     0,     0,     0,    20,    92,    91,    89,    38,    40,
       0,    43,    36,    48,    45,    46,    41,     0,     0,    42,
      44,    37
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -69,   -69,   -69,   172,   167,     8,   -69,   -69,   -69,   -46,
      48,   -69,   -69,   146,   117,   -69,   -69,   -69,   -30,   205,
     -69,   140,   -53,   -69,   -68,   -69,    76,   -69,   123,   -69
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,     6,     7,    49,     9,    50,    51,    52,
      34,    11,    18,    35,    36,    37,    38,    39,    40,    41,
      42,    59,    43,    79,    44,    83,    45,    46,    94,    95
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      70,    60,    72,    88,    14,    14,    91,   108,     8,    15,
      23,   112,   126,     8,   -55,   -55,   -55,   -55,    68,    17,
      25,    19,    63,    26,    92,   110,    25,    65,    85,    26,
      93,    96,    93,    86,   100,    12,   102,   -88,   -88,   -88,
     -88,    75,   119,   120,   107,    92,    25,    25,    10,    26,
      26,     1,     2,    10,    53,    54,    55,    56,     1,    48,
      71,   117,    25,    67,    71,    26,    25,    20,    21,    26,
       1,     2,   -55,    61,   -55,    62,   -55,   -55,   -14,    89,
     -55,   -55,   -55,   -55,   -55,   -55,   -55,   127,    47,    69,
      73,   135,    32,   136,   137,   -88,    64,   -88,    32,   -88,
     -88,    66,    74,    84,   -88,   -88,   -88,   -88,   -88,   -88,
      20,    21,   -58,    22,   -58,    80,   -58,   -58,    32,    32,
     -88,    57,    58,    76,    77,   -58,   -58,   -15,   -68,   -68,
     -68,   -68,    75,   118,    32,    31,   -19,   -19,    32,   105,
      87,   106,   116,   125,     3,   -59,   -59,   -59,   -59,   123,
     122,   128,    99,   109,    25,    25,   113,    26,    26,   115,
     131,   134,   -87,   -87,   -87,   -87,    80,   132,   133,   111,
     114,    25,    25,   140,    26,    26,   148,    13,    16,   -69,
     -69,   -69,   -69,    78,   103,    97,   -68,     0,   -68,     0,
     -68,   -68,     0,     0,     0,   -68,   -68,   -68,   -68,    81,
      82,     0,     0,   -59,     0,   -59,     0,   -59,   -59,    98,
       0,   101,   -59,   -59,    76,    77,   -59,   -59,     0,     0,
     -87,     0,   -87,     0,   -87,   124,    32,    32,     0,   -87,
     -87,   -87,   -87,   -87,   -87,     0,     0,   -69,     0,   -69,
      75,   -69,   -69,    32,    32,   130,   -69,   -69,   -69,   -69,
      81,    82,     0,   -57,   -57,   -57,   -57,    80,     0,    53,
      54,    55,    56,     0,    90,     0,     0,     0,     0,     0,
     -67,   -67,   -67,   -67,   138,   139,     0,   142,   144,   145,
      90,     0,     0,    90,    90,    90,   146,     0,    90,     0,
      71,     0,    25,   149,   151,    26,     0,     0,     0,     0,
       0,     0,     0,    53,    54,    55,    56,     0,     0,     0,
       0,   -57,     0,   -57,     0,   -57,   -57,   104,     0,     0,
     -57,   -57,    76,    77,   -57,   -57,    57,    58,   -67,    24,
     -67,    25,   -67,   -67,    26,     0,     0,   -67,   -67,   -67,
     -67,    81,    82,     0,    71,    27,    25,     0,    28,    26,
      29,     0,     0,     0,    30,     0,    53,    54,    55,    56,
       0,    31,     0,     0,    32,   129,     0,     3,     0,     0,
      57,    58,   141,   143,    25,    25,     0,    26,    26,     0,
       0,     0,     0,     0,    27,     0,     0,    28,     0,    29,
       0,     0,     0,    30,     0,     0,   150,     0,    25,    27,
      31,    26,    28,    32,    29,     0,     3,    33,    30,     0,
      53,    54,    55,    56,     0,    31,     0,     0,    32,   121,
       0,     3,     0,    57,    58,     0,     0,    27,    27,     0,
      28,    28,    29,    29,     0,     0,    30,    30,    53,    54,
      55,    56,     0,    31,    31,     0,    32,    32,     0,     3,
       3,    27,     0,   147,    28,     0,    29,     0,     0,     0,
      30,     0,     0,     0,     0,     0,     0,    31,     0,     0,
      32,     0,     0,     3,     0,     0,     0,    57,    58,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    57,    58
};

static const yytype_int16 yycheck[] =
{
      30,     1,    32,     1,     1,     1,    59,    75,     0,     6,
       6,    79,     1,     5,    14,    15,    16,    17,     1,    11,
       3,    72,     1,     6,     1,    78,     3,     1,     1,     6,
      60,    61,    62,     6,    64,     0,    66,    14,    15,    16,
      17,     1,    88,    89,    74,     1,     3,     3,     0,     6,
       6,     4,     5,     5,    14,    15,    16,    17,     4,     5,
       1,     1,     3,    75,     1,     6,     3,    72,    73,     6,
       4,     5,    72,    73,    74,    75,    76,    77,    76,    77,
      80,    81,    82,    83,    84,    85,    86,    76,     3,    72,
      72,   121,    75,   123,   124,    72,    75,    74,    75,    76,
      77,    75,    80,    74,    81,    82,    83,    84,    85,    86,
      72,    73,    72,    75,    74,     1,    76,    77,    75,    75,
      76,    81,    82,    83,    84,    85,    86,    76,    14,    15,
      16,    17,     1,    73,    75,    72,    76,    77,    75,    72,
      76,    76,    72,    74,    78,    14,    15,    16,    17,     1,
      76,    57,     1,     1,     3,     3,    80,     6,     6,    83,
      76,    74,    14,    15,    16,    17,     1,    76,    76,     1,
       1,     3,     3,    57,     6,     6,    57,     5,    11,    14,
      15,    16,    17,    43,    67,    62,    72,    -1,    74,    -1,
      76,    77,    -1,    -1,    -1,    81,    82,    83,    84,    85,
      86,    -1,    -1,    72,    -1,    74,    -1,    76,    77,    63,
      -1,    65,    81,    82,    83,    84,    85,    86,    -1,    -1,
      72,    -1,    74,    -1,    76,    77,    75,    75,    -1,    81,
      82,    83,    84,    85,    86,    -1,    -1,    72,    -1,    74,
       1,    76,    77,    75,    75,    99,    81,    82,    83,    84,
      85,    86,    -1,    14,    15,    16,    17,     1,    -1,    14,
      15,    16,    17,    -1,    59,    -1,    -1,    -1,    -1,    -1,
      14,    15,    16,    17,   128,   129,    -1,   131,   132,   133,
      75,    -1,    -1,    78,    79,    80,   140,    -1,    83,    -1,
       1,    -1,     3,   147,   148,     6,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    14,    15,    16,    17,    -1,    -1,    -1,
      -1,    72,    -1,    74,    -1,    76,    77,    72,    -1,    -1,
      81,    82,    83,    84,    85,    86,    81,    82,    72,     1,
      74,     3,    76,    77,     6,    -1,    -1,    81,    82,    83,
      84,    85,    86,    -1,     1,    56,     3,    -1,    59,     6,
      61,    -1,    -1,    -1,    65,    -1,    14,    15,    16,    17,
      -1,    72,    -1,    -1,    75,    76,    -1,    78,    -1,    -1,
      81,    82,     1,     1,     3,     3,    -1,     6,     6,    -1,
      -1,    -1,    -1,    -1,    56,    -1,    -1,    59,    -1,    61,
      -1,    -1,    -1,    65,    -1,    -1,     1,    -1,     3,    56,
      72,     6,    59,    75,    61,    -1,    78,    79,    65,    -1,
      14,    15,    16,    17,    -1,    72,    -1,    -1,    75,    77,
      -1,    78,    -1,    81,    82,    -1,    -1,    56,    56,    -1,
      59,    59,    61,    61,    -1,    -1,    65,    65,    14,    15,
      16,    17,    -1,    72,    72,    -1,    75,    75,    -1,    78,
      78,    56,    -1,    57,    59,    -1,    61,    -1,    -1,    -1,
      65,    -1,    -1,    -1,    -1,    -1,    -1,    72,    -1,    -1,
      75,    -1,    -1,    78,    -1,    -1,    -1,    81,    82,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    82
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,     5,    78,    88,    89,    90,    91,    92,    93,
      97,    98,     0,    90,     1,     6,    91,    92,    99,    72,
      72,    73,    75,     6,     1,     3,     6,    56,    59,    61,
      65,    72,    75,    79,    97,   100,   101,   102,   103,   104,
     105,   106,   107,   109,   111,   113,   114,     3,     5,    92,
      94,    95,    96,    14,    15,    16,    17,    81,    82,   108,
       1,    73,    75,     1,    75,     1,    75,    75,     1,    72,
     105,     1,   105,    72,    80,     1,    83,    84,   108,   110,
       1,    85,    86,   112,    74,     1,     6,    76,     1,    77,
     106,   109,     1,   105,   115,   116,   105,   115,   100,     1,
     105,   100,   105,   101,    72,    72,    76,   105,   111,     1,
     109,     1,   111,   113,     1,   113,    72,     1,    73,    96,
      96,    77,    76,     1,    77,    74,     1,    76,    57,    76,
     100,    76,    76,    76,    74,   105,   105,   105,   100,   100,
      57,     1,   100,     1,   100,   100,   100,    57,    57,   100,
       1,   100
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    87,    88,    89,    89,    90,    90,    91,    91,    91,
      92,    92,    93,    93,    94,    94,    95,    95,    95,    96,
      96,    96,    96,    97,    97,    98,    98,    99,    99,   100,
     100,   100,   100,   100,   101,   101,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   103,   103,   103,   103,   104,
     104,   104,   104,   105,   105,   106,   106,   107,   107,   107,
     107,   108,   108,   108,   108,   108,   108,   109,   109,   109,
     109,   110,   110,   111,   111,   111,   111,   112,   112,   113,
     113,   113,   113,   114,   114,   114,   114,   115,   115,   116,
     116,   116,   116
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     6,     3,
       1,     1,     5,     1,     1,     1,     3,     1,     3,     2,
       4,     3,     2,     4,     4,     2,     0,     2,     0,     1,
       1,     1,     1,     1,     2,     1,     5,     7,     5,     3,
       5,     6,     7,     5,     7,     5,     5,     3,     5,     2,
       3,     3,     2,     3,     1,     1,     4,     3,     1,     3,
       3,     1,     1,     1,     1,     1,     1,     3,     1,     3,
       3,     1,     1,     3,     1,     3,     3,     1,     1,     3,
       1,     1,     1,     4,     4,     3,     4,     1,     0,     3,
       1,     3,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


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
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
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
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
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
  case 2: /* program: declaration_list  */
#line 77 "c-grammar.y"
                       { exeNode((yyvsp[0].nPtr), 0); printTree((yyvsp[0].nPtr)); freeNode((yyvsp[0].nPtr)); }
#line 1604 "y.tab.c"
    break;

  case 3: /* declaration_list: declaration_list declaration  */
#line 81 "c-grammar.y"
                                   { (yyval.nPtr) = createNode(';', 2, (yyvsp[-1].nPtr), (yyvsp[0].nPtr)); }
#line 1610 "y.tab.c"
    break;

  case 4: /* declaration_list: declaration  */
#line 82 "c-grammar.y"
                  { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1616 "y.tab.c"
    break;

  case 5: /* declaration: var_declaration  */
#line 87 "c-grammar.y"
        { 
            (yyval.nPtr)  = createNode(GLOBAL_VAR, 1, (yyvsp[0].nPtr));
        }
#line 1624 "y.tab.c"
    break;

  case 6: /* declaration: fun_declaration  */
#line 90 "c-grammar.y"
                      { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1630 "y.tab.c"
    break;

  case 7: /* var_declaration: type_specifier IDENTIFIER ';'  */
#line 95 "c-grammar.y"
        {
            Node *tmp1;
            /* here to insert new var declaration */
            tmp1 = set_index((yyvsp[-1].sIndex));
            (yyval.nPtr) = createNode(VAR, 2, (yyvsp[-2].nPtr), tmp1);
        }
#line 1641 "y.tab.c"
    break;

  case 8: /* var_declaration: type_specifier IDENTIFIER '[' CONSTANT ']' ';'  */
#line 102 "c-grammar.y"
        {
            Node *tmp1, *tmp2;
            tmp1 = set_index((yyvsp[-4].sIndex));
            tmp2 = set_content((yyvsp[-2].iValue));
            (yyval.nPtr) = createNode(VAR, 3, (yyvsp[-5].nPtr), tmp1, tmp2);
        }
#line 1652 "y.tab.c"
    break;

  case 9: /* var_declaration: type_specifier error ';'  */
#line 109 "c-grammar.y"
        {
            printf("C--:error Definition of variate;\n");
            exit(1);
        }
#line 1661 "y.tab.c"
    break;

  case 10: /* type_specifier: INT  */
#line 116 "c-grammar.y"
          { (yyval.nPtr) = set_content(INT); }
#line 1667 "y.tab.c"
    break;

  case 11: /* type_specifier: VOID  */
#line 117 "c-grammar.y"
           { (yyval.nPtr) = set_content(VOID); }
#line 1673 "y.tab.c"
    break;

  case 12: /* fun_declaration: type_specifier IDENTIFIER '(' params ')'  */
#line 122 "c-grammar.y"
        {
            Node *tmp1;
            tmp1 = set_index((yyvsp[-3].sIndex));
            (yyval.nPtr) = createNode(FUNC, 3, (yyvsp[-4].nPtr), tmp1, (yyvsp[-1].nPtr));
        }
#line 1683 "y.tab.c"
    break;

  case 13: /* fun_declaration: compound_stmt  */
#line 129 "c-grammar.y"
        { (yyval.nPtr) = createNode(FUNC, 1, (yyvsp[0].nPtr)); }
#line 1689 "y.tab.c"
    break;

  case 14: /* params: params_list  */
#line 133 "c-grammar.y"
                  { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1695 "y.tab.c"
    break;

  case 15: /* params: VOID  */
#line 134 "c-grammar.y"
           { (yyval.nPtr) = NULL; }
#line 1701 "y.tab.c"
    break;

  case 16: /* params_list: params_list ',' param  */
#line 138 "c-grammar.y"
                            { (yyval.nPtr) = createNode(',', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1707 "y.tab.c"
    break;

  case 17: /* params_list: param  */
#line 139 "c-grammar.y"
            { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1713 "y.tab.c"
    break;

  case 18: /* params_list: params_list error param  */
#line 141 "c-grammar.y"
    {
        printf("C--:disappear ',' in function declaration;\n");
        exit(1);
    }
#line 1722 "y.tab.c"
    break;

  case 19: /* param: type_specifier IDENTIFIER  */
#line 149 "c-grammar.y"
        {
            Node *tmp1;
            /* here to insert new var declaration */
            tmp1 = set_index((yyvsp[0].sIndex));
            (yyval.nPtr) = createNode(PARAM, 2, (yyvsp[-1].nPtr), tmp1);
        }
#line 1733 "y.tab.c"
    break;

  case 20: /* param: type_specifier IDENTIFIER '[' ']'  */
#line 156 "c-grammar.y"
        {
            Node *tmp1;
            /* here to insert new var declaration */
            tmp1 = set_index((yyvsp[-2].sIndex));
            (yyval.nPtr) = createNode(PARAM, 3, (yyvsp[-3].nPtr), tmp1, NULL);
        }
#line 1744 "y.tab.c"
    break;

  case 21: /* param: type_specifier IDENTIFIER error  */
#line 163 "c-grammar.y"
        {
            printf("C--:error declaration of function params;\n");
            exit(1);
        }
#line 1753 "y.tab.c"
    break;

  case 22: /* param: type_specifier error  */
#line 168 "c-grammar.y"
        {
            printf("C--:error declaration of function params;\n");
            exit(1);
        }
#line 1762 "y.tab.c"
    break;

  case 23: /* compound_stmt: '{' local_declarations statement_list '}'  */
#line 176 "c-grammar.y"
        { (yyval.nPtr) = createNode('{', 2, (yyvsp[-2].nPtr), (yyvsp[-1].nPtr)); }
#line 1768 "y.tab.c"
    break;

  case 24: /* compound_stmt: '{' local_declarations statement_list error  */
#line 178 "c-grammar.y"
        {
            printf("C--:disappear '}' for the function body;\n");
            exit(1);
        }
#line 1777 "y.tab.c"
    break;

  case 25: /* local_declarations: local_declarations var_declaration  */
#line 185 "c-grammar.y"
                                         { (yyval.nPtr) = createNode(';', 2, (yyvsp[-1].nPtr), (yyvsp[0].nPtr)); }
#line 1783 "y.tab.c"
    break;

  case 26: /* local_declarations: %empty  */
#line 186 "c-grammar.y"
                  { (yyval.nPtr) = NULL; }
#line 1789 "y.tab.c"
    break;

  case 27: /* statement_list: statement_list statement  */
#line 190 "c-grammar.y"
                               { (yyval.nPtr) = createNode(';', 2, (yyvsp[-1].nPtr), (yyvsp[0].nPtr)); }
#line 1795 "y.tab.c"
    break;

  case 28: /* statement_list: %empty  */
#line 191 "c-grammar.y"
                  { (yyval.nPtr) = NULL; }
#line 1801 "y.tab.c"
    break;

  case 29: /* statement: expression_stmt  */
#line 195 "c-grammar.y"
                      { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1807 "y.tab.c"
    break;

  case 30: /* statement: compound_stmt  */
#line 196 "c-grammar.y"
                    { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1813 "y.tab.c"
    break;

  case 31: /* statement: selection_stmt  */
#line 197 "c-grammar.y"
                     { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1819 "y.tab.c"
    break;

  case 32: /* statement: iteration_stmt  */
#line 198 "c-grammar.y"
                     { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1825 "y.tab.c"
    break;

  case 33: /* statement: return_stmt  */
#line 199 "c-grammar.y"
                  { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1831 "y.tab.c"
    break;

  case 34: /* expression_stmt: expression ';'  */
#line 203 "c-grammar.y"
                     { (yyval.nPtr) = (yyvsp[-1].nPtr); }
#line 1837 "y.tab.c"
    break;

  case 35: /* expression_stmt: ';'  */
#line 204 "c-grammar.y"
          { (yyval.nPtr) = NULL; }
#line 1843 "y.tab.c"
    break;

  case 36: /* selection_stmt: IF '(' expression ')' statement  */
#line 208 "c-grammar.y"
                                      { (yyval.nPtr) = createNode(IF, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1849 "y.tab.c"
    break;

  case 37: /* selection_stmt: IF '(' expression ')' statement ELSE statement  */
#line 210 "c-grammar.y"
        { (yyval.nPtr) = createNode(IF, 3, (yyvsp[-4].nPtr), (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1855 "y.tab.c"
    break;

  case 38: /* selection_stmt: IF error statement ELSE statement  */
#line 212 "c-grammar.y"
    {
        printf("C--:disappear boolean statement;\n");
        exit(1);
    }
#line 1864 "y.tab.c"
    break;

  case 39: /* selection_stmt: IF error statement  */
#line 217 "c-grammar.y"
    {
        printf("C--:disappear boolean statement;\n");
        exit(1);
    }
#line 1873 "y.tab.c"
    break;

  case 40: /* selection_stmt: IF '(' error ')' statement  */
#line 222 "c-grammar.y"
    {
        printf("C--:disappear boolean statement;\n");
        exit(1);
    }
#line 1882 "y.tab.c"
    break;

  case 41: /* selection_stmt: IF '(' error statement ELSE statement  */
#line 227 "c-grammar.y"
    {
        printf("C--:disappear boolean statement and ')';\n");
        exit(1);
    }
#line 1891 "y.tab.c"
    break;

  case 42: /* selection_stmt: IF '(' expression ')' error ELSE statement  */
#line 232 "c-grammar.y"
    {
        printf("C--:disappear IF statement;\n");
        exit(1);
    }
#line 1900 "y.tab.c"
    break;

  case 43: /* selection_stmt: IF '(' expression ')' error  */
#line 237 "c-grammar.y"
    {
        printf("C--:disappear IF statement;\n");
        exit(1);
    }
#line 1909 "y.tab.c"
    break;

  case 44: /* selection_stmt: IF '(' expression ')' statement ELSE error  */
#line 242 "c-grammar.y"
    {
        printf("C--:disappear ELSE statement;\n");
        exit(1);
    }
#line 1918 "y.tab.c"
    break;

  case 45: /* iteration_stmt: WHILE '(' expression ')' statement  */
#line 249 "c-grammar.y"
                                         { (yyval.nPtr) = createNode(WHILE, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1924 "y.tab.c"
    break;

  case 46: /* iteration_stmt: FOR '(' expression_stmt ')' statement  */
#line 250 "c-grammar.y"
                                            {
        printf("FOR iteration is not allowed!\n");
        exit(1);
    }
#line 1933 "y.tab.c"
    break;

  case 47: /* iteration_stmt: WHILE error statement  */
#line 255 "c-grammar.y"
    {
        printf("C--:disappear while boolean statement;\n");
        exit(1);
    }
#line 1942 "y.tab.c"
    break;

  case 48: /* iteration_stmt: WHILE '(' expression ')' error  */
#line 260 "c-grammar.y"
    {
        printf("C--:disappear while statement;\n");
        exit(1);
    }
#line 1951 "y.tab.c"
    break;

  case 49: /* return_stmt: RETURN ';'  */
#line 267 "c-grammar.y"
                 { (yyval.nPtr) = createNode(RETURN, 0); }
#line 1957 "y.tab.c"
    break;

  case 50: /* return_stmt: RETURN expression ';'  */
#line 268 "c-grammar.y"
                            { (yyval.nPtr) = createNode(RETURN, 1, (yyvsp[-1].nPtr)); }
#line 1963 "y.tab.c"
    break;

  case 51: /* return_stmt: RETURN error ';'  */
#line 270 "c-grammar.y"
        {
            printf("C--:error return statement;\n");
            exit(1);
        }
#line 1972 "y.tab.c"
    break;

  case 52: /* return_stmt: RETURN error  */
#line 275 "c-grammar.y"
        {
            printf("C--:error return statement;\n");
            exit(1);
        }
#line 1981 "y.tab.c"
    break;

  case 53: /* expression: var '=' expression  */
#line 283 "c-grammar.y"
        {
            (yyval.nPtr) = createNode('=', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));
        }
#line 1989 "y.tab.c"
    break;

  case 54: /* expression: simple_expression  */
#line 286 "c-grammar.y"
                        { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1995 "y.tab.c"
    break;

  case 55: /* var: IDENTIFIER  */
#line 290 "c-grammar.y"
                 { (yyval.nPtr) = set_index((yyvsp[0].sIndex)); }
#line 2001 "y.tab.c"
    break;

  case 56: /* var: IDENTIFIER '[' expression ']'  */
#line 292 "c-grammar.y"
        {
            Node *tmp1;
            tmp1 = set_index((yyvsp[-3].sIndex));
            (yyval.nPtr) = createNode('[', 2, tmp1, (yyvsp[-1].nPtr)); 
        }
#line 2011 "y.tab.c"
    break;

  case 57: /* simple_expression: additive_expression relop additive_expression  */
#line 301 "c-grammar.y"
        {
            (yyval.nPtr) = createNode((yyvsp[-1].iValue), 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); 
        }
#line 2019 "y.tab.c"
    break;

  case 58: /* simple_expression: additive_expression  */
#line 304 "c-grammar.y"
                          { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 2025 "y.tab.c"
    break;

  case 59: /* simple_expression: error relop additive_expression  */
#line 306 "c-grammar.y"
        {
            printf("C--:disappear compare statement;\n");
            exit(1);
        }
#line 2034 "y.tab.c"
    break;

  case 60: /* simple_expression: additive_expression relop error  */
#line 311 "c-grammar.y"
        {
            printf("C--:disappear compare statement;\n");
            exit(1);
        }
#line 2043 "y.tab.c"
    break;

  case 61: /* relop: LE_OP  */
#line 318 "c-grammar.y"
            { (yyval.iValue) = LE_OP; }
#line 2049 "y.tab.c"
    break;

  case 62: /* relop: '<'  */
#line 319 "c-grammar.y"
          { (yyval.iValue) = '<'; }
#line 2055 "y.tab.c"
    break;

  case 63: /* relop: '>'  */
#line 320 "c-grammar.y"
          { (yyval.iValue) = '>'; }
#line 2061 "y.tab.c"
    break;

  case 64: /* relop: GE_OP  */
#line 321 "c-grammar.y"
            { (yyval.iValue) = GE_OP; }
#line 2067 "y.tab.c"
    break;

  case 65: /* relop: EQ_OP  */
#line 322 "c-grammar.y"
            { (yyval.iValue) = EQ_OP; }
#line 2073 "y.tab.c"
    break;

  case 66: /* relop: NE_OP  */
#line 323 "c-grammar.y"
            { (yyval.iValue) = NE_OP; }
#line 2079 "y.tab.c"
    break;

  case 67: /* additive_expression: additive_expression addop term  */
#line 328 "c-grammar.y"
        {
            (yyval.nPtr) = createNode((yyvsp[-1].iValue), 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));
        }
#line 2087 "y.tab.c"
    break;

  case 68: /* additive_expression: term  */
#line 332 "c-grammar.y"
        { 
            (yyval.nPtr) = (yyvsp[0].nPtr);
        }
#line 2095 "y.tab.c"
    break;

  case 69: /* additive_expression: additive_expression error term  */
#line 336 "c-grammar.y"
    {
        printf("C--:disappear '/' or '*' or ' '+' or '-' statement;\n");
        exit(1);
    }
#line 2104 "y.tab.c"
    break;

  case 70: /* additive_expression: additive_expression addop error  */
#line 341 "c-grammar.y"
    {
        printf("C--:disappear statement;\n");
        exit(1);
    }
#line 2113 "y.tab.c"
    break;

  case 71: /* addop: '+'  */
#line 348 "c-grammar.y"
          { (yyval.iValue) = '+'; }
#line 2119 "y.tab.c"
    break;

  case 72: /* addop: '-'  */
#line 349 "c-grammar.y"
          { (yyval.iValue) = '-'; }
#line 2125 "y.tab.c"
    break;

  case 73: /* term: term mulop factor  */
#line 354 "c-grammar.y"
        {
            (yyval.nPtr) = createNode((yyvsp[-1].iValue), 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));
        }
#line 2133 "y.tab.c"
    break;

  case 74: /* term: factor  */
#line 357 "c-grammar.y"
             { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 2139 "y.tab.c"
    break;

  case 75: /* term: term error factor  */
#line 359 "c-grammar.y"
    {
        printf("C--:disappear '/' or '* or '+' or '-' statement;\n");
        exit(1);
    }
#line 2148 "y.tab.c"
    break;

  case 76: /* term: term mulop error  */
#line 364 "c-grammar.y"
    {
        printf("C--:disappear statement;\n");
        exit(1);
    }
#line 2157 "y.tab.c"
    break;

  case 77: /* mulop: '*'  */
#line 371 "c-grammar.y"
          { (yyval.iValue) = '*'; }
#line 2163 "y.tab.c"
    break;

  case 78: /* mulop: '/'  */
#line 372 "c-grammar.y"
          { (yyval.iValue) = '/'; }
#line 2169 "y.tab.c"
    break;

  case 79: /* factor: '(' expression ')'  */
#line 376 "c-grammar.y"
                         { (yyval.nPtr) = (yyvsp[-1].nPtr); }
#line 2175 "y.tab.c"
    break;

  case 80: /* factor: var  */
#line 377 "c-grammar.y"
          { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 2181 "y.tab.c"
    break;

  case 81: /* factor: call  */
#line 378 "c-grammar.y"
           { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 2187 "y.tab.c"
    break;

  case 82: /* factor: CONSTANT  */
#line 379 "c-grammar.y"
               { (yyval.nPtr) = set_content((yyvsp[0].iValue)); }
#line 2193 "y.tab.c"
    break;

  case 83: /* call: IDENTIFIER '(' args ')'  */
#line 384 "c-grammar.y"
        { 
            Node *tmp1;
            tmp1 = set_index((yyvsp[-3].sIndex));
            (yyval.nPtr) = createNode(CALL, 2, tmp1, (yyvsp[-1].nPtr));
        }
#line 2203 "y.tab.c"
    break;

  case 84: /* call: IDENTIFIER error args ')'  */
#line 390 "c-grammar.y"
        { 
           printf("C--:disappear '(' statement;\n");
           exit(1);
        }
#line 2212 "y.tab.c"
    break;

  case 85: /* call: IDENTIFIER error args  */
#line 395 "c-grammar.y"
        {
           printf("C--:disappear '(' and ')' statement;\n");
           exit(1);
        }
#line 2221 "y.tab.c"
    break;

  case 86: /* call: IDENTIFIER '(' args error  */
#line 400 "c-grammar.y"
        {
           printf("C--:disappear ')' statement;\n");
           exit(1);
        }
#line 2230 "y.tab.c"
    break;

  case 87: /* args: arg_list  */
#line 407 "c-grammar.y"
               { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 2236 "y.tab.c"
    break;

  case 88: /* args: %empty  */
#line 408 "c-grammar.y"
                  { (yyval.nPtr) = NULL; }
#line 2242 "y.tab.c"
    break;

  case 89: /* arg_list: arg_list ',' expression  */
#line 412 "c-grammar.y"
                              { (yyval.nPtr) = createNode(',', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 2248 "y.tab.c"
    break;

  case 90: /* arg_list: expression  */
#line 413 "c-grammar.y"
                 { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 2254 "y.tab.c"
    break;

  case 91: /* arg_list: arg_list error expression  */
#line 415 "c-grammar.y"
        {
            printf("C--:incorrent function arg_list;\n");
            exit(1);
        }
#line 2263 "y.tab.c"
    break;

  case 92: /* arg_list: error ',' expression  */
#line 420 "c-grammar.y"
        {
            printf("C--:incorrent function arg_list;\n");
            exit(1);
        }
#line 2272 "y.tab.c"
    break;


#line 2276 "y.tab.c"

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
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
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

#line 426 "c-grammar.y"

#define SIZE_OF_NODE ((char *)&p->content - (char *)p)

Node *set_content(int value) 
{
	Node *p;
	size_t sizeNode;
	/* 分配结点空间 */
	sizeNode = SIZE_OF_NODE + sizeof(int);
	
	if ((p = malloc(sizeNode)) == NULL)
		yyerror("out of memory");
		
	/* 复制内容 */
	p->type = TYPE_CONTENT;
	p->content = value;

	return p;
}

Node *set_index(int value) 
{
	Node *p;
	size_t sizeNode;
	/* 分配结点空间 */
	sizeNode = SIZE_OF_NODE + sizeof(int);
	if ((p = malloc(sizeNode)) == NULL)
		yyerror("out of memory"); 
	
	/* 复制内容 */
	p->type = TYPE_INDEX;
	p->index = value;  
	return p;
}

Node *createNode(int name, int num, ...) 
{
	va_list valist;
	Node *p;
	size_t sizeNode;
	int i;
	/* 分配结点空间 */
	sizeNode = SIZE_OF_NODE + sizeof(OpNode) + (num - 1) * sizeof(Node*);
 
	if ((p = malloc(sizeNode)) == NULL)
		yyerror("out of memory"); 
		
	/* 复制内容 */
	p->type = TYPE_OP;
	p->op.name = name;
	p->op.num = num;
	va_start(valist, num);
 
	for (i = 0; i < num; i++)
		p->op.node[i] = va_arg(valist, Node*);
		
	va_end(valist);
	return p;
}

void printTree(Node *node){
    printf("node");
}

void freeNode(Node *p) 
{
	int i;
	if (!p) return;
	if (p->type == TYPE_OP) {
		for (i = 0; i < p->op.num; i++)
            freeNode(p->op.node[i]);
	}
	free (p);
}

void yyerror(char *s) 
{
   printf("%s\n", s);
}

int main() 
{

    hash_init(var_local, HASHSIZE);
    hash_init(var_local_SorA, HASHSIZE);
    hash_init(var_local_GorP, HASHSIZE);

    yyparse();

    return 0;
}
