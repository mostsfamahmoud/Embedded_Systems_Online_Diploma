/*
 ============================================================================
 Name        : Q8.c
 Author      : Mostafa Mahmoud
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
C Function that takes an array and reverse its elements
Test Case 1:
Input -> a[5] = {1,2,3,4,5}
Output -> 5 4 3 2 1
 */

#include <stdio.h>
#include <stdlib.h>

void reverseArray(int arr[], int n);
void displayArray(int arr[], int n);

int main(void) {

	int size , i;

	printf("Enter the size of an array : ");
	fflush(stdout);
	scanf("%d",&size);

	if (size <= 0)
	{
		printf("SIZE of the array must be POSITIVE\n");
		return 0;
	}

	int arr[size];

	for(i = 0; i < size; i++)
	{
		printf("Enter Element %d: ",(i + 1));
		fflush(stdout);
		scanf("%d",&arr[i]);
	}

	/* Before Reversing */
	printf("The Original Array: ");
	displayArray(arr, size);

	/* After Reversing */
	reverseArray(arr, size);
	printf("The Reversed Array: ");
	displayArray(arr, size);

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

void displayArray(int arr[], int n)
{
	for(unsigned int i = 0; i < n;i++)
		printf("%d ",arr[i]);

	printf("\n");
}
