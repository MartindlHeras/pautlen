########################################################
CC=gcc
CFLAGS= -g -Wall
SRC=../src
EJS= ej1 ej2 ej3 ej4 ej5 ej6 ej7
########################################################
OBJECTSGENERACIONES = generacion.o
########################################################

# - nasm -g –o [<fichero objeto (.o)>] –f elf <fichero fuente (.asm)>
# - gcc -o <fichero ejecutable> <fichero objeto 1> <fichero objeto 2>

all: $(EJS)

ej1: ejemplo1.c $(SRC)/generacion.o
	$(CC) $(CFLAGS) -o ej1 ejemplo1.c $(SRC)/generacion.o
	./$@ ej1.asm
	nasm -g -o ej1.o -f elf32 ej1.asm
	gcc -m32 -o ej1 ej1.o ../alfalib.o

ej2: ejemplo2.c $(SRC)/generacion.o
	$(CC) $(CFLAGS) -o ej2 ejemplo2.c $(SRC)/generacion.o
	./$@ ej2.asm
	nasm -g -o ej2.o -f elf32 ej2.asm
	gcc -m32 -o ej2 ej2.o ../alfalib.o

ej3: ejemplo3.c $(SRC)/generacion.o
	$(CC) $(CFLAGS) -o ej3 ejemplo3.c $(SRC)/generacion.o
	./$@ ej3.asm
	nasm -g -o ej3.o -f elf32 ej3.asm
	gcc -m32 -o ej3 ej3.o ../alfalib.o

ej4: ejemplo4.c $(SRC)/generacion.o
	$(CC) $(CFLAGS) -o ej4 ejemplo4.c $(SRC)/generacion.o
	./$@ ej4.asm
	nasm -g -o ej4.o -f elf32 ej4.asm
	gcc -m32 -o ej4 ej4.o ../alfalib.o

ej5: ejemplo5.c $(SRC)/generacion.o
	$(CC) $(CFLAGS) -o ej5 ejemplo5.c $(SRC)/generacion.o
	./$@ ej5.asm
	nasm -g -o ej5.o -f elf32 ej5.asm
	gcc -m32 -o ej5 ej5.o ../alfalib.o

ej6: ejemplo6.c $(SRC)/generacion.o
	$(CC) $(CFLAGS) -o ej6 ejemplo6.c $(SRC)/generacion.o
	./$@ ej6.asm
	nasm -g -o ej6.o -f elf32 ej6.asm
	gcc -m32 -o ej6 ej6.o ../alfalib.o

ej7: ejemplo7.c $(SRC)/generacion.o
	$(CC) $(CFLAGS) -o ej7 ejemplo7.c $(SRC)/generacion.o
	./$@ ej7.asm
	nasm -g -o ej7.o -f elf32 ej7.asm
	gcc -m32 -o ej7 ej7.o ../alfalib.o

.PHONY: clear clean
clear:
	rm -rf *.o

clean:
	rm -rf *.o *.asm $(EJS)
