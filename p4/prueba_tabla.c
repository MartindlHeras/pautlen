#include "tablasimbolos.h"

int main(int argc, char const **argv) {
  char *buff,*readed;
  FILE *in,*out;
  hash_table_t *hash_global;
  const char *entry,*exit;


  if (argc != 3){
    fprintf(stderr, "Error en los parametros de entrada");
  }

  entry = argv[1];
  exit = argv[2];
  in = fopen(entry,"r");
  if (!in){
    fprintf(stderr, "Error en el fichero de entrada");
    return -1;
  }
  out = fopen(exit,"w");
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
    interaction_table(buff,out, hash_global);
    readed = fgets(buff,SIZE,in);
  }

  fclose(in);
  fclose(out);

  return 0;
}
