########################################################
# Santiago Valderrábano
# Saúl Almazán
# Martín de las Heras
# Grupo 140
########################################################

all: pruebaSinta

pruebaSinta: pruebaSinta.c lex.yy.o y.tab.o
	gcc -Wall -o pruebaSinta pruebaSinta.c lex.yy.o y.tab.o

lex.yy.o: lex.yy.c
	gcc -Wall -c lex.yy.c

lex.yy.c: alfa.l
	flex alfa.l

y.tab.o: y.tab.c
	gcc -Wall -c y.tab.c

y.tab.c: alfa.y
	bison -d -y -v alfa.y

y.tab.h: alfa.y
	bison -d -y -v alfa.y

.PHONY: clean
clean:
	rm -rf lex.yy.* pruebaSinta y.tab.* ficheros_prueba_morfologico/misalida*
