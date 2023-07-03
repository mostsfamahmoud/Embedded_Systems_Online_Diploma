/*
 ============================================================================
 Name        : EX6.c
 Author      : Mostafa Mahmoud
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
EX6: C Program to Calculate Sum of Natural Numbers

Positive integers 1, 2, 3, 4... are known as natural numbers. This program takes a positive integer from user(suppose user entered n ) then,
this program displays the value of 1+2+3+....n.

Output
Enter an integer: 100
Sum	= 5050
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	unsigned int n;  // Last term
	unsigned long long sum = 0;

	printf("Enter an integer: ");
	fflush(stdout);
	scanf("%u",&n);

	for(unsigned int i = 1; i <= n; i++)
		sum += i;

	/* Another way (Using the sum of Natural numbers Formula)
	 * Starting from 1 to n then Sum = n(n + 1)/2

	sum = n*(n + 1)/2;
	*/

	printf("Sum = %llu\n",sum);

	return EXIT_SUCCESS;
}
