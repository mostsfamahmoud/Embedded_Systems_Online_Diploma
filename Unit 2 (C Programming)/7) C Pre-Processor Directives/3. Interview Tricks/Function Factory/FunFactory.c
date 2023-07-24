/*
Try to make function factory and use it by Macro
Use one macro to create two Functions, one responsible on multiply input argument to 4 
and the other to multiply one input argument to 2.
* The first function name will be fun_quadruple(int x)
* The Second one will be fun_double (int x)
*/

#include <stdio.h>

#define FUNCTION(name,a) int fun_##name(int x) {return (a) * x;} 
#define PRINT(a,...)     printf(__VA_ARGS__,a);
#define OUTPUT(a)        printf(#a);

FUNCTION(double,2)
FUNCTION(quadruple,4)

#undef FUNCTION
#define FUNCTION  20

int main()
{
    PRINT(fun_quadruple(13),"Quadruple(13) = %d\n")
    PRINT(fun_double(10),"Double(10) = %d\n")
    PRINT(FUNCTION,"FUNCTION after undef and Redef: %d")

    OUTPUT(\nMOSTAFA_MAHMOUD)

    return 0;
}
