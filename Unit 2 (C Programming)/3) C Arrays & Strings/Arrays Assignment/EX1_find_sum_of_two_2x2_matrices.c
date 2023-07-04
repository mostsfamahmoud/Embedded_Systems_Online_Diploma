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
EX1: Example of Multidimensional Array In C
Write a C program to find sum of two matrix of order 2*2 using multidimensional arrays where, elements of matrix are entered by user.

Output:
Enter the elements of 1st matrix
Enter all:	2;
Enter a12:	0.5;
Enter a21:	-1.1;
Enter a22:	2;
Enter the elements of 2nd matrix

Enter b11:	0.2;
Enter b12:	0;
Enter b21:	0.23;
Enter b22:	23;

Sum Of Matrix:
2.2	    0.5
-0.9	25.0

*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE  2

int main(void) {

	float m1[SIZE][SIZE] , m2[SIZE][SIZE];
	double sum = 0;
	unsigned char i = 0 , j = 0;

	printf("Enter the elements of 1st matrix:\n");
	for(i = 0; i < SIZE; ++i)
	{
		for(j = 0; j < SIZE; ++j)
		{
			printf("Enter a%d: ", (i + 1) * 10 + (j + 1));
			fflush(stdout);
			scanf("%f",&m1[i][j]);
		}
	}

	printf("\nEnter the elements of 2nd matrix:\n");
	for(i = 0; i < SIZE; ++i)
	{
		for(j = 0; j < SIZE; ++j)
		{
			printf("Enter b%d: ", (i + 1) * 10 + (j + 1));
			fflush(stdout);
			scanf("%f",&m2[i][j]);
		}
	}

	printf("\nSum Of Matrix:\n");
	for(i = 0; i < SIZE; ++i)
	{
		for(j = 0; j < SIZE; ++j)
		{
			sum = m1[i][j] + m2[i][j];
			printf("%.2f ",sum);
		}
		printf("\n");
	}

	return 0;
}
