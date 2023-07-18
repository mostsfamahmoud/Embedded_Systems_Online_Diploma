/*
 ============================================================================
 Name        : Q7.c
 Author      : Mostafa Mahmoud
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/* C function to sum numbers from 1 to 100 (Without Loop)*/

#include <stdio.h>
#include <stdlib.h>

unsigned long long calculateSum(unsigned int num1, unsigned int num2);

int main(void) {
	unsigned int t1, t2;

	printf("Enter the 1st term of the summation: ");
	fflush(stdout);
	scanf("%d",&t1);

	printf("Enter the 2nd term of the summation: ");
	fflush(stdout);
	scanf("%d",&t2);
	if (t2 >= t1)
		printf("\nThe sum of numbers from %u to %u is %llu\n",t1,t2,calculateSum(t1,t2));
	else
		printf("The 2nd term MUST be larger than the first\n");

	return 0;
}

/* num1 -> The First Term of the summation (Lower Bound)
 * num2 -> The Last Term of the summation (Upper Bound)
 */
unsigned long long calculateSum(unsigned int num1, unsigned int num2)
{
	/* Using the Natural Sum Formula
	 * The sum of Natural number for 1 to n is
	 * n(n + 1)/ 2 -> CountOfTerms * (First term + Last Term) / 2     */
	unsigned int countTerms = num2 - num1 + 1;
	unsigned int total = num2 + num1;

	return (unsigned long long)(countTerms * total / 2);
}
