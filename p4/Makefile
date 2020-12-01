########################################################
# Santiago Valderrábano
# Saúl Almazán
# Martín de las Heras
# Grupo 140
########################################################

all: prueba_tabla

prueba_tabla: prueba_tabla.c tabla_simbolos.o hash.o
	gcc -Wall -o prueba_tabla prueba_tabla.c tabla_simbolos.o hash.o

tabla_simbolos.o: tabla_simbolos.c hash.h
	gcc -Wall -c tabla_simbolos.c

hash.o: hash.c
	gcc -Wall -c hash.c

.PHONY: clean
clean:
	rm -rf *.o prueba_tabla pruebas/misalida*
