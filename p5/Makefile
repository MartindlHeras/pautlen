########################################################
# Santiago Valderrábano
# Saúl Almazán
# Martín de las Heras
# Grupo 140
########################################################

all: alfa

alfa: alfa.c lex.yy.o y.tab.o generacion.o tabla_simbolos.o hash.o
	gcc -Wall -o alfa alfa.c lex.yy.o y.tab.o generacion.o tabla_simbolos.o hash.o

generacion.o: generacion.c generacion.h
	gcc -Wall -c generacion.c

tabla_simbolos.o: tabla_simbolos.c hash.h
	gcc -Wall -c tabla_simbolos.c

hash.o: hash.c
	gcc -Wall -c hash.c

lex.yy.o: lex.yy.c
	gcc -Wall -c lex.yy.c

lex.yy.c: alfa.l y.tab.h
	flex alfa.l

y.tab.o: y.tab.c
	gcc -Wall -c y.tab.c

y.tab.c: alfa.y
	bison -d -y -v alfa.y

y.tab.h: alfa.y
	bison -d -y -v alfa.y

.PHONY: clean
clean:
	rm -rf lex.yy.* y.* alfa prueba/misalida.output

# MINI = mini mini2 mini3 mini4 mini5 mini6 mini7 mini8 mini9 factorial condicionales vectores fibonacci funciones_vectores funciones
# ERR = err1 err2 err3 err4 err5 err6 err7 err8 err9 err10 err11 err12 err13 err14 err15 err16
# EXE = alfa $(MINI)

# ${MINI}: %: alfa examples/%.alfa
# 	./alfa examples/$@.alfa examples/$@.asm
# 	nasm -g -o examples/$@.o -f elf32 examples/$@.asm
# 	gcc -m32 -o examples/$@ examples/$@.o ../alfalib.o

# ${ERR}: %: alfa errors/%.alfa
# 	./alfa errors/$@.alfa errors/$@.asm
# 	nasm -g -o errors/$@.o -f elf32 errors/$@.asm
# 	gcc -m32 -o errors/$@ errors/$@.o ../alfalib.o