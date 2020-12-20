/////////////////////////////////////////////////////////////////////////
// Santiago Valderrabano Zamorano santiago.valderrabano@estudiante.uam.es
// Martin de las Heras Moreno martin.delasheras@estudiante.uam.es
// Saul Almazan saul.almazan@estudiante.uam.es
// Grupo 140
/////////////////////////////////////////////////////////////////////////

#include "tabla_simbolos.h"

int insert_table(symbol_table *hashes, char *key, symbol *value){

  if(!hashes) return -1;
  if(!key) return -1;
  if (!value) return -1;
  

  int res_value;

  if (hashes->local_flag == 1)
  {
    res_value = hash_table_set(hashes->local_hash, key, value);

    return res_value;
  }
  else
  {
    res_value = hash_table_set(hashes->global_hash, key, value);

    if(res_value == -1) return -1;

    if (value->symb_cat == FUNCTION)
    {
      if (hashes->local_flag != 0) return -1;

      hashes->local_flag = 1;
      hashes->local_hash = hash_table_create(65536);

      res_value = hash_table_set(hashes->local_hash, key, value);
      if(res_value == -1) return -1;
    }
    return 0;
  }
}

int close_scope(symbol_table *hashes){

  if(!hashes) return -1;

  if(hashes->local_flag == 1)
  {
    free(hashes->local_hash);
    hashes->local_flag = 0;
    return 0;
  }
  return -1;
}

symbol *search_table(symbol_table *hashes, char *key){

  if(!hashes) return NULL;
  if(!key) return NULL;

  symbol *res_value;

  if (hashes->local_flag == 1)
  {
    res_value = hash_table_get(hashes->local_hash, key);

    if(res_value) return res_value;
  }

  res_value = hash_table_get(hashes->global_hash, key);
  return res_value;
}
