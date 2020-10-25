########################################################
# Makefile que genera el objeto .o de generacion
########################################################
CC=gcc
CFLAGS= -g -Wall
########################################################

# MAKEFILE DE PPROG, HAY QUE CAMBIARLO
# - nasm -g –o [<fichero objeto (.o)>] –f elf <fichero fuente (.asm)>
# - gcc -o <fichero ejecutable> <fichero objeto 1> <fichero objeto 2>

all: generacion.o

generacion.o: generacion.c generacion.h
	$(CC) $(CFLAGS) -c generacion.c


.PHONY: clean
clean:
	rm -rf *.o
