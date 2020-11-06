/////////////////////////////////////////////////////////////////////////
// Santiago Valderrabano Zamorano santiago.valderrabano@estudiante.uam.es
// Martin de las Heras Moreno martin.delasheras@estudiante.uam.es
// Saul Almazan saul.almazan@estudiante.uam.es
// Grupo 140
/////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include "tokens.h"

#define ERR -1

extern int yylex(void);
extern size_t yyleng, n_cols, n_lines;
extern char* yytext;
extern FILE* yyin;

int main(int argc, char const *argv[]) {
  FILE* yyout;
  int aux;

  if (argc < 3) {
    fprintf(stdout, "Missing entry parameters: ./pruebaMorfo <input.txt> <output.txt>\n");
    return ERR;
  }

  if (!(yyin = fopen(argv[1], "r"))) {
    fprintf(stdout, "Error opening %s\n", argv[1]);
    return ERR;
  }

  if (!(yyout = fopen(argv[2], "w"))) {
    fprintf(stdout, "Error opening %s\n", argv[2]);
    return ERR;
  }

  while ((aux = yylex())) {
    printf("%d\n", aux);
    switch (aux) {
      case TOK_MAIN:
        fprintf(yyout, "TOK_MAIN\t%d\t%s\n", aux, yytext);
      break;
      case TOK_INT:
        fprintf(yyout, "TOK_INT\t%d\t%s\n", aux, yytext);
      break;
      case TOK_BOOLEAN:
        fprintf(yyout, "TOK_BOOLEAN\t%d\t%s\n", aux, yytext);
      break;
      case TOK_ARRAY:
        fprintf(yyout, "TOK_ARRAY\t%d\t%s\n", aux, yytext);
      break;
      case TOK_FUNCTION:
        fprintf(yyout, "TOK_FUNCTION\t%d\t%s\n", aux, yytext);
      break;
      case TOK_IF:
        fprintf(yyout, "TOK_IF\t%d\t%s\n", aux, yytext);
      break;
      case TOK_ELSE:
        fprintf(yyout, "TOK_ELSE\t%d\t%s\n", aux, yytext);
      break;
      case TOK_WHILE:
        fprintf(yyout, "TOK_WHILE\t%d\t%s\n", aux, yytext);
      break;
      case TOK_SCANF:
        fprintf(yyout, "TOK_SCANF\t%d\t%s\n", aux, yytext);
      break;
      case TOK_PRINTF:
        fprintf(yyout, "TOK_PRINTF\t%d\t%s\n", aux, yytext);
      break;
      case TOK_RETURN:
        fprintf(yyout, "TOK_RETURN\t%d\t%s\n", aux, yytext);
      break;
      case TOK_PUNTOYCOMA:
        fprintf(yyout, "TOK_PUNTOYCOMA\t%d\t%s\n", aux, yytext);
      break;
      case TOK_COMA:
        fprintf(yyout, "TOK_COMA\t%d\t%s\n", aux, yytext);
      break;
      case TOK_PARENTESISIZQUIERDO:
        fprintf(yyout, "TOK_PARENTESISIZQUIERDO\t%d\t%s\n", aux, yytext);
      break;
      case TOK_PARENTESISDERECHO:
        fprintf(yyout, "TOK_PARENTESISDERECHO\t%d\t%s\n", aux, yytext);
      break;
      case TOK_CORCHETEIZQUIERDO:
        fprintf(yyout, "TOK_CORCHETEIZQUIERDO\t%d\t%s\n", aux, yytext);
      break;
      case TOK_CORCHETEDERECHO:
        fprintf(yyout, "TOK_CORCHETEDERECHO\t%d\t%s\n", aux, yytext);
      break;
      case TOK_LLAVEIZQUIERDA:
        fprintf(yyout, "TOK_LLAVEIZQUIERDA\t%d\t%s\n", aux, yytext);
      break;
      case TOK_LLAVEDERECHA:
        fprintf(yyout, "TOK_LLAVEDERECHA\t%d\t%s\n", aux, yytext);
      break;
      case TOK_ASIGNACION:
        fprintf(yyout, "TOK_ASIGNACION\t%d\t%s\n", aux, yytext);
      break;
      case TOK_MAS:
        fprintf(yyout, "TOK_MAS\t%d\t%s\n", aux, yytext);
      break;
      case TOK_MENOS:
        fprintf(yyout, "TOK_MENOS\t%d\t%s\n", aux, yytext);
      break;
      case TOK_DIVISION:
        fprintf(yyout, "TOK_DIVISION\t%d\t%s\n", aux, yytext);
      break;
      case TOK_ASTERISCO:
        fprintf(yyout, "TOK_ASTERISCO\t%d\t%s\n", aux, yytext);
      break;
      case TOK_AND:
        fprintf(yyout, "TOK_AND\t%d\t%s\n", aux, yytext);
      break;
      case TOK_OR:
        fprintf(yyout, "TOK_OR\t%d\t%s\n", aux, yytext);
      break;
      case TOK_NOT:
        fprintf(yyout, "TOK_NOT\t%d\t%s\n", aux, yytext);
      break;
      case TOK_IGUAL:
        fprintf(yyout, "TOK_IGUAL\t%d\t%s\n", aux, yytext);
      break;
      case TOK_DISTINTO:
        fprintf(yyout, "TOK_DISTINTO\t%d\t%s\n", aux, yytext);
      break;
      case TOK_MENORIGUAL:
        fprintf(yyout, "TOK_MENORIGUAL\t%d\t%s\n", aux, yytext);
      break;
      case TOK_MAYORIGUAL:
        fprintf(yyout, "TOK_MAYORIGUAL\t%d\t%s\n", aux, yytext);
      break;
      case TOK_MENOR:
        fprintf(yyout, "TOK_MENOR\t%d\t%s\n", aux, yytext);
      break;
      case TOK_MAYOR:
        fprintf(yyout, "TOK_MAYOR\t%d\t%s\n", aux, yytext);
      break;
      case TOK_IDENTIFICADOR:
        fprintf(yyout, "TOK_IDENTIFICADOR\t%d\t%s\n", aux, yytext);
      break;
      case TOK_CONSTANTE_ENTERA:
        fprintf(yyout, "TOK_CONSTANTE_ENTERA\t%d\t%s\n", aux, yytext);
      break;
      case TOK_TRUE:
        fprintf(yyout, "TOK_TRUE\t%d\t%s\n", aux, yytext);
      break;
      case TOK_FALSE:
        fprintf(yyout, "TOK_FALSE\t%d\t%s\n", aux, yytext);
      break;
      case TOK_ERROR:
        fprintf(stderr, "ERROR %lu:%lu ID not allowed %s\n", n_lines, n_cols, yytext);
        fclose(yyin);
        fclose(yyout);
        exit(0);
      break;
      case TOK_ERRORID:
        fprintf(stderr, "ERROR %lu:%lu ID too long %s\n", n_lines, n_cols, yytext);
        fclose(yyin);
        fclose(yyout);
        exit(0);
      break;
      default:
        fprintf(stderr, "ERROR\n");
    }
  }
  fclose(yyin);
  fclose(yyout);
  return 0;
}
