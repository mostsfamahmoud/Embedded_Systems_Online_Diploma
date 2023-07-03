/*
 ============================================================================
 Name        : EX7.c
 Author      : Mostafa Mahmoud
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
EX7: C Program to Find Factorial of a Number

For any positive number n, its factorial is given by: factorial = 1*2*3*4.....*n
If a number is negative, factorial does not exist and factorial of 0 is 1.

This program takes an integer from a user.
If user enters negative integer, this program will display error message and
If user enters non-negative integer, this program will display the factorial of that number.

Output 1
Enter an integer: -5
Error!!! Factorial of negative number doesn't exist.

Output 2
Enter an integer: 10
Factorial = 3628800
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n;
	unsigned long long fact = 1;

	printf("Enter an integer: ");
	fflush(stdout);
	scanf("%d",&n);

	if (n < 0)
		printf("Error!!! Factorial of negative number doesn't exist.");
	else
	{
		for(unsigned int i = 2; i <= n; i++)
		{
			fact *= i;
		}

		printf("Factorial = %llu\n",fact);

	}

	return EXIT_SUCCESS;
}
