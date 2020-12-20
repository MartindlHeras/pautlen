########################################################
# Santiago Valderrábano
# Saúl Almazán
# Martín de las Heras
# Grupo 140
########################################################

PRUEBA = prueba/aritmeticas1 prueba/aritmeticas2 prueba/comparaciones prueba/error_ej1 prueba/error_ej2 prueba/error_se prueba/funciones1 prueba/funciones2 prueba/funciones3 prueba/funciones4 prueba/if1 prueba/if2 prueba/if3 prueba/logicas1 prueba/logicas2 prueba/vectores1 prueba/vectores2 prueba/vectores3 prueba/vectores4 prueba/while

all: alfa

alfa: alfa.c alfa.h lex.yy.o y.tab.o generacion.o tabla_simbolos.o hash.o
	gcc -Wall -g $^ -o $@

run:
	./script.sh

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
	rm -rf *.o lex.yy.* y.* prueba/*.o alfa prueba/misalida.* $(PRUEBA)

clear:
	rm -rf *.o lex.yy.* y.* prueba/*.o $(PRUEBA)