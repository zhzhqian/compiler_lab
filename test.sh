cd src
bison -dv parser.y -g 
cp back_up.h parser.tab.h
flex wordAnaly.l
gcc var.c parser.tab.c lex.yy.c -o ../compiler
cd ..
