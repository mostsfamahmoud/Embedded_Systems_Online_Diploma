/*
 ============================================================================
 Name        : EX5_Array.c
 Author      : Mostafa Mahmoud
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
EX5: C Program to Search an element in Array
Output :
Enter no of elements : 5
11 22 33 44 55
Enter the elements to be searched : 44
Number found at the location = 4
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	unsigned int location = -1;      // Initialize Location as -1 (Element not found)

	unsigned int numOfElements, i;
	printf("Enter no of elements : ");
	fflush(stdout);
	scanf("%u",&numOfElements);

	int arr[numOfElements];

	for(i = 0;i < numOfElements; i++)
		scanf("%d",&arr[i]);

	int key;
	printf("\nEnter the elements to be searched : ");
	fflush(stdout);
	scanf("%d",&key);

	for(i = 0;i < numOfElements; i++)
	{
		if (arr[i] == key)
		{
			location = i + 1;
			printf("Number found at the location = %d", location);
			break;
		}
	}

	if (location == -1)
		printf("Element Not Found\n");

	return 0;
}
