/*
 ============================================================================
 Name        : EX2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

/* Write a C program for swapping 2 arrays with different lengths

 Arrays before swapping
 First array ->   1 2 3 4 5 6 7 8 9 10
 Second array ->  1 8 9 7 5

 Arrays After swapping
 First array ->  1 8 9 7 5
 Second array -> 1 2 3 4 5 6 7 8 9 10

 */

void inputArray(int arr[], int n);
void printArray(int arr[], int n);
void swapArrays(int a[], int b[]);


#define SIZE_1 10
#define SIZE_2 5

#define MAX_SIZE  100

int main(void)
{
	int a[MAX_SIZE] , b[MAX_SIZE];

	unsigned int firstArrSize, secondArrSize;

	/* Taking the first array as input from user */
	printf("Enter size of the first array (Max = 100): ");
	fflush(stdout);
	scanf("%u",&firstArrSize);

	printf("Enter First array: \n");
	fflush(stdout);
	inputArray(a, firstArrSize);

	/* Taking the first array as input from user */
	printf("Enter size of the second array (Max = 100): ");
	fflush(stdout);
	scanf("%u",&secondArrSize);

	printf("Enter second array: \n");
	fflush(stdout);
	inputArray(b, secondArrSize);

	/* Displaying both first and second arrays before swapping them */
	printf("Arrays before swapping: \nFirst array ->\t");
	printArray(a, firstArrSize);

	printf("\nSecond array ->\t");
	printArray(b, secondArrSize);

	/* SWAPPING Process */
	swapArrays(a, b);

	/* Displaying both first and second arrays after swapping them */
	printf("\nArrays After swapping: \nFirst array ->\t");
	printArray(a, secondArrSize);

	printf("\nSecond array ->\t");
	printArray(b, firstArrSize);

	return 0;
}

void inputArray(int arr[], int n)
{
	for(unsigned int i = 0; i < n; i++)
		scanf("%d",&arr[i]);
}

void printArray(int arr[], int n)
{
	for(unsigned int i = 0; i < n; i++)
		printf("%d ", arr[i]);
}

void swapArrays(int a[], int b[])
{
	int temp;
	for(unsigned int i = 0; i < MAX_SIZE; i++)
	{
		temp = a[i];
		a[i] = b[i];
		b[i] = temp;
	}
}
