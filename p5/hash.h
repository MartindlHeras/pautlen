/////////////////////////////////////////////////////////////////////////
// Santiago Valderrabano Zamorano santiago.valderrabano@estudiante.uam.es
// Martin de las Heras Moreno martin.delasheras@estudiante.uam.es
// Saul Almazan saul.almazan@estudiante.uam.es
// Grupo 140
/////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define VARIABLE 0
#define PARAMETER 1
#define FUNCTION 2

#define INT 1
#define BOOL 0

#define SCALAR 0
#define VECTOR 1

typedef struct _symbol {
    char id[64];
    int symb_cat;
    int cat;
    int type;
    int size;
    int num_param;
    int position;
    int value;
    int num_local_var;
}symbol;

typedef struct input_s{
    symbol value;
    char* key;
    struct input_s* next;
}input_t;

typedef struct hash_table_s{
    int size;
    struct input_s** table;
}hash_table_t;

hash_table_t* hash_table_create(int size);
input_t* hash_table_pair(char* key, symbol* value);
int hash_table_hash(hash_table_t* hash_table, char* key);
int hash_table_set(hash_table_t* hash_table, char* key, symbol* value);
symbol* hash_table_get(hash_table_t* hash_table, char* key);
symbol* symbol_create(char *id, int symb_cat, int type, int cat, int value, int size, int num_param, int position, int num_local_var);
void symbol_delete(symbol *symbol);
