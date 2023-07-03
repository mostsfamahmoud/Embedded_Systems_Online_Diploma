/*
 ============================================================================
 Name        : EX8.c
 Author      : Mostafa Mahmoud
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
EX8: C Program to Make a Simple Calculator to Add, Subtract, Multiply or Divide Using switch...case

This program takes an arithmetic operator(+, -, * , /) and two operands from an user and
performs the operation on those two operands depending upon the operator entered by user.

Output
Enter operator either + or - or * or divide (/) : -
Enter two operands: 3.4
8.4
3.4 - 8.4 = -5.0

*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char operator;
	double num1, num2;

	printf("Enter operator either + or - or * or divide (/) : ");
	fflush(stdout);
	scanf("%c",&operator);

	printf("\nEnter two operands: ");
	fflush(stdout);
	scanf("%lf %lf",&num1, &num2);

	switch(operator)
	{
	case '+':
		printf("%.2lf + %.2lf = %.2lf\n",num1,num2,(num1 + num2));
		break;
	case '-':
		printf("%.2lf - %.2lf = %.2lf\n",num1,num2,(num1 - num2));
		break;
	case '*':
		printf("%.2lf * %.2lf = %.2lf\n",num1,num2,(num1 * num2));
		break;
	case '/':
		printf("%.2lf / %.2lf = %.2lf\n",num1,num2,(num1 / num2));
		break;
	default:
		printf("Unknown Operation\n");
		break;
	}

	return EXIT_SUCCESS;
}
