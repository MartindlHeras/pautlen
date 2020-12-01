#include "hash.h"

struct input_s{
    char* value;
    char* key;
    struct input_s* succ;
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

    if (!(pair->key = strdup(key)))
        return NULL;

    if (!(pair->key = strdup(value)))
        return NULL;

    pair->succ = NULL;
    
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
        pair = pair->succ;
    }

    if (strcmp(key, pair->key) == 0 && pair->key && pair)
        return -1;
    
    pair = hash_table_pair(key, value);

    if (next == hash_table->table[bin]){
        pair->succ = next;
        hash_table->table[bin] = pair;
    }
    else if (!next)
        last->succ = pair;
    else {
        pair->succ = next;
        last->succ = pair;
    }
    
    return 0;
}

char* hash_table_get(hash_table_t* hash_table, char* key){
    input_t* pair;
    int bin = hash_table_hash(hash_table, key);

    pair = hash_table->table[bin];

    while (strcmp(key, pair->key) > 0 && pair->key && pair)
        pair = pair->succ;

    if (strcmp(key, pair->key) != 0 || !pair->key || !pair)
        return NULL;

    return pair->value;
}