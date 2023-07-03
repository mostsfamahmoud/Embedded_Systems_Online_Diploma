/*
 ============================================================================
 Name        : EX3.c
 Author      : Mostafa Mahmoud
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
EX3:

Write C Program to Add Two Integers

i should see the Console as following:
##########Console-output###
Enter two integers: 12
11
Sum: 23
###########################
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num1 , num2;
	long int sum = 0;

	printf("Enter two integers: ");
	fflush(stdout);
	scanf("%d %d",&num1,&num2);

	sum = num1 + num2;
	printf("Sum: %ld\n",sum);

	return EXIT_SUCCESS;
}
