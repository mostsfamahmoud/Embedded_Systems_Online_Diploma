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
Program to Find Transpose of a Matrix

Output
Enter rows and column of matrix: 2
3
Enter elements of matrix:
Enter elements all: 1
Enter elements a12: 2
Enter elements a13: 9
Enter elements a21: 0
Enter elements a22: 4
Enter elements a23: 7
Entered Matrix:
1 2 9
0 4 7
Transpose of Matrix:
1 0
2 4
9 7
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	
	unsigned int dim1, dim2;  // First and Second dimensions
	
	printf("Enter rows and column of matrix: ");
	fflush(stdout);
	scanf("%u %u",&dim1,&dim2);
	
	int matrix[dim1][dim2];     // Original Matrix
	int transpose[dim2][dim1];  // Transpose Matrix

	printf("\nEnter elements of matrix: \n");
	unsigned int i = 0 , j = 0;
	for(i = 0; i < dim1; ++i)
	{
		for(j = 0; j < dim2; ++j)
		{
			printf("Enter elements a%d: ", (i + 1) * 10 + (j + 1));
			fflush(stdout);
			scanf("%d",&matrix[i][j]);
		}
	}

	printf("\nEntered Matrix: \n");
	for(i = 0; i < dim1; ++i)
	{
		for(j = 0; j < dim2; ++j)
		{
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}
	
	for(i = 0; i < dim1; ++i)
	{
		for(j = 0; j < dim2; ++j)
		{
			transpose[j][i] = matrix[i][j];
		}
	}
	
	printf("\nTranspose of Matrix: \n");
	for(i = 0; i < dim2; ++i)
	{
		for(j = 0; j < dim1; ++j)
		{
			printf("%d ",transpose[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
