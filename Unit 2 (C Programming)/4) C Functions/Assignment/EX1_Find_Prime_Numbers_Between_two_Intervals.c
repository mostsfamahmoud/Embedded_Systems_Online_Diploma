/*
 ============================================================================
 Name        : EX1.c
 Author      : Mostafa Mahmoud
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
EX1: Prime Numbers Between two Intervals by Making User-defined Function
Output
Enter two numbers(intervals): 10
30
Prime numbers between 10 and 30 are: 11 13 17 19 23 29
*/

#include <stdio.h>
#include <stdlib.h>

void findPrimes(int num1,int num2);

int main(void) {

	unsigned int num1, num2;

	printf("Enter two numbers(intervals): ");
	fflush(stdout);
	scanf("%u %u",&num1,&num2);

	findPrimes(num1, num2);

	return 0;
}

void findPrimes(int num1,int num2)
{
	int count;
	/* To make sure that the first number is always the smallest */
	if (num1 > num2)
	{
		int temp = num1;
		num1 = num2;
		num2 = temp;
	}

	printf("Prime numbers between %d and %d are: ",num1,num2);

	for(int i = num1; i <= num2; i++)
	{
		count = 0; // To count number of factors that can divide the number
		for(int j = 2; j <= (i/2); j++)
		{
			if (i % j == 0)
				count++;
		}
		/* To have a prime number
		 * then count must be equal to zero
		 * as the inner loop starts from 0 to the half of each number in the interval
		 * and primes only have two factors: 1 and the number itself
		 * Also 0 and 1 are not primes
		 */
		if (count == 0 && i > 1)
			printf("%d ",i);
	}
}


