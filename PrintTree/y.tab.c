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
#line 1 "printTree.y"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include "node.h"
#include "queue.h"
int yydebug =1;
Node *tmp;
Node* Tree;

extern int yylex(void);

/* 属性操作类型 */
void freeNode(Node *p);
int exeNode(Node *p, int signal, int* calling_func);
int yylexeNode(void);
void yyerror(char *s);
void PrintfNode(Node * node);
Node* opr(int row,int column,int name,int num,...);
Node* set_oprNode(LexNode lex,int num,int name);
Node* set_typeNode(LexNode lex,int type);
Node* set_constantNode(LexNode lex);
Node* set_indexNode(LexNode lex);
Node* root = NULL;

#line 98 "y.tab.c"

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
    ErrorIDENTIFIER = 262,         /* ErrorIDENTIFIER  */
    STRING_LITERAL = 263,          /* STRING_LITERAL  */
    LE_OP = 264,                   /* LE_OP  */
    GE_OP = 265,                   /* GE_OP  */
    EQ_OP = 266,                   /* EQ_OP  */
    NE_OP = 267,                   /* NE_OP  */
    IF = 268,                      /* IF  */
    ELSE = 269,                    /* ELSE  */
    WHILE = 270,                   /* WHILE  */
    FOR = 271,                     /* FOR  */
    RETURN = 272,                  /* RETURN  */
    PARAM = 273,                   /* PARAM  */
    FUNC = 274,                    /* FUNC  */
    VAR = 275,                     /* VAR  */
    CALL = 276,                    /* CALL  */
    GLOBAL_VAR = 277               /* GLOBAL_VAR  */
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
#define ErrorIDENTIFIER 262
#define STRING_LITERAL 263
#define LE_OP 264
#define GE_OP 265
#define EQ_OP 266
#define NE_OP 267
#define IF 268
#define ELSE 269
#define WHILE 270
#define FOR 271
#define RETURN 272
#define PARAM 273
#define FUNC 274
#define VAR 275
#define CALL 276
#define GLOBAL_VAR 277

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 28 "printTree.y"

    LexNode lexNode;
    Node *nPtr;

#line 200 "y.tab.c"

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
  YYSYMBOL_ErrorIDENTIFIER = 7,            /* ErrorIDENTIFIER  */
  YYSYMBOL_STRING_LITERAL = 8,             /* STRING_LITERAL  */
  YYSYMBOL_LE_OP = 9,                      /* LE_OP  */
  YYSYMBOL_GE_OP = 10,                     /* GE_OP  */
  YYSYMBOL_EQ_OP = 11,                     /* EQ_OP  */
  YYSYMBOL_NE_OP = 12,                     /* NE_OP  */
  YYSYMBOL_13_ = 13,                       /* '+'  */
  YYSYMBOL_14_ = 14,                       /* '-'  */
  YYSYMBOL_15_ = 15,                       /* '<'  */
  YYSYMBOL_16_ = 16,                       /* '>'  */
  YYSYMBOL_17_ = 17,                       /* '*'  */
  YYSYMBOL_18_ = 18,                       /* '='  */
  YYSYMBOL_19_ = 19,                       /* '/'  */
  YYSYMBOL_20_ = 20,                       /* ','  */
  YYSYMBOL_21_ = 21,                       /* '{'  */
  YYSYMBOL_22_ = 22,                       /* '}'  */
  YYSYMBOL_IF = 23,                        /* IF  */
  YYSYMBOL_ELSE = 24,                      /* ELSE  */
  YYSYMBOL_WHILE = 25,                     /* WHILE  */
  YYSYMBOL_FOR = 26,                       /* FOR  */
  YYSYMBOL_RETURN = 27,                    /* RETURN  */
  YYSYMBOL_PARAM = 28,                     /* PARAM  */
  YYSYMBOL_FUNC = 29,                      /* FUNC  */
  YYSYMBOL_VAR = 30,                       /* VAR  */
  YYSYMBOL_CALL = 31,                      /* CALL  */
  YYSYMBOL_GLOBAL_VAR = 32,                /* GLOBAL_VAR  */
  YYSYMBOL_33_ = 33,                       /* ';'  */
  YYSYMBOL_34_ = 34,                       /* '['  */
  YYSYMBOL_35_ = 35,                       /* ']'  */
  YYSYMBOL_36_ = 36,                       /* '('  */
  YYSYMBOL_37_ = 37,                       /* ')'  */
  YYSYMBOL_YYACCEPT = 38,                  /* $accept  */
  YYSYMBOL_program = 39,                   /* program  */
  YYSYMBOL_declaration_list = 40,          /* declaration_list  */
  YYSYMBOL_declaration = 41,               /* declaration  */
  YYSYMBOL_var_declaration = 42,           /* var_declaration  */
  YYSYMBOL_type_specifier = 43,            /* type_specifier  */
  YYSYMBOL_fun_declaration = 44,           /* fun_declaration  */
  YYSYMBOL_params = 45,                    /* params  */
  YYSYMBOL_params_list = 46,               /* params_list  */
  YYSYMBOL_param = 47,                     /* param  */
  YYSYMBOL_compound_stmt = 48,             /* compound_stmt  */
  YYSYMBOL_local_declarations = 49,        /* local_declarations  */
  YYSYMBOL_statement_list = 50,            /* statement_list  */
  YYSYMBOL_statement = 51,                 /* statement  */
  YYSYMBOL_expression_stmt = 52,           /* expression_stmt  */
  YYSYMBOL_selection_stmt = 53,            /* selection_stmt  */
  YYSYMBOL_iteration_stmt = 54,            /* iteration_stmt  */
  YYSYMBOL_return_stmt = 55,               /* return_stmt  */
  YYSYMBOL_expression = 56,                /* expression  */
  YYSYMBOL_var = 57,                       /* var  */
  YYSYMBOL_simple_expression = 58,         /* simple_expression  */
  YYSYMBOL_relop = 59,                     /* relop  */
  YYSYMBOL_additive_expression = 60,       /* additive_expression  */
  YYSYMBOL_addop = 61,                     /* addop  */
  YYSYMBOL_term = 62,                      /* term  */
  YYSYMBOL_mulop = 63,                     /* mulop  */
  YYSYMBOL_factor = 64,                    /* factor  */
  YYSYMBOL_call = 65,                      /* call  */
  YYSYMBOL_args = 66,                      /* args  */
  YYSYMBOL_arg_list = 67                   /* arg_list  */
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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   480

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  90
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  147

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   277


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
      36,    37,    17,    13,    20,    14,     2,    19,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    33,
      15,    18,    16,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    34,     2,    35,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    21,     2,    22,     2,     2,     2,     2,
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
       5,     6,     7,     8,     9,    10,    11,    12,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    55,    55,    62,    63,    67,    71,    75,    82,    89,
      98,    99,   103,   112,   113,   117,   118,   119,   128,   135,
     142,   151,   160,   162,   171,   172,   176,   177,   181,   182,
     183,   184,   185,   189,   190,   194,   195,   197,   203,   209,
     215,   221,   227,   233,   242,   243,   249,   258,   259,   260,
     266,   275,   279,   283,   284,   293,   297,   298,   310,   319,
     320,   321,   322,   323,   324,   328,   332,   337,   343,   351,
     352,   356,   360,   361,   367,   376,   377,   381,   382,   383,
     384,   388,   394,   402,   410,   421,   422,   426,   427,   428,
     434
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
  "VOID", "IDENTIFIER", "ErrorIDENTIFIER", "STRING_LITERAL", "LE_OP",
  "GE_OP", "EQ_OP", "NE_OP", "'+'", "'-'", "'<'", "'>'", "'*'", "'='",
  "'/'", "','", "'{'", "'}'", "IF", "ELSE", "WHILE", "FOR", "RETURN",
  "PARAM", "FUNC", "VAR", "CALL", "GLOBAL_VAR", "';'", "'['", "']'", "'('",
  "')'", "$accept", "program", "declaration_list", "declaration",
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
     265,   266,   267,    43,    45,    60,    62,    42,    61,    47,
      44,   123,   125,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,    59,    91,    93,    40,    41
};
#endif

#define YYPACT_NINF (-74)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-87)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       1,   -74,   -74,    37,     1,   -74,   -74,    33,   -74,   -74,
     -74,   -18,    74,   -74,   -74,    41,   127,    31,    35,    58,
      51,    13,   -74,    57,   -74,    12,    75,     1,     1,   -74,
     -74,    63,   -74,   -74,   -74,   -74,   -74,     1,   -74,    86,
     363,   100,   268,   -74,    66,   -74,     9,    19,    15,   -74,
      16,   -74,   -74,   -74,   -74,   -74,   -74,    72,    93,   -74,
     169,   198,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,
      32,   103,    16,     6,   386,    25,   386,    16,   447,   -74,
      95,   268,    84,   -74,    16,    32,   -74,   -74,    59,    88,
      32,   -74,   -74,   124,   -74,   227,   239,   -74,    98,   256,
     107,    10,   113,   140,   110,   -74,   111,   -74,   -74,   -74,
     -74,   285,   -74,   314,   -74,   343,   -74,   -74,   -74,    16,
     -74,    16,    16,   -74,   -74,   -74,   386,   386,   129,   400,
     414,   -74,   -74,   -74,   -74,   -74,   386,   210,   130,   268,
     -74,   -74,   386,   428,   -74,   268,   -74
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    10,    11,     0,     2,     4,     5,     0,     6,     1,
       3,     0,     0,     9,     7,     0,     0,     0,    11,     0,
       0,     0,    16,     0,    21,     0,     0,     0,     0,     8,
      20,     0,    25,    12,    17,    15,    19,    27,    24,     0,
       0,     0,    23,    80,     0,    22,     0,     0,     0,    34,
       0,    29,    26,    28,    30,    31,    32,     0,    78,    52,
       0,     0,    72,    79,    59,    62,    63,    64,    60,    61,
       0,     0,     0,     0,     0,     0,     0,     0,    50,    47,
       0,     0,     0,    33,     0,     0,    69,    70,     0,     0,
       0,    75,    76,     0,    78,     0,     0,    88,    83,     0,
       0,     0,    38,     0,     0,    45,     0,    49,    48,    77,
      51,     0,    58,     0,    68,     0,    73,    74,    71,     0,
      82,     0,     0,    54,    84,    81,     0,     0,     0,     0,
       0,    90,    89,    87,    37,    39,     0,    42,    35,    46,
      44,    40,     0,     0,    41,    43,    36
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -74,   -74,   -74,   153,   121,     4,   -74,   -74,   -74,   117,
     133,   -74,   -74,   -73,   -74,   -74,   -74,   -74,   -48,   102,
     -74,   104,   -30,   -74,     8,   -74,    36,   -74,    89,   -74
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,     5,     6,    19,     8,    20,    21,    22,
      51,    37,    40,    52,    53,    54,    55,    56,    57,    58,
      59,    70,    60,    89,    61,    93,    62,    63,    98,    99
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      80,   102,    82,   105,     7,     1,     2,    96,     7,    43,
      74,   124,    44,    30,    27,    13,    78,    81,    43,    43,
      76,    44,    44,    97,   100,    97,   103,   104,    43,   106,
     128,    44,   -18,    28,    11,    43,   110,     9,    44,    12,
      95,    39,    50,   -86,    17,    75,    31,   125,    79,   -18,
     -13,    50,    50,   134,   135,    77,   138,   140,   113,    24,
     112,    50,    43,   141,    25,    44,    23,    71,    50,   144,
     146,   131,   -14,   132,   133,   -53,   -53,   -53,   -53,   -53,
     -53,   -53,   -53,   -53,   -53,   -53,   -53,    11,    26,   114,
      29,    43,    41,   111,    44,    50,    32,   115,    36,   -53,
      72,   -53,    73,   -53,    96,    83,    43,    14,    15,    44,
      16,    84,   -86,   -86,   -86,   -86,   -86,   -86,   -86,   -86,
     -86,   109,   -86,   -86,    50,   117,   116,    43,   108,   118,
      44,     1,    18,    14,    15,   120,   -86,   126,   -86,    50,
     -86,    81,   123,    43,    34,    35,    44,   129,   130,    64,
      65,    66,    67,   136,   143,    68,    69,    10,    38,    33,
      50,    32,   101,    46,    88,    47,     0,    48,     0,     0,
      85,     0,    94,    49,     0,     0,    50,   127,    64,    65,
      66,    67,    86,    87,    68,    69,   -56,    94,   -56,   -56,
      94,    94,    94,     0,     0,    94,     0,     0,     0,    90,
       0,     0,   -56,     0,   -56,     0,   -56,   -66,   -66,   -66,
     -66,   -66,   -66,   -66,   -66,    91,     0,    92,   -66,    64,
      65,    66,    67,     0,     0,    68,    69,     0,    85,     0,
       0,   -66,     0,   -66,   142,   -66,   -57,   -57,   -57,   -57,
      86,    87,   -57,   -57,   -57,     0,   -57,   -57,    64,    65,
      66,    67,     0,     0,    68,    69,     0,   121,     0,   119,
     -57,     0,   -57,     0,   -57,   -85,   -85,   -85,   -85,   -85,
     -85,   -85,   -85,   -85,     0,   -85,   122,    64,    65,    66,
      67,     0,     0,    68,    69,     0,    90,     0,     0,   -85,
       0,   -85,     0,   -85,   -67,   -67,   -67,   -67,   -67,   -67,
     -67,   -67,    91,     0,    92,   -67,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    85,     0,     0,   -67,     0,
     -67,     0,   -67,   -55,   -55,   -55,   -55,    86,    87,   -55,
     -55,   -55,     0,   -55,   -55,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    90,     0,     0,   -55,     0,   -55,
       0,   -55,   -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,
      91,     0,    92,   -65,    42,     0,    43,     0,     0,    44,
       0,     0,     0,     0,     0,     0,   -65,     0,   -65,     0,
     -65,     0,     0,     0,    32,    45,    46,    81,    47,    43,
      48,     0,    44,     0,     0,     0,    49,     0,     0,    50,
       0,   137,     0,    43,     0,     0,    44,    32,     0,    46,
       0,    47,     0,    48,     0,   139,     0,    43,     0,    49,
      44,    32,    50,    46,     0,    47,     0,    48,     0,   145,
       0,    43,     0,    49,    44,    32,    50,    46,     0,    47,
       0,    48,     0,     0,     0,     0,     0,    49,     0,    32,
      50,    46,     0,    47,     0,    48,    64,    65,    66,    67,
       0,    49,    68,    69,    50,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     107
};

static const yytype_int16 yycheck[] =
{
      48,    74,    50,    76,     0,     4,     5,     1,     4,     3,
       1,     1,     6,     1,     1,    33,     1,     1,     3,     3,
       1,     6,     6,    71,    72,    73,     1,    75,     3,    77,
     103,     6,    20,    20,     1,     3,    84,     0,     6,     6,
      70,    37,    36,    37,     3,    36,    34,    37,    33,    37,
      37,    36,    36,   126,   127,    36,   129,   130,    88,     1,
       1,    36,     3,   136,     6,     6,    35,     1,    36,   142,
     143,   119,    37,   121,   122,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,     1,    37,     1,
      33,     3,     6,    85,     6,    36,    21,    89,    35,    33,
      34,    35,    36,    37,     1,    33,     3,    33,    34,     6,
      36,    18,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    37,    19,    20,    36,     1,    90,     3,    33,    93,
       6,     4,     5,    33,    34,    37,    33,    24,    35,    36,
      37,     1,    35,     3,    27,    28,     6,    37,    37,     9,
      10,    11,    12,    24,    24,    15,    16,     4,    37,    26,
      36,    21,    73,    23,    60,    25,    -1,    27,    -1,    -1,
       1,    -1,    70,    33,    -1,    -1,    36,    37,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    85,    19,    20,
      88,    89,    90,    -1,    -1,    93,    -1,    -1,    -1,     1,
      -1,    -1,    33,    -1,    35,    -1,    37,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    -1,    19,    20,     9,
      10,    11,    12,    -1,    -1,    15,    16,    -1,     1,    -1,
      -1,    33,    -1,    35,    24,    37,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    -1,    19,    20,     9,    10,
      11,    12,    -1,    -1,    15,    16,    -1,     1,    -1,    20,
      33,    -1,    35,    -1,    37,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    -1,    19,    20,     9,    10,    11,
      12,    -1,    -1,    15,    16,    -1,     1,    -1,    -1,    33,
      -1,    35,    -1,    37,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    -1,    19,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    -1,    -1,    33,    -1,
      35,    -1,    37,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    -1,    19,    20,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    -1,    -1,    33,    -1,    35,
      -1,    37,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    -1,    19,    20,     1,    -1,     3,    -1,    -1,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    35,    -1,
      37,    -1,    -1,    -1,    21,    22,    23,     1,    25,     3,
      27,    -1,     6,    -1,    -1,    -1,    33,    -1,    -1,    36,
      -1,     1,    -1,     3,    -1,    -1,     6,    21,    -1,    23,
      -1,    25,    -1,    27,    -1,     1,    -1,     3,    -1,    33,
       6,    21,    36,    23,    -1,    25,    -1,    27,    -1,     1,
      -1,     3,    -1,    33,     6,    21,    36,    23,    -1,    25,
      -1,    27,    -1,    -1,    -1,    -1,    -1,    33,    -1,    21,
      36,    23,    -1,    25,    -1,    27,     9,    10,    11,    12,
      -1,    33,    15,    16,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      33
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,     5,    39,    40,    41,    42,    43,    44,     0,
      41,     1,     6,    33,    33,    34,    36,     3,     5,    43,
      45,    46,    47,    35,     1,     6,    37,     1,    20,    33,
       1,    34,    21,    48,    47,    47,    35,    49,    42,    43,
      50,     6,     1,     3,     6,    22,    23,    25,    27,    33,
      36,    48,    51,    52,    53,    54,    55,    56,    57,    58,
      60,    62,    64,    65,     9,    10,    11,    12,    15,    16,
      59,     1,    34,    36,     1,    36,     1,    36,     1,    33,
      56,     1,    56,    33,    18,     1,    13,    14,    59,    61,
       1,    17,    19,    63,    57,    60,     1,    56,    66,    67,
      56,    66,    51,     1,    56,    51,    56,    33,    33,    37,
      56,    62,     1,    60,     1,    62,    64,     1,    64,    20,
      37,     1,    20,    35,     1,    37,    24,    37,    51,    37,
      37,    56,    56,    56,    51,    51,    24,     1,    51,     1,
      51,    51,    24,    24,    51,     1,    51
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    38,    39,    40,    40,    41,    41,    42,    42,    42,
      43,    43,    44,    45,    45,    46,    46,    46,    47,    47,
      47,    47,    48,    48,    49,    49,    50,    50,    51,    51,
      51,    51,    51,    52,    52,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    54,    54,    54,    55,    55,    55,
      55,    56,    56,    57,    57,    58,    58,    58,    58,    59,
      59,    59,    59,    59,    59,    60,    60,    60,    60,    61,
      61,    62,    62,    62,    62,    63,    63,    64,    64,    64,
      64,    65,    65,    65,    65,    66,    66,    67,    67,    67,
      67
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     6,     3,
       1,     1,     6,     1,     1,     3,     1,     3,     2,     4,
       3,     2,     4,     4,     2,     0,     2,     0,     1,     1,
       1,     1,     1,     2,     1,     5,     7,     5,     3,     5,
       6,     7,     5,     7,     5,     3,     5,     2,     3,     3,
       2,     3,     1,     1,     4,     3,     1,     3,     3,     1,
       1,     1,     1,     1,     1,     3,     1,     3,     3,     1,
       1,     3,     1,     3,     3,     1,     1,     3,     1,     1,
       1,     4,     4,     3,     4,     1,     0,     3,     1,     3,
       3
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
#line 55 "printTree.y"
                       {
        printf("tree\n");
        PrintTree((yyvsp[0].nPtr), 0);
    }
#line 1424 "y.tab.c"
    break;

  case 3: /* declaration_list: declaration_list declaration  */
#line 62 "printTree.y"
                                   { (yyval.nPtr) = opr( 0 , 0 ,';', 2, (yyvsp[-1].nPtr), (yyvsp[0].nPtr)); }
#line 1430 "y.tab.c"
    break;

  case 4: /* declaration_list: declaration  */
#line 63 "printTree.y"
                  { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1436 "y.tab.c"
    break;

  case 5: /* declaration: var_declaration  */
#line 68 "printTree.y"
        { 
            (yyval.nPtr)  = opr((yyvsp[0].nPtr)->row,(yyvsp[0].nPtr)->column,GLOBAL_VAR,1, (yyvsp[0].nPtr));
        }
#line 1444 "y.tab.c"
    break;

  case 6: /* declaration: fun_declaration  */
#line 71 "printTree.y"
                      { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1450 "y.tab.c"
    break;

  case 7: /* var_declaration: type_specifier IDENTIFIER ';'  */
#line 76 "printTree.y"
        {
            Node *tmp1;
            /* here to insert new var declaration */
            tmp1 = set_indexNode((yyvsp[-1].lexNode));
            (yyval.nPtr) = opr((yyvsp[-1].lexNode).row,(yyvsp[-1].lexNode).column,VAR, 2, (yyvsp[-2].nPtr), tmp1);
        }
#line 1461 "y.tab.c"
    break;

  case 8: /* var_declaration: type_specifier IDENTIFIER '[' CONSTANT ']' ';'  */
#line 83 "printTree.y"
        {
           Node * mid1, * mid2;
           mid1 = set_indexNode((yyvsp[-4].lexNode));
           mid2 = set_constantNode((yyvsp[-2].lexNode));
           (yyval.nPtr) = opr( (yyvsp[-4].lexNode).row,(yyvsp[-4].lexNode).column,VAR, 3, (yyvsp[-5].nPtr), mid1, mid2);
        }
#line 1472 "y.tab.c"
    break;

  case 9: /* var_declaration: type_specifier error ';'  */
#line 90 "printTree.y"
        {
            printf("C-minus(row %d:column %d):error Definition of variate;\n",(yyvsp[-2].nPtr)->row,(yyvsp[-2].nPtr)->column);
            yyerrok;
            (yyval.nPtr) = opr((yyvsp[-2].nPtr)->row,(yyvsp[-2].nPtr)->column,VAR,2,NULL,NULL);
        }
#line 1482 "y.tab.c"
    break;

  case 10: /* type_specifier: INT  */
#line 98 "printTree.y"
          { (yyval.nPtr) = set_typeNode((yyvsp[0].lexNode),0); }
#line 1488 "y.tab.c"
    break;

  case 11: /* type_specifier: VOID  */
#line 99 "printTree.y"
           { (yyval.nPtr) = set_typeNode((yyvsp[0].lexNode),1); }
#line 1494 "y.tab.c"
    break;

  case 12: /* fun_declaration: type_specifier IDENTIFIER '(' params ')' compound_stmt  */
#line 104 "printTree.y"
        {
           Node *tmp1;
           tmp1 = set_indexNode((yyvsp[-4].lexNode));
           (yyval.nPtr) = opr( (yyvsp[-4].lexNode).row, (yyvsp[-4].lexNode).column , FUNC,4, (yyvsp[-5].nPtr), tmp1, (yyvsp[-2].nPtr),(yyvsp[0].nPtr));
        }
#line 1504 "y.tab.c"
    break;

  case 13: /* params: params_list  */
#line 112 "printTree.y"
                  { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1510 "y.tab.c"
    break;

  case 14: /* params: VOID  */
#line 113 "printTree.y"
           { (yyval.nPtr) = set_typeNode((yyvsp[0].lexNode),1); }
#line 1516 "y.tab.c"
    break;

  case 15: /* params_list: params_list ',' param  */
#line 117 "printTree.y"
                            { (yyval.nPtr) = opr((yyvsp[-1].lexNode).row,(yyvsp[-1].lexNode).column, ',', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1522 "y.tab.c"
    break;

  case 16: /* params_list: param  */
#line 118 "printTree.y"
            { (yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1528 "y.tab.c"
    break;

  case 17: /* params_list: params_list error param  */
#line 120 "printTree.y"
    {
        printf("C-minus(row %d:column %d):disappear ',' in function declaration;\n",(yyvsp[-2].nPtr)->row,(yyvsp[-2].nPtr)->column);
        yyerrok;
        (yyval.nPtr) = opr((yyvsp[-2].nPtr)->row,(yyvsp[-2].nPtr)->column, ',', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));
    }
#line 1538 "y.tab.c"
    break;

  case 18: /* param: type_specifier IDENTIFIER  */
#line 129 "printTree.y"
        {
           Node *tmp1;
            /* here to insert new var declaration */
           tmp1 = set_indexNode((yyvsp[0].lexNode));
           (yyval.nPtr) = opr( (yyvsp[0].lexNode).row , (yyvsp[0].lexNode).column , PARAM, 2, (yyvsp[-1].nPtr), tmp1);
        }
#line 1549 "y.tab.c"
    break;

  case 19: /* param: type_specifier IDENTIFIER '[' ']'  */
#line 136 "printTree.y"
        {
            Node *tmp1;
            /* here to insert new var declaration */
            tmp1 = set_indexNode((yyvsp[-2].lexNode));
            (yyval.nPtr) = opr( (yyvsp[-2].lexNode).row , (yyvsp[-2].lexNode).column ,PARAM,3, (yyvsp[-3].nPtr), tmp1, NULL);
        }
#line 1560 "y.tab.c"
    break;

  case 20: /* param: type_specifier IDENTIFIER error  */
#line 143 "printTree.y"
        {
            printf("C-minus(row %d:column %d):error declaration of function params;\n",(yyvsp[-2].nPtr)->row,(yyvsp[-2].nPtr)->column);
            yyerrok;
            Node *tmp1;
            /* here to insert new var declaration */
            tmp1 = set_indexNode((yyvsp[-1].lexNode));
            (yyval.nPtr) = opr( (yyvsp[-1].lexNode).row , (yyvsp[-1].lexNode).column ,PARAM,2, (yyvsp[-2].nPtr), tmp1);
        }
#line 1573 "y.tab.c"
    break;

  case 21: /* param: type_specifier error  */
#line 152 "printTree.y"
        {
            printf("C-minus(row %d:column %d):error declaration of function params;\n",(yyvsp[-1].nPtr)->row,(yyvsp[-1].nPtr)->column);
            yyerrok;
            (yyval.nPtr) = opr( (yyvsp[-1].nPtr)->row , (yyvsp[-1].nPtr)->column ,PARAM,2, (yyvsp[-1].nPtr), NULL);
        }
#line 1583 "y.tab.c"
    break;

  case 22: /* compound_stmt: '{' local_declarations statement_list '}'  */
#line 161 "printTree.y"
        { (yyval.nPtr) = opr( (yyvsp[-3].lexNode).row,(yyvsp[-3].lexNode).column, '{', 2, (yyvsp[-2].nPtr), (yyvsp[-1].nPtr)); }
#line 1589 "y.tab.c"
    break;

  case 23: /* compound_stmt: '{' local_declarations statement_list error  */
#line 163 "printTree.y"
        {
            printf("C-minus(row %d:column %d):disappear '}' for the function body;\n",(yyvsp[-3].lexNode).row,(yyvsp[-3].lexNode).column);
            yyerrok;
            (yyval.nPtr) = opr( (yyvsp[-3].lexNode).row,(yyvsp[-3].lexNode).column, '{', 2, (yyvsp[-2].nPtr), (yyvsp[-1].nPtr)); 
        }
#line 1599 "y.tab.c"
    break;

  case 24: /* local_declarations: local_declarations var_declaration  */
#line 171 "printTree.y"
                                         { (yyval.nPtr) = opr((yyvsp[0].nPtr)->row,(yyvsp[0].nPtr)->column,';', 2, (yyvsp[-1].nPtr), (yyvsp[0].nPtr));}
#line 1605 "y.tab.c"
    break;

  case 25: /* local_declarations: %empty  */
#line 172 "printTree.y"
                  { (yyval.nPtr) = NULL; }
#line 1611 "y.tab.c"
    break;

  case 26: /* statement_list: statement_list statement  */
#line 176 "printTree.y"
                               { (yyval.nPtr) = opr((yyvsp[0].nPtr)->row , (yyvsp[0].nPtr)->column , ';',  2, (yyvsp[-1].nPtr), (yyvsp[0].nPtr)); }
#line 1617 "y.tab.c"
    break;

  case 27: /* statement_list: %empty  */
#line 177 "printTree.y"
                  { (yyval.nPtr) = NULL; }
#line 1623 "y.tab.c"
    break;

  case 28: /* statement: expression_stmt  */
#line 181 "printTree.y"
                      { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1629 "y.tab.c"
    break;

  case 29: /* statement: compound_stmt  */
#line 182 "printTree.y"
                    {  (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1635 "y.tab.c"
    break;

  case 30: /* statement: selection_stmt  */
#line 183 "printTree.y"
                     { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1641 "y.tab.c"
    break;

  case 31: /* statement: iteration_stmt  */
#line 184 "printTree.y"
                     { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1647 "y.tab.c"
    break;

  case 32: /* statement: return_stmt  */
#line 185 "printTree.y"
                  { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1653 "y.tab.c"
    break;

  case 33: /* expression_stmt: expression ';'  */
#line 189 "printTree.y"
                     {  (yyval.nPtr) = (yyvsp[-1].nPtr);  }
#line 1659 "y.tab.c"
    break;

  case 34: /* expression_stmt: ';'  */
#line 190 "printTree.y"
          { (yyval.nPtr) = NULL; }
#line 1665 "y.tab.c"
    break;

  case 35: /* selection_stmt: IF '(' expression ')' statement  */
#line 194 "printTree.y"
                                      { (yyval.nPtr) = opr( (yyvsp[-4].lexNode).row , (yyvsp[-4].lexNode).column, IF, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1671 "y.tab.c"
    break;

  case 36: /* selection_stmt: IF '(' expression ')' statement ELSE statement  */
#line 196 "printTree.y"
        { (yyval.nPtr) = opr( (yyvsp[-6].lexNode).row , (yyvsp[-6].lexNode).column , IF, 3, (yyvsp[-4].nPtr), (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1677 "y.tab.c"
    break;

  case 37: /* selection_stmt: IF error statement ELSE statement  */
#line 198 "printTree.y"
    {
        printf("C-minus(row %d,column %d):disappear boolean statement;\n",(yyvsp[-4].lexNode).row,(yyvsp[-4].lexNode).column);
        yyerrok;
        (yyval.nPtr) = opr((yyvsp[-4].lexNode).column,(yyvsp[-4].lexNode).column,IF,3,NULL,(yyvsp[-2].nPtr),(yyvsp[0].nPtr));
    }
#line 1687 "y.tab.c"
    break;

  case 38: /* selection_stmt: IF error statement  */
#line 204 "printTree.y"
    {
        printf("C-minus(row %d,column %d):disappear boolean statement;\n",(yyvsp[-2].lexNode).row,(yyvsp[-2].lexNode).column);
        yyerrok;
        (yyval.nPtr) = opr((yyvsp[-2].lexNode).column,(yyvsp[-2].lexNode).column,IF,2,NULL,(yyvsp[0].nPtr));
    }
#line 1697 "y.tab.c"
    break;

  case 39: /* selection_stmt: IF '(' error ')' statement  */
#line 210 "printTree.y"
    {
        printf("C-minus(row %d,column %d):disappear boolean statement;\n",(yyvsp[-4].lexNode).row,(yyvsp[-4].lexNode).column);
        yyerrok;
        (yyval.nPtr) = opr((yyvsp[-4].lexNode).column,(yyvsp[-4].lexNode).column,IF,2,NULL,(yyvsp[0].nPtr));
    }
#line 1707 "y.tab.c"
    break;

  case 40: /* selection_stmt: IF '(' error statement ELSE statement  */
#line 216 "printTree.y"
    {
        printf("C-minus(row %d,column %d):disappear boolean statement and ')';\n",(yyvsp[-5].lexNode).row,(yyvsp[-5].lexNode).column);
        yyerrok;
        (yyval.nPtr) = opr((yyvsp[-5].lexNode).column,(yyvsp[-5].lexNode).column,IF,3,NULL,(yyvsp[-2].nPtr),(yyvsp[0].nPtr));
    }
#line 1717 "y.tab.c"
    break;

  case 41: /* selection_stmt: IF '(' expression ')' error ELSE statement  */
#line 222 "printTree.y"
    {
        printf("C-minus(row %d,column %d):disappear IF statement;\n",(yyvsp[-6].lexNode).row,(yyvsp[-6].lexNode).column);
        yyerrok;
        (yyval.nPtr) = opr((yyvsp[-6].lexNode).column,(yyvsp[-6].lexNode).column,IF,3,(yyvsp[-4].nPtr),NULL,(yyvsp[0].nPtr));
    }
#line 1727 "y.tab.c"
    break;

  case 42: /* selection_stmt: IF '(' expression ')' error  */
#line 228 "printTree.y"
    {
        printf("C-minus(row %d,column %d):disappear IF statement;\n",(yyvsp[-4].lexNode).row,(yyvsp[-4].lexNode).column);
        yyerrok;
        (yyval.nPtr) = opr((yyvsp[-4].lexNode).column,(yyvsp[-4].lexNode).column,IF,2,(yyvsp[-2].nPtr),NULL);
    }
#line 1737 "y.tab.c"
    break;

  case 43: /* selection_stmt: IF '(' expression ')' statement ELSE error  */
#line 234 "printTree.y"
    {
        printf("C-minus(row %d,column %d):disappear ELSE statement;\n",(yyvsp[-6].lexNode).row,(yyvsp[-6].lexNode).column);
        yyerrok;
        (yyval.nPtr) = opr((yyvsp[-6].lexNode).column,(yyvsp[-6].lexNode).column,IF,3,NULL,(yyvsp[-4].nPtr),(yyvsp[-2].nPtr));
    }
#line 1747 "y.tab.c"
    break;

  case 44: /* iteration_stmt: WHILE '(' expression ')' statement  */
#line 242 "printTree.y"
                                         {  (yyval.nPtr) = opr( (yyvsp[-4].lexNode).row , (yyvsp[-4].lexNode).column , WHILE, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1753 "y.tab.c"
    break;

  case 45: /* iteration_stmt: WHILE error statement  */
#line 244 "printTree.y"
    {
        printf("C-minus(row %d,column %d):disappear while boolean statement;\n",(yyvsp[-2].lexNode).row,(yyvsp[-2].lexNode).column);
        yyerrok;
        (yyval.nPtr) = opr((yyvsp[-2].lexNode).column,(yyvsp[-2].lexNode).column,WHILE,2,NULL,(yyvsp[0].nPtr));
    }
#line 1763 "y.tab.c"
    break;

  case 46: /* iteration_stmt: WHILE '(' expression ')' error  */
#line 250 "printTree.y"
    {
        printf("C-minus(row %d,column %d):disappear while statement;\n",(yyvsp[-4].lexNode).row,(yyvsp[-4].lexNode).column);
        yyerrok;
        (yyval.nPtr) = opr((yyvsp[-4].lexNode).column,(yyvsp[-4].lexNode).column,WHILE,2,(yyvsp[-2].nPtr),NULL);
    }
#line 1773 "y.tab.c"
    break;

  case 47: /* return_stmt: RETURN ';'  */
#line 258 "printTree.y"
                 { (yyval.nPtr) = opr((yyvsp[-1].lexNode).row , (yyvsp[-1].lexNode).column , RETURN,  0); }
#line 1779 "y.tab.c"
    break;

  case 48: /* return_stmt: RETURN expression ';'  */
#line 259 "printTree.y"
                            { (yyval.nPtr) = opr((yyvsp[-2].lexNode).row , (yyvsp[-2].lexNode).column ,  RETURN,  1, (yyvsp[-1].nPtr)); }
#line 1785 "y.tab.c"
    break;

  case 49: /* return_stmt: RETURN error ';'  */
#line 261 "printTree.y"
        {
            printf("C-minus(row %d,column %d):error return statement;\n",(yyvsp[-2].lexNode).row,(yyvsp[-2].lexNode).column);
            yyerrok;
            (yyval.nPtr) = opr((yyvsp[-2].lexNode).column,(yyvsp[-2].lexNode).column,RETURN,1,NULL);
        }
#line 1795 "y.tab.c"
    break;

  case 50: /* return_stmt: RETURN error  */
#line 267 "printTree.y"
        {
            printf("C-minus(row %d,column %d):error return statement;\n",(yyvsp[-1].lexNode).row,(yyvsp[-1].lexNode).column);
            yyerrok;
            (yyval.nPtr) = opr((yyvsp[-1].lexNode).row,(yyvsp[-1].lexNode).column,RETURN,1,NULL);
        }
#line 1805 "y.tab.c"
    break;

  case 51: /* expression: var '=' expression  */
#line 276 "printTree.y"
        {
            (yyval.nPtr) = opr( (yyvsp[-1].lexNode).row , (yyvsp[-1].lexNode).column , '=', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));
        }
#line 1813 "y.tab.c"
    break;

  case 52: /* expression: simple_expression  */
#line 279 "printTree.y"
                        { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1819 "y.tab.c"
    break;

  case 53: /* var: IDENTIFIER  */
#line 283 "printTree.y"
                 {  (yyval.nPtr) = set_indexNode((yyvsp[0].lexNode));  }
#line 1825 "y.tab.c"
    break;

  case 54: /* var: IDENTIFIER '[' expression ']'  */
#line 285 "printTree.y"
        {
           Node *tmp1;
            tmp1 = set_indexNode((yyvsp[-3].lexNode));
            (yyval.nPtr) = opr( (yyvsp[-3].lexNode).row , (yyvsp[-3].lexNode).column ,'[', 2, tmp1, (yyvsp[-1].nPtr)); 
        }
#line 1835 "y.tab.c"
    break;

  case 55: /* simple_expression: additive_expression relop additive_expression  */
#line 294 "printTree.y"
        {
            (yyval.nPtr) = opr( (yyvsp[-1].nPtr)->row , (yyvsp[-1].nPtr)->column , (yyvsp[-1].nPtr)->op.name, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); 
        }
#line 1843 "y.tab.c"
    break;

  case 56: /* simple_expression: additive_expression  */
#line 297 "printTree.y"
                          { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1849 "y.tab.c"
    break;

  case 57: /* simple_expression: error relop additive_expression  */
#line 299 "printTree.y"
        {
            printf("C-minus(row %d,column %d):disappear compare statement;\n",(yyvsp[-1].nPtr)->row,(yyvsp[-1].nPtr)->column);
            yyerrok;
            (yyval.nPtr) = opr( (yyvsp[-1].nPtr)->row , (yyvsp[-1].nPtr)->column , (yyvsp[-1].nPtr)->op.name, 2, NULL, (yyvsp[0].nPtr)); 
        }
#line 1859 "y.tab.c"
    break;

  case 58: /* simple_expression: additive_expression relop error  */
#line 311 "printTree.y"
        {
            printf("C-minus(row %d,column %d):disappear compare statement;\n",(yyvsp[-2].nPtr)->row,(yyvsp[-2].nPtr)->column);
            yyerrok;
            (yyval.nPtr) = opr( (yyvsp[-1].nPtr)->row , (yyvsp[-1].nPtr)->column , (yyvsp[-1].nPtr)->op.name, 2, (yyvsp[-2].nPtr), NULL); 
        }
#line 1869 "y.tab.c"
    break;

  case 59: /* relop: LE_OP  */
#line 319 "printTree.y"
            { (yyval.nPtr) = set_oprNode((yyvsp[0].lexNode),2,LE_OP); }
#line 1875 "y.tab.c"
    break;

  case 60: /* relop: '<'  */
#line 320 "printTree.y"
          { (yyval.nPtr) = set_oprNode((yyvsp[0].lexNode),2,'<'); }
#line 1881 "y.tab.c"
    break;

  case 61: /* relop: '>'  */
#line 321 "printTree.y"
          { (yyval.nPtr) = set_oprNode((yyvsp[0].lexNode),2,'>'); }
#line 1887 "y.tab.c"
    break;

  case 62: /* relop: GE_OP  */
#line 322 "printTree.y"
            { (yyval.nPtr) = set_oprNode((yyvsp[0].lexNode),2,GE_OP); }
#line 1893 "y.tab.c"
    break;

  case 63: /* relop: EQ_OP  */
#line 323 "printTree.y"
            { (yyval.nPtr) = set_oprNode((yyvsp[0].lexNode),2,EQ_OP); }
#line 1899 "y.tab.c"
    break;

  case 64: /* relop: NE_OP  */
#line 324 "printTree.y"
            { (yyval.nPtr) = set_oprNode((yyvsp[0].lexNode),2,NE_OP); }
#line 1905 "y.tab.c"
    break;

  case 65: /* additive_expression: additive_expression addop term  */
#line 329 "printTree.y"
        {
            (yyval.nPtr) = opr((yyvsp[-1].nPtr)->row,(yyvsp[-1].nPtr)->column,(yyvsp[-1].nPtr)->op.name, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));
        }
#line 1913 "y.tab.c"
    break;

  case 66: /* additive_expression: term  */
#line 333 "printTree.y"
        { 
            (yyval.nPtr) = (yyvsp[0].nPtr);
        }
#line 1921 "y.tab.c"
    break;

  case 67: /* additive_expression: additive_expression error term  */
#line 338 "printTree.y"
    {
        printf("C-minus(row %d,column %d):disappear '/' or '*' or ' '+' or '-' statement;\n",(yyvsp[-2].nPtr)->row,(yyvsp[-2].nPtr)->column);
        yyerrok;
        (yyval.nPtr) = opr((yyvsp[-2].nPtr)->column,(yyvsp[-2].nPtr)->column,'+',1,NULL);
    }
#line 1931 "y.tab.c"
    break;

  case 68: /* additive_expression: additive_expression addop error  */
#line 344 "printTree.y"
    {
        printf("C-minus(row %d,column %d):disappear statement;\n",(yyvsp[-2].nPtr)->row,(yyvsp[-2].nPtr)->column);
        yyerrok;
        (yyval.nPtr) = opr((yyvsp[-1].nPtr)->column,(yyvsp[-1].nPtr)->column,(yyvsp[-1].nPtr)->op.name,2,(yyvsp[-2].nPtr),NULL);
    }
#line 1941 "y.tab.c"
    break;

  case 69: /* addop: '+'  */
#line 351 "printTree.y"
          { (yyval.nPtr) = set_oprNode((yyvsp[0].lexNode),2,'+'); }
#line 1947 "y.tab.c"
    break;

  case 70: /* addop: '-'  */
#line 352 "printTree.y"
          { (yyval.nPtr) = set_oprNode((yyvsp[0].lexNode),2,'-'); }
#line 1953 "y.tab.c"
    break;

  case 71: /* term: term mulop factor  */
#line 357 "printTree.y"
        {
            (yyval.nPtr) = opr((yyvsp[-1].nPtr)->row,(yyvsp[-1].nPtr)->column,(yyvsp[-1].nPtr)->op.name,2,(yyvsp[-2].nPtr),(yyvsp[0].nPtr));
        }
#line 1961 "y.tab.c"
    break;

  case 72: /* term: factor  */
#line 360 "printTree.y"
             { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1967 "y.tab.c"
    break;

  case 73: /* term: term error factor  */
#line 362 "printTree.y"
    {
        printf("C-minus(row %d,column %d):disappear '/' or '* or '+' or '-' statement;\n",(yyvsp[-2].nPtr)->row,(yyvsp[-2].nPtr)->column);
        yyerrok;
        (yyval.nPtr) = opr((yyvsp[0].nPtr)->row,(yyvsp[0].nPtr)->column,'/',1,NULL);
    }
#line 1977 "y.tab.c"
    break;

  case 74: /* term: term mulop error  */
#line 368 "printTree.y"
    {
        printf("C-minus(row %d,column %d):disappear statement;\n",(yyvsp[-2].nPtr)->row,(yyvsp[-2].nPtr)->column);
        yyerrok;
        (yyval.nPtr) = opr((yyvsp[-2].nPtr)->column,(yyvsp[-2].nPtr)->column,(yyvsp[-1].nPtr)->op.name,2,(yyvsp[-2].nPtr),NULL);
    }
#line 1987 "y.tab.c"
    break;

  case 75: /* mulop: '*'  */
#line 376 "printTree.y"
          { (yyval.nPtr) = set_oprNode((yyvsp[0].lexNode),2,'*'); }
#line 1993 "y.tab.c"
    break;

  case 76: /* mulop: '/'  */
#line 377 "printTree.y"
          { (yyval.nPtr) = set_oprNode((yyvsp[0].lexNode),2,'/'); }
#line 1999 "y.tab.c"
    break;

  case 77: /* factor: '(' expression ')'  */
#line 381 "printTree.y"
                         { (yyval.nPtr) = (yyvsp[-1].nPtr); }
#line 2005 "y.tab.c"
    break;

  case 78: /* factor: var  */
#line 382 "printTree.y"
          { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 2011 "y.tab.c"
    break;

  case 79: /* factor: call  */
#line 383 "printTree.y"
           { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 2017 "y.tab.c"
    break;

  case 80: /* factor: CONSTANT  */
#line 384 "printTree.y"
               { (yyval.nPtr) = set_constantNode((yyvsp[0].lexNode));}
#line 2023 "y.tab.c"
    break;

  case 81: /* call: IDENTIFIER '(' args ')'  */
#line 389 "printTree.y"
        { 
           Node *tmp1;
           tmp1 = set_indexNode((yyvsp[-3].lexNode));
           (yyval.nPtr) = opr((yyvsp[-3].lexNode).row,(yyvsp[-3].lexNode).column,CALL,2, tmp1, (yyvsp[-1].nPtr));
        }
#line 2033 "y.tab.c"
    break;

  case 82: /* call: IDENTIFIER error args ')'  */
#line 395 "printTree.y"
        { 
           printf("C-minus(row %d,column %d):disappear '(' statement;\n",(yyvsp[-3].lexNode).row,(yyvsp[-3].lexNode).column);
           yyerrok;
           Node *tmp1;
           tmp1 = set_indexNode((yyvsp[-3].lexNode));
           (yyval.nPtr) = opr((yyvsp[-3].lexNode).row,(yyvsp[-3].lexNode).column,CALL,2, tmp1, (yyvsp[-1].nPtr));
        }
#line 2045 "y.tab.c"
    break;

  case 83: /* call: IDENTIFIER error args  */
#line 403 "printTree.y"
        {
           printf("C-minus(row %d,column %d):disappear '(' and ')' statement;\n",(yyvsp[-2].lexNode).row,(yyvsp[-2].lexNode).column);
           yyerrok;
           Node *tmp1;
           tmp1 = set_indexNode((yyvsp[-2].lexNode));
           (yyval.nPtr) = opr((yyvsp[-2].lexNode).row,(yyvsp[-2].lexNode).column,CALL,2, tmp1, (yyvsp[0].nPtr));
        }
#line 2057 "y.tab.c"
    break;

  case 84: /* call: IDENTIFIER '(' args error  */
#line 411 "printTree.y"
        {
           printf("C-minus(row %d,column %d):disappear ')' statement;\n",(yyvsp[-3].lexNode).row,(yyvsp[-3].lexNode).column);
           yyerrok;
           Node *tmp1;
           tmp1 = set_indexNode((yyvsp[-3].lexNode));
           (yyval.nPtr) = opr((yyvsp[-3].lexNode).row,(yyvsp[-3].lexNode).column,CALL,2, tmp1, (yyvsp[-1].nPtr));
        }
#line 2069 "y.tab.c"
    break;

  case 85: /* args: arg_list  */
#line 421 "printTree.y"
               { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 2075 "y.tab.c"
    break;

  case 86: /* args: %empty  */
#line 422 "printTree.y"
                  { (yyval.nPtr) = NULL; }
#line 2081 "y.tab.c"
    break;

  case 87: /* arg_list: arg_list ',' expression  */
#line 426 "printTree.y"
                              { (yyval.nPtr) = opr((yyvsp[-1].lexNode).row,(yyvsp[-1].lexNode).column,',',2,(yyvsp[-2].nPtr),(yyvsp[0].nPtr)); }
#line 2087 "y.tab.c"
    break;

  case 88: /* arg_list: expression  */
#line 427 "printTree.y"
                 { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 2093 "y.tab.c"
    break;

  case 89: /* arg_list: arg_list error expression  */
#line 429 "printTree.y"
        {
            printf("C-minus(row %d,column %d):incorrent function arg_list;\n",(yyvsp[-2].nPtr)->row,(yyvsp[-2].nPtr)->column);
            yyerrok;
            (yyval.nPtr) = opr((yyvsp[-2].nPtr)->row,(yyvsp[-2].nPtr)->column,',',2,(yyvsp[-2].nPtr),(yyvsp[0].nPtr)); 
        }
#line 2103 "y.tab.c"
    break;

  case 90: /* arg_list: error ',' expression  */
#line 435 "printTree.y"
        {
            printf("C-minus(row %d,column %d):incorrent function arg_list;\n",(yyvsp[0].nPtr)->row,(yyvsp[0].nPtr)->column);
            yyerrok;
            (yyval.nPtr) = opr((yyvsp[0].nPtr)->row,(yyvsp[0].nPtr)->column,',',2,NULL,NULL); 
        }
#line 2113 "y.tab.c"
    break;


#line 2117 "y.tab.c"

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

#line 442 "printTree.y"


 /* New the constant*/
Node* set_constantNode(LexNode lex) 
{
	Node *p = (Node *)(malloc(sizeof(Node)));
	/* 复制内容 */
    p->row = lex.row;
    p->column = lex.column;
	p->type = TYPE_CONSTANT;
	p->content = lex.value;
	return p;
}
 /* New the Identifer*/ 
Node* set_indexNode(LexNode lex) 
{
	Node *p = (Node *)(malloc(sizeof(Node)));
	/* 复制内容 */
    p->row = lex.row;
    p->column = lex.column;
	p->type = TYPE_INDENTIFER;
	p->string = lex.string;  
	return p;
}
 /* New the OpNode*/
OpNode setopNode(int num,int name){
    OpNode op;
    op.name = name;
    op.num = num;
    op.nodeArray = NULL;
    return op;
}
 /* New the opr_Node*/
Node* set_oprNode(LexNode lex,int num,int name){
    Node* p = (Node *)(malloc(sizeof(Node)));
    p->type = TYPE_OP;
    p->row = lex.row;
    p->column = lex.column;
    p->op = setopNode(num,name);
    return p;
}
 /* New the type Node */
Node* set_typeNode(LexNode lex,int type){
    Node* p = (Node*)(malloc(sizeof(Node)));
    p->row = lex.row;
    p->column = lex.column;
    p->type = TYPE_VAR;
    p->var_type = type;
    return p;
}
 /* opnumber 指的是 操作符的number num 代表操作符node数组有几个element*/
Node* opr(int row,int column,int name,int num , ...) 
{
    int i;
	va_list valist;
	Node* p = (Node *)(malloc(sizeof(Node)));
	/* 复制内容 */
    p->row = row;
    p->column = column;
	p->type = TYPE_OP;
	p->op = setopNode(num,name);
    p->op.nodeArray = (Node **)malloc(sizeof(Node *)*num);
	va_start(valist, num);
	for (i = 0; i < num; i++)
		p->op.nodeArray[i] = va_arg(valist, Node*);	
	va_end(valist);
	return p;
}

// void freeNode(Node *p) 
// { 
//     // free every element of tree 分配
// 	int i;
// 	if (!p) return;
// 	if (p->type == TYPE_OP) {
// 		for (i = 0; i < p->op.num; i++)
//             freeNode(p->op.node[i]);
// 	}
// 	free (p);
// }
void yyerror(char *s) 
{
   hasError = 1;
   printf("the syntax error is \n");
}
void PrintfNode(Node * p){
    switch(p->type){
        case TYPE_CONSTANT:
            PRINTF_CONTENT_NODE
            break;
        case TYPE_INDENTIFER:
            PRINTF_INDEX_NODE
            break;
        case TYPE_OP:
        {
            OpNode op = p->op;
            PRINTF_OP_NODE
            break;
        }
        case TYPE_VAR:
            PRINTF_TYPENODE
            break;
    }
}
int main(int argc, char* argv[]) 
{
    if (argc == 2) {
        freopen(argv[1],"r",stdin);
    } else {
        printf("please input like \"parser inputfile\"\n");
    }
    
    int len = strlen(argv[1]);
    char* c = (char*)malloc(sizeof(char)*(len-1));
    memcpy(c, argv[1], len-2);
    c[len-2] = '\0';

    char* asmoutput = (char*)malloc(sizeof(char)*(len+1));
    strcpy(asmoutput, c); asmoutput[len-2] = '.'; asmoutput[len-1] = 's'; asmoutput[len] = '\0';
    freopen(asmoutput, "w", stdout);

    yyparse();
    return 0;
}







