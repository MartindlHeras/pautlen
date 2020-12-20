########################################################
# Santiago Valderrábano
# Saúl Almazán
# Martín de las Heras
# Grupo 140
########################################################

PRUEBA = aritmeticas comparaciones error_ej error_se funciones1 funciones2 funciones3 funciones4 if1 if2 if3 logicas1 logicas2 vectores1 vectores2 vectores3 vectores4 while

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
	rm -rf *.o lex.yy.* y.* prueba/*.o alfa prueba/misalida.* prueba/$(PRUEBA)

clear:
	rm -rf *.o lex.yy.* y.* prueba/*.o prueba/$(PRUEBA)