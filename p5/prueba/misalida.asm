segment .data
out_of_range db "****Error de ejecucion: Indice fuera de rango.",10,0
div_zero db "****Error de ejecucion: Division por cero.",10,0
segment .bss
__esp resd 1
;D:	main
;D:	{
;D:	boolean
;R11:	<tipo> ::= boolean
;R9:	<clase_escalar> ::= <tipo>
;R5:	<clase> ::= <clase_escalar>
;D:	a
;R108:	<identificador> ::= TOK_IDENTIFICADOR
_a resd 1
;D:	;
;R18:	<identificadores> ::= <identificador>
;R4:	<declaracion> ::= <clase> <identificadores> ;
;D:	a
;R2:	<declaraciones> ::= <declaracion>
segment .text
global main
extern print_int, scan_int, print_boolean, scan_boolean, print_string, print_blank, print_endofline
;R21:	<funciones> ::=
main:
mov [__esp], esp
;D:	=
;D:	true
;R102:	<constante_logica> ::= true
push dword 1
;R101:	<constante> ::= <constante_logica>
;R81:	<exp> ::= <constante>
;D:	;
;R43:	<asignacion> ::= <identificador> = <exp>
pop dword [_a] 
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	if
;D:	(
;D:	a
;D:	)
;R80:	<exp> ::= <identificador>
push dword _a
;D:	{
pop dword eax
mov eax, [eax]
cmp eax, 0
je ifthen_end_0
;D:	printf
;D:	1
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
push dword 1
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	;
;R56:	<escritura> ::= printf <exp>
pop dword eax
push dword eax
call print_int
add esp, 4
call print_endofline
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
jmp ifthen_end_0
ifthenelse_end_0:
;D:	else
;D:	{
;D:	printf
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
push dword 0
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	;
;R56:	<escritura> ::= printf <exp>
pop dword eax
push dword eax
call print_int
add esp, 4
call print_endofline
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
;R51:	<condicional> ::= if ( <exp> ) { <sentencias> } else { <sentencias> }
ifthen_end_0:
;R40:	<bloque> ::= <condicional>
;R33:	<sentencia> ::= <bloque>
;D:	a
;D:	=
;D:	false
;R103:	<constante_logica> ::= false
push dword 0
;R101:	<constante> ::= <constante_logica>
;R81:	<exp> ::= <constante>
;D:	;
;R43:	<asignacion> ::= <identificador> = <exp>
pop dword [_a] 
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	if
;D:	(
;D:	a
;D:	)
;R80:	<exp> ::= <identificador>
push dword _a
;D:	{
pop dword eax
mov eax, [eax]
cmp eax, 0
je ifthen_end_1
;D:	printf
;D:	1
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
push dword 1
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	;
;R56:	<escritura> ::= printf <exp>
pop dword eax
push dword eax
call print_int
add esp, 4
call print_endofline
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
jmp ifthen_end_1
ifthenelse_end_1:
;D:	else
;D:	{
;D:	printf
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
push dword 0
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	;
;R56:	<escritura> ::= printf <exp>
pop dword eax
push dword eax
call print_int
add esp, 4
call print_endofline
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
;R51:	<condicional> ::= if ( <exp> ) { <sentencias> } else { <sentencias> }
ifthen_end_1:
;R40:	<bloque> ::= <condicional>
;R33:	<sentencia> ::= <bloque>
;D:	}
;R30:	<sentencias> ::= <sentencia>
;R31:	<sentencias> ::= <sentencia> <sentencias>
;R31:	<sentencias> ::= <sentencia> <sentencias>
;R31:	<sentencias> ::= <sentencia> <sentencias>
;R1:	<programa> ::= main { <declaraciones> <funciones> <sentencias> }
flag_end:
mov esp, [__esp]
ret
flag_div_zero:
push dword div_zero
call print_string
add esp, 4
jmp flag_end
flag_out_of_range:
push dword out_of_range
call print_string
add esp, 4
jmp flag_end
