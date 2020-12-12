/////////////////////////////////////////////////////////////////////////
// Santiago Valderrabano Zamorano santiago.valderrabano@estudiante.uam.es
// Martin de las Heras Moreno martin.delasheras@estudiante.uam.es
// Saul Almazan saul.almazan@estudiante.uam.es
// Grupo 140
/////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

#include "generacion.h"

#define ERR -1

extern int yyparse(void);
extern FILE *yyin;
extern FILE *yyout;

int main(int argc, char const *argv[])
{

    if (argc < 3)
    {
        fprintf(stdout, "Missing entry parameters: ./pruebaSinta <input.txt> <output.txt>\n");
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

    yyparse();

    fclose(yyin);
    fclose(yyout);
    return 0;
}