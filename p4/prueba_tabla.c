#include "tablasimbolos.h"

int int main(int argc, char const **argv) {
  char *entry,*exit,*buff,*readed;
  FILE *in;


  if (argv != 3){
    fprintf(stderr, "Error en los parametros de entrada");
  }

  entry = argv[1];
  exit = argv[2];
  in = fopen(entry,"r");
  if (!in){
    fprintf(stderr, "Error en el fichero de entrada");
    return -1;
  }
  out = fopen(salida,"w");
  if (!out){
    fprintf(stderr, "Error en el fichero de salida");
    return -1;
  }
  hash_global = hash_table_create(432243);
  buff = (char * )malloc(SIZE * sizeof(char));
  if(!buff){
    return -1;
  }
  readed = fgets(buff , SIZE, in);

  while (readed){
    interaction_table(buff,out);
    readed = fgets(buff,SIZE,in);
  }

  fclose(in);
  fclose(out);

  return 0;
}
