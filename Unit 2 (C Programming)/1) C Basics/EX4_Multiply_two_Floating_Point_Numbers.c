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
EX4:

Write C Program to Multiply two Floating Point Numbers
i should see the Console as following:
##########Console-output##############################
Enter two numbers: 2.4
1.1
Product: 2.640000
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
	float num1 , num2;
	double mul = 0;

	printf("Enter two numbers: ");
	fflush(stdout);
	scanf("%f %f",&num1,&num2);

	mul = num1 * num2;
	printf("Product: %lf\n",mul);

	return EXIT_SUCCESS;
}
