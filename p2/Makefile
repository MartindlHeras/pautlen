########################################################
# Makefile
########################################################
all: pruebaMorfo

pruebaMorfo: pruebaMorfo.c lex.yy.o
	gcc -Wall -o pruebaMorfo pruebaMorfo.c lex.yy.o

lex.yy.o: lex.yy.c
  gcc -Wall -c lex.yy.c

lex.yy.c: alfa.l
  flex alfa.l

.PHONY: clean
clean:
	rm -rf lex.yy.* pruebaMorfo
