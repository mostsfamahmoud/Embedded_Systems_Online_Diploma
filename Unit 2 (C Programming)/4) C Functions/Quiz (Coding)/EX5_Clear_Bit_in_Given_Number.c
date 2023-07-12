/*
 ============================================================================
 Name        : EX5.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

/* Write a C function that clears a Bit in a Given Number */
int clearBit(int num, unsigned char pos);

int main(void) {

	int num;
	unsigned char bitPosition;

	printf("Input Number : ");
	fflush(stdout);
	scanf("%d",&num);

	printf("Bit Position : ");
	fflush(stdout);
	scanf("%hhu",&bitPosition);

	printf("Result = %d\n",clearBit(num,bitPosition));

	return 0;
}

int clearBit(int num, unsigned char pos)
{
	return num & ~(1 << pos);
}
