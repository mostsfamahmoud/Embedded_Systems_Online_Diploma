/*
 ============================================================================
 Name        : EX2.c
 Author      : Mostafa Mahmoud
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
EX2: C program to Calculate Factorial of a Number Using Recursion
Output
Enter an positive integer: 6
Factorial of 6 = 720

*/

#include <stdio.h>
#include <stdlib.h>

unsigned long long factorial(int num);

int main(void) {

	unsigned int num;
	printf("Enter an positive integer: ");
	fflush(stdout);
	scanf("%u",&num);

	unsigned long long result = factorial(num);

	printf("Factorial of %u = %llu\n",num,result);

	return 0;
}

unsigned long long factorial(int num)
{
	if (num <= 1)
		return 1;

	return num * factorial(num - 1);
}
