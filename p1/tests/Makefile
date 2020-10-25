########################################################
CC=gcc
CFLAGS= -g -Wall
SRC=../src
EJS= ej1 #ej2 ej3 ej4 ej5 ej6 ej7
########################################################
OBJECTSGENERACIONES = generacion.o
########################################################

# MAKEFILE DE PPROG, HAY QUE CAMBIARLO
# - nasm -g –o [<fichero objeto (.o)>] –f elf <fichero fuente (.asm)>
# - gcc -o <fichero ejecutable> <fichero objeto 1> <fichero objeto 2>

all: $(EJS)

ej1: ejemplo1.c $(SRC)/generacion.o
	$(CC) $(CFLAGS) -o ej1 $(SRC)/generacion.o
	./$@ ej1.asm
	nasm -g -o ej1.o -f elf32 ej1.asm
	gcc -m32 -o ej1 ej1.o ../alfalib.o

.PHONY: clear clean
clear:
	rm -rf *.o

clean:
	rm -rf *.o *.asm $(EJS)

