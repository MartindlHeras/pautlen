%{
#include "tokens.h"
size_t n_cols = 1;
size_t n_lines = 1;

%}
%option noyywrap

%%
main { n_cols+= yyleng; return TOK_MAIN;}
int { n_cols+= yyleng; return TOK_INT;}
boolean { n_cols+= yyleng; return TOK_BOOLEAN;}
array { n_cols+= yyleng; return TOK_ARRAY;}
function { n_cols+= yyleng; return TOK_FUNCTION;}
if { n_cols+= yyleng; return TOK_IF;}
else { n_cols+= yyleng; return TOK_ELSE;}
while { n_cols+= yyleng; return TOK_WHILE;}
scanf { n_cols+= yyleng; return TOK_SCANF;}
printf { n_cols+= yyleng; return TOK_PRINTF;}
return { n_cols+= yyleng; return TOK_RETURN;}

";" { n_cols+= yyleng; return TOK_PUNTOYCOMA;}
"," { n_cols+= yyleng; return TOK_COMA;}
"(" { n_cols+= yyleng; return TOK_PARENTESISIZQUIERDO;}
")" { n_cols+= yyleng; return TOK_PARENTESISIZQUIERDO;}
"[" { n_cols+= yyleng; return TOK_CORCHETEIZQUIERDO;}
"]" { n_cols+= yyleng; return TOK_CORCHETEDERECHO;}
"{" { n_cols+= yyleng; return TOK_LLAVEIZQUIERDA;}
"}" { n_cols+= yyleng; return TOK_LLAVEDERECHA;}
"=" { n_cols+= yyleng; return TOK_ASIGNACION;}
"+" { n_cols+= yyleng; return TOK_MAS;}
"-" { n_cols+= yyleng; return TOK_MENOS;}
"/" { n_cols+= yyleng; return TOK_DIVISION;}
"*" { n_cols+= yyleng; return TOK_ASTERISCO;}
"&&" { n_cols+= yyleng; return TOK_AND;}
"||" { n_cols+= yyleng; return TOK_OR;}
"!" { n_cols+= yyleng; return TOK_NOT;}
"==" { n_cols+= yyleng; return TOK_IGUAL;}
"!=" { n_cols+= yyleng; return TOK_DISTINTO;}
"<=" { n_cols+= yyleng; return TOK_MENORIGUAL;}
">=" { n_cols+= yyleng; return TOK_MAYORIGUAL;}
"<" { n_cols+= yyleng; return TOK_MENOR;}
">" { n_cols+= yyleng; return TOK_MAYOR;}

[a-zA-Z]([0-9]|[a-zA-Z]){0,99} { n_cols+= yyleng; return TOK_IDENTIFICADOR;}

[0-9]+ { n_cols+= yyleng; return TOK_CONSTANTE_ENTERA;}
true { n_cols+= yyleng; return TOK_TRUE;}
false { n_cols+= yyleng; return TOK_FALSE;}

. { return TOK_ERROR;}



"\n" { n_cols=1;nlines++; }
"\t"+ { n_cols+= yyleng;}
" "+ { n_cols+= yyleng;}
"//".*{ n_cols+= yyleng;}
