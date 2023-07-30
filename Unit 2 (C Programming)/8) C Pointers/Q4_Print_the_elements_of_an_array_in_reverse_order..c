/*
 ============================================================================
 Name        : Q4.c
 Author      : Mostafa Mahmoud
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
Q4:
Write a program in C to print the elements of an array in reverse order.

Test Data :
Input the number of elements to store in the array (max 15) : 5
Input 5 number of elements in the array :
element - 1 : 2
element - 2 : 3
element - 3 : 4
element - 4 : 5
element - 5 : 6

Expected Output :
The elements of array in reverse order are :
element - 5 : 6
element - 4 : 5
element - 3 : 4
element - 2 : 3
element - 1 : 2
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE  15

int main(void) {

	int arr[MAX_SIZE];
	int size;

	printf("Enter the number of elements to store in the array (max 15) : ");
	fflush(stdout);
	scanf("%d",&size);

	if (size > 0)
	{
		/* ptr -> Pointer to int to point to the 1st integer in the array */
		int *ptr = arr;

		printf("\nEnter %d number of elements in the array :\n",size);
		fflush(stdout);
		for(unsigned int i = 0; i < size; i++)
		{
			printf("element - %d : ",(i + 1));
			fflush(stdout);
			scanf("%d", (ptr + i));
		}

		ptr = &arr[size - 1];

		printf("\nThe elements of array in reverse order are :\n");
		for(int i = (size - 1); i >= 0; i--)
		{
			printf("element - %d : %d\n",(i + 1),*ptr);
			ptr--;
		}
	}
	else
		printf("Invalid Size\n");


	return 0;
}
