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
extern FILE* fin;

int main(int argc, char const *argv[]) {
  FILE* fout;
  int aux;

  if (argc < 3) {
    fprintf(stdout, "Missing entry parameters: ./pruebaMorfo <input.txt> <output.txt>\n");
    return ERR;
  }

  if (!(fin = fopen(argv[1], "r"))) {
    fprintf(stdout, "Error opening %s\n", argv[1]);
    return ERR;
  }

  if (!(fout = fopen(argv[2], "w"))) {
    fprintf(stdout, "Error opening %s\n", argv[2]);
    return ERR;
  }

  while ((aux = yylex())) {
    switch (aux) {
      case TOK_MAIN:
        fprintf(fout, "TOK_MAIN\t%d\t%s\n", aux, yytext);
      break;
      case TOK_INT:
        fprintf(fout, "TOK_INT\t%d\t%s\n", aux, yytext);
      break;
      case TOK_BOOLEAN:
        fprintf(fout, "TOK_BOOLEAN\t%d\t%s\n", aux, yytext);
      break;
      case TOK_ARRAY:
        fprintf(fout, "TOK_ARRAY\t%d\t%s\n", aux, yytext);
      break;
      case TOK_FUNCTION:
        fprintf(fout, "TOK_FUNCTION\t%d\t%s\n", aux, yytext);
      break;
      case TOK_IF:
        fprintf(fout, "TOK_IF\t%d\t%s\n", aux, yytext);
      break;
      case TOK_ELSE:
        fprintf(fout, "TOK_ELSE\t%d\t%s\n", aux, yytext);
      break;
      case TOK_WHILE:
        fprintf(fout, "TOK_WHILE\t%d\t%s\n", aux, yytext);
      break;
      case TOK_SCANF:
        fprintf(fout, "TOK_SCANF\t%d\t%s\n", aux, yytext);
      break;
      case TOK_PRINTF:
        fprintf(fout, "TOK_PRINTF\t%d\t%s\n", aux, yytext);
      break;
      case TOK_RETURN:
        fprintf(fout, "TOK_RETURN\t%d\t%s\n", aux, yytext);
      break;
      case TOK_PUNTOYCOMA:
        fprintf(fout, "TOK_PUNTOYCOMA\t%d\t%s\n", aux, yytext);
      break;
      case TOK_COMA:
        fprintf(fout, "TOK_COMA\t%d\t%s\n", aux, yytext);
      break;
      case TOK_PARENTESISIZQUIERDO:
        fprintf(fout, "TOK_PARENTESISIZQUIERDO\t%d\t%s\n", aux, yytext);
      break;
      case TOK_PARENTESISDERECHO:
        fprintf(fout, "TOK_PARENTESISDERECHO\t%d\t%s\n", aux, yytext);
      break;
      case TOK_CORCHETEIZQUIERDO:
        fprintf(fout, "TOK_CORCHETEIZQUIERDO\t%d\t%s\n", aux, yytext);
      break;
      case TOK_CORCHETEDERECHO:
        fprintf(fout, "TOK_CORCHETEDERECHO\t%d\t%s\n", aux, yytext);
      break;
      case TOK_LLAVEIZQUIERDA:
        fprintf(fout, "TOK_LLAVEIZQUIERDA\t%d\t%s\n", aux, yytext);
      break;
      case TOK_LLAVEDERECHA:
        fprintf(fout, "TOK_LLAVEDERECHA\t%d\t%s\n", aux, yytext);
      break;
      case TOK_ASIGNACION:
        fprintf(fout, "TOK_ASIGNACION\t%d\t%s\n", aux, yytext);
      break;
      case TOK_MAS:
        fprintf(fout, "TOK_MAS\t%d\t%s\n", aux, yytext);
      break;
      case TOK_MENOS:
        fprintf(fout, "TOK_MENOS\t%d\t%s\n", aux, yytext);
      break;
      case TOK_DIVISION:
        fprintf(fout, "TOK_DIVISION\t%d\t%s\n", aux, yytext);
      break;
      case TOK_ASTERISCO:
        fprintf(fout, "TOK_ASTERISCO\t%d\t%s\n", aux, yytext);
      break;
      case TOK_AND:
        fprintf(fout, "TOK_AND\t%d\t%s\n", aux, yytext);
      break;
      case TOK_OR:
        fprintf(fout, "TOK_OR\t%d\t%s\n", aux, yytext);
      break;
      case TOK_NOT:
        fprintf(fout, "TOK_NOT\t%d\t%s\n", aux, yytext);
      break;
      case TOK_IGUAL:
        fprintf(fout, "TOK_IGUAL\t%d\t%s\n", aux, yytext);
      break;
      case TOK_DISTINTO:
        fprintf(fout, "TOK_DISTINTO\t%d\t%s\n", aux, yytext);
      break;
      case TOK_MENORIGUAL:
        fprintf(fout, "TOK_MENORIGUAL\t%d\t%s\n", aux, yytext);
      break;
      case TOK_MAYORIGUAL:
        fprintf(fout, "TOK_MAYORIGUAL\t%d\t%s\n", aux, yytext);
      break;
      case TOK_MENOR:
        fprintf(fout, "TOK_MENOR\t%d\t%s\n", aux, yytext);
      break;
      case TOK_MAYOR:
        fprintf(fout, "TOK_MAYOR\t%d\t%s\n", aux, yytext);
      break;
      case TOK_IDENTIFICADOR:
        fprintf(fout, "TOK_IDENTIFICADOR\t%d\t%s\n", aux, yytext);
      break;
      case TOK_CONSTANTE_ENTERA:
        fprintf(fout, "TOK_CONSTANTE_ENTERA\t%d\t%s\n", aux, yytext);
      break;
      case TOK_TRUE:
        fprintf(fout, "TOK_TRUE\t%d\t%s\n", aux, yytext);
      break;
      case TOK_FALSE:
        fprintf(fout, "TOK_FALSE\t%d\t%s\n", aux, yytext);
      break;
      case TOK_ERROR:
        fprintf(stderr, "ERROR %lu:%lu ID too long %s\n", n_lines, n_cols, yytext);
        fclose(fin);
        fclose(fout);
        exit(0);
      break;
      default:
        fprintf(stderr, "ERROR\n");
    }
  }
  fclose(fin);
  fclose(fout);
  return 0;
}
