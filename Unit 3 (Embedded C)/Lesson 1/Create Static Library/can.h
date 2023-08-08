#ifndef CAN_H_
#define CAN_H_

#include <stdio.h>

/*
This declaration tells the compiler that there exists a function named CAN_Init() somewhere else in the codebase

The actual definition of the CAN_Init() function would be provided in another source file, and when the program is linked, 
the linker will ensure that the calls to CAN_Init() in your code are correctly connected to the actual implementation of the function.*/
extern void CAN_Init();

#endif 