%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alfa.h"

#define MAX 64

extern FILE* yyout;
extern int yylex(void);
void yyerror(const char * s);

extern int is_morpho;
extern int n_lines;
extern int n_cols;

extern symbol_table aux_symbol_table;
symbol *aux_symb;

int curr_type;
int curr_class;
int curr_len;

int local_var_pos;
int pos_params;

int num_params = 0;
int local_var_num = 1;
int func_ret = 0;
int func_flag_dec = 0;
int num_params_call = 0;
int func_call = 0;
int label = 0;



%}

%union
{
    attribute_type attributes;
}

%token TOK_MAIN
%token TOK_INT       
%token TOK_BOOLEAN   
%token TOK_ARRAY     
%token TOK_FUNCTION  
%token TOK_IF        
%token TOK_ELSE      
%token TOK_WHILE     
%token TOK_SCANF     
%token TOK_PRINTF    
%token TOK_RETURN    


/* S�mbolos */
%token TOK_PUNTOYCOMA
%token TOK_COMA
%token TOK_PARENTESISIZQUIERDO
%token TOK_PARENTESISDERECHO
%token TOK_CORCHETEIZQUIERDO
%token TOK_CORCHETEDERECHO
%token TOK_LLAVEIZQUIERDA 
%token TOK_LLAVEDERECHA
%token TOK_ASIGNACION
%token TOK_MAS
%token TOK_MENOS
%token TOK_DIVISION
%token TOK_ASTERISCO
%token TOK_AND
%token TOK_OR
%token TOK_NOT
%token TOK_IGUAL
%token TOK_DISTINTO
%token TOK_MENORIGUAL
%token TOK_MAYORIGUAL
%token TOK_MENOR
%token TOK_MAYOR

%token TOK_TRUE
%token TOK_FALSE


%token <attributes> TOK_CONSTANTE_ENTERA
%token <attributes> TOK_IDENTIFICADOR

%type <attributes> clase_vector
%type <attributes> declaraciones_funcion
%type <attributes> funcion
%type <attributes> funcion_declaracion
%type <attributes> nombre_funcion
%type <attributes> elemento_vector
%type <attributes> if_exp
%type <attributes> if_exp_sentencias
%type <attributes> while
%type <attributes> while_exp
%type <attributes> exp
%type <attributes> comparacion
%type <attributes> constante
%type <attributes> constante_entera
%type <attributes> constante_logica
%type <attributes> identificador

%start programa

%left TOK_IGUAL TOK_DISTINTO TOK_MENORIGUAL TOK_MAYORIGUAL TOK_MENOR TOK_MAYOR
%left TOK_AND 
%left TOK_OR
%left TOK_MENOS TOK_MAS
%left TOK_DIVISION TOK_ASTERISCO
%right TOK_NOT

%%

programa:
    escritura_cabecera TOK_MAIN TOK_LLAVEIZQUIERDA declaraciones escritura_codigo funciones escritura_main sentencias TOK_LLAVEDERECHA {
        fprintf(yyout, ";R1:\t<programa> ::= main { <declaraciones> <funciones> <sentencias> }\n");
        escribir_fin(yyout);
    };

escritura_cabecera: 
    %empty {
        escribir_subseccion_data(yyout);
        escribir_cabecera_bss(yyout);
    };

escritura_codigo: 
    %empty {
        escribir_segmento_codigo(yyout);
    };

escritura_main: 
    %empty {
        escribir_inicio_main(yyout);
    };

declaraciones:
    declaracion { 
        fprintf(yyout, ";R2:\t<declaraciones> ::= <declaracion>\n");
    } | 
    declaracion declaraciones {
        fprintf(yyout, ";R3:\t<declaraciones> ::= <declaracion> <declaraciones>\n");
    };

declaracion:
    clase identificadores TOK_PUNTOYCOMA { 
        fprintf(yyout, ";R4:\t<declaracion> ::= <clase> <identificadores> ;\n"); 
    };

clase:
    clase_escalar {
        fprintf(yyout, ";R5:\t<clase> ::= <clase_escalar>\n");
        curr_class = SCALAR;
    } | 
    clase_vector {
        fprintf(yyout, ";R7:\t<clase> ::= <clase_vector>\n");
        curr_class = VECTOR;
    };

clase_escalar:
    tipo {
        fprintf(yyout, ";R9:\t<clase_escalar> ::= <tipo>\n");
    };

tipo:
    TOK_INT { 
        fprintf(yyout, ";R10:\t<tipo> ::= int\n");
        curr_type = INT;
        curr_len = 1;
    } | 
    TOK_BOOLEAN { 
        fprintf(yyout, ";R11:\t<tipo> ::= boolean\n"); 
        curr_type = BOOL;
        curr_len = 1;
    };

clase_vector:
    TOK_ARRAY tipo TOK_CORCHETEIZQUIERDO constante_entera TOK_CORCHETEDERECHO {
        fprintf(yyout, ";R15:\t<clase_vector> ::= array <tipo> [ <constante_entera> ]\n");
        if($4.value > MAX || $4.value <= 0){
            printf("****Error semantico en lin %d: El tamanyo del vector %s excede los limites permitidos (1,64).\n", n_lines, $4.lexeme);
            return -1;
        }
        $$.value = $4.value;
        curr_len = $4.value;
    };

identificadores:
    identificador {
        fprintf(yyout, ";R18:\t<identificadores> ::= <identificador>\n");
    } | 
    identificador TOK_COMA identificadores{
        fprintf(yyout, ";R19:\t<identificadores> ::= <identificador> , <identificadores>\n");
    };

funciones:
    funcion funciones{
        fprintf(yyout, ";R20:\t<funciones> ::= <funcion> <funciones>\n");
    } |
    %empty {
        fprintf(yyout, ";R21:\t<funciones> ::=\n"); 
    };

funcion:
    funcion_declaracion sentencias TOK_LLAVEDERECHA{
        fprintf(yyout, ";R22:\t<funcion> ::= function <tipo> <identificador> ( <parametros_funcion> ) { <declaraciones_funcion> <sentencias> }\n");
        if(func_ret==0){
            printf("****Error semantico en lin %d: Funcion <nombre_funcion> sin sentencia de retorno\n", n_lines);
			return -1;
        }
        if(close_scope(&aux_symbol_table) == -1) return -1;

        aux_symb = search_table(&aux_symbol_table, $1.lexeme);
        if(!aux_symb) return -1;

        aux_symb = symbol_create($1.lexeme, FUNCTION, aux_symb->type, -1, -1, -1, num_params, -1, local_var_num);

        insert_table(&aux_symbol_table, $1.lexeme, aux_symb);

        if(close_scope(&aux_symbol_table) == -1) return -1;

        func_flag_dec = 0;
        symbol_delete(aux_symb);
    };

funcion_declaracion: 
    nombre_funcion TOK_PARENTESISIZQUIERDO parametros_funcion TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA declaraciones_funcion {
        
        strcpy($$.lexeme, $1.lexeme);
        $$.type = $1.type;

        declararFuncion(yyout, $1.lexeme, local_var_num);

        aux_symb = search_table(&aux_symbol_table, $1.lexeme);

        if(!aux_symb) return -1;

        aux_symb = symbol_create($1.lexeme, FUNCTION, aux_symb->type, -1, -1, -1, num_params, -1, local_var_num);

        insert_table(&aux_symbol_table, $1.lexeme, aux_symb);

        symbol_delete(aux_symb);
    };

nombre_funcion: TOK_FUNCTION tipo TOK_IDENTIFICADOR {

        aux_symb = search_table(&aux_symbol_table, $3.lexeme);

        if(!aux_symb){
            printf("****Error semantico en lin %d: Declaracion duplicada.\n", n_lines);
			return -1;
        }

        aux_symb = symbol_create($3.lexeme, FUNCTION, curr_type, -1, -1, -1, -1, -1, -1);

        insert_table(&aux_symbol_table, $3.lexeme, aux_symb);

        num_params = 0;
        pos_params = 0;
        local_var_num = 1;
        local_var_pos = 1;
        func_flag_dec = 1;
        func_ret = 0;

        strcpy($$.lexeme, $3.lexeme);
        $$.type = curr_type;

        symbol_delete(aux_symb);
    };

parametros_funcion:
    parametro_funcion resto_parametros_funcion {
        fprintf(yyout, ";R23:\t<parametros_funcion> ::= <parametro_funcion> <resto_parametros_funcion>\n");
    } |
    %empty {
        fprintf(yyout, ";R24:\t<parametros_funcion> ::=\n");
    };

resto_parametros_funcion:
    TOK_PUNTOYCOMA parametro_funcion resto_parametros_funcion {
        fprintf(yyout, ";R25:\t<resto_parametros_funcion> ::= ; <parametro_funcion> <resto_parametros_funcion>\n");
    } |
    %empty {
        fprintf(yyout, ";R26:\t<resto_parametros_funcion> ::=\n");
    };

parametro_funcion:
    tipo idpf {
        fprintf(yyout, ";R27:\t<parametro_funcion> ::= <tipo> <identificador>\n");
        num_params++;
        pos_params++;
    };

declaraciones_funcion:
    declaraciones {
        fprintf(yyout, ";R28:\t<declaraciones_funcion> ::= <declaraciones>\n");
    } | 
    %empty {
        fprintf(yyout, ";R29:\t<declaraciones_funcion> ::=\n");
    };

sentencias:
    sentencia {
        fprintf(yyout, ";R30:\t<sentencias> ::= <sentencia>\n");
    } | 
    sentencia sentencias {
        fprintf(yyout, ";R31:\t<sentencias> ::= <sentencia> <sentencias>\n");
    };

sentencia:
    sentencia_simple TOK_PUNTOYCOMA {
        fprintf(yyout, ";R32:\t<sentencia> ::= <sentencia_simple> ;\n");
    } | 
    bloque {
        fprintf(yyout, ";R33:\t<sentencia> ::= <bloque>\n");
    };

sentencia_simple:
    asignacion { 
        fprintf(yyout, ";R34:\t<sentencia_simple> ::= <asignacion>\n");
    } |   
    lectura {
        fprintf(yyout, ";R35:\t<sentencia_simple> ::= <lectura>\n");
    } | 
    escritura {
        fprintf(yyout, ";R36:\t<sentencia_simple> ::= <escritura>\n");
    } | 
    retorno_funcion {
        fprintf(yyout, ";R38:\t<sentencia_simple> ::= <retorno_funcion>\n");
    };

bloque:
    condicional {
        fprintf(yyout, ";R40:\t<bloque> ::= <condicional>\n");
    } | 
    bucle {
        fprintf(yyout, ";R41:\t<bloque> ::= <bucle>\n");
    };

asignacion:
    TOK_IDENTIFICADOR TOK_ASIGNACION exp {
        fprintf(yyout, ";R43:\t<asignacion> ::= <identificador> = <exp>\n");

        aux_symb = search_table(&aux_symbol_table, $1.lexeme);
        if(!aux_symb || aux_symb->symb_cat == FUNCTION || aux_symb->cat == VECTOR){
            printf("****Error semántico en lin %d: Asignacion incompatible.\n",n_lines);
            return -1;
        }

        if(aux_symb->type != $3.type){
            printf("****Error semántico en lin %d: Asignacion incompatible.\n",n_lines);
            return -1;
        }

        if(func_flag_dec == 1){

            if(aux_symb->symb_cat == PARAMETER){
			    escribirParametro(yyout, aux_symb->position, num_params);
            }
            else
            {
                escribirVariableLocal(yyout, aux_symb->position);
            }

		    asignarDestinoEnPila(yyout, $3.is_address);
        }
        else
        {
		    asignar(yyout, $1.lexeme, $3.is_address);
        }

    } |
    elemento_vector TOK_ASIGNACION exp {
        fprintf(yyout, ";R44:\t<asignacion> ::= <elemento_vector> = <exp>\n");

        if($1.type != $3.type){
            printf("****Error semantico en linea %d: Asignacion incompatible\n", n_lines);
            return -1;
        }
        
        aux_symb = search_table(&aux_symbol_table, $1.lexeme);
        if(!aux_symb){
            printf("****Error semantico en linea %d: Acceso a variable no delcarada (%s)\n", n_lines, $1.lexeme);
            return -1;
        }

        if(aux_symb->symb_cat == FUNCTION || aux_symb->cat != VECTOR){
            printf("****Error semántico en lin %d: Asignacion incompatible.\n",n_lines);
            return -1;
        }

        if($1.index_address == 0) {
            char buffer[MAX];
            sprintf(buffer, "%d", $1.value);
            escribir_operando(yyout, buffer, 0);
        }
        if($1.index_address == 1) escribir_operando(yyout, $1.index, 1);

        escribir_elemento_vector(yyout, $1.lexeme, aux_symb->size, $3.is_address);
        asignarDestinoEnPila(yyout, $3.is_address);
        symbol_delete(aux_symb);

    };

elemento_vector:
    TOK_IDENTIFICADOR TOK_CORCHETEIZQUIERDO exp TOK_CORCHETEDERECHO {
        fprintf(yyout, ";R48:\t<elemento_vector> ::= <identificador> [ <exp> ]\n");

        if($3.type != INT){
            printf("****Error semantico en lin %d: El indice en una operacion de indexacion tiene que ser de tipo entero.\n", n_lines);
            return -1;
        }

        aux_symb = search_table(&aux_symbol_table, $1.lexeme);
        
        if(!aux_symb){
            printf("****Error semantico en lin %d: Acceso a variable no declarada (%s).\n", n_lines, $1.lexeme);
            return -1;
        }

        if(aux_symb->symb_cat == FUNCTION || aux_symb->cat != VECTOR){
            printf("****Error semántico en lin %d: Intento de indexacion de una variable que no es de tipo vector.\n",n_lines);
            return -1;
        }

        if($3.is_address == 0){
            $$.index_address = 0;
            $$.value = $3.value;
        }
        else if($3.is_address == 1){
            $$.index_address = 1;
            strcpy($$.index, $3.lexeme);
        }

        $$.type = aux_symb->type;
        $$.is_address = 1;
        strcpy($$.lexeme, $1.lexeme);
        symbol_delete(aux_symb);
    };

condicional:
    if_exp_sentencias TOK_LLAVEDERECHA {
        fprintf(yyout, ";R50:\t<condicional> ::= if ( <exp> ) { <sentencias> }\n");
        ifthenelse_fin(yyout, $1.label);
    } |
    if_exp_sentencias TOK_LLAVEDERECHA TOK_ELSE TOK_LLAVEIZQUIERDA sentencias TOK_LLAVEDERECHA{
        fprintf(yyout, ";R51:\t<condicional> ::= if ( <exp> ) { <sentencias> } else { <sentencias> }\n");
        ifthenelse_fin(yyout, $1.label);
    };

if_exp: 
    TOK_IF TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA {

        if($3.type != BOOL){
            printf("****Error semantico en linea %d: Condicional con condicion de tipo int.\n", n_lines);
            return -1;
        }

        $$.label = label++;
        ifthen_inicio(yyout, $3.is_address, $$.label);
    };

if_exp_sentencias: 
    if_exp sentencias {
        $$.label = $1.label;
        ifthenelse_fin_then(yyout, $$.label);
    };

bucle:
    while_exp sentencias TOK_LLAVEDERECHA{
        fprintf(yyout, ";R52:\t<bucle> ::= while ( <exp> ) { <sentencias> }\n");
        while_fin(yyout, $1.label);
    };

while: 
    TOK_WHILE TOK_PARENTESISIZQUIERDO {
        $$.label = label++;
        while_inicio(yyout, $$.label);
    };

while_exp: 
    while exp TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA{
        if($2.type != BOOL){
            printf("****Error semantico en linea %d: Condicional con condicion de tipo int.\n", n_lines);
            return -1;
        }

        $$.label = $1.label;
        while_exp_pila(yyout, $2.is_address, $$.label);
    };

lectura:
    TOK_SCANF TOK_IDENTIFICADOR {
        fprintf(yyout, ";R54:\t<lectura> ::= scanf <identificador>\n");
        aux_symb = search_table(&aux_symbol_table, $2.lexeme);
        if(!aux_symb){
            printf("****Error semantico en lin %d: Acceso a variable no declarada (%s).\n", n_lines, $2.lexeme);
            return -1;
        }

        if(aux_symb->symb_cat == FUNCTION || aux_symb->cat != SCALAR){
            printf("****Error semántico en lin %d: Asignacion incompatible.\n", n_lines);
            return -1;
        }

        leer(yyout, $2.lexeme, aux_symb->type);
        symbol_delete(aux_symb);
    };

escritura:
    TOK_PRINTF exp {
        fprintf(yyout, ";R56:\t<escritura> ::= printf <exp>\n");
        escribir(yyout, $2.is_address, $2.type);
    };

retorno_funcion:
    TOK_RETURN exp {
        fprintf(yyout, ";R61:\t<retorno_funcion> ::= return <exp>\n");

        if(func_flag_dec == 0){
            printf("****Error semantico en lin %d: Sentencia de retorno fuera del cuerpo de una funcion.\n", n_lines);
		    return -1;
        }
        func_ret = 1;
        retornarFuncion(yyout, $2.is_address);

    };

exp:
    exp TOK_MAS exp {
        fprintf(yyout, ";R72:\t<exp> ::= <exp> + <exp>\n");

        if($1.type == BOOL || $3.type == BOOL){
            printf("****Error semantico en lin %d: Operacion aritmetica con operandos boolean.\n", n_lines);
            return -1;
        }

        if($1.type == INT && $3.type == INT){
            sumar(yyout,$1.is_address, $3.is_address);

            $$.type = INT;
            $$.is_address = 0;
            $$.value = $1.value + $3.value;
        }

    } | 
    exp TOK_MENOS exp {
        fprintf(yyout, ";R73:\t<exp> ::= <exp> - <exp>\n");

        if($1.type == BOOL || $3.type == BOOL){
            printf("****Error semantico en lin %d: Operacion aritmetica con operandos boolean.\n", n_lines);
            return -1;
        }

        if($1.type == INT && $3.type == INT){
            restar(yyout,$1.is_address, $3.is_address);

            $$.type = INT;
            $$.is_address = 0;
            $$.value = $1.value - $3.value;
        }

    } | 
    exp TOK_DIVISION exp {
        fprintf(yyout, ";R74:\t<exp> ::= <exp> / <exp>\n");

        if($1.type == BOOL || $3.type == BOOL){
            printf("****Error semantico en lin %d: Operacion aritmetica con operandos boolean.\n", n_lines);
            return -1;
        }

        if($1.type == INT && $3.type == INT){
            dividir(yyout,$1.is_address, $3.is_address);

            $$.type = INT;
            $$.is_address = 0;
            if($3.value == 0){
                printf("****Error de ejecucion: Division por 0\n");
                return -1;
            }
            $$.value = $1.value / $3.value;
        }

    } | 
    exp TOK_ASTERISCO exp {
        fprintf(yyout, ";R75:\t<exp> ::= <exp> * <exp>\n");

        if($1.type == BOOL || $3.type == BOOL){
            printf("****Error semantico en lin %d: Operacion aritmetica con operandos boolean.\n", n_lines);
            return -1;
        }

        if($1.type == INT && $3.type == INT){
            multiplicar(yyout,$1.is_address, $3.is_address);

            $$.type = INT;
            $$.is_address = 0;
            $$.value = $1.value * $3.value;
        }

    } | 
    TOK_MENOS exp {
        fprintf(yyout, ";R76:\t<exp> ::= - <exp>\n");

        if($2.type == BOOL){
            printf("****Error semantico en lin %d: Operacion aritmetica con operandos boolean.\n", n_lines);
            return -1;
        }

        if($2.type == INT){
            cambiar_signo(yyout,$2.is_address);

            $$.type = INT;
            $$.is_address = 0;
            $$.value = -$2.value;
        }

    } | 
    exp TOK_AND exp {
        fprintf(yyout, ";R77:\t<exp> ::= <exp> && <exp>\n");

        if($1.type == INT || $3.type == INT){
            printf("****Error semantico en lin %d: Operacion logica con operandos int.\n", n_lines);
            return -1;
        }

        if($1.type == BOOL && $3.type == BOOL){
            y(yyout,$1.is_address, $3.is_address);

            $$.type = BOOL;
            $$.is_address = 0;
            $$.value = $1.value && $3.value;
        }

    } | 
    exp TOK_OR exp {
        fprintf(yyout, ";R78:\t<exp> ::= <exp> || <exp>\n");

        if($1.type == INT || $3.type == INT){
            printf("****Error semantico en lin %d: Operacion logica con operandos int.\n", n_lines);
            return -1;
        }

        if($1.type == BOOL && $3.type == BOOL){
            o(yyout,$1.is_address, $3.is_address);

            $$.type = BOOL;
            $$.is_address = 0;
            $$.value = $1.value || $3.value;
        }

    } | 
    TOK_NOT exp {
        fprintf(yyout, ";R79:\t<exp> ::= ! <exp>\n");

        if($2.type == INT){
            printf("****Error semantico en lin %d: Operacion logica con operandos int.\n", n_lines);
            return -1;
        }

        if($2.type == BOOL){
            no(yyout, $2.is_address, 1);

            $$.type = BOOL;
            $$.is_address = 0;
            $$.value = !$2.value;
        }


    } |
    TOK_IDENTIFICADOR {
        fprintf(yyout, ";R80:\t<exp> ::= <identificador>\n");

        aux_symb = search_table(&aux_symbol_table, $1.lexeme);

        if(!aux_symb){
            printf("****Error semantico en linea %d: Acceso a variable no delcarada (%s)\n", n_lines, $1.lexeme);
            return -1;
        }

        if(aux_symb->cat == VECTOR || aux_symb->symb_cat == FUNCTION){
            printf("****Error semantico en linea %d: Asignacion incompatible\n", n_lines);
            return -1;
        }

        $$.type = aux_symb->type;
        $$.is_address = 1;

        if(func_flag_dec != 1) escribir_operando(yyout, $1.lexeme, 1);
        else
        {
            if(aux_symb->symb_cat == PARAMETER) escribirParametro(yyout, aux_symb->position, num_params);
            else escribirVariableLocal(yyout, aux_symb->position);
        }

        if(func_call == 1){
            operandoEnPilaAArgumento(yyout, 1);
            $$.is_address = 0;
        }
        symbol_delete(aux_symb);

    } |
    constante {
        fprintf(yyout, ";R81:\t<exp> ::= <constante>\n");

        $$.type = $1.type;
        $$.is_address = $1.is_address;
        if(func_call == 1) operandoEnPilaAArgumento(yyout, 0);

    } |
    TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO {
        fprintf(yyout, ";R82:\t<exp> ::= ( <exp> )\n");
        $$.type = $2.type;
        $$.is_address = $2.is_address;
    } | 
    TOK_PARENTESISIZQUIERDO comparacion TOK_PARENTESISDERECHO {
        fprintf(yyout, ";R83:\t<exp> ::= ( <comparacion> )\n");
        $$.type = $2.type;
        $$.is_address = $2.is_address;
    } | 
    elemento_vector {
        fprintf(yyout, ";R85:\t<exp> ::= <elemento_vector>\n");

        $$.type = $1.type;
        $$.is_address = 1;
        $$.value = $1.value;
        strcpy($$.lexeme, $1.lexeme);

        aux_symb = search_table(&aux_symbol_table, $1.lexeme);

        if(!aux_symb || aux_symb->cat != VECTOR || aux_symb->symb_cat == FUNCTION){
            printf("****Error semantico en linea %d: Asignacion incompatible\n", n_lines);
            return -1;
        }

        escribir_elemento_vector(yyout, $1.lexeme, aux_symb->size, $1.index_address);

        if(func_call == 1){
            operandoEnPilaAArgumento(yyout, 1);
            $$.is_address = 0;
        }

    } | 
    TOK_IDENTIFICADOR TOK_PARENTESISIZQUIERDO lista_expresiones TOK_PARENTESISDERECHO {
        fprintf(yyout, ";R88:\t<exp> ::= <identificador> ( <lista_expresiones> )\n");

        if(func_call == 1){
            printf("****Error semantico en lin %d: No esta permitido el uso de llamadas a funciones como parametros de otras funciones.\n", n_lines);
            return -1;
        }

        func_call = 1;

        aux_symb = search_table(&aux_symbol_table, $1.lexeme);
        if(!aux_symb){
            printf("****Error semantico en lin %d. Asignacion incompatible.\n", n_lines);
		    return -1;
        }
        if(num_params_call != aux_symb->num_param){
            printf("****Error semantico en lin %d: Numero incorrecto de parametros en llamada a funcion.\n", n_lines);
            return -1;
        }

        llamarFuncion(yyout, $1.lexeme, num_params_call);
        limpiarPila(yyout, num_params_call);
        num_params_call = 0;
        func_call = 0;
        $$.is_address = 0;
        $$.type = aux_symb->type;
        symbol_delete(aux_symb);
    };

lista_expresiones:
    exp resto_lista_expresiones {
        fprintf(yyout, ";R89:\t<lista_expresiones> ::= <exp> <resto_lista_expresiones>\n");
        num_params_call++;
    } | 
    %empty {
        fprintf(yyout, ";R90:\t<lista_expresiones> ::=\n");
    };

resto_lista_expresiones:
    TOK_COMA exp resto_lista_expresiones {
        fprintf(yyout, ";R91:\t<resto_lista_expresiones> ::= , <exp> <resto_lista_expresiones>\n");
        num_params_call++;
    } | 
    %empty {
        fprintf(yyout, ";R92:\t<resto_lista_expresiones> ::=\n");
    };

comparacion:
    exp TOK_IGUAL exp {
        fprintf(yyout, ";R93:\t<comparacion> ::= <exp> == <exp>\n");

        if($1.type == BOOL || $3.type == BOOL){
            printf("****Error semantico en lin %d: Comparacion con operandos boolean.\n", n_lines);
            return -1;
        }

        if($1.type == INT && $3.type == INT){
            igual(yyout,$1.is_address, $3.is_address, label);

            label++;
            $$.type =  BOOL;
            $$.is_address = 0;
            $$.value = $1.value == $3.value;
        }
    } | 
    exp TOK_DISTINTO exp {
        fprintf(yyout, ";R94:\t<comparacion> ::= <exp> != <exp>\n");

        if($1.type == BOOL || $3.type == BOOL){
            printf("****Error semantico en lin %d: Comparacion con operandos boolean.\n", n_lines);
            return -1;
        }

        if($1.type == INT && $3.type == INT){
            distinto(yyout,$1.is_address, $3.is_address, label);

            label++;
            $$.type =  BOOL;
            $$.is_address = 0;
            $$.value = $1.value != $3.value;
        }

    } | 
    exp TOK_MENORIGUAL exp {
        fprintf(yyout, ";R95:\t<comparacion> ::= <exp> <= <exp>\n");

        if($1.type == BOOL || $3.type == BOOL){
            printf("****Error semantico en lin %d: Comparacion con operandos boolean.\n", n_lines);
            return -1;
        }

        if($1.type == INT && $3.type == INT){
            menor_igual(yyout,$1.is_address, $3.is_address, label);

            label++;
            $$.type =  BOOL;
            $$.is_address = 0;
            $$.value = $1.value <= $3.value;
        }

    } | 
    exp TOK_MAYORIGUAL exp {
        fprintf(yyout, ";R96:\t<comparacion> ::= <exp> >= <exp>\n");

        if($1.type == BOOL || $3.type == BOOL){
            printf("****Error semantico en lin %d: Comparacion con operandos boolean.\n", n_lines);
            return -1;
        }

        if($1.type == INT && $3.type == INT){
            mayor_igual(yyout,$1.is_address, $3.is_address, label);

            label++;
            $$.type =  BOOL;
            $$.is_address = 0;
            $$.value = $1.value >= $3.value;
        }

    } |
    exp TOK_MENOR exp {
        fprintf(yyout, ";R97:\t<comparacion> ::= <exp> < <exp>\n");

        if($1.type == BOOL || $3.type == BOOL){
            printf("****Error semantico en lin %d: Comparacion con operandos boolean.\n", n_lines);
            return -1;
        }

        if($1.type == INT && $3.type == INT){
            menor(yyout,$1.is_address, $3.is_address, label);

            label++;
            $$.type =  BOOL;
            $$.is_address = 0;
            $$.value = $1.value < $3.value;
        }

    } | 
    exp TOK_MAYOR exp {
        fprintf(yyout, ";R98:\t<comparacion> ::= <exp> > <exp>\n");

        if($1.type == BOOL || $3.type == BOOL){
            printf("****Error semantico en lin %d: Comparacion con operandos boolean.\n", n_lines);
            return -1;
        }

        if($1.type == INT && $3.type == INT){
            mayor(yyout,$1.is_address, $3.is_address, label);

            label++;
            $$.type =  BOOL;
            $$.is_address = 0;
            $$.value = $1.value > $3.value;
        }

    };

constante:
    constante_entera {
        fprintf(yyout, ";R100:\t<constante> ::= <constante_entera>\n");
        $$.type = $1.type;
        $$.is_address = $1.is_address;
    } | 
    constante_logica {
        fprintf(yyout, ";R101:\t<constante> ::= <constante_logica>\n");
        $$.type = $1.type;
        $$.is_address = $1.is_address;
    };

constante_logica:
    TOK_TRUE {
        fprintf(yyout, ";R102:\t<constante_logica> ::= true\n");

        $$.type = BOOL;
        $$.is_address = 0;
        escribir_operando(yyout, "1", 0);
    } | 
    TOK_FALSE {
        fprintf(yyout, ";R103:\t<constante_logica> ::= false\n");

        $$.type = BOOL;
        $$.is_address = 0;
        escribir_operando(yyout, "0", 0);
    };

constante_entera:
    TOK_CONSTANTE_ENTERA {
        fprintf(yyout, ";R104:\t<constante_entera> ::= TOK_CONSTANTE_ENTERA\n");

        $$.type = INT;
        $$.is_address = 0;
        $$.value = $1.value;

        char buffer[MAX];
        sprintf(buffer, "%d", $$.value);
        escribir_operando(yyout, buffer, 0);
    };

identificador:
    TOK_IDENTIFICADOR {
        fprintf(yyout, ";R108:\t<identificador> ::= TOK_IDENTIFICADOR\n");
        if(search_table(&aux_symbol_table, $1.lexeme)){
            printf( "****Error semantico en linea %d: Declaracion duplicada.", n_lines);
            return -1;
        }
        if(func_flag_dec == 1){
            if(curr_class != SCALAR){
                printf("****Error semantico en lin %d: Variable local de tipo no escalar.\n", n_lines);
                return -1;
            }

            aux_symb = symbol_create($1.lexeme, VARIABLE, curr_type, SCALAR, -1, 1, -1, local_var_num, -1);
            insert_table(&aux_symbol_table, $1.lexeme, aux_symb);
            local_var_num++;
        }
        else
        {
            aux_symb = symbol_create($1.lexeme, VARIABLE, curr_type, curr_class, -1, curr_len, -1, -1, -1);
            insert_table(&aux_symbol_table, $1.lexeme, aux_symb);
            declarar_variable(yyout, $1.lexeme, curr_type, curr_len);
        }
        symbol_delete(aux_symb);
    };

idpf: 
    TOK_IDENTIFICADOR {
        fprintf(yyout, ";R108:\t<identificador> ::= TOK_IDENTIFICADOR\n");

        if(search_table(&aux_symbol_table, $1.lexeme)){
            printf( "****Error semantico en linea %d: Declaracion duplicada.", n_lines);
            return -1;
        }

        aux_symb = symbol_create($1.lexeme, PARAMETER, curr_type, SCALAR, -1, 1, -1, pos_params, -1);

        insert_table(&aux_symbol_table, $1.lexeme, aux_symb);
        symbol_delete(aux_symb);
    };

%%

void yyerror(const char *error){
    extern int yyleng;
    extern int is_morpho;
    extern int n_cols;
    extern int n_lines;
    if(!is_morpho){
        printf("****Error sintactico en [lin %d, col %d]\n", n_lines, n_cols-yyleng);
    }
}