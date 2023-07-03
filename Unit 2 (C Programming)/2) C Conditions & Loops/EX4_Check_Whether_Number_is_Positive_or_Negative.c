/*
 ============================================================================
 Name        : EX4.c
 Author      : Mostafa Mahmoud
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
EX4: C Program to Check Whether a Number is Positive or Negative

This program takes a number from user and checks whether that number is either positive or negative or zero.

Output 1
Enter a number: 12.3
12.30 is positive.

Output 2
Enter a number: 0
You entered zero.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	double num;
	printf("Enter a number: ");
	fflush(stdout);
	scanf("%lf",&num);

	if (num > 0.0)
		printf("%.2lf is positive.\n",num);
	else if (num == 0.0)
		printf("You entered zero.\n");
	else
		printf("%.2lf is negative.\n",num);


	return EXIT_SUCCESS;
}
