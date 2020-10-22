#include "generacion.h"

void segmento_bss(FILE* fpasm){
  fprintf(fpasm, "segment .bss\n");
  fprintf(fpasm, "__esp resd 1\n");
}

void segmento_data(FILE* fpasm){
  fprintf(fpasm, "segment .data\n");
  fprintf(fpasm, "out_of_range db \"Accessing a memory out of range\",10,0\n");
  fprintf(fpasm, "div_zero db \"Dividing by zero\",10,0\n");
}
