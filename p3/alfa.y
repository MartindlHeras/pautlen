%{
#include <stdio.h>
extern FILE* yyout;
extern int yylex(void);
void yyerror(const char * s);

%}

{
    int number;
    char* string;
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


/* Identificadores  */
%token <string> TOK_IDENTIFICADOR

/* Constantes */
%token <number> TOK_CONSTANTE_ENTERA
%token TOK_TRUE
%token TOK_FALSE


%left TOK_IGUAL TOK_DISTINTO TOK_MENORIGUAL TOK_MAYORIGUAL TOK_MENOR TOK_MAYOR
%left TOK_AND TOK_OR
%left TOK_MAS TOK_MENOS
%left TOK_DIVISION TOK_ASTERISCO
%right TOK_NOT

%%

// FALTAAAAA 