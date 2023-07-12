/*
 ============================================================================
 Name        : EX3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

/* Write a C Function that reverse an input array */
void reverseArray(int arr[], int n);

int main(void) {

	unsigned int size , i;

	printf("Please Enter the size of an array : ");
	fflush(stdout);
	scanf("%u",&size);

	int arr[size];

	for(i = 0; i < size; i++)
	{
		printf("Enter Element %d: ",(i + 1));
		fflush(stdout);
		scanf("%d",&arr[i]);
	}

	printf("Result of an Reverse array is: ");
	reverseArray(arr, size);

	for(i = 0; i < size; i++)
		printf("%d\t",arr[i]);

	return 0;
}

void reverseArray(int arr[], int n)
{
	for(int i = 0, j = (n - 1); i < j; i++, j--)
	{
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
}
