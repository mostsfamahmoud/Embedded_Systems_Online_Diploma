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
EX4: C Program to Insert an element in an Array
Output of the Program :
Enter no of elements : 5
1 2 3 4 5
Enter the element to be inserted : 6
Enter the location : 2
1 6 2 3 4 5
*/


#include <stdio.h>
#include <stdlib.h>

int main(void) {

	unsigned int numOfElements, i;
	printf("Enter no of elements : ");
	fflush(stdout);
	scanf("%u",&numOfElements);

	int arr[numOfElements + 1];

	for(i = 0;i < numOfElements; i++)
		scanf("%d",&arr[i]);

	int newValue;
	printf("\nEnter the element to be inserted : ");
	fflush(stdout);
	scanf("%d",&newValue);

	unsigned int location;
	printf("Enter the location : ");
	fflush(stdout);
	scanf("%u",&location);

	if (location >= 1 && location <= (numOfElements + 1))
	{
		for(unsigned int i = numOfElements; i != (location - 1) ; i--)
		{
			arr[i] = arr[i - 1];
		}

		arr[location - 1] = newValue;

		for(i = 0;i < (numOfElements + 1); i++)
			printf("%d ",arr[i]);
	}
	else
		printf("Invalid Location\n");


	return 0;
}
