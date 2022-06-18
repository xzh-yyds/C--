/* A Bison parser, made by GNU Bison 3.7.6.  */

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

#line 215 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
