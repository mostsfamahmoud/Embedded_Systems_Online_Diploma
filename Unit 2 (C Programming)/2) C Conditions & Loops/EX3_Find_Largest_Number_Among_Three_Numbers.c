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
EX3:C Program to Find the Largest Number Among Three Numbers

In this program user is asked to enter three numbers and this program will find the largest number among three numbers entered by user.
This program can be solved in more than one way.

Output
Enter three numbers: 12.2 13.452
10.193
Largest number = 13.45
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	float a ,b ,c;

	printf("Enter three numbers: ");
	fflush(stdout);
	scanf("%f %f %f",&a,&b,&c);

	/* Assume that one of them is already the maximum and
	 * start comparing it with the others */
	float max = a;

	if (b > max)
		max = b;

	if (c > max)
		max = c;

	printf("Largest number = %.2f\n",max);

	return EXIT_SUCCESS;
}
