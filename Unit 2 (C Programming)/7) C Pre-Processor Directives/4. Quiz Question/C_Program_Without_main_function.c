#include <stdio.h>
#include <stdlib.h>

/*********** Using Macro that define the main *********/
#define MOSTAFA     main

int MOSTAFA()
{
    printf("Hello, world!\n");
    return 0;
}

/*********** Using Token pasting Operator (##) *********/
#define FUNC     m##a##i##n

int FUNC()
{
    printf("Hello, world!\n");
    return 0;
}
