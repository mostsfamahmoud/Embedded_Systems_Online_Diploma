/*
 ============================================================================
 Name        : Q1.c
 Author      : Mostafa Mahmoud
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

unsigned int sumDigits(int num);
unsigned int DigitSum(int num);


/*
C function to take a number and sum all the digits
Test case 1:
Input -> 123
Output -> 6

Test case 2:
Input -> 4565
Output -> 20
*/

int main(void) {

	int num;

	/* Taking the number as input from user */
	printf("Enter an integer number: ");
	fflush(stdout);
	scanf("%d",&num);

	printf("Sum of all digits in %d = %d\n",num,sumDigits(num));
	//printf("Sum of all digits in %d = %d\n",num,DigitSum(num));

	return 0;
}

/* Iterative Version */
unsigned int sumDigits(int num)
{
	unsigned int sum = 0;

	/* Ignoring the negative sign as it's on the whole number not a specific digit */
	if (num < 0)
		num = abs(num);

	while(num != 0)
	{
		sum += num % 10;
		num /= 10;
	}
	return sum;
}

/* Recursive Version */
unsigned int DigitSum(int num)
{
	/* Ignoring the negative sign as it's on the whole number not a specific digit */
	if (num < 0)
		num = abs(num);

	/* Base case */
	if (num == 0)
		return 0;

	/* Recursive Step */
	return (num % 10) + DigitSum(num / 10);
}
