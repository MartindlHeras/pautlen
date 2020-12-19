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
extern size_t n_lines;
extern size_t n_cols;

extern symbol_table symbol_table;
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

int vector_size = 0;
int active_func = 0;
int func_body = 0;
int label = -1;
int main_declaration = 0;
int param_list = 0



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
        fprintf(yyout, ";escribir_fin\n");
        escribir_fin(yyout);
    };

escritura_cabecera: {
        fprintf(yyout, ";escribir_subseccion_data\n");
        escribir_subseccion_data(yyout);
        fprintf(yyout, ";escribir_cabecera_bss\n");
        escribir_cabecera_bss(yyout);
    };

escritura_codigo: {
        fprintf(yyout, ";escribir_segmento_codigo\n");
        escribir_segmento_codigo(yyout);
    };

escritura_main: {
        fprintf(yyout, ";escribir_inicio_main\n");
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
        if($4.int_value > MAX || $4.int_value <= 0){
            printf("****Error semantico en lin %lu: El tamanyo del vector <nombre_vector> excede los limites permitidos (1,64).\n", n_lines);
            return -1;
        }
        $$.int_value = $4.int_value;
        curr_len = $4.int_value;
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
        if(close_scope(&symbol_table) == -1) return -1;

        aux_symb = search_table(&symbol_table, $1.lexeme);
        if(!aux_symb) return -1;

        aux_symb = symbol_create($1.lexeme, FUNCTION, aux_symb->type, -1, -1, -1, num_params, -1, local_var_num);

        insert_table(&symbol_table, $1.lexeme, aux_symb);

        if(close_scope(&symbol_table) == -1) return -1;

        func_flag_dec = 0;

    };

funcion_declaracion: funcion_nombre TOK_PARENTESISIZQUIERDO parametros_funcion TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA declaraciones_funcion {
        strcpy($$.lexeme, $1.lexeme);
        $$.type = $1.type;

        fprintf(yyout, ";declararFuncion\n");

        declararFuncion(yyout, $1.lexeme, local_var_num);

        aux_symb = search_table(&symbol_table, $1.lexeme);

        if(!aux_symb) return -1;

        aux_symb = symbol_create($1.lexeme, FUNCTION, aux_symb->type, -1, -1, -1, num_params, -1, local_var_num);

        insert_table(&symbol_table, $1.lexeme, aux_symb);

    };

funcion_nombre: TOK_FUNCTION tipo TOK_IDENTIFICADOR {

        aux_symb = search_table(&symbol_table, $3.lexeme);

        if(!aux_symb){
            printf("****Error semantico en lin %d: Declaracion duplicada.\n", n_lines);
			return -1;
        }

        aux_symb = symbol_create($1.lexeme, FUNCTION, curr_type, -1, -1, -1, -1, -1, -1);

        insert_table(&symbol_table, $3.lexeme, aux_symb);

        num_params = 0;
        pos_params = 0;
        local_var_num = 1;
        local_var_pos = 1;
        func_flag_dec = 1;
        func_ret = 0;

        strcpy($$.lexeme, $3.lexeme);
        $$.type = curr_type;
    
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
    tipo identificador {
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
    identificador TOK_ASIGNACION exp {
        fprintf(yyout, ";R43:\t<asignacion> ::= <identificador> = <exp>\n");
    } |
    elemento_vector TOK_ASIGNACION exp {
        fprintf(yyout, ";R44:\t<asignacion> ::= <elemento_vector> = <exp>\n");
    };

elemento_vector:
    identificador TOK_CORCHETEIZQUIERDO exp TOK_CORCHETEDERECHO {
        fprintf(yyout, ";R48:\t<elemento_vector> ::= <identificador> [ <exp> ]\n");
    };

condicional:
    TOK_IF TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA sentencias TOK_LLAVEDERECHA {
        fprintf(yyout, ";R50:\t<condicional> ::= if ( <exp> ) { <sentencias> }\n");
    } |
    TOK_IF TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA sentencias TOK_LLAVEDERECHA TOK_ELSE TOK_LLAVEIZQUIERDA sentencias TOK_LLAVEDERECHA{
        fprintf(yyout, ";R51:\t<condicional> ::= if ( <exp> ) { <sentencias> } else { <sentencias> }\n");
    };

bucle:
    TOK_WHILE TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA sentencias TOK_LLAVEDERECHA{
        fprintf(yyout, ";R52:\t<bucle> ::= while ( <exp> ) { <sentencias> }\n");
    };

lectura:
    TOK_SCANF identificador {
        fprintf(yyout, ";R54:\t<lectura> ::= scanf <identificador>\n");
    };

escritura:
    TOK_PRINTF exp {
        fprintf(yyout, ";R56:\t<escritura> ::= printf <exp>\n");
    };

retorno_funcion:
    TOK_RETURN exp {
        fprintf(yyout, ";R61:\t<retorno_funcion> ::= return <exp>\n");
    };

exp:
    exp TOK_MAS exp {
        fprintf(yyout, ";R72:\t<exp> ::= <exp> + <exp>\n");
    } | 
    exp TOK_MENOS exp {
        fprintf(yyout, ";R73:\t<exp> ::= <exp> - <exp>\n");
    } | 
    exp TOK_DIVISION exp {
        fprintf(yyout, ";R74:\t<exp> ::= <exp> / <exp>\n");
    } | 
    exp TOK_ASTERISCO exp {
        fprintf(yyout, ";R75:\t<exp> ::= <exp> * <exp>\n");
    } | 
    TOK_MENOS exp {
        fprintf(yyout, ";R76:\t<exp> ::= - <exp>\n");
    } | 
    exp TOK_AND exp {
        fprintf(yyout, ";R77:\t<exp> ::= <exp> && <exp>\n");
    } | 
    exp TOK_OR exp {
        fprintf(yyout, ";R78:\t<exp> ::= <exp> || <exp>\n");
    } | 
    TOK_NOT exp {
        fprintf(yyout, ";R79:\t<exp> ::= ! <exp>\n");
    } |
    identificador {
        fprintf(yyout, ";R80:\t<exp> ::= <identificador>\n");
    } |
    constante {
        fprintf(yyout, ";R81:\t<exp> ::= <constante>\n");
    } |
    TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO {
        fprintf(yyout, ";R82:\t<exp> ::= ( <exp> )\n");
    } | 
    TOK_PARENTESISIZQUIERDO comparacion TOK_PARENTESISDERECHO {
        fprintf(yyout, ";R83:\t<exp> ::= ( <comparacion> )\n");
    } | 
    elemento_vector {
        fprintf(yyout, ";R85:\t<exp> ::= <elemento_vector>\n");
    } | 
    identificador TOK_PARENTESISIZQUIERDO lista_expresiones TOK_PARENTESISDERECHO {
        fprintf(yyout, ";R88:\t<exp> ::= <identificador> ( <lista_expresiones> )\n");
    };

lista_expresiones:
    exp resto_lista_expresiones {
        fprintf(yyout, ";R89:\t<lista_expresiones> ::= <exp> <resto_lista_expresiones>\n");
    } | 
    %empty {
        fprintf(yyout, ";R90:\t<lista_expresiones> ::=\n");
    };

resto_lista_expresiones:
    TOK_COMA exp resto_lista_expresiones {
        fprintf(yyout, ";R91:\t<resto_lista_expresiones> ::= , <exp> <resto_lista_expresiones>\n");
    } | 
    %empty {
        fprintf(yyout, ";R92:\t<resto_lista_expresiones> ::=\n");
    };

comparacion:
    exp TOK_IGUAL exp {
        fprintf(yyout, ";R93:\t<comparacion> ::= <exp> == <exp>\n");
    } | 
    exp TOK_DISTINTO exp {
        fprintf(yyout, ";R94:\t<comparacion> ::= <exp> != <exp>\n");
    } | 
    exp TOK_MENORIGUAL exp {
        fprintf(yyout, ";R95:\t<comparacion> ::= <exp> <= <exp>\n");
    } | 
    exp TOK_MAYORIGUAL exp {
        fprintf(yyout, ";R96:\t<comparacion> ::= <exp> >= <exp>\n");
    } |
    exp TOK_MENOR exp {
        fprintf(yyout, ";R97:\t<comparacion> ::= <exp> < <exp>\n");
    } | 
    exp TOK_MAYOR exp {
        fprintf(yyout, ";R98:\t<comparacion> ::= <exp> > <exp>\n");
    };

constante:
    constante_entera {
        fprintf(yyout, ";R100:\t<constante> ::= <constante_entera>\n");
    } | 
    constante_logica {
        fprintf(yyout, ";R101:\t<constante> ::= <constante_logica>\n");
    };

constante_logica:
    TOK_TRUE {
        fprintf(yyout, ";R102:\t<constante_logica> ::= true\n");
    } | 
    TOK_FALSE {
        fprintf(yyout, ";R103:\t<constante_logica> ::= false\n");
    };

constante_entera:
    TOK_CONSTANTE_ENTERA {
        fprintf(yyout, ";R104:\t<constante_entera> ::= TOK_CONSTANTE_ENTERA\n");
    };

identificador:
    TOK_IDENTIFICADOR {
        fprintf(yyout, ";R108:\t<identificador> ::= TOK_IDENTIFICADOR\n");
    };

%%

void yyerror(const char *error){
    extern int yyleng;
    extern int is_morpho;
    extern size_t n_cols;
    extern size_t n_lines;
    if(!is_morpho){
        printf("****Error sintactico en [lin %lu, col %lu]\n", n_lines, n_cols-yyleng);
    }
}