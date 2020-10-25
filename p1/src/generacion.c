#include "generacion.h"

void escribir_cabecera_bss(FILE* fpasm){
  fprintf(fpasm, "segment .bss\n");
  fprintf(fpasm, "__esp resd 1\n");
}

void escribir_subseccion_data(FILE* fpasm){
  fprintf(fpasm, "segment .data\n");
  fprintf(fpasm, "out_of_range db \"Accessing a memory out of range\",10,0\n");
  fprintf(fpasm, "div_zero db \"Dividing by zero\",10,0\n");
}

void declarar_variable(FILE* fpasm, char * nombre, int tipo, int tamano){
  fprintf(fpasm, "_%s resd %d\n", nombre, tamano);
}

void escribir_segmento_codigo(FILE* fpasm){
  fprintf(fpasm, "segment .text\n");
  fprintf(fpasm, "global main\n");
  fprintf(fpasm, "extern print_int, scan_int, print_string, print_blank, ");
  fprintf(fpasm, "print_endofline, print_boolean, scan_boolean\n");
}

void escribir_inicio_main(FILE* fpasm){
  fprintf(fpasm, "main:\n");
  fprintf(fpasm, "mov [__esp], esp\n");
}

void escribir_fin(FILE* fpasm){
  fprintf(fpasm, "ret\n");
  fprintf(fpasm, "mov esp, [__esp]\n");
  fprintf(fpasm, "ret\n");
}

void escribir_operando(FILE* fpasm, char* nombre, int es_variable){
  if (es_variable == 0){
        fprintf(fpasm, "push dword %s\n", nombre);
    }else{
        fprintf(fpasm, "push dword _%s\n", nombre);
    }
}

void asignar(FILE* fpasm, char* nombre, int es_variable){
  if (es_variable == 0) {
        fprintf(fpasm, "pop dword [_%s] \n", nombre);
    }else{
        fprintf(fpasm, "pop dword ebx\n");
        fprintf(fpasm, "mov _%s, [ebx]\n", nombre);
    }
}

void sumar(FILE* fpasm, int es_variable_1, int es_variable_2){
  fprintf(fpasm, "mov eax, %d", es_variable1);
  fprintf(fpasm, "add eax, %d", es_variable2);
}

void restar(FILE* fpasm, int es_variable_1, int es_variable_2){
  fprintf(fpasm, "mov eax, %d", es_variable1);
  fprintf(fpasm, "sub eax, %d", es_variable2);
}

void multiplicar(FILE* fpasm, int es_variable_1, int es_variable_2){
  fprintf(fpasm, "mov eax, %d", es_variable1);
  fprintf(fpasm, "mov edx, %d", es_variable2);
  fprintf(fpasm, "mul edx");

}

void dividir(FILE* fpasm, int es_variable_1, int es_variable_2){


}

void o(FILE* fpasm, int es_variable_1, int es_variable_2){


}

void y(FILE* fpasm, int es_variable_1, int es_variable_2){


}

void cambiar_signo(FILE* fpasm, int es_variable){


}

void no(FILE* fpasm, int es_variable, int cuantos_no){

}

void igual(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){

}

void distinto(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){

}

void menor_igual(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){

}

void mayor_igual(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){

}

void menor(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){

}

void mayor(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){

}

void leer(FILE* fpasm, char* nombre, int tipo){

}

void escribir(FILE* fpasm, int es_variable, int tipo){

}


/* FUNCIONES DE CONTROL DEL FLUJO */
void ifthenelse_inicio(FILE * fpasm, int exp_es_variable, int etiqueta){

}

void ifthen_inicio(FILE * fpasm, int exp_es_variable, int etiqueta){

}

void ifthen_fin(FILE * fpasm, int etiqueta){

}

void ifthenelse_fin_then(FILE * fpasm, int etiqueta){

}

void ifthenelse_fin(FILE * fpasm, int etiqueta){

}


/* FUNCIONES BUCLES WHILE */
void while_inicio(FILE * fpasm, int etiqueta){

}

void while_exp_pila (FILE * fpasm, int exp_es_variable, int etiqueta){

}

void while_fin( FILE * fpasm, int etiqueta){

}

/* HASTA AQUI PARA EL LUNES */

/* FUNCIONES INDEXAR VECTORES */
void escribir_elemento_vector(FILE * fpasm,char * nombre_vector, int tam_max, int exp_es_direccion){

}


void declararFuncion(FILE * fd_asm, char * nombre_funcion, int num_var_loc){

}

void retornarFuncion(FILE * fd_asm, int es_variable){

}

void escribirParametro(FILE* fpasm, int pos_parametro, int num_total_parametros){

}

void escribirVariableLocal(FILE* fpasm, int posicion_variable_local){

}

void asignarDestinoEnPila(FILE* fpasm, int es_variable){

}

void operandoEnPilaAArgumento(FILE * fd_asm, int es_variable){

}

void llamarFuncion(FILE * fd_asm, char * nombre_funcion, int num_argumentos){

}

void limpiarPila(FILE * fd_asm, int num_argumentos){

}
