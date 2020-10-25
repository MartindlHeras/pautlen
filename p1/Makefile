########################################################
CC=gcc
CFLAGS= -g -Wall -O3 -std=c90  -I./include/ #-ansi -pedantic
LDFLAGS= -lncurses
EJS = player_test
########################################################
OBJECTSPLAYER = player_test.o player.o inventory.o set.o
########################################################

# MAKEFILE DE PPROG, HAY QUE CAMBIARLO
# - nasm -g –o [<fichero objeto (.o)>] –f elf <fichero fuente (.asm)>
# - gcc -o <fichero ejecutable> <fichero objeto 1> <fichero objeto 2>

all: $(EJS)

player_test: $(OBJECTSPLAYER)
	$(CC) $(CFLAGS) -o player_test obj/player_test.o obj/player.o obj/inventory.o obj/set.o $(LDFLAGS)


player.o: src/player.c include/player.h
	$(CC) $(CFLAGS) -c -o obj/player.o src/player.c $(LDFLAGS)

player_test.o: src/player_test.c include/player.h include/inventory.h
	$(CC) $(CFLAGS) -c -o obj/player_test.o src/player_test.c $(LDFLAGS)


clear:
	rm -rf obj/*.o

clean:
	rm -rf obj/*.o $(EJS)

doxygen:
	doxygen Doxyfile
