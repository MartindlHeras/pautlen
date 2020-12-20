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
;D:	,
;D:	b
;R108:	<identificador> ::= TOK_IDENTIFICADOR
_b resd 1
;D:	,
;D:	c
;R108:	<identificador> ::= TOK_IDENTIFICADOR
_c resd 1
;D:	;
;R18:	<identificadores> ::= <identificador>
;R19:	<identificadores> ::= <identificador> , <identificadores>
;R19:	<identificadores> ::= <identificador> , <identificadores>
;R4:	<declaracion> ::= <clase> <identificadores> ;
;D:	scanf
;R2:	<declaraciones> ::= <declaracion>
segment .text
global main
extern print_int, scan_int, print_boolean, scan_boolean, print_string, print_blank, print_endofline
;R21:	<funciones> ::=
main:
mov [__esp], esp
;D:	a
;R54:	<lectura> ::= scanf <identificador>
push dword _a
call scan_boolean
add esp, 4
;R35:	<sentencia_simple> ::= <lectura>
;D:	;
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	scanf
;D:	b
;R54:	<lectura> ::= scanf <identificador>
push dword _b
call scan_boolean
add esp, 4
;R35:	<sentencia_simple> ::= <lectura>
;D:	;
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	scanf
;D:	c
;R54:	<lectura> ::= scanf <identificador>
push dword _c
call scan_boolean
add esp, 4
;R35:	<sentencia_simple> ::= <lectura>
;D:	;
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	printf
;D:	a
;D:	||
;R80:	<exp> ::= <identificador>
push dword _a
;D:	b
;D:	&&
;R80:	<exp> ::= <identificador>
push dword _b
;R78:	<exp> ::= <exp> || <exp>
pop dword ebx
pop dword eax
mov ebx, [ebx]
mov eax, [eax]
or eax, ebx
push dword eax
;D:	c
;D:	;
;R80:	<exp> ::= <identificador>
push dword _c
;R77:	<exp> ::= <exp> && <exp>
pop dword ebx
pop dword eax
mov ebx, [ebx]
and eax, ebx
push dword eax
;R56:	<escritura> ::= printf <exp>
pop dword eax
push dword eax
call print_boolean
add esp, 4
call print_endofline
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	printf
;D:	(
;D:	a
;D:	||
;R80:	<exp> ::= <identificador>
push dword _a
;D:	b
;D:	)
;R80:	<exp> ::= <identificador>
push dword _b
;R78:	<exp> ::= <exp> || <exp>
pop dword ebx
pop dword eax
mov ebx, [ebx]
mov eax, [eax]
or eax, ebx
push dword eax
;R82:	<exp> ::= ( <exp> )
;D:	&&
;D:	c
;D:	;
;R80:	<exp> ::= <identificador>
push dword _c
;R77:	<exp> ::= <exp> && <exp>
pop dword ebx
pop dword eax
mov ebx, [ebx]
and eax, ebx
push dword eax
;R56:	<escritura> ::= printf <exp>
pop dword eax
push dword eax
call print_boolean
add esp, 4
call print_endofline
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	printf
;D:	!
;D:	a
;D:	&&
;R80:	<exp> ::= <identificador>
push dword _a
;R79:	<exp> ::= ! <exp>
pop dword ebx
mov ebx, [ebx]
cmp ebx, 0
je true_1
push dword 0
jmp end_1
true_1:
push dword 1
end_1:
;D:	b
;D:	&&
;R80:	<exp> ::= <identificador>
push dword _b
;R77:	<exp> ::= <exp> && <exp>
pop dword ebx
pop dword eax
mov ebx, [ebx]
and eax, ebx
push dword eax
;D:	!
;D:	c
;D:	;
;R80:	<exp> ::= <identificador>
push dword _c
;R79:	<exp> ::= ! <exp>
pop dword ebx
mov ebx, [ebx]
cmp ebx, 0
je true_1
push dword 0
jmp end_1
true_1:
push dword 1
end_1:
;R77:	<exp> ::= <exp> && <exp>
pop dword ebx
pop dword eax
and eax, ebx
push dword eax
;R56:	<escritura> ::= printf <exp>
pop dword eax
push dword eax
call print_boolean
add esp, 4
call print_endofline
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
;R31:	<sentencias> ::= <sentencia> <sentencias>
;R31:	<sentencias> ::= <sentencia> <sentencias>
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
