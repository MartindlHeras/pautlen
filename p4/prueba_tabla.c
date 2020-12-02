#include "tabla_simbolos.h"

int main(int argc, char const **argv) {
  char *buff,*readed;
  FILE *in,*out;
  hash_table_t *hash_global;

  if (argc != 3){
    fprintf(stderr, "Error en los parametros de entrada");
  }

  in = fopen(argv[1], "r");
  if (!in){
    fprintf(stderr, "Error en el fichero de entrada");
    return -1;
  }
  out = fopen(argv[2], "w");
  if (!out){
    fprintf(stderr, "Error en el fichero de salida");
    return -1;
  }

  hash_global = hash_table_create(65536);

  buff = (char*)malloc(SIZE * sizeof(char));
  if(!buff){
    return -1;
  }

  readed = fgets(buff, SIZE, in);

  while (readed){
    interact_table(buff, out, hash_global);
    readed = fgets(buff, SIZE, in);
  }

  fclose(in);
  fclose(out);

  return 0;
}
