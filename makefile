make: parser
	./parser < test/test1.c > testfile.asm
	nasm -f elf -g -F stabs testfile.asm -o testfile.o
	ld -m elf_i386 -o testfile testfile.o

parser: lex.yy.c y.tab.c y.tab.h parser.c hash.h hash.c var.h command.h command.c
	gcc -o parser lex.yy.c y.tab.c parser.c hash.c command.c -ll

lex.yy.c:
	lex c-grammar.lex

y.tab.c:
	yacc -d c-grammar.y

run:
	./testfile

clean:
	rm testfile testfile.asm testfile.o y.tab.h y.tab.c lex.yy.c parser