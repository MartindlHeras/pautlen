%{
#include "y.tab.h"
size_t n_cols = 1;
size_t n_lines = 1;
int is_morpho;

%}

%option noinput
%option nounput
%option noyywrap
%%
"\n" { n_cols=1; n_lines++;}
"\t"+ {n_cols+= yyleng;}
" "+ {n_cols+= yyleng;}
"//".* {n_cols+= yyleng;}
main { n_cols+= yyleng; fprintf(yyout, ";D:\t%s\n", yytext); return TOK_MAIN;}
int { n_cols+= yyleng; fprintf(yyout, ";D:\t%s\n", yytext); return TOK_INT;}
boolean { n_cols+= yyleng; fprintf(yyout, ";D:\t%s\n", yytext); return TOK_BOOLEAN;}
array { n_cols+= yyleng; fprintf(yyout, ";D:\t%s\n", yytext); return TOK_ARRAY;}
function { n_cols+= yyleng; fprintf(yyout, ";D:\t%s\n", yytext); return TOK_FUNCTION;}
if { n_cols+= yyleng; fprintf(yyout, ";D:\t%s\n", yytext); return TOK_IF;}
else { n_cols+= yyleng; fprintf(yyout, ";D:\t%s\n", yytext); return TOK_ELSE;}
while { n_cols+= yyleng; fprintf(yyout, ";D:\t%s\n", yytext); return TOK_WHILE;}
scanf { n_cols+= yyleng; fprintf(yyout, ";D:\t%s\n", yytext); return TOK_SCANF;}
printf { n_cols+= yyleng; fprintf(yyout, ";D:\t%s\n", yytext); return TOK_PRINTF;}
return { n_cols+= yyleng; fprintf(yyout, ";D:\t%s\n", yytext); return TOK_RETURN;}

";" { n_cols+= yyleng; fprintf(yyout, ";D:\t%s\n", yytext); return TOK_PUNTOYCOMA;}
"," { n_cols+= yyleng; fprintf(yyout, ";D:\t%s\n", yytext); return TOK_COMA;}
"(" { n_cols+= yyleng; fprintf(yyout, ";D:\t%s\n", yytext); return TOK_PARENTESISIZQUIERDO;}
")" { n_cols+= yyleng; fprintf(yyout, ";D:\t%s\n", yytext); return TOK_PARENTESISDERECHO;}
"[" { n_cols+= yyleng; fprintf(yyout, ";D:\t%s\n", yytext); return TOK_CORCHETEIZQUIERDO;}
"]" { n_cols+= yyleng; fprintf(yyout, ";D:\t%s\n", yytext); return TOK_CORCHETEDERECHO;}
"{" { n_cols+= yyleng; fprintf(yyout, ";D:\t%s\n", yytext); return TOK_LLAVEIZQUIERDA;}
"}" { n_cols+= yyleng; fprintf(yyout, ";D:\t%s\n", yytext); return TOK_LLAVEDERECHA;}
"=" { n_cols+= yyleng; fprintf(yyout, ";D:\t%s\n", yytext); return TOK_ASIGNACION;}
"+" { n_cols+= yyleng; fprintf(yyout, ";D:\t%s\n", yytext); return TOK_MAS;}
"-" { n_cols+= yyleng; fprintf(yyout, ";D:\t%s\n", yytext); return TOK_MENOS;}
"/" { n_cols+= yyleng; fprintf(yyout, ";D:\t%s\n", yytext); return TOK_DIVISION;}
"*" { n_cols+= yyleng; fprintf(yyout, ";D:\t%s\n", yytext); return TOK_ASTERISCO;}
"&&" { n_cols+= yyleng; fprintf(yyout, ";D:\t%s\n", yytext); return TOK_AND;}
"||" { n_cols+= yyleng; fprintf(yyout, ";D:\t%s\n", yytext); return TOK_OR;}
"!" { n_cols+= yyleng; fprintf(yyout, ";D:\t%s\n", yytext); return TOK_NOT;}
"==" { n_cols+= yyleng; fprintf(yyout, ";D:\t%s\n", yytext); return TOK_IGUAL;}
"!=" { n_cols+= yyleng; fprintf(yyout, ";D:\t%s\n", yytext); return TOK_DISTINTO;}
"<=" { n_cols+= yyleng; fprintf(yyout, ";D:\t%s\n", yytext); return TOK_MENORIGUAL;}
">=" { n_cols+= yyleng; fprintf(yyout, ";D:\t%s\n", yytext); return TOK_MAYORIGUAL;}
"<" { n_cols+= yyleng; fprintf(yyout, ";D:\t%s\n", yytext); return TOK_MENOR;}
">" { n_cols+= yyleng; fprintf(yyout, ";D:\t%s\n", yytext); return TOK_MAYOR;}

true { n_cols+= yyleng; fprintf(yyout, ";D:\t%s\n", yytext); return TOK_TRUE;}
false { n_cols+= yyleng; fprintf(yyout, ";D:\t%s\n", yytext); return TOK_FALSE;}

[0-9]+ { n_cols+= yyleng; fprintf(yyout, ";D:\t%s\n", yytext); return TOK_CONSTANTE_ENTERA;}

[a-zA-Z]([0-9]|[a-zA-Z]){0,99} { n_cols+= yyleng; fprintf(yyout, ";D:\t%s\n", yytext); return TOK_IDENTIFICADOR;}
[a-zA-Z]([0-9]|[a-zA-Z]){100,} { printf("****Error en [lin %lu, col %lu]: id demasiado largo\n", n_lines, n_cols); is_morpho=1; return -2;}



. {printf("****Error en [lin %lu, col %lu]: simbolo no permitido (%s)\n", n_lines, n_cols, yytext); n_cols++; is_morpho=1; return -1;}
%%
