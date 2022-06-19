flex Node.lex
bison -vdty Node.y
g++ -o printTree TreeNode.cpp lex.yy.c y.tab.c