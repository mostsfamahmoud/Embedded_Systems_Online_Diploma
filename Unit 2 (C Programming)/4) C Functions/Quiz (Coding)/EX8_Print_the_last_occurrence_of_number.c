/*
 ============================================================================
 Name        : EX8.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

/* Write a C function to print the last occurrence of a number */
int FindLastOccurence(int arr[], int n, int key);

int main(void) {
	unsigned int size , i;
	int element;

	printf("Enter size of array : ");
	fflush(stdout);
	scanf("%u",&size);

	int arr[size];
	for(i = 0; i < size; i++)
	{
		printf("Enter Element %d: ",(i + 1));
		fflush(stdout);
		scanf("%d",&arr[i]);
	}

	printf("\nEnter the number you want to get its last occurrence: ");
	fflush(stdout);
	scanf("%d",&element);

	printf("Last occurrence is %d\n",FindLastOccurence(arr, size, element));

	return 0;
}

int FindLastOccurence(int arr[], int n, int key)
{
	for(int i = (n - 1); i >= 0; i--)
	{
		if (arr[i] == key)
			return (i + 1);    /* @ index 4 -> return Found at Element 5 */
	}

	return -1; /* In case -> No match */
}


