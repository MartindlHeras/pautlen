########################################################
# Santiago Valderrábano
# Saúl Almazán
# Martín de las Heras
# Grupo 140
########################################################

all: alfa

alfa: alfa.c alfa.h lex.yy.o y.tab.o generacion.o tabla_simbolos.o hash.o
	gcc -Wall -g $^ -o $@

run: ./script.sh

generacion.o: generacion.c generacion.h
	gcc -Wall -g -c $<

tabla_simbolos.o: tabla_simbolos.c tabla_simbolos.h
	gcc -Wall -g -c $<

hash.o: hash.c hash.h
	gcc -Wall -g -c $<

lex.yy.o: lex.yy.c
	gcc -Wall -g -c $^

y.tab.o: y.tab.c
	gcc -Wall -g -c $<

lex.yy.c: alfa.l y.tab.h
	flex $<

y.tab.c: alfa.y
	bison -d -y -v $^

y.tab.h: alfa.y
	bison -d -y -v $^

.PHONY: clean
clean:
	rm -rf *.o lex.yy.* y.* prueba/*.o alfa prueba/misalida.asm

clear:
	rm -rf *.o lex.yy.* y.* prueba/*.o