/////////////////////////////////////////////////////////////////////////
// Santiago Valderrabano Zamorano santiago.valderrabano@estudiante.uam.es
// Martin de las Heras Moreno martin.delasheras@estudiante.uam.es
// Saul Almazan saul.almazan@estudiante.uam.es
// Grupo 140
/////////////////////////////////////////////////////////////////////////

#ifndef ALFA_H
#define ALFA_H

#include "generacion.h"
#include "hash.h"
#include "tabla_simbolos.h"

#define MAX_VECTOR_SIZE 64
#define MAX_ID_LONGITUDE 100

/*
* !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
* REVISASR NOMBRES DE VARIABLES POR SI NO SON LOS MEJORES
* ¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡
*/

typedef struct _attribute_type
{
    int type;
    int value;
    int label;
    char lexeme[MAX_ID_LONGITUDE + 1];
    char index[MAX_ID_LONGITUDE + 1];
    int is_address;
    int index_address;
} attribute_type;

#endif /* ALFA_H */