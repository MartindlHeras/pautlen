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

void pop_operaciones(FILE* fpasm, int es_variable_1, int es_variable_2){
  fprintf(fpasm, "pop dword ebx\n");
  fprintf(fpasm, "pop dword eax\n");
  if (es_variable_2)fprintf(fpasm, "mov ebx, [ebx]\n");
  if (es_variable_1)fprintf(fpasm, "mov eax, [eax]\n");
}

void sumar(FILE* fpasm, int es_variable_1, int es_variable_2){
  pop_operaciones(fpasm, es_variable_1, es_variable_2);
  fprintf(fpasm, "add eax, ebx\n");
  fprintf(fpasm, "push dword eax\n");
}

void restar(FILE* fpasm, int es_variable_1, int es_variable_2){
  pop_operaciones(fpasm, es_variable_1, es_variable_2);
  fprintf(fpasm, "aub eax, ebx\n");
  fprintf(fpasm, "push dword eax\n");
}

void multiplicar(FILE* fpasm, int es_variable_1, int es_variable_2){
  pop_operaciones(fpasm, es_variable_1, es_variable_2);
  fprintf(fpasm, "imul eax, ebx\n");
  fprintf(fpasm, "push dword eax\n");

}

void dividir(FILE* fpasm, int es_variable_1, int es_variable_2){
  pop_operaciones(fpasm, es_variable_1, es_variable_2);
  fprintf(fpasm, "mov edx, 0\n");
  fprintf(fpasm, "cmp ebx, 0\n");
  fprintf(fpasm, "je div_zero_f\n"); // FLAG DE DIV_ZERO
  fprintf(fpasm, "idiv ebx\n");
  fprintf(fpasm, "push dword eax\n");
}

void o(FILE* fpasm, int es_variable_1, int es_variable_2){
  pop_operaciones(fpasm, es_variable_1, es_variable_2);
  fprintf(fpasm, "or eax, ebx\n");
  fprintf(fpasm, "push dword eax\n");
}

void y(FILE* fpasm, int es_variable_1, int es_variable_2){
  pop_operaciones(fpasm, es_variable_1, es_variable_2);
  fprintf(fpasm, "and eax, ebx\n");
  fprintf(fpasm, "push dword eax\n");
}

void cambiar_signo(FILE* fpasm, int es_variable){
  fprintf(fpasm, "pop dword ebx\n");
  if(es_variable) fprintf(fpasm, "mov ebx, [ebx]\n");
  fprintf(fpasm, "neg ebx\n");
  fprintf(fpasm, "push dword ebx\n");
}

void no(FILE* fpasm, int es_variable, int cuantos_no){
  fprintf(fpasm, "pop dword ebx\n");
  if(es_variable) fprintf(fpasm, "mov ebx, [ebx]\n");
  fprintf(fpasm, "cmp ebx, 0\n");
  fprintf(fpasm, "je true_%d\n", cuantos_no);
  fprintf(fpasm, "push dword 0\n");
  fprintf(fpasm, "jmp end_%d\n", cuantos_no);
  fprintf(fpasm, "true_%d:\n", cuantos_no);
  fprintf(fpasm, "push dword 1\n");
  fprintf(fpasm, "end_%d:\n", cuantos_no);
}

void igual(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){
  pop_operaciones(fpasm, es_variable_1, es_variable_2);
  fprintf(fpasm, "cmp eax, ebx\n");
  fprintf(fpasm, "je equal_%d\n", etiqueta);
  fprintf(fpasm, "push dword 0\n");
  fprintf(fpasm, "jmp equal_end_%d\n", etiqueta);
  fprintf(fpasm, "equal_%d\n", etiqueta);
  fprintf(fpasm, "push dword 1\n");
  fprintf(fpasm, "equal_end_%d\n", etiqueta);
}

void distinto(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){
  pop_operaciones(fpasm, es_variable_1, es_variable_2);
  fprintf(fpasm, "cmp eax, ebx\n");
  fprintf(fpasm, "jne nequal_%d\n", etiqueta);
  fprintf(fpasm, "push dword 0\n");
  fprintf(fpasm, "jmp nequal_end_%d\n", etiqueta);
  fprintf(fpasm, "nequal_%d\n", etiqueta);
  fprintf(fpasm, "push dword 1\n");
  fprintf(fpasm, "nequal_end_%d\n", etiqueta);
}

void menor_igual(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){
  pop_operaciones(fpasm, es_variable_1, es_variable_2);
  fprintf(fpasm, "cmp eax, ebx\n");
  fprintf(fpasm, "jle lessequal_%d\n", etiqueta);
  fprintf(fpasm, "push dword 0\n");
  fprintf(fpasm, "jmp lessequal_end_%d\n", etiqueta);
  fprintf(fpasm, "lessequal_%d\n", etiqueta);
  fprintf(fpasm, "push dword 1\n");
  fprintf(fpasm, "lessequal_end_%d\n", etiqueta);
}

void mayor_igual(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){
  pop_operaciones(fpasm, es_variable_1, es_variable_2);
  fprintf(fpasm, "cmp eax, ebx\n");
  fprintf(fpasm, "jge greatequal_%d\n", etiqueta);
  fprintf(fpasm, "push dword 0\n");
  fprintf(fpasm, "jmp greatequal_end_%d\n", etiqueta);
  fprintf(fpasm, "greatequal_%d\n", etiqueta);
  fprintf(fpasm, "push dword 1\n");
  fprintf(fpasm, "greatequal_end_%d\n", etiqueta);
}

void menor(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){
  pop_operaciones(fpasm, es_variable_1, es_variable_2);
  fprintf(fpasm, "cmp eax, ebx\n");
  fprintf(fpasm, "jl less_%d\n", etiqueta);
  fprintf(fpasm, "push dword 0\n");
  fprintf(fpasm, "jmp less_end_%d\n", etiqueta);
  fprintf(fpasm, "less_%d\n", etiqueta);
  fprintf(fpasm, "push dword 1\n");
  fprintf(fpasm, "less_end_%d\n", etiqueta);
}

void mayor(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){
  pop_operaciones(fpasm, es_variable_1, es_variable_2);
  fprintf(fpasm, "cmp eax, ebx\n");
  fprintf(fpasm, "jg great_%d\n", etiqueta);
  fprintf(fpasm, "push dword 0\n");
  fprintf(fpasm, "jmp great_end_%d\n", etiqueta);
  fprintf(fpasm, "great_%d\n", etiqueta);
  fprintf(fpasm, "push dword 1\n");
  fprintf(fpasm, "great_end_%d\n", etiqueta);
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
