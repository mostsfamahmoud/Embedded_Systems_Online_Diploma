/*
 ============================================================================
 Name        : Q2.c
 Author      : Mostafa Mahmoud
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
C Function to take an integer number and calculate its square root
Test case 1:
Input -> 4
Output -> 2.000

Test case 2:
Input -> 10
Output -> 3.126
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double getSquareRoot(int num);

int main(void) {

	int num;

	/* Taking the number as input from user */
	printf("Enter an Integer Number: ");
	fflush(stdout);
	scanf("%d",&num);

	printf("Square Root = %.3lf\n",getSquareRoot(num));

	return 0;
}

double getSquareRoot(int num)
{
	return sqrt(num);
}
