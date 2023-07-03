/*
 ============================================================================
 Name        : EX7.c
 Author      : Mostafa Mahmoud
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
EX7:
it is an interview trick

Write Source Code to Swap Two Numbers without temp variable.
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

	/* Method 1 (By addition & Subtraction) */
	a = a + b;
	b = a - b;
	a = a - b;

	/* Method 2 (By XORing them)
	 * Valid Only for Integer Numbers
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	*/

	printf("\nAfter swapping, value of a = %.2f\n", a);
	printf("After swapping, value of b = %.2f", b);

	return EXIT_SUCCESS;
}
