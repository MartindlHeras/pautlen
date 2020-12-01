########################################################
# Santiago Valderrábano
# Saúl Almazán
# Martín de las Heras
# Grupo 140
########################################################

all: prueba_tabla

prueba_tabla: prueba_tabla.c tablasimbolos.o hash.o
	gcc -Wall -o prueba_tabla prueba_tabla.c tablasimbolos.o hash.o

tablasimbolos.o: tablasimbolos.c
	gcc -Wall -c tablasimbolos.c

hash.o: hash.c
	gcc -Wall hash.c

.PHONY: clean
clean:
	rm -rf *.o pruebaSinta pruebas/misalida*
