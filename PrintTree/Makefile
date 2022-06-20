lex:
	lex printTree.lex
yacc:
	yacc -d  printTree.y 
parser: lex.yy.c y.tab.h y.tab.c queue.c queue.h
	gcc -o parser lex.yy.c y.tab.c queue.c -ll
run :
	make lex
	make yacc
	make parser
	./parser ../test/error4.c
clean:
	rm -f lex.yy.c y.tab.h y.tab.c
debug:
	lex c-minus-grammar.lex
	yacc -d -t c-minus-grammar.y 
	gcc -o parser lex.yy.c y.tab.c queue.c -ll -lm
Lex:
	make lex
	gcc -o flex lex.yy.c