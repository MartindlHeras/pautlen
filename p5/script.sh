# ARITMETICAS1
./alfa prueba/aritmeticas1.alf prueba/misalida.asm
nasm -g -o prueba/aritmeticas1.o -f elf32 prueba/misalida.asm
gcc -m32 -o prueba/aritmeticas1 prueba/aritmeticas1.o alfalib/alfalib.o

./prueba/aritmeticas1 < prueba/aritmeticas1_1.input > prueba/misalida.output
diff -bB prueba/misalida.output prueba/aritmeticas1_1.output
./prueba/aritmeticas1 < prueba/aritmeticas1_2.input > prueba/misalida.output
diff -bB prueba/misalida.output prueba/aritmeticas1_2.output
./prueba/aritmeticas1 < prueba/aritmeticas1_3.input > prueba/misalida.output
diff -bB prueba/misalida.output prueba/aritmeticas1_3.output

# ARITMETICAS2
./alfa prueba/aritmeticas2.alf prueba/misalida.asm
nasm -g -o prueba/aritmeticas2.o -f elf32 prueba/misalida.asm
gcc -m32 -o prueba/aritmeticas2 prueba/aritmeticas2.o alfalib/alfalib.o

./prueba/aritmeticas2 < prueba/aritmeticas2_1.input > prueba/misalida.output
diff -bB prueba/misalida.output prueba/aritmeticas2_1.output
./prueba/aritmeticas2 < prueba/aritmeticas2_2.input > prueba/misalida.output
diff -bB prueba/misalida.output prueba/aritmeticas2_2.output
./prueba/aritmeticas2 < prueba/aritmeticas2_3.input > prueba/misalida.output
diff -bB prueba/misalida.output prueba/aritmeticas2_3.output


# COMPARACIONES
./alfa prueba/comparaciones.alf prueba/misalida.asm
nasm -g -o prueba/comparaciones.o -f elf32 prueba/misalida.asm
gcc -m32 -o prueba/comparaciones prueba/comparaciones.o alfalib/alfalib.o

./prueba/comparaciones > prueba/misalida.output
diff -bB prueba/misalida.output prueba/comparaciones.output


# ERRORES NO SEMANTICOS
./alfa prueba/error_ej1.alf prueba/misalida.asm
nasm -g -o prueba/error_ej1.o -f elf32 prueba/misalida.asm
gcc -m32 -o prueba/error_ej1 prueba/error_ej1.o alfalib/alfalib.o

./prueba/error_ej1

./alfa prueba/error_ej2.alf prueba/misalida.asm
nasm -g -o prueba/error_ej2.o -f elf32 prueba/misalida.asm
gcc -m32 -o prueba/error_ej2 prueba/error_ej2.o alfalib/alfalib.o

./prueba/error_ej2

# ERRORES SEMANTICOS
./alfa prueba/error_se1.alf prueba/misalida.asm

./alfa prueba/error_se2.alf prueba/misalida.asm

./alfa prueba/error_se3.alf prueba/misalida.asm

./alfa prueba/error_se4.alf prueba/misalida.asm

./alfa prueba/error_se5.alf prueba/misalida.asm

./alfa prueba/error_se6.alf prueba/misalida.asm

./alfa prueba/error_se7.alf prueba/misalida.asm

./alfa prueba/error_se8.alf prueba/misalida.asm

./alfa prueba/error_se9.alf prueba/misalida.asm

./alfa prueba/error_se10.alf prueba/misalida.asm

./alfa prueba/error_se11.alf prueba/misalida.asm

./alfa prueba/error_se12.alf prueba/misalida.asm

./alfa prueba/error_se13.alf prueba/misalida.asm

./alfa prueba/error_se14.alf prueba/misalida.asm

./alfa prueba/error_se15.alf prueba/misalida.asm


# FUNCIONES1
./alfa prueba/funciones1.alf prueba/misalida.asm
nasm -g -o prueba/funciones1.o -f elf32 prueba/misalida.asm
gcc -m32 -o prueba/funciones1 prueba/funciones1.o alfalib/alfalib.o

./prueba/funciones1 > prueba/misalida.output
diff -bB prueba/misalida.output prueba/funciones1.output

# FUNCIONES2
./alfa prueba/funciones2.alf prueba/misalida.asm
nasm -g -o prueba/funciones2.o -f elf32 prueba/misalida.asm
gcc -m32 -o prueba/funciones2 prueba/funciones2.o alfalib/alfalib.o

./prueba/funciones2 < prueba/funciones2_1.input > prueba/misalida.output
diff -bB prueba/misalida.output prueba/funciones2_1.output
./prueba/funciones2 < prueba/funciones2_2.input > prueba/misalida.output
diff -bB prueba/misalida.output prueba/funciones2_2.output
./prueba/funciones2 < prueba/funciones2_3.input > prueba/misalida.output
diff -bB prueba/misalida.output prueba/funciones2_3.output

# FUNCIONES3
./alfa prueba/funciones3.alf prueba/misalida.asm
nasm -g -o prueba/funciones3.o -f elf32 prueba/misalida.asm
gcc -m32 -o prueba/funciones3 prueba/funciones3.o alfalib/alfalib.o

./prueba/funciones3 > prueba/misalida.output
diff -bB prueba/misalida.output prueba/funciones3.output

# FUNCIONES4
./alfa prueba/funciones4.alf prueba/misalida.asm
nasm -g -o prueba/funciones4.o -f elf32 prueba/misalida.asm
gcc -m32 -o prueba/funciones4 prueba/funciones4.o alfalib/alfalib.o

./prueba/funciones4 > prueba/misalida.output
diff -bB prueba/misalida.output prueba/funciones4.output


# IF1
./alfa prueba/if1.alf prueba/misalida.asm
nasm -g -o prueba/if1.o -f elf32 prueba/misalida.asm
gcc -m32 -o prueba/if1 prueba/if1.o alfalib/alfalib.o

./prueba/if1 > prueba/misalida.output
diff -bB prueba/misalida.output prueba/if1.output

# IF2
./alfa prueba/if2.alf prueba/misalida.asm
nasm -g -o prueba/if2.o -f elf32 prueba/misalida.asm
gcc -m32 -o prueba/if2 prueba/if2.o alfalib/alfalib.o

./prueba/if2 > prueba/misalida.output
diff -bB prueba/misalida.output prueba/if2.output

# IF3
./alfa prueba/if3.alf prueba/misalida.asm
nasm -g -o prueba/if3.o -f elf32 prueba/misalida.asm
gcc -m32 -o prueba/if3 prueba/if3.o alfalib/alfalib.o

./prueba/if3 < prueba/if3_1.input > prueba/misalida.output
diff -bB prueba/misalida.output prueba/if3_1.output
./prueba/if3 < prueba/if3_2.input > prueba/misalida.output
diff -bB prueba/misalida.output prueba/if3_2.output
./prueba/if3 < prueba/if3_3.input > prueba/misalida.output
diff -bB prueba/misalida.output prueba/if3_3.output
./prueba/if3 < prueba/if3_4.input > prueba/misalida.output
diff -bB prueba/misalida.output prueba/if3_4.output
./prueba/if3 < prueba/if3_5.input > prueba/misalida.output
diff -bB prueba/misalida.output prueba/if3_5.output


# LOGICAS1
./alfa prueba/logicas1.alf prueba/misalida.asm
nasm -g -o prueba/logicas1.o -f elf32 prueba/misalida.asm
gcc -m32 -o prueba/logicas1 prueba/logicas1.o alfalib/alfalib.o

./prueba/logicas1 < prueba/logicas1_1.input > prueba/misalida.output
diff -bB prueba/misalida.output prueba/logicas1_1.output
./prueba/logicas1 < prueba/logicas1_2.input > prueba/misalida.output
diff -bB prueba/misalida.output prueba/logicas1_2.output
./prueba/logicas1 < prueba/logicas1_3.input > prueba/misalida.output
diff -bB prueba/misalida.output prueba/logicas1_3.output
./prueba/logicas1 < prueba/logicas1_4.input > prueba/misalida.output
diff -bB prueba/misalida.output prueba/logicas1_4.output

# LOGICAS2
./alfa prueba/logicas2.alf prueba/misalida.asm
nasm -g -o prueba/logicas2.o -f elf32 prueba/misalida.asm
gcc -m32 -o prueba/logicas2 prueba/logicas2.o alfalib/alfalib.o

./prueba/logicas2 < prueba/logicas2_1.input > prueba/misalida.output
diff -bB prueba/misalida.output prueba/logicas2_1.output
./prueba/logicas2 < prueba/logicas2_2.input > prueba/misalida.output
diff -bB prueba/misalida.output prueba/logicas2_2.output
./prueba/logicas2 < prueba/logicas2_3.input > prueba/misalida.output
diff -bB prueba/misalida.output prueba/logicas2_3.output


# VECTORES1
./alfa prueba/vectores1.alf prueba/misalida.asm
nasm -g -o prueba/vectores1.o -f elf32 prueba/misalida.asm
gcc -m32 -o prueba/vectores1 prueba/vectores1.o alfalib/alfalib.o

./prueba/vectores1 > prueba/misalida.output
diff -bB prueba/misalida.output prueba/vectores1.output

# VECTORES2
./alfa prueba/vectores2.alf prueba/misalida.asm
nasm -g -o prueba/vectores2.o -f elf32 prueba/misalida.asm
gcc -m32 -o prueba/vectores2 prueba/vectores2.o alfalib/alfalib.o

./prueba/vectores2 > prueba/misalida.output
diff -bB prueba/misalida.output prueba/vectores2.output

# VECTORES3
./alfa prueba/vectores3.alf prueba/misalida.asm
nasm -g -o prueba/vectores3.o -f elf32 prueba/misalida.asm
gcc -m32 -o prueba/vectores3 prueba/vectores3.o alfalib/alfalib.o

./prueba/vectores3 > prueba/misalida.output
diff -bB prueba/misalida.output prueba/vectores3.output

# VECTORES4
./alfa prueba/vectores4.alf prueba/misalida.asm
nasm -g -o prueba/vectores4.o -f elf32 prueba/misalida.asm
gcc -m32 -o prueba/vectores4 prueba/vectores4.o alfalib/alfalib.o

./prueba/vectores4 > prueba/misalida.output
diff -bB prueba/misalida.output prueba/vectores4.output


# WHILE
./alfa prueba/while.alf prueba/misalida.asm
nasm -g -o prueba/while.o -f elf32 prueba/misalida.asm
gcc -m32 -o prueba/while prueba/while.o alfalib/alfalib.o

./prueba/while < prueba/while_1.input > prueba/misalida.output
diff -bB prueba/misalida.output prueba/while_1.output
./prueba/while < prueba/while_2.input > prueba/misalida.output
diff -bB prueba/misalida.output prueba/while_2.output
./prueba/while < prueba/while_3.input > prueba/misalida.output
diff -bB prueba/misalida.output prueba/while_3.output
