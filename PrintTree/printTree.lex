DEight      [0-7]
D			[0-9]
L			[a-zA-Z_]
H			[a-fA-F0-9]
E			[Ee][+-]?{D}+
P                       [Pp][+-]?{D}+
FS			(f|F|l|L)
IS                      ((u|U)|(u|U)?(l|L|ll|LL)|(l|L|ll|LL)(u|U))

%{
#include <stdio.h>
#include <string.h>
#include "node.h"
#include "y.tab.h"
void countColumn(void);
void comment(void);
LexNode count(int type);
int column = 0;
int row = 1;
int hasError;	
%}

%%
 /*comment*/
"/*"			{ comment(); }
"//"[^\n]*              { /* consume //-comment */ }
 /*key word */
"else"			{ yylval.lexNode = count(1); return(ELSE); }
"for"			{ yylval.lexNode = count(1); return(FOR); }
"if"			{ yylval.lexNode = count(1); return(IF); }
"int"			{ yylval.lexNode = count(1); return(INT); }
"return"		{ yylval.lexNode = count(1); return(RETURN); }
"void"			{ yylval.lexNode = count(1); return(VOID); }
"while"			{ yylval.lexNode = count(1); return(WHILE); }
 /*IDENTIFIER rule*/ 
{L}({L}|{D})*		{  yylval.lexNode = count(1); return(IDENTIFIER); }
 /*any 16 scale number into 32 btye int*/
0[xX]{H}+{IS}?		{  yylval.lexNode =count(0); return(CONSTANT); }
 /*any 8 scale number turn into 32 byte int*/ 
0{DEight}+{IS}?		{  yylval.lexNode =count(0); return(CONSTANT); }
 /*any 10 scale number turn into 32 byte int*/ 
{D}+{IS}?		{ yylval.lexNode = count(0); return(CONSTANT); }

 /* operator */
"<="			{ yylval.lexNode = count(1); return(LE_OP); }
">="			{ yylval.lexNode = count(1); return(GE_OP); }
"=="			{ yylval.lexNode = count(1); return(EQ_OP); }
"!="			{ yylval.lexNode = count(1); return(NE_OP); }
";"			{ yylval.lexNode = count(1); return(';') ; }
","			{ yylval.lexNode = count(1); return(','); }
"{"		{ yylval.lexNode = count(1); return('{'); }
"}"		{ yylval.lexNode = count(1); return('}'); }
"="			{ yylval.lexNode = count(1); return('='); }
"("			{ yylval.lexNode = count(1); return('('); }
")"			{ yylval.lexNode = count(1); return(')'); }
"["			{ yylval.lexNode = count(1); return('['); }
"]"			{ yylval.lexNode = count(1); return(']'); }
"~"			{ yylval.lexNode = count(1); return('~'); }
"-"			{ yylval.lexNode = count(1); return('-'); }
"+"			{ yylval.lexNode = count(1); return('+'); }
"*"			{ yylval.lexNode = count(1); return('*'); }
"/"			{ yylval.lexNode = count(1); return('/'); }
"%"			{ yylval.lexNode = count(1); return('%'); }
"<"			{ yylval.lexNode = count(1); return('<'); }
">"			{ yylval.lexNode = count(1); return('>'); }
 /* delete any character don't need */ 
[ \t\v\n\f\r]		{ countColumn(); }
 /* other point */
.	{
	hasError = 1;
	countColumn();
	printf("the lexical error:\nThe C-Minus(row %d,column %d):an %s token can't identify\n",row,column,yytext);
	/* Add code to complain about unmatched characters */ 
}

%%
   
int yywrap(void)
{
	return 1;
}

 /* parse comment */
void comment(void)
{
	char c, prev = 0;
  
	while ((c = input()) != 0)      /* (EOF maps to 0) */
	{
		if (c == '/' && prev == '*')
			return;
		prev = c;
	}
	perror("unterminated comment");
}


 /*type = 0 代表数字 type = 1 代表 字符串*/
LexNode count(int type)
{
	int i;
	LexNode p;
	p.column = column;
	p.row = row;
	for (i = 0; yytext[i] != '\0'; i++){
		if (yytext[i] == '\n')
		{
			column = 0;
			row +=1;
		}
		else if (yytext[i] == '\t')
			column += 8 - (column % 8);
		else
			column++;
	}
	//printf("The column is %d The row is %d The sign is %s\n",column,row,yytext);
	if(type == 0)
	p.value = atoi(yytext);
	else
	{
		p.string = yytext;
		char * a = strdup(yytext);
		p.string = a;
	}
	return p;
	/*ECHO; */

}
void countColumn()
{
	int i;
	for (i = 0; yytext[i] != '\0'; i++){
		if (yytext[i] == '\n')
		{
			column = 0;
			row +=1;
		}
		else if (yytext[i] == '\t')
			column += 8 - (column % 8);
		else
			column++;
	}
	//printf("The column is %d The row is %d The sign is %s\n",column,row,yytext);
}


