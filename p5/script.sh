echo ================    aritmeticas1.alf   ======================================
./alfa prueba/aritmeticas1.alf prueba/misalida.asm
nasm -g -o prueba/aritmeticas1.o -f elf32 prueba/misalida.asm
gcc -m32 -o prueba/aritmeticas1 prueba/aritmeticas1.o alfalib/alfalib.o

echo ================    aritmeticas1_1.input
./prueba/aritmeticas1 < prueba/aritmeticas1_1.input > prueba/misalida.output
diff -bB prueba/misalida.output prueba/aritmeticas1_1.output
echo ================    aritmeticas1_2.input
./prueba/aritmeticas1 < prueba/aritmeticas1_2.input > prueba/misalida.output
diff -bB prueba/misalida.output prueba/aritmeticas1_2.output
echo ================    aritmeticas1_3.input
./prueba/aritmeticas1 < prueba/aritmeticas1_3.input > prueba/misalida.output
diff -bB prueba/misalida.output prueba/aritmeticas1_3.output

echo ================    aritmeticas2.alf   ======================================
./alfa prueba/aritmeticas2.alf prueba/misalida.asm
nasm -g -o prueba/aritmeticas2.o -f elf32 prueba/misalida.asm
gcc -m32 -o prueba/aritmeticas2 prueba/aritmeticas2.o alfalib/alfalib.o

echo ================    aritmeticas2_1.input
./prueba/aritmeticas2 < prueba/aritmeticas2_1.input > prueba/misalida.output
diff -bB prueba/misalida.output prueba/aritmeticas2_1.output
echo ================    aritmeticas2_2.input
./prueba/aritmeticas2 < prueba/aritmeticas2_2.input > prueba/misalida.output
diff -bB prueba/misalida.output prueba/aritmeticas2_2.output
echo ================    aritmeticas2_3.input
./prueba/aritmeticas2 < prueba/aritmeticas2_3.input > prueba/misalida.output
diff -bB prueba/misalida.output prueba/aritmeticas2_3.output


echo ================    comparaciones.alf   ======================================
./alfa prueba/comparaciones.alf prueba/misalida.asm
nasm -g -o prueba/comparaciones.o -f elf32 prueba/misalida.asm
gcc -m32 -o prueba/comparaciones prueba/comparaciones.o alfalib/alfalib.o

./prueba/comparaciones > prueba/misalida.output
diff -bB prueba/misalida.output prueba/comparaciones.output


echo ================    error_ej1.alf   ======================================
./alfa prueba/error_ej1.alf prueba/misalida.asm
nasm -g -o prueba/error_ej1.o -f elf32 prueba/misalida.asm
gcc -m32 -o prueba/error_ej1 prueba/error_ej1.o alfalib/alfalib.o

./prueba/error_ej1

echo ================    error_ej2.alf   ======================================
./alfa prueba/error_ej2.alf prueba/misalida.asm
nasm -g -o prueba/error_ej2.o -f elf32 prueba/misalida.asm
gcc -m32 -o prueba/error_ej2 prueba/error_ej2.o alfalib/alfalib.o

./prueba/error_ej2

echo ================    error_se1.alf   ======================================
./alfa prueba/error_se1.alf prueba/misalida.asm
echo ================    error_se2.alf   ======================================
./alfa prueba/error_se2.alf prueba/misalida.asm
echo ================    error_se3.alf   ======================================
./alfa prueba/error_se3.alf prueba/misalida.asm
echo ================    error_se4.alf   ======================================
./alfa prueba/error_se4.alf prueba/misalida.asm
echo ================    error_se5.alf   ======================================
./alfa prueba/error_se5.alf prueba/misalida.asm
echo ================    error_se6.alf   ======================================
./alfa prueba/error_se6.alf prueba/misalida.asm
echo ================    error_se7.alf   ======================================
./alfa prueba/error_se7.alf prueba/misalida.asm
echo ================    error_se8.alf   ======================================
./alfa prueba/error_se8.alf prueba/misalida.asm
echo ================    error_se9.alf   ======================================
./alfa prueba/error_se9.alf prueba/misalida.asm
echo ================    error_se10.alf   ======================================
./alfa prueba/error_se10.alf prueba/misalida.asm
echo ================    error_se11.alf   ======================================
./alfa prueba/error_se11.alf prueba/misalida.asm
echo ================    error_se12.alf   ======================================
./alfa prueba/error_se12.alf prueba/misalida.asm
echo ================    error_se13.alf   ======================================
./alfa prueba/error_se13.alf prueba/misalida.asm
echo ================    error_se14.alf   ======================================
./alfa prueba/error_se14.alf prueba/misalida.asm
echo ================    error_se15.alf   ======================================
./alfa prueba/error_se15.alf prueba/misalida.asm


echo ================    funciones1.alf   ======================================
./alfa prueba/funciones1.alf prueba/misalida.asm
nasm -g -o prueba/funciones1.o -f elf32 prueba/misalida.asm
gcc -m32 -o prueba/funciones1 prueba/funciones1.o alfalib/alfalib.o

./prueba/funciones1 > prueba/misalida.output
diff -bB prueba/misalida.output prueba/funciones1.output

echo ================    funciones2.alf   ======================================
./alfa prueba/funciones2.alf prueba/misalida.asm
nasm -g -o prueba/funciones2.o -f elf32 prueba/misalida.asm
gcc -m32 -o prueba/funciones2 prueba/funciones2.o alfalib/alfalib.o

echo ================    funciones2_1.input
./prueba/funciones2 < prueba/funciones2_1.input > prueba/misalida.output
diff -bB prueba/misalida.output prueba/funciones2_1.output
echo ================    funciones2_2.input
./prueba/funciones2 < prueba/funciones2_2.input > prueba/misalida.output
diff -bB prueba/misalida.output prueba/funciones2_2.output
echo ================    funciones2_3.input
./prueba/funciones2 < prueba/funciones2_3.input > prueba/misalida.output
diff -bB prueba/misalida.output prueba/funciones2_3.output

echo ================    funciones3.alf   ======================================
./alfa prueba/funciones3.alf prueba/misalida.asm
nasm -g -o prueba/funciones3.o -f elf32 prueba/misalida.asm
gcc -m32 -o prueba/funciones3 prueba/funciones3.o alfalib/alfalib.o

./prueba/funciones3 > prueba/misalida.output
diff -bB prueba/misalida.output prueba/funciones3.output

echo ================    funciones4.alf   ======================================
./alfa prueba/funciones4.alf prueba/misalida.asm
nasm -g -o prueba/funciones4.o -f elf32 prueba/misalida.asm
gcc -m32 -o prueba/funciones4 prueba/funciones4.o alfalib/alfalib.o

./prueba/funciones4 > prueba/misalida.output
diff -bB prueba/misalida.output prueba/funciones4.output


echo ================    if1.alf   ======================================
./alfa prueba/if1.alf prueba/misalida.asm
nasm -g -o prueba/if1.o -f elf32 prueba/misalida.asm
gcc -m32 -o prueba/if1 prueba/if1.o alfalib/alfalib.o

./prueba/if1 > prueba/misalida.output
diff -bB prueba/misalida.output prueba/if1.output

echo ================    if2.alf   ======================================
./alfa prueba/if2.alf prueba/misalida.asm
nasm -g -o prueba/if2.o -f elf32 prueba/misalida.asm
gcc -m32 -o prueba/if2 prueba/if2.o alfalib/alfalib.o

./prueba/if2 > prueba/misalida.output
diff -bB prueba/misalida.output prueba/if2.output

echo ================    if3.alf   ======================================
./alfa prueba/if3.alf prueba/misalida.asm
nasm -g -o prueba/if3.o -f elf32 prueba/misalida.asm
gcc -m32 -o prueba/if3 prueba/if3.o alfalib/alfalib.o

echo ================    if3_1.input
./prueba/if3 < prueba/if3_1.input > prueba/misalida.output
diff -bB prueba/misalida.output prueba/if3_1.output
echo ================    if3_2.input
./prueba/if3 < prueba/if3_2.input > prueba/misalida.output
diff -bB prueba/misalida.output prueba/if3_2.output
echo ================    if3_3.input
./prueba/if3 < prueba/if3_3.input > prueba/misalida.output
diff -bB prueba/misalida.output prueba/if3_3.output
echo ================    if3_4.input
./prueba/if3 < prueba/if3_4.input > prueba/misalida.output
diff -bB prueba/misalida.output prueba/if3_4.output
echo ================    if3_5.input
./prueba/if3 < prueba/if3_5.input > prueba/misalida.output
diff -bB prueba/misalida.output prueba/if3_5.output


echo ================    logicas1.alf   ======================================
./alfa prueba/logicas1.alf prueba/misalida.asm
nasm -g -o prueba/logicas1.o -f elf32 prueba/misalida.asm
gcc -m32 -o prueba/logicas1 prueba/logicas1.o alfalib/alfalib.o

echo ================    logicas1_1.input
./prueba/logicas1 < prueba/logicas1_1.input > prueba/misalida.output
diff -bB prueba/misalida.output prueba/logicas1_1.output
echo ================    logicas1_2.input
./prueba/logicas1 < prueba/logicas1_2.input > prueba/misalida.output
diff -bB prueba/misalida.output prueba/logicas1_2.output
echo ================    logicas1_3.input
./prueba/logicas1 < prueba/logicas1_3.input > prueba/misalida.output
diff -bB prueba/misalida.output prueba/logicas1_3.output
echo ================    logicas1_4.input
./prueba/logicas1 < prueba/logicas1_4.input > prueba/misalida.output
diff -bB prueba/misalida.output prueba/logicas1_4.output

echo ================    logicas2.alf   ======================================
./alfa prueba/logicas2.alf prueba/misalida.asm
nasm -g -o prueba/logicas2.o -f elf32 prueba/misalida.asm
gcc -m32 -o prueba/logicas2 prueba/logicas2.o alfalib/alfalib.o

echo ================    logicas2_1.input
./prueba/logicas2 < prueba/logicas2_1.input > prueba/misalida.output
diff -bB prueba/misalida.output prueba/logicas2_1.output
echo ================    logicas2_2.input
./prueba/logicas2 < prueba/logicas2_2.input > prueba/misalida.output
diff -bB prueba/misalida.output prueba/logicas2_2.output
echo ================    logicas2_3.input
./prueba/logicas2 < prueba/logicas2_3.input > prueba/misalida.output
diff -bB prueba/misalida.output prueba/logicas2_3.output


echo ================    vectores1.alf   ======================================
./alfa prueba/vectores1.alf prueba/misalida.asm
nasm -g -o prueba/vectores1.o -f elf32 prueba/misalida.asm
gcc -m32 -o prueba/vectores1 prueba/vectores1.o alfalib/alfalib.o

./prueba/vectores1 > prueba/misalida.output
diff -bB prueba/misalida.output prueba/vectores1.output

echo ================    vectores2.alf   ======================================
./alfa prueba/vectores2.alf prueba/misalida.asm
nasm -g -o prueba/vectores2.o -f elf32 prueba/misalida.asm
gcc -m32 -o prueba/vectores2 prueba/vectores2.o alfalib/alfalib.o

./prueba/vectores2 > prueba/misalida.output
diff -bB prueba/misalida.output prueba/vectores2.output

echo ================    vectores3.alf   ======================================
./alfa prueba/vectores3.alf prueba/misalida.asm
nasm -g -o prueba/vectores3.o -f elf32 prueba/misalida.asm
gcc -m32 -o prueba/vectores3 prueba/vectores3.o alfalib/alfalib.o

./prueba/vectores3 > prueba/misalida.output
diff -bB prueba/misalida.output prueba/vectores3.output

echo ================    vectores4.alf   ======================================
./alfa prueba/vectores4.alf prueba/misalida.asm
nasm -g -o prueba/vectores4.o -f elf32 prueba/misalida.asm
gcc -m32 -o prueba/vectores4 prueba/vectores4.o alfalib/alfalib.o

./prueba/vectores4 > prueba/misalida.output
diff -bB prueba/misalida.output prueba/vectores4.output


echo ================    while.alf   ======================================
./alfa prueba/while.alf prueba/misalida.asm
nasm -g -o prueba/while.o -f elf32 prueba/misalida.asm
gcc -m32 -o prueba/while prueba/while.o alfalib/alfalib.o

echo ================    while_1.input
./prueba/while < prueba/while_1.input > prueba/misalida.output
diff -bB prueba/misalida.output prueba/while_1.output
echo ================    while_2.input
./prueba/while < prueba/while_2.input > prueba/misalida.output
diff -bB prueba/misalida.output prueba/while_2.output
echo ================    while_3.input
./prueba/while < prueba/while_3.input > prueba/misalida.output
diff -bB prueba/misalida.output prueba/while_3.output
