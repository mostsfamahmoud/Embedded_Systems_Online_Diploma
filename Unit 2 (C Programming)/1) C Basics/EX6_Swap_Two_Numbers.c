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
EX6:

Write Source Code to Swap Two Numbers

#########Console_output######
Enter value of a: 1.20
Enter value of b: 2.45

After swapping, value of a = 2.45
After swapping, value of b = 1.2
#############################
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	float a, b;

	printf("Enter value of a: ");
	fflush(stdout);
	scanf("%f",&a);
	printf("Enter value of b: ");
	fflush(stdout);
	scanf("%f",&b);

	/* Swapping using temp variable */
	float temp = a;
	a = b;
	b = temp;

	printf("\nAfter swapping, value of a = %.2f\n", a);
	printf("After swapping, value of b = %.2f", b);

	return EXIT_SUCCESS;
}
