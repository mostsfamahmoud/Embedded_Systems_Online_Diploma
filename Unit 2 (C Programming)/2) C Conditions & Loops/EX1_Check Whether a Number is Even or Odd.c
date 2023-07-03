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
EX1: Write C Program to Check Whether a Number is Even or Odd

You should know those topics:
C Programming Operators
C Programming if, if..else and Nested if...else Statement

The program idea
Numbers perfectly divisible by 2 are known even numbers and numbers which are not divisible by 2 are called odd numbers. This program takes an integer from user and checks whether that number is even or odd and displays the result.

Output 1
Enter an integer you want to check: 25
25 is odd .

Output 2
Enter an integer you want to check: 12
12 is even.

*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int num;

	printf("Enter an integer you want to check: ");
	fflush(stdout);
	scanf("%d",&num);

	if (num % 2)
		printf("%d is odd",num);
	else
		printf("%d is even",num);

	/*
	 * Another way by using (bitwise AND)
	if (num & 0x01)
		printf("%d is odd",num);
	else
		printf("%d is even",num);

	*/

	return EXIT_SUCCESS;
}
