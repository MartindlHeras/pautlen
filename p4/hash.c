/////////////////////////////////////////////////////////////////////////
// Santiago Valderrabano Zamorano santiago.valderrabano@estudiante.uam.es
// Martin de las Heras Moreno martin.delasheras@estudiante.uam.es
// Saul Almazan saul.almazan@estudiante.uam.es
// Grupo 140
/////////////////////////////////////////////////////////////////////////

#include "hash.h"

struct input_s{
    char* value;
    char* key;
    struct input_s* next;
};

struct hash_table_s{
    int size;
    struct input_s** table;
};

hash_table_t* hash_table_create(int size){
    int i;
    hash_table_t* hash_table = NULL;

    if (size <= 0)
        return NULL;

    if (!(hash_table->table = malloc(sizeof(input_t*)*size)))
        return NULL;
    for (i = 0; i < size; i++)
        hash_table->table[i] = NULL;
    hash_table->size = size;

    return hash_table;    
}

input_t* hash_table_pair(char* key, char* value){
    input_t* pair;

    if (!(pair = malloc(sizeof(input_t))))
        return NULL;

    if (!(pair->key = strdup(key)) || !(pair->value = strdup(value)))
        return NULL;

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

int hash_table_set(hash_table_t* hash_table, char* key, char* value){
    input_t* pair = NULL, * next = NULL, * last = NULL;
    int bin  = hash_table_hash(hash_table, key);

    next = hash_table->table[bin];
    while (strcmp(key, pair->key) > 0 && pair->key && pair){
        last = next;
        pair = pair->next;
    }

    if (strcmp(key, pair->key) == 0 && pair->key && pair)
        return -1;
    
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

char* hash_table_get(hash_table_t* hash_table, char* key){
    input_t* pair;
    int bin = hash_table_hash(hash_table, key);

    pair = hash_table->table[bin];

    while (strcmp(key, pair->key) > 0 && pair->key && pair)
        pair = pair->next;

    if (strcmp(key, pair->key) != 0 || !pair->key || !pair)
        return NULL;

    return pair->value;
}