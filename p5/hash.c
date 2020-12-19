/////////////////////////////////////////////////////////////////////////
// Santiago Valderrabano Zamorano santiago.valderrabano@estudiante.uam.es
// Martin de las Heras Moreno martin.delasheras@estudiante.uam.es
// Saul Almazan saul.almazan@estudiante.uam.es
// Grupo 140
/////////////////////////////////////////////////////////////////////////

#include "hash.h"

hash_table_t* hash_table_create(int size){
    int i;
    hash_table_t* hash_table = NULL;

    if (size <= 0)
        return NULL;
    if (!(hash_table = malloc(sizeof(hash_table_t))))
        return NULL;
    if (!(hash_table->table = malloc(sizeof(input_t*)*size)))
        return NULL;
    for (i = 0; i < size; i++)
        hash_table->table[i] = NULL;
    hash_table->size = size;

    return hash_table;    
}

input_t* hash_table_pair(char* key, symbol* value){
    input_t* pair;

    if (!(pair = malloc(sizeof(input_t))))
        return NULL;

    if (!(pair->key = strdup(key)))
        return NULL;

    strcpy(pair->value.id, value->id);
    pair->value.symb_cat = value->symb_cat;
    pair->value.cat = value->cat;
    pair->value.type = value->type;
    pair->value.size = value->size;
    pair->value.num_param = value->num_param;
    pair->value.position = value->position;
    pair->value.value = value->value;
    pair->value.num_local_var = value->num_local_var;

    pair->next = NULL;
    
    return pair;
}

int hash_table_hash(hash_table_t* hash_table, char* key){
    int i = 0;
    unsigned long int hash_value;
    
    while (i < strlen(key) && hash_value < ULONG_MAX){
        hash_value = hash_value << 8;
        hash_value += key[i];
        i++;
    }

    return hash_value%hash_table->size;
}

int hash_table_set(hash_table_t* hash_table, char* key, symbol* value){
    input_t* pair = NULL, * next = NULL, * last = NULL;
    int bin  = hash_table_hash(hash_table, key);

    next = hash_table->table[bin];
    
    while (next && next->key && strcmp(key, next->key) > 0){
        last = next;
        next = next->next;
    }

    if (next && next->key && strcmp(key, next->key) == 0){
        strcpy(pair->value.id, value->id);
        pair->value.symb_cat = value->symb_cat;
        pair->value.cat = value->cat;
        pair->value.type = value->type;
        pair->value.size = value->size;
        pair->value.num_param = value->num_param;
        pair->value.position = value->position;
        pair->value.value = value->value;
        pair->value.num_local_var = value->num_local_var;

        return 0;
    }
    
    pair = hash_table_pair(key, value);

    if (next == hash_table->table[bin]){
        pair->next = next;
        hash_table->table[bin] = pair;
    }
    else if (!next)
        last->next = pair;
    else {
        pair->next = next;
        last->next = pair;
    }
    
    return 0;
}

symbol* hash_table_get(hash_table_t* hash_table, char* key){
    input_t* pair;
    int bin = hash_table_hash(hash_table, key);

    pair = hash_table->table[bin];

    while (pair && pair->key && strcmp(key, pair->key) > 0)
        pair = pair->next;

    if (!pair || !pair->key || strcmp(key, pair->key) != 0)
        return NULL;

    return &pair->value;
}

symbol* symbol_create(char *id, int symb_cat, int cat, int type, int size, int num_param, int position, int value, int num_local_var){
    symbol *new;
    new = calloc(1,sizeof(symbol));
    strcpy(new->id, id);
    new->symb_cat = symb_cat;
    new->cat = cat;
    new->type = type;
    new->size = size;
    new->num_param = num_param;
    new->position = position;
    new->value = value;
    new->num_local_var = num_local_var;

    return new;
}

void symbol_delete(symbol *symbol) {
    if (symbol) free(symbol);    
}