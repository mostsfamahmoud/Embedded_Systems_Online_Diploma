/*
 ============================================================================
 Name        : EX7.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

/* Write a C program to check if a given number is power of 3 */
unsigned char isPowerOfThree(unsigned int num);

int main(void) {

	unsigned int num;
	printf("Enter a number: \n");
	fflush(stdout);
	scanf("%u",&num);

	printf("%d => %hhu\n",num,isPowerOfThree(num));
	return 0;
}

unsigned char isPowerOfThree(unsigned int num)
{
	if (num < 3)
		return 0;

	while(num % 3 == 0)
		num /= 3;

	return (num == 1);
}
