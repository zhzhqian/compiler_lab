bison -dv parser.y
flex wordAnaly.l
cp back.h parser.tab.h
gcc var.c parser.tab.c lex.yy.c
./a.out < test.c
