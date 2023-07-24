#include <stdio.h>

#define height 100
#define PI 3.14
#define Letter 'A'
#define Letter_Seq "ABC"
#define BackSlash_Char '\\'

#define PRINT_1(...) printf(__VA_ARGS__)
#define PRINT_2(a,...) printf(__VA_ARGS__,a)

int main()
{
    printf("Value of height : %d\n",height);
    printf("Value of PI : %f\n",PI);
    printf("Value of Letter : %c\n",Letter);
    printf("Value of Letter_Seq : %s\n",Letter_Seq);
    printf("Value of BackSlash_Char : %c\n",BackSlash_Char);

    PRINT_1("Hello To Learn In Depth\n");

    int val = 15;
    PRINT_2(val,"val = %x\n");
    
    return 0;
}

/*************** C Compilation Process **************/
/* 
 * To Know all details about MingW GCC
 * Run this -> gcc --help
 * 
 * Note:  -o <file> -> Place the output into <file>.
 * 
 * To Generate the executable file (.exe) [Linker Job --> Links all Obj files into the .exe]
 * gcc .\macros.c -o macros.exe
 * 
 * To generate the PreCompiled file or PreProccessed (.i) file -> [Preprocessor Job]
 * gcc -E .\macros.c -o macros.i
 * where -E -> Preprocess only; do not compile, assemble or link.
 * 
 * To generate the assembly code or compiled file (.asm or .s) -> [Compiler Job]
 * gcc -S .\macros.c -o macros.asm
 * Where -S -> Compile only; do not assemble or link.
 * 
 * To generate the object code or machine code (.obj or .o) -> [Assembler Job]
 * gcc -c .\macros.c -o macros.o
 * Where -c -> Compile and assemble, but do not link.
 */