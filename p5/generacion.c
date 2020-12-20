/////////////////////////////////////////////////////////////////////////
// Santiago Valderrabano Zamorano santiago.valderrabano@estudiante.uam.es
// Martin de las Heras Moreno martin.delasheras@estudiante.uam.es
// Saul Almazan saul.almazan@estudiante.uam.es
// Grupo 140
/////////////////////////////////////////////////////////////////////////

#include "generacion.h"

void escribir_cabecera_bss(FILE* fpasm){
  fprintf(fpasm, "segment .bss\n");
  fprintf(fpasm, "__esp resd 1\n");
}

void escribir_subseccion_data(FILE* fpasm){
  fprintf(fpasm, "segment .data\n");
  fprintf(fpasm, "out_of_range db \"****Error de ejecucion: Indice fuera de rango.\",10,0\n");
  fprintf(fpasm, "div_zero db \"****Error de ejecucion: Division por cero.\",10,0\n");
}

void declarar_variable(FILE* fpasm, char * nombre, int tipo, int tamano){
  fprintf(fpasm, "_%s resd %d\n", nombre, tamano);
}

void escribir_segmento_codigo(FILE* fpasm){
  fprintf(fpasm, "segment .text\n");
  fprintf(fpasm, "global main\n");
  fprintf(fpasm, "extern print_int, scan_int, print_boolean, scan_boolean,");
  fprintf(fpasm, " print_string, print_blank, print_endofline\n");
}

void escribir_inicio_main(FILE* fpasm){
  fprintf(fpasm, "main:\n");
  fprintf(fpasm, "mov [__esp], esp\n");
}

void escribir_fin(FILE* fpasm){
  fprintf(fpasm, "flag_end:\n");
  fprintf(fpasm, "mov esp, [__esp]\n");
  fprintf(fpasm, "ret\n");

  fprintf(fpasm, "flag_div_zero:\n");
  fprintf(fpasm, "push dword div_zero\n");
  fprintf(fpasm, "call print_string\n");
  fprintf(fpasm, "add esp, 4\n");
  fprintf(fpasm, "jmp flag_end\n");

  fprintf(fpasm, "flag_out_of_range:\n");
  fprintf(fpasm, "push dword out_of_range\n");
  fprintf(fpasm, "call print_string\n");
  fprintf(fpasm, "add esp, 4\n");
  fprintf(fpasm, "jmp flag_end\n");
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
  fprintf(fpasm, "sub eax, ebx\n");
  fprintf(fpasm, "push dword eax\n");
}

void multiplicar(FILE* fpasm, int es_variable_1, int es_variable_2){
  pop_operaciones(fpasm, es_variable_1, es_variable_2);
  fprintf(fpasm, "imul eax, ebx\n");
  fprintf(fpasm, "push dword eax\n");

}

void dividir(FILE* fpasm, int es_variable_1, int es_variable_2){
  pop_operaciones(fpasm, es_variable_1, es_variable_2);
  fprintf(fpasm, "cdq\n");
  fprintf(fpasm, "cmp ebx, 0\n");
  fprintf(fpasm, "je flag_div_zero\n");
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

void igual(FILE* fpasm, int es_variable_1, int es_variable_2, int etiqueta){
  pop_operaciones(fpasm, es_variable_1, es_variable_2);
  fprintf(fpasm, "cmp eax, ebx\n");
  fprintf(fpasm, "je equal_%d\n", etiqueta);
  fprintf(fpasm, "push dword 0\n");
  fprintf(fpasm, "jmp equal_end_%d\n", etiqueta);
  fprintf(fpasm, "equal_%d:\n", etiqueta);
  fprintf(fpasm, "push dword 1\n");
  fprintf(fpasm, "equal_end_%d:\n", etiqueta);
}

void distinto(FILE* fpasm, int es_variable_1, int es_variable_2, int etiqueta){
  pop_operaciones(fpasm, es_variable_1, es_variable_2);
  fprintf(fpasm, "cmp eax, ebx\n");
  fprintf(fpasm, "jne nequal_%d\n", etiqueta);
  fprintf(fpasm, "push dword 0\n");
  fprintf(fpasm, "jmp nequal_end_%d\n", etiqueta);
  fprintf(fpasm, "nequal_%d:\n", etiqueta);
  fprintf(fpasm, "push dword 1\n");
  fprintf(fpasm, "nequal_end_%d:\n", etiqueta);
}

void menor_igual(FILE* fpasm, int es_variable_1, int es_variable_2, int etiqueta){
  pop_operaciones(fpasm, es_variable_1, es_variable_2);
  fprintf(fpasm, "cmp eax, ebx\n");
  fprintf(fpasm, "jle lessequal_%d\n", etiqueta);
  fprintf(fpasm, "push dword 0\n");
  fprintf(fpasm, "jmp lessequal_end_%d\n", etiqueta);
  fprintf(fpasm, "lessequal_%d:\n", etiqueta);
  fprintf(fpasm, "push dword 1\n");
  fprintf(fpasm, "lessequal_end_%d:\n", etiqueta);
}

void mayor_igual(FILE* fpasm, int es_variable_1, int es_variable_2, int etiqueta){
  pop_operaciones(fpasm, es_variable_1, es_variable_2);
  fprintf(fpasm, "cmp eax, ebx\n");
  fprintf(fpasm, "jge greatequal_%d\n", etiqueta);
  fprintf(fpasm, "push dword 0\n");
  fprintf(fpasm, "jmp greatequal_end_%d\n", etiqueta);
  fprintf(fpasm, "greatequal_%d:\n", etiqueta);
  fprintf(fpasm, "push dword 1\n");
  fprintf(fpasm, "greatequal_end_%d:\n", etiqueta);
}

void menor(FILE* fpasm, int es_variable_1, int es_variable_2, int etiqueta){
  pop_operaciones(fpasm, es_variable_1, es_variable_2);
  fprintf(fpasm, "cmp eax, ebx\n");
  fprintf(fpasm, "jl less_%d\n", etiqueta);
  fprintf(fpasm, "push dword 0\n");
  fprintf(fpasm, "jmp less_end_%d\n", etiqueta);
  fprintf(fpasm, "less_%d:\n", etiqueta);
  fprintf(fpasm, "push dword 1\n");
  fprintf(fpasm, "less_end_%d:\n", etiqueta);
}

void mayor(FILE* fpasm, int es_variable_1, int es_variable_2, int etiqueta){
  pop_operaciones(fpasm, es_variable_1, es_variable_2);
  fprintf(fpasm, "cmp eax, ebx\n");
  fprintf(fpasm, "jg great_%d\n", etiqueta);
  fprintf(fpasm, "push dword 0\n");
  fprintf(fpasm, "jmp great_end_%d\n", etiqueta);
  fprintf(fpasm, "great_%d:\n", etiqueta);
  fprintf(fpasm, "push dword 1\n");
  fprintf(fpasm, "great_end_%d:\n", etiqueta);
}

void leer(FILE* fpasm, char* nombre, int tipo){
  fprintf(fpasm, "push dword _%s\n", nombre);
  if(tipo == BOOLEANO){
    fprintf(fpasm, "call scan_boolean\n");
  }else if(tipo == ENTERO){
    fprintf(fpasm, "call scan_int\n");
  }
  fprintf(fpasm, "add esp, 4\n"); //Posible poner dword
}

void escribir(FILE* fpasm, int es_variable, int tipo){
  fprintf(fpasm, "pop dword eax\n");
  if (es_variable) fprintf(fpasm, "mov eax, [eax]\n");
  fprintf(fpasm, "push dword eax\n");
  if(tipo == BOOLEANO){
    fprintf(fpasm, "call print_boolean\n");
  }else if(tipo == ENTERO){
    fprintf(fpasm, "call print_int\n");
  }
  fprintf(fpasm, "add esp, 4\n");
  fprintf(fpasm, "call print_endofline\n");
}

/* FUNCIONES DE CONTROL DEL FLUJO */
void ifthenelse_inicio(FILE * fpasm, int exp_es_variable, int etiqueta){
  fprintf(fpasm, "pop dword eax\n");
  if (exp_es_variable) fprintf(fpasm, "mov eax, [eax]\n");
  fprintf(fpasm, "cmp eax, 0\n");
  fprintf(fpasm, "je ifthenelse_end_%d\n", etiqueta);
}

void ifthen_inicio(FILE * fpasm, int exp_es_variable, int etiqueta){
  fprintf(fpasm, "pop dword eax\n");
  if (exp_es_variable) fprintf(fpasm, "mov eax, [eax]\n");
  fprintf(fpasm, "cmp eax, 0\n");
  fprintf(fpasm, "je ifthen_end_%d\n", etiqueta);
}

void ifthen_fin(FILE * fpasm, int etiqueta){
  fprintf(fpasm, "ifthen_end_%d:\n", etiqueta);
}

void ifthenelse_fin_then(FILE * fpasm, int etiqueta){
  fprintf(fpasm, "jmp ifthen_end_%d\n", etiqueta);
  fprintf(fpasm, "ifthenelse_end_%d:\n", etiqueta);
}

void ifthenelse_fin(FILE * fpasm, int etiqueta){
  fprintf(fpasm, "ifthen_end_%d:\n", etiqueta);
}


/* FUNCIONES BUCLES WHILE */
void while_inicio(FILE * fpasm, int etiqueta){
  fprintf(fpasm, "while_%d:\n", etiqueta);
}

void while_exp_pila (FILE * fpasm, int exp_es_variable, int etiqueta){
  fprintf(fpasm, "pop dword eax\n");
  if (exp_es_variable) fprintf(fpasm, "mov eax, [eax]\n");
  fprintf(fpasm, "cmp eax, 0\n");
  fprintf(fpasm, "je while_end_%d\n", etiqueta);
}

void while_fin( FILE * fpasm, int etiqueta){
  fprintf(fpasm, "jmp while_%d\n", etiqueta);
  fprintf(fpasm, "while_end_%d:\n", etiqueta);
}

/* FUNCIONES INDEXAR VECTORES */
void escribir_elemento_vector(FILE * fpasm, char * nombre_vector, int tam_max, int exp_es_direccion){
  fprintf(fpasm, "pop dword eax\n");
  if (exp_es_direccion) fprintf(fpasm, "mov eax, [eax]\n");
  fprintf(fpasm, "cmp eax, 0\n");
  fprintf(fpasm, "jl flag_out_of_range\n");
  fprintf(fpasm, "cmp eax, %d-1\n", tam_max);
  fprintf(fpasm, "jg flag_out_of_range\n");
  fprintf(fpasm, "mov edx, _%s\n", nombre_vector);
  fprintf(fpasm, "lea eax, [edx + eax*4]\n");
  fprintf(fpasm, "push dword eax\n");
}

void declararFuncion(FILE * fd_asm, char * nombre_funcion, int num_var_loc){
  fprintf(fd_asm, "_%s:\n", nombre_funcion);
  fprintf(fd_asm, "push ebp\n");
  fprintf(fd_asm, "mov ebp, esp\n");
  fprintf(fd_asm, "sub esp, 4*%d\n", num_var_loc);
}

void retornarFuncion(FILE * fd_asm, int es_variable){
  fprintf(fd_asm, "pop dword eax\n");
  if (es_variable) fprintf(fd_asm, "mov eax, [eax]\n");
  fprintf(fd_asm, "mov esp, ebp\n");
  fprintf(fd_asm, "pop dword ebp\n");
  fprintf(fd_asm, "ret\n");
}

void escribirParametro(FILE* fpasm, int pos_parametro, int num_total_parametros){
  fprintf(fpasm, "lea eax, [ebp + 4*%d]\n", 1+num_total_parametros-pos_parametro);
  fprintf(fpasm, "push dword eax\n");
}

void escribirVariableLocal(FILE* fpasm, int posicion_variable_local){
  fprintf(fpasm, "lea eax, [ebp - 4*%d]\n", posicion_variable_local);
  fprintf(fpasm, "push dword eax\n");
}

void asignarDestinoEnPila(FILE* fpasm, int es_variable){
  fprintf(fpasm, "pop dword ebx\n");
  fprintf(fpasm, "pop dword eax\n");
  if (es_variable) fprintf(fpasm, "mov eax, [eax]\n");
  fprintf(fpasm, "mov dword [ebx], eax\n");
}

void operandoEnPilaAArgumento(FILE * fd_asm, int es_variable){
  if (es_variable) {
    fprintf(fd_asm, "pop dword eax\n");
    fprintf(fd_asm, "mov eax, [eax]\n");
    fprintf(fd_asm, "push dword eax\n");
  }
}

void llamarFuncion(FILE * fd_asm, char * nombre_funcion, int num_argumentos){
  fprintf(fd_asm, "call _%s\n", nombre_funcion);
  limpiarPila(fd_asm, num_argumentos);
  fprintf(fd_asm, "push dword eax\n");
}

void limpiarPila(FILE * fd_asm, int num_argumentos){
  fprintf(fd_asm, "add esp, 4*%d\n", num_argumentos);
}
