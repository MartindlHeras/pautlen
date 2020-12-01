#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct input_s input_t;
typedef struct hash_table_s hash_table_t;

hash_table_t* hash_table_create(int size);
input_t* hash_table_pair(char* key, char* value);
int hash_table_hash(hash_table_t* hash_table, char* key);
int hash_table_set(hash_table_t* hash_table, char* key, char* value);
char* hash_table_get(hash_table_t* hash_table, char* key);