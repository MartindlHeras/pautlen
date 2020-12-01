#include "hash.h"

int flag = 0;
hash_table_t *hash_local;


void interaction_table(char * buff,FILE *out,hash_table_t *hash_global){

  char *token1,*token2 ,*result;
  int result_number;

  token1 = strtok(buff,"\t\n");
  token2 = strtok(NULL,"\t\n");

  if(flag == 1){
    if(token2 == NULL){
      result = hash_table_get(hash_local,token1);
      if(result == NULL){
        result = hash_table_get(hash_global,token1);
        if(result == NULL){
          fprintf(out, "%s -1\n",token1);
        }
        else{
          fprintf(out, "%s %s\n",token1,result);
        }
      }
      else{
        fprintf(out, "%s %s\n",token1,result);
      }
    }
    else{
      if(strcmp(token1,"cierre")==0 && strcmp(token2,"-999")==0){
        flag = 0;
        free(hash_local);
        fprintf(out, "cierre");
      }
      else{
        result_number = hash_table_set(hash_local,token1,token2);
        if(result_number== -1){
          fprintf(out, "-1 %s\n",token1);
        }
        else{
            fprintf(out, "%s\n",token1);
        }
      }
    }
  }
  else{
    if(token2 == NULL) {
      result = hash_table_get(hash_global,token1);

      if(result == NULL){
        fprintf(out, "%s -1\n",token1);
      }
      else{
        fprintf(out, "%s %s\n",token1,result);

      }
    }
    else{
      if(atoi(token2)>0){
        result_number = hash_table_set(hash_global,token1,token2);

        if(result_number== -1){
          fprintf(out, "-1 %s\n",token1);
        }
        else{
          fprintf(out, "%s\n",token1);
        }
      }

      else{
        result_number = hash_table_set(hash_global,token1,token2);
        flag = 1;
        hash_local = hash_table_create(655386);
        hash_table_set(hash_local,token1,token2);
        fprintf(out, "%s\n", token1);
      }
    }
  }
}
