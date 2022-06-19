%{
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

%}

%union {
    int iValue;
    int sIndex;
    Node *nPtr;
};

%token <iValue> CONSTANT INT VOID
%token <sIndex> IDENTIFIER
%token STRING_LITERAL SIZEOF 
%token PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token XOR_ASSIGN OR_ASSIGN TYPE_NAME

%token TYPEDEF EXTERN STATIC AUTO REGISTER INLINE RESTRICT
%token CHAR SHORT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE 
%token BOOL COMPLEX IMAGINARY
%token STRUCT UNION ENUM ELLIPSIS

%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN

%token PARAM FUNC VAR CALL GLOBAL_VAR

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%type <nPtr> term var factor var_declaration local_declarations
%type <nPtr> additive_expression simple_expression expression
%type <nPtr> return_stmt iteration_stmt expression_stmt selection_stmt compound_stmt
%type <nPtr> statement statement_list 
%type <nPtr> param params_list params type_specifier
%type <nPtr> fun_declaration declaration declaration_list
%type <nPtr> call args arg_list
%type <iValue> relop mulop addop

%start program
%%

program
    : declaration_list { exeNode($1, 0); printTree($1); freeNode($1); }
    ;

declaration_list
    : declaration_list declaration { $$ = createNode(';', 2, $1, $2); }
    | declaration { $$ = $1; }
    ;

declaration
    : var_declaration 
        { 
            $$  = createNode(GLOBAL_VAR, 1, $1);
        }
    | fun_declaration { $$ = $1; }
    ;

var_declaration
    : type_specifier IDENTIFIER ';'
        {
            Node *tmp1;
            /* here to insert new var declaration */
            tmp1 = set_index($2);
            $$ = createNode(VAR, 2, $1, tmp1);
        }
    | type_specifier IDENTIFIER '[' CONSTANT ']' ';'
        {
            Node *tmp1, *tmp2;
            tmp1 = set_index($2);
            tmp2 = set_content($4);
            $$ = createNode(VAR, 3, $1, tmp1, tmp2);
        }
    | type_specifier error ';'
        {
            printf("C--:error Definition of variate;\n");
            exit(1);
        }
    ;

type_specifier
    : INT { $$ = set_content(INT); }
    | VOID { $$ = set_content(VOID); }
    ;

fun_declaration
    : type_specifier IDENTIFIER '(' params ')' 
        {
            Node *tmp1;
            tmp1 = set_index($2);
            $$ = createNode(FUNC, 3, $1, tmp1, $4);
        }

    | compound_stmt 
        { $$ = createNode(FUNC, 1, $1); }
    ;

params
    : params_list { $$ = $1; }
    | VOID { $$ = NULL; }
    ;

params_list
    : params_list ',' param { $$ = createNode(',', 2, $1, $3); }
    | param { $$ = $1; }
    | params_list error param 
    {
        printf("C--:disappear ',' in function declaration;\n");
        exit(1);
    }
    ;

param
    : type_specifier IDENTIFIER
        {
            Node *tmp1;
            /* here to insert new var declaration */
            tmp1 = set_index($2);
            $$ = createNode(PARAM, 2, $1, tmp1);
        }
    | type_specifier IDENTIFIER '[' ']'
        {
            Node *tmp1;
            /* here to insert new var declaration */
            tmp1 = set_index($2);
            $$ = createNode(PARAM, 3, $1, tmp1, NULL);
        }
    | type_specifier IDENTIFIER error
        {
            printf("C--:error declaration of function params;\n");
            exit(1);
        }
    | type_specifier error 
        {
            printf("C--:error declaration of function params;\n");
            exit(1);
        }
    ;

compound_stmt
    : '{' local_declarations statement_list '}' 
        { $$ = createNode('{', 2, $2, $3); }
    | '{' local_declarations statement_list error
        {
            printf("C--:disappear '}' for the function body;\n");
            exit(1);
        }
    ;

local_declarations
    : local_declarations var_declaration { $$ = createNode(';', 2, $1, $2); }
    | /* empty */ { $$ = NULL; }
    ;

statement_list
    : statement_list statement { $$ = createNode(';', 2, $1, $2); }
    | /* empty */ { $$ = NULL; }
    ;

statement
    : expression_stmt { $$ = $1; }
    | compound_stmt { $$ = $1; }
    | selection_stmt { $$ = $1; }
    | iteration_stmt { $$ = $1; }
    | return_stmt { $$ = $1; }
    ;

expression_stmt
    : expression ';' { $$ = $1; }
    | ';' { $$ = NULL; }
    ;

selection_stmt
    : IF '(' expression ')' statement { $$ = createNode(IF, 2, $3, $5); }
    | IF '(' expression ')' statement ELSE statement
        { $$ = createNode(IF, 3, $3, $5, $7); }
    | IF error statement ELSE statement 
    {
        printf("C--:disappear boolean statement;\n");
        exit(1);
    }
    | IF error statement
    {
        printf("C--:disappear boolean statement;\n");
        exit(1);
    }
    | IF '(' error ')' statement
    {
        printf("C--:disappear boolean statement;\n");
        exit(1);
    }
    | IF '(' error statement ELSE statement
    {
        printf("C--:disappear boolean statement and ')';\n");
        exit(1);
    }
    | IF '(' expression ')' error ELSE statement
    {
        printf("C--:disappear IF statement;\n");
        exit(1);
    }
    | IF '(' expression ')' error
    {
        printf("C--:disappear IF statement;\n");
        exit(1);
    }
    | IF '(' expression ')' statement ELSE error 
    {
        printf("C--:disappear ELSE statement;\n");
        exit(1);
    }
    ;

iteration_stmt
    : WHILE '(' expression ')' statement { $$ = createNode(WHILE, 2, $3, $5); }
    | FOR '(' expression_stmt ')' statement {
        printf("FOR iteration is not allowed!\n");
        exit(1);
    }
    | WHILE error statement 
    {
        printf("C--:disappear while boolean statement;\n");
        exit(1);
    }
    | WHILE '(' expression ')' error 
    {
        printf("C--:disappear while statement;\n");
        exit(1);
    }
    ;

return_stmt
    : RETURN ';' { $$ = createNode(RETURN, 0); }
    | RETURN expression ';' { $$ = createNode(RETURN, 1, $2); }
    | RETURN error ';'
        {
            printf("C--:error return statement;\n");
            exit(1);
        }
    | RETURN error
        {
            printf("C--:error return statement;\n");
            exit(1);
        }
    ;

expression
    : var '=' expression
        {
            $$ = createNode('=', 2, $1, $3);
        }
    | simple_expression { $$ = $1; }
    ;

var
    : IDENTIFIER { $$ = set_index($1); }
    | IDENTIFIER '[' expression ']' 
        {
            Node *tmp1;
            tmp1 = set_index($1);
            $$ = createNode('[', 2, tmp1, $3); 
        }
    ;

simple_expression
    : additive_expression relop additive_expression
        {
            $$ = createNode($2, 2, $1, $3); 
        }
    | additive_expression { $$ = $1; }
    | error relop additive_expression
        {
            printf("C--:disappear compare statement;\n");
            exit(1);
        }
    | additive_expression relop error
        {
            printf("C--:disappear compare statement;\n");
            exit(1);
        }
    ;

relop
    : LE_OP { $$ = LE_OP; }
    | '<' { $$ = '<'; }
    | '>' { $$ = '>'; }
    | GE_OP { $$ = GE_OP; }
    | EQ_OP { $$ = EQ_OP; }
    | NE_OP { $$ = NE_OP; }
    ;

additive_expression
    : additive_expression addop term
        {
            $$ = createNode($2, 2, $1, $3);
        }
    | term
        { 
            $$ = $1;
        }
    | additive_expression error term 
    {
        printf("C--:disappear '/' or '*' or ' '+' or '-' statement;\n");
        exit(1);
    } 
    | additive_expression addop error 
    {
        printf("C--:disappear statement;\n");
        exit(1);
    }
    ;

addop
    : '+' { $$ = '+'; }
    | '-' { $$ = '-'; }
    ;

term
    : term mulop factor
        {
            $$ = createNode($2, 2, $1, $3);
        }
    | factor { $$ = $1; }
    | term error factor
    {
        printf("C--:disappear '/' or '* or '+' or '-' statement;\n");
        exit(1);
    }
    | term mulop error
    {
        printf("C--:disappear statement;\n");
        exit(1);
    }
    ;

mulop
    : '*' { $$ = '*'; }
    | '/' { $$ = '/'; }
    ;

factor
    : '(' expression ')' { $$ = $2; }
    | var { $$ = $1; }
    | call { $$ = $1; }
    | CONSTANT { $$ = set_content($1); }
    ;

call
    : IDENTIFIER '(' args ')'
        { 
            Node *tmp1;
            tmp1 = set_index($1);
            $$ = createNode(CALL, 2, tmp1, $3);
        }
    | IDENTIFIER error args ')' 
        { 
           printf("C--:disappear '(' statement;\n");
           exit(1);
        }
    | IDENTIFIER error args 
        {
           printf("C--:disappear '(' and ')' statement;\n");
           exit(1);
        }
    | IDENTIFIER '(' args error 
        {
           printf("C--:disappear ')' statement;\n");
           exit(1);
        }
    ;

args
    : arg_list { $$ = $1; }
    | /* empty */ { $$ = NULL; }
    ;

arg_list
    : arg_list ',' expression { $$ = createNode(',', 2, $1, $3); }
    | expression { $$ = $1; }
    | arg_list error expression 
        {
            printf("C--:incorrent function arg_list;\n");
            exit(1);
        }
    | error ',' expression 
        {
            printf("C--:incorrent function arg_list;\n");
            exit(1);
        }
    ;

%%
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
