%{
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "node.h"
#include "queue.h"
#include "hash.h"
#include "asm.h"
int yydebug =1;
Node *tmp;
Node* Tree;
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
%}

%union {
    LexNode lexNode;
    Node *nPtr;
};

%token <lexNode> CONSTANT INT VOID
%token <lexNode> IDENTIFIER ErrorIDENTIFIER
%token STRING_LITERAL
%token <lexNode> LE_OP GE_OP EQ_OP NE_OP
%token <lexNode> '+' '-' '<' '>' '*' '=' '/' ',' '{' '}'
%token <lexNode> IF ELSE WHILE FOR RETURN
%token PARAM FUNC VAR CALL GLOBAL_VAR
%nonassoc ELSE

%type <nPtr> term var factor var_declaration local_declarations
%type <nPtr> additive_expression simple_expression expression
%type <nPtr> return_stmt iteration_stmt expression_stmt selection_stmt compound_stmt
%type <nPtr> statement statement_list 
%type <nPtr> param params_list params type_specifier
%type <nPtr> fun_declaration declaration declaration_list
%type <nPtr> call args arg_list
%type <nPtr> relop mulop addop

%start program
%%

program
    : declaration_list {
        if (hasError == 1)
        {
           ret2cons();
        }
        else{
            int calling_func = -1;
            init_func();
            exeNode($1, 0, &calling_func);
            bss_global_variable(HASH_SIZE);
        }
    }
    ;

declaration_list
    : declaration_list declaration { $$ = opr( 0 , 0 ,';', 2, $1, $2); }
    | declaration { $$ = $1; }
    ;

declaration
    : var_declaration 
        { 
            $$  = opr($1->row,$1->column,GLOBAL_VAR,1, $1);
        }
    | fun_declaration { $$ = $1; }
    ;

var_declaration
    : type_specifier IDENTIFIER ';'
        {
            Node *tmp1;
            /* here to insert new var declaration */
            tmp1 = set_indexNode($2);
            $$ = opr($2.row,$2.column,VAR, 2, $1, tmp1);
        }
    | type_specifier IDENTIFIER '[' CONSTANT ']' ';'
        {
           Node * mid1, * mid2;
           mid1 = set_indexNode($2);
           mid2 = set_constantNode($4);
           $$ = opr( $2.row,$2.column,VAR, 3, $1, mid1, mid2);
        }
    | type_specifier error ';'
        {
            printf("C-minus(row %d:column %d):error Definition of variate;\n",$1->row,$1->column);
            yyerrok;
            $$ = opr($1->row,$1->column,VAR,2,NULL,NULL);
        }
    ;

type_specifier
    : INT { $$ = set_typeNode($1,0); }
    | VOID { $$ = set_typeNode($1,1); }
    ;

fun_declaration
    : type_specifier IDENTIFIER '(' params ')' compound_stmt 
        {
           Node *tmp1;
           tmp1 = set_indexNode($2);
           $$ = opr( $2.row, $2.column , FUNC,4, $1, tmp1, $4,$6);
        }
    ;

params
    : params_list { $$ = $1; }
    | VOID { $$ = set_typeNode($1,1); }
    ;

params_list
    : params_list ',' param { $$ = opr($2.row,$2.column, ',', 2, $1, $3); }
    | param { $$ = $1;}
    | params_list error param 
    {
        printf("C-minus(row %d:column %d):disappear ',' in function declaration;\n",$1->row,$1->column);
        yyerrok;
        $$ = opr($1->row,$1->column, ',', 2, $1, $3);
    }
    ;

param
    : type_specifier IDENTIFIER
        {
           Node *tmp1;
            /* here to insert new var declaration */
           tmp1 = set_indexNode($2);
           $$ = opr( $2.row , $2.column , PARAM, 2, $1, tmp1);
        }
    | type_specifier IDENTIFIER '[' ']'
        {
            Node *tmp1;
            /* here to insert new var declaration */
            tmp1 = set_indexNode($2);
            $$ = opr( $2.row , $2.column ,PARAM,3, $1, tmp1, NULL);
        }
    | type_specifier IDENTIFIER error
        {
            printf("C-minus(row %d:column %d):error declaration of function params;\n",$1->row,$1->column);
            yyerrok;
            Node *tmp1;
            /* here to insert new var declaration */
            tmp1 = set_indexNode($2);
            $$ = opr( $2.row , $2.column ,PARAM,2, $1, tmp1);
        }
    | type_specifier error 
        {
            printf("C-minus(row %d:column %d):error declaration of function params;\n",$1->row,$1->column);
            yyerrok;
            $$ = opr( $1->row , $1->column ,PARAM,2, $1, NULL);
        }
    ;

compound_stmt
    : '{' local_declarations statement_list '}' 
        { $$ = opr( $1.row,$1.column, '{', 2, $2, $3); }
    | '{' local_declarations statement_list error
        {
            printf("C-minus(row %d:column %d):disappear '}' for the function body;\n",$1.row,$1.column);
            yyerrok;
            $$ = opr( $1.row,$1.column, '{', 2, $2, $3); 
        }
    ;

local_declarations
    : local_declarations var_declaration { $$ = opr($2->row,$2->column,';', 2, $1, $2);}
    | /* empty */ { $$ = NULL; }
    ;

statement_list
    : statement_list statement { $$ = opr($2->row , $2->column , ';',  2, $1, $2); }
    | /* empty */ { $$ = NULL; }
    ;

statement
    : expression_stmt { $$ = $1; }
    | compound_stmt {  $$ = $1; }
    | selection_stmt { $$ = $1; }
    | iteration_stmt { $$ = $1; }
    | return_stmt { $$ = $1; }
    ;

expression_stmt
    : expression ';' {  $$ = $1;  }
    | ';' { $$ = NULL; }
    ;

selection_stmt
    : IF '(' expression ')' statement { $$ = opr( $1.row , $1.column, IF, 2, $3, $5); }
    | IF '(' expression ')' statement ELSE statement
        { $$ = opr( $1.row , $1.column , IF, 3, $3, $5, $7); }
    | IF error statement ELSE statement 
    {
        printf("C-minus(row %d,column %d):disappear boolean statement;\n",$1.row,$1.column);
        yyerrok;
        $$ = opr($1.column,$1.column,IF,3,NULL,$3,$5);
    }
    | IF error statement
    {
        printf("C-minus(row %d,column %d):disappear boolean statement;\n",$1.row,$1.column);
        yyerrok;
        $$ = opr($1.column,$1.column,IF,2,NULL,$3);
    }
    | IF '(' error ')' statement
    {
        printf("C-minus(row %d,column %d):disappear boolean statement;\n",$1.row,$1.column);
        yyerrok;
        $$ = opr($1.column,$1.column,IF,2,NULL,$5);
    }
    | IF '(' error statement ELSE statement
    {
        printf("C-minus(row %d,column %d):disappear boolean statement and ')';\n",$1.row,$1.column);
        yyerrok;
        $$ = opr($1.column,$1.column,IF,3,NULL,$4,$6);
    }
    | IF '(' expression ')' error ELSE statement
    {
        printf("C-minus(row %d,column %d):disappear IF statement;\n",$1.row,$1.column);
        yyerrok;
        $$ = opr($1.column,$1.column,IF,3,$3,NULL,$7);
    }
    | IF '(' expression ')' error
    {
        printf("C-minus(row %d,column %d):disappear IF statement;\n",$1.row,$1.column);
        yyerrok;
        $$ = opr($1.column,$1.column,IF,2,$3,NULL);
    }
    | IF '(' expression ')' statement ELSE error 
    {
        printf("C-minus(row %d,column %d):disappear ELSE statement;\n",$1.row,$1.column);
        yyerrok;
        $$ = opr($1.column,$1.column,IF,3,NULL,$3,$5);
    }
    ;

iteration_stmt
    : WHILE '(' expression ')' statement {  $$ = opr( $1.row , $1.column , WHILE, 2, $3, $5); }
    | WHILE error statement 
    {
        printf("C-minus(row %d,column %d):disappear while boolean statement;\n",$1.row,$1.column);
        yyerrok;
        $$ = opr($1.column,$1.column,WHILE,2,NULL,$3);
    }
    | WHILE '(' expression ')' error 
    {
        printf("C-minus(row %d,column %d):disappear while statement;\n",$1.row,$1.column);
        yyerrok;
        $$ = opr($1.column,$1.column,WHILE,2,$3,NULL);
    }
    ;

return_stmt
    : RETURN ';' { $$ = opr($1.row , $1.column , RETURN,  0); }
    | RETURN expression ';' { $$ = opr($1.row , $1.column ,  RETURN,  1, $2); }
    | RETURN error ';'
        {
            printf("C-minus(row %d,column %d):error return statement;\n",$1.row,$1.column);
            yyerrok;
            $$ = opr($1.column,$1.column,RETURN,1,NULL);
        }
    | RETURN error
        {
            printf("C-minus(row %d,column %d):error return statement;\n",$1.row,$1.column);
            yyerrok;
            $$ = opr($1.row,$1.column,RETURN,1,NULL);
        }
    ;

expression
    : var '=' expression
        {
            $$ = opr( $2.row , $2.column , '=', 2, $1, $3);
        }
    | simple_expression { $$ = $1; }
    ;

var
    : IDENTIFIER {  $$ = set_indexNode($1);  }
    | IDENTIFIER '[' expression ']' 
        {
           Node *tmp1;
            tmp1 = set_indexNode($1);
            $$ = opr( $1.row , $1.column ,'[', 2, tmp1, $3); 
        }
    ;

simple_expression
    : additive_expression relop additive_expression
        {
            $$ = opr( $2->row , $2->column , $2->op.name, 2, $1, $3); 
        }
    | additive_expression { $$ = $1; }
    | error relop additive_expression
        {
            printf("C-minus(row %d,column %d):disappear compare statement;\n",$2->row,$2->column);
            yyerrok;
            $$ = opr( $2->row , $2->column , $2->op.name, 2, NULL, $3); 
        }
    // // | additive_expression error additive_expression
    // //     {
    // //         printf("C-minus(row %d,column %d):disappear compare operator;\n",$1->row,$1->column);
    // //         yyerrok;
    // //         $$ = opr( $1->row , $1->column , '>', 2, NULL, $3); 
    // //     }
    | additive_expression relop error
        {
            printf("C-minus(row %d,column %d):disappear compare statement;\n",$1->row,$1->column);
            yyerrok;
            $$ = opr( $2->row , $2->column , $2->op.name, 2, $1, NULL); 
        }
    ;

relop
    : LE_OP { $$ = set_oprNode($1,2,LE_OP); }
    | '<' { $$ = set_oprNode($1,2,'<'); }
    | '>' { $$ = set_oprNode($1,2,'>'); }
    | GE_OP { $$ = set_oprNode($1,2,GE_OP); }
    | EQ_OP { $$ = set_oprNode($1,2,EQ_OP); }
    | NE_OP { $$ = set_oprNode($1,2,NE_OP); }
    ;

additive_expression
    : additive_expression addop term
        {
            $$ = opr($2->row,$2->column,$2->op.name, 2, $1, $3);
        }
    | term
        { 
            $$ = $1;
        }
    ;
    | additive_expression error term 
    {
        printf("C-minus(row %d,column %d):disappear '/' or '*' or ' '+' or '-' statement;\n",$1->row,$1->column);
        yyerrok;
        $$ = opr($1->column,$1->column,'+',1,NULL);
    } 
    | additive_expression addop error 
    {
        printf("C-minus(row %d,column %d):disappear statement;\n",$1->row,$1->column);
        yyerrok;
        $$ = opr($2->column,$2->column,$2->op.name,2,$1,NULL);
    }

addop
    : '+' { $$ = set_oprNode($1,2,'+'); }
    | '-' { $$ = set_oprNode($1,2,'-'); }
    ;

term
    : term mulop factor
        {
            $$ = opr($2->row,$2->column,$2->op.name,2,$1,$3);
        }
    | factor { $$ = $1; }
    | term error factor
    {
        printf("C-minus(row %d,column %d):disappear '/' or '* or '+' or '-' statement;\n",$1->row,$1->column);
        yyerrok;
        $$ = opr($3->row,$3->column,'/',1,NULL);
    }
    | term mulop error
    {
        printf("C-minus(row %d,column %d):disappear statement;\n",$1->row,$1->column);
        yyerrok;
        $$ = opr($1->column,$1->column,$2->op.name,2,$1,NULL);
    }
    ;

mulop
    : '*' { $$ = set_oprNode($1,2,'*'); }
    | '/' { $$ = set_oprNode($1,2,'/'); }
    ;

factor
    : '(' expression ')' { $$ = $2; }
    | var { $$ = $1; }
    | call { $$ = $1; }
    | CONSTANT { $$ = set_constantNode($1);}
    ;

call
    : IDENTIFIER '(' args ')'
        { 
           Node *tmp1;
           tmp1 = set_indexNode($1);
           $$ = opr($1.row,$1.column,CALL,2, tmp1, $3);
        }
    | IDENTIFIER error args ')' 
        { 
           printf("C-minus(row %d,column %d):disappear '(' statement;\n",$1.row,$1.column);
           yyerrok;
           Node *tmp1;
           tmp1 = set_indexNode($1);
           $$ = opr($1.row,$1.column,CALL,2, tmp1, $3);
        }
    | IDENTIFIER error args 
        {
           printf("C-minus(row %d,column %d):disappear '(' and ')' statement;\n",$1.row,$1.column);
           yyerrok;
           Node *tmp1;
           tmp1 = set_indexNode($1);
           $$ = opr($1.row,$1.column,CALL,2, tmp1, $3);
        }
    | IDENTIFIER '(' args error 
        {
           printf("C-minus(row %d,column %d):disappear ')' statement;\n",$1.row,$1.column);
           yyerrok;
           Node *tmp1;
           tmp1 = set_indexNode($1);
           $$ = opr($1.row,$1.column,CALL,2, tmp1, $3);
        }
    ;

args
    : arg_list { $$ = $1; }
    | /* empty */ { $$ = NULL; }
    ;

arg_list
    : arg_list ',' expression { $$ = opr($2.row,$2.column,',',2,$1,$3); }
    | expression { $$ = $1; }
    | arg_list error expression 
        {
            printf("C-minus(row %d,column %d):incorrent function arg_list;\n",$1->row,$1->column);
            yyerrok;
            $$ = opr($1->row,$1->column,',',2,$1,$3); 
        }
    | error ',' expression 
        {
            printf("C-minus(row %d,column %d):incorrent function arg_list;\n",$3->row,$3->column);
            yyerrok;
            $$ = opr($3->row,$3->column,',',2,NULL,NULL); 
        }
    ;

%%

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

    hash_init(var_local, HASH_SIZE);
    hash_init(var_global, HASH_SIZE);
    hash_init(funcs, HASH_SIZE);
    // hash_init(var_local_SorA, HASHSIZE);
    // hash_init(var_local_GorP, HASHSIZE);
    yyparse();
    if (hasError == 1)
    return 0;
    
    freopen("/dev/tty", "w", stdout);
    freopen("/dev/tty", "r", stdin);
    pid_t pid = fork();
    if (pid == 0) {
        execlp("nasm", "nasm", "-f elf64", asmoutput, NULL);
    } else {
        wait();
        asmoutput[len-1] = 'o';
        char* elf = (char*)malloc(sizeof(char)*(len-1));
        memcpy(elf, argv[1], len-2); elf[len-2] = '\0';
        pid = fork();
        if (pid == 0) {
            execlp("ld", "ld", "-o", elf, asmoutput, NULL);
        } else {
            wait();
            execlp("rm", "rm", asmoutput, NULL);
        }
    }

    return 0;
}
