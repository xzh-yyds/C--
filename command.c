#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "command.h"
#include "hash.h"

char strbucket[MAX_STR_LENGTH];
static int func_is_main(int funcname)
{
	if (funcname == ELFHash("main", 4))
		return 1;

	return 0;
}

char *getregs[5] = { "0", EAX, EBX, ECX, EDX };

static void getvarstr(char *varstr, int offset)
{
	if (offset >= 0)
		sprintf(varstr, "[%s+%d]", EBP, offset);
	else
		sprintf(varstr, "[%s%d]", EBP, offset);
}

static int getregstr(char *regstr, int reg)
{	
	if(reg >= 1 && reg <= 4){
		strcpy(regstr, getregs[reg]);
		return 0;
	}else{
		return -1;
	}
}

int creat_label()
{
	static int labelno = 0;
	return ++labelno;
}

void code_label(int labelno)
{
	sprintf(strbucket, "%s%d:", LABEL, labelno);
	printf("%s\n", strbucket);
}

void code_jmp(int labelno)
{
	sprintf(strbucket, "%s\t%s%d", JMP, LABEL, labelno);
	printf("%s\n", strbucket);
}

void code_pop(int reg)
{
	char regstr[REGSTR_LENGTH];
	if(getregstr(regstr, reg) == -1){
		printf("getregstr error\n");
		exit(1);
	}

	sprintf(strbucket, "%s\t%s", POP, regstr);
	printf("%s\n", strbucket);
}

void code_lea_global(int target, int addr, int offset)
{
	int array;

	char offreg[REGSTR_LENGTH];
	char tarreg[REGSTR_LENGTH];
	array = getregstr(offreg, offset);
	if(getregstr(tarreg, target) == -1){
		printf("get regstr error\n");
		exit(1);
	}

	if (array == -1) {	/* not array */
		sprintf(strbucket, "%s\t%s, [%s%d]", LEA, tarreg, GDATA_PRE,
			addr);
	} else {		/* array with offset */
		sprintf(strbucket, "%s\t%s, [%s%d+%s]", LEA, tarreg, GDATA_PRE,
			addr, offreg);
	}
	printf("%s\n", strbucket);
}

void code_lea_local(int target, int var)
{
	char t_reg[REGSTR_LENGTH];
	char s_var[VARSTR_LENGTH];

	if(getregstr(t_reg, target) == -1){
		printf("get regstr error\n");
		exit(1);
	};
	getvarstr(s_var, var);

	sprintf(strbucket, "%s\t%s, %s", LEA, t_reg, s_var);
	printf("%s\n", strbucket);
}

void code_move_reg(int target, int source)
{
	char t_reg[REGSTR_LENGTH];
	char s_reg[REGSTR_LENGTH];

	if (target == source)
		return;

	if(getregstr(t_reg, target) == -1){
		printf("get regstr error\n");
		exit(1);
	}
	if(getregstr(s_reg, source) == -1){
		printf("get regstr error\n");
		exit(1);
	}

	sprintf(strbucket, "%s\t%s, %s", MOV, t_reg, s_reg);
	printf("%s\n", strbucket);
}

void code_push_mem(int addr, int offset)
{
	char regstr[REGSTR_LENGTH];
	if(getregstr(regstr, offset) == -1){
		printf("get regstr error\n");
		exit(1);
	}

	sprintf(strbucket, "%s\t%s [%s%d+%s]", PUSH, VARSIZE,
		GDATA_PRE, addr, regstr);
	printf("%s\n", strbucket);
}

void code_push_reg(int reg, int mem)
{
	char regstr[REGSTR_LENGTH];
	if(getregstr(regstr, reg) == -1){
		printf("get regstr error\n");
		exit(1);
	}

	if (mem) {
		sprintf(strbucket, "%s\t%s [%s]", PUSH, VARSIZE, regstr);
	} else {
		sprintf(strbucket, "%s\t%s %s", PUSH, VARSIZE, regstr);
	}
	printf("%s\n", strbucket);
}

void code_push_ind(int idx)
{
	char varstr[VARSTR_LENGTH];
	getvarstr(varstr, idx);
	sprintf(strbucket, "%s\t%s %s", PUSH, VARSIZE, varstr);
	printf("%s\n", strbucket);
}

void code_push_cons(int constant)
{
	sprintf(strbucket, "%s\t%s %d", PUSH, VARSIZE, constant);
	printf("%s\n", strbucket);
}

void code_push_global_var(int var, int offset)
{
	if (offset >= 0) {
		sprintf(strbucket, "%s\t%s [%s%d+%d]", PUSH, VARSIZE, GDATA_PRE,
			var, offset);
	} else {
		sprintf(strbucket, "%s\t%s [%s%d%d]", PUSH, VARSIZE, GDATA_PRE,
			var, offset);
	}
	printf("%s\n", strbucket);
}

void code_push_global_array(int var)
{
	sprintf(strbucket, "%s\t%s %s%d", PUSH, VARSIZE, GDATA_PRE, var);
	printf("%s\n", strbucket);
}

void code_call_func(int funcname)
{
	sprintf(strbucket, "%s\t%s%d", CALLF, FUNC_PRE, funcname);
	printf("%s\n", strbucket);
}

void code_start_bss()
{
	static int bss_mark = 0;

	if (!bss_mark) {
		strcpy(strbucket, "section .bss");
		printf("%s\n", strbucket);
		++bss_mark;
	}
}

void code_start_text()
{
	static int text_mark = 0;

	if (!text_mark) {
		strcpy(strbucket, "section .text");
		printf("%s\n", strbucket);
		++text_mark;
	}
}

void code_declare_global_var(int varname, int size)
{
	sprintf(strbucket, "%s%d:\t%s %d", GDATA_PRE, varname,
		GLOBAL_VAR_DEFINE, GLOBAL_VAR_LENGTH * size);
	printf("%s\n", strbucket);
}

void code_start_func(int funcname)
{
	if (func_is_main(funcname)) {
		strcpy(strbucket, "global _start\n_start:");
	} else {
		sprintf(strbucket, "global %s%d\n%s%d:", FUNC_PRE, funcname,
			FUNC_PRE, funcname);
	}
	printf("%s\n", strbucket);
	sprintf(strbucket, "%s\t%s", PUSH, EBP);
	printf("%s\n", strbucket);
	sprintf(strbucket, "%s\t%s, %s", MOV, EBP, ESP);
	printf("%s\n", strbucket);
}

void code_clean_stack(int height)
{
	sprintf(strbucket, "%s\t%s, %d", ADD, ESP, height);
	printf("%s\n", strbucket);
}

void code_end_func(int funcname)
{
	sprintf(strbucket, "%s", LEAVE);
	printf("%s\n", LEAVE);

	if (!func_is_main(funcname)) {
		printf("%s\n", RET);
	} else {
		code_end_main();
	}
}

void code_sub_esp(int size)
{
	sprintf(strbucket, "%s\t%s, %d", SUB, ESP, size);
	printf("%s\n", strbucket);
}

void code_test_condition(int reg, int test, int labelno)
{
	char regstr[REGSTR_LENGTH];
	if(getregstr(regstr, reg) == -1){
		printf("get regstr error\n");
		exit(1);
	}

	sprintf(strbucket, "%s\t%s, %d", CMP, regstr, test);
	printf("%s\n", strbucket);
	sprintf(strbucket, "%s\t%s%d", JE, LABEL, labelno);
	printf("%s\n", strbucket);
}

void code_op_assign(int target, int source)
{
	char t_reg[VARSTR_LENGTH];
	char s_reg[REGSTR_LENGTH];

	if(getregstr(s_reg, source) == -1){
		printf("get regstr error\n");
		exit(1);
	}
	if(getregstr(t_reg, target) == -1){
		printf("get regstr error\n");
		exit(1);
	}

	sprintf(strbucket, "%s\t%s [%s], %s", MOV, VARSIZE, t_reg, s_reg);
	printf("%s\n", strbucket);
}

int code_get_array_offset(int baseoff, int idxreg, int varlength, int global)
{
	char regstr[REGSTR_LENGTH];
	if(getregstr(regstr, idxreg) == -1){
		printf("get regstr error\n");
		exit(1);
	}

	if (global == 0) {	/* general local var */
		sprintf(strbucket, "%s\t%s, %s", MOV, EBX, EBP);
		printf("%s\n", strbucket);
	} else if (global == -1) {	/* parameter */
		/* the array position in memory */
		sprintf(strbucket, "%s\t%s, [%s+%d]", MOV, EBX, EBP, baseoff);
		printf("%s\n", strbucket);
	} else {		/* global var, just calculate the array index offset */
		sprintf(strbucket, "%s\t%s, 0", MOV, EBX);
		printf("%s\n", strbucket);
	}

	/* get the array index offset */
	sprintf(strbucket, "%s\t%s, %d", IMUL, regstr, varlength);
	printf("%s\n", strbucket);

	sprintf(strbucket, "%s\t%s, %s", ADD, EBX, EAX);
	printf("%s\n", strbucket);

	if (global == 0) {
		sprintf(strbucket, "%s\t%s, %d", SUB, EBX, abs(baseoff));
		printf("%s\n", strbucket);
	}

	return 2;		/* store in ebx */
}

/* put the result in eax */
int code_op_binary(int v1, int v2, char *op)
{
	char regstr1[REGSTR_LENGTH];
	char regstr2[REGSTR_LENGTH];

	if(getregstr(regstr1, v1) == -1){
		printf("get regstr error\n");
		exit(1);
	}
	if(getregstr(regstr2, v2) == -1){
		printf("get regstr error\n");
		exit(1);
	}

	int sar = 31;

	if (strcmp(op, "+") == 0) {
		sprintf(strbucket, "%s\t%s, [%s+%s]", LEA, EAX, regstr1,
			regstr2);

	} else if (strcmp(op, "-") == 0) {
		sprintf(strbucket, "%s\t%s, %s", SUB, regstr1, regstr2);

	} else if (strcmp(op, "*") == 0) {
		sprintf(strbucket, "%s\t%s, %s", IMUL, regstr1, regstr2);

	} else if (strcmp(op, "/") == 0) {
		sprintf(strbucket, "%s\t%s, %s", MOV, EDX, regstr1);
		printf("%s\n", strbucket);
		sprintf(strbucket, "%s\t%s, %d", SAR, EDX, sar);
		printf("%s\n", strbucket);
		sprintf(strbucket, "%s\t%s", IDIV, regstr2);

	} else {		/* relop */
		sprintf(strbucket, "%s\t%s, %s", CMP, regstr1, regstr2);
		printf("%s\n", strbucket);

		if (strcmp(op, "==") == 0) {
			sprintf(strbucket, "%s\t%s", SETE, AL);

		} else if (strcmp(op, "!=") == 0) {
			sprintf(strbucket, "%s\t%s", SETNE, AL);

		} else if (strcmp(op, ">") == 0) {
			sprintf(strbucket, "%s\t%s", SETG, AL);

		} else if (strcmp(op, "<") == 0) {
			sprintf(strbucket, "%s\t%s", SETL, AL);

		} else if (strcmp(op, ">=") == 0) {
			sprintf(strbucket, "%s\t%s", SETGE, AL);

		} else if (strcmp(op, "<=") == 0) {
			sprintf(strbucket, "%s\t%s", SETLE, AL);
		}

		printf("%s\n", strbucket);
		sprintf(strbucket, "%s\t%s, %s", MOVZX, EAX, AL);
	}

	printf("%s\n", strbucket);

	return 1;		/* return which reg it stores the result */
}

int code_data_section()
{
	static int data_mark = 0;

	if (!data_mark) {
		strcpy(strbucket, "section .data");
		printf("%s\n", strbucket);
		strcpy(strbucket, "numbers db \"0123456789\", 0xA");
		printf("%s\n", strbucket);
		strcpy(strbucket, "inputchar db 0");
		printf("%s\n", strbucket);

		++data_mark;
		return 0;
	}

	return data_mark;
}

/* output function */
void code_func_output()
{
	/*code_start_func(); */
	strcpy(strbucket,
	       "sub esp, 4\nmov dword [ebp-4], 0\njmp G2\nG1:\nadd dword [ebp-4], 1\npush edx");
	printf("%s\n", strbucket);
	strcpy(strbucket,
	       "G2:\nmov edx, 0\nmov eax, [ebp+8]\nmov ebx, 10\ndiv ebx\nmov [ebp+8], eax");
	printf("%s\n", strbucket);
	strcpy(strbucket,
	       "cmp eax, 0\njnz G1\npush edx\nadd dword [ebp-4], 1\njmp G3");
	printf("%s\n", strbucket);
	strcpy(strbucket,
	       "G4:\nsub dword [ebp-4], 1\npop edx\nmov eax, 4\nmov ebx, 1\nmov ecx, numbers");
	printf("%s\n", strbucket);
	strcpy(strbucket, "add ecx, edx\nmov edx, 1\nint 80h");
	printf("%s\n", strbucket);
	strcpy(strbucket,
	       "G3:\ncmp dword [ebp-4], 0\njnz G4\nmov eax, 4\nmov ebx, 1\nlea ecx, [numbers+10]");
	printf("%s\n", strbucket);
	strcpy(strbucket, "mov edx, 1\nint 80h");
	printf("%s\n", strbucket);
}

/* input function */
void code_func_input()
{
	strcpy(strbucket,
	       "sub esp, 4\nmov dword [ebp-4], 0\nmov byte [inputchar], 0\njmp G6");
	printf("%s\n", strbucket);
	strcpy(strbucket,
	       "G5:\nmov dword eax, [ebp-4]\nmov ebx, 10\nmul ebx\nxor ecx, ecx");
	printf("%s\n", strbucket);
	strcpy(strbucket,
	       "mov byte cl, [inputchar]\nsub ecx, 48\nadd eax, ecx\nmov dword [ebp-4], eax");
	printf("%s\n", strbucket);
	strcpy(strbucket,
	       "G6:\nmov eax, 03h\nmov ebx, 00h\nmov ecx, inputchar\nmov edx, 01h");
	printf("%s\n", strbucket);
	strcpy(strbucket,
	       "int 80h\ncmp byte [inputchar], 0ah\njne G5\nmov dword eax, [ebp-4]");
	printf("%s\n", strbucket);
}

static void code_end_main()
{
	sprintf(strbucket, "mov ebx, eax\nmov eax,1\nint 80h");
	printf("%s\n", strbucket);
}
