/////////////////////////////////////////////////////////////////////////
// Santiago Valderrabano Zamorano santiago.valderrabano@estudiante.uam.es
// Martin de las Heras Moreno martin.delasheras@estudiante.uam.es
// Saul Almazan saul.almazan@estudiante.uam.es
// Grupo 140
/////////////////////////////////////////////////////////////////////////

#include "hash.h"
#define SIZE 32

typedef struct _symbol_table {
    int local_flag;
    hash_table_t *local_hash;
    hash_table_t *global_hash;
} symbol_table;

int insert_table(symbol_table *hashes, char *key, symbol *value);

int close_scope(symbol_table *hashes);

symbol *search_table(symbol_table *hashes, char *key);