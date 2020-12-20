/////////////////////////////////////////////////////////////////////////
// Santiago Valderrabano Zamorano santiago.valderrabano@estudiante.uam.es
// Martin de las Heras Moreno martin.delasheras@estudiante.uam.es
// Saul Almazan saul.almazan@estudiante.uam.es
// Grupo 140
/////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

#include "alfa.h"

#define ERR -1

symbol_table aux_symbol_table;

extern int yyparse(void);
extern FILE *yyin;
extern FILE *yyout;

int main(int argc, char const *argv[])
{

    if (argc < 3)
    {
        fprintf(stdout, "Missing entry parameters: ./alfa <input.txt> <output.txt>\n");
        return ERR;
    }

    if (!(yyin = fopen(argv[1], "r")))
    {
        fprintf(stdout, "Error opening %s\n", argv[1]);
        return ERR;
    }

    if (!(yyout = fopen(argv[2], "w")))
    {
        fprintf(stdout, "Error opening %s\n", argv[2]);
        return ERR;
    }

    aux_symbol_table.global_hash = hash_table_create(65536);
    aux_symbol_table.local_flag = 0;
    yyparse();

    fclose(yyin);
    fclose(yyout);
    return 0;
}   