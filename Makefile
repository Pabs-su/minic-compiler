minic: lex.yy.c anasin.tab.c anasin.tab.h listaSimbolos.c listaCodigo.c
	gcc lex.yy.c anasin.tab.c listaSimbolos.c listaCodigo.c -lfl -o minic
lex.yy.c: analex.l anasin.tab.h
	flex analex.l

anasin.tab.c anasin.tab.h: anasin.y
	bison -d anasin.y
limpia:
	rm -f lex.yy.c  anasin.tab.h anasin.tab.c
