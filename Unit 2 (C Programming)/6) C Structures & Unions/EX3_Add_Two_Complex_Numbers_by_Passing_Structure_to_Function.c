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
EX3: C Program to Add Two Complex Numbers by Passing Structure to a Function

Output
For 1st complex number:
Enter real and imaginary respectively: 2.3 4.5
For 2nd complex number:
Enter real and imaginary respectively: 3.4 5
Sum=5.7+9.5i
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE   3

struct Complex
{
	float real;
	float imag;
};

typedef struct Complex Complex;
Complex AddComplex(Complex num1, Complex num2);

int main(void) {

	/* Using the 1st and 2nd structures as the two distances that are taken as input from user
	 * and the 3rd as the sum of the two distances
	 */
	Complex complexArr[SIZE];


	for(unsigned int i = 0; i < (SIZE - 1); i++)
	{
		if (i == 0)
			printf("For %s complex number:\n", "1st");
		else
			printf("For %s complex number:\n", "2nd");

		printf("Enter real and imaginary respectively: ");
		fflush(stdout);
		scanf("%f %f",&complexArr[i].real,&complexArr[i].imag);

		printf("\n");
	}

	complexArr[2] = AddComplex(complexArr[0], complexArr[1]);

	printf("Sum = %.2f + %.2f i\n",complexArr[2].real,complexArr[2].imag);
	return 0;
}

Complex AddComplex(Complex num1, Complex num2)
{
	Complex result;
	result.real = num1.real + num2.real;
	result.imag = num1.imag + num2.imag;

	return result;
}
