segment .text
extern print_int
global main
main:
push dword 515
call print_int
add esp, 4
ret
