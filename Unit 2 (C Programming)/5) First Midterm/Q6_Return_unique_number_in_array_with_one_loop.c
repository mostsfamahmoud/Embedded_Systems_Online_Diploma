/*
 ============================================================================
 Name        : Q6.c
 Author      : Mostafa Mahmoud
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/* C Function to return unique number in array with one loop
 Test case 1:
 Input -> a[7] = {4,2,5,2,5,7,4}
 Output -> 7

 Test case 2:
 Input -> a[3] = {4,2,4}
 Output -> 2
*/

#include <stdio.h>
#include <stdlib.h>

int findUniqueNumber(int arr[], int size);

int main() {

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

	printf("\nThe Unique Number -> %d\n",findUniqueNumber(arr, size));

    return 0;
}

int findUniqueNumber(int arr[], int size)
{
	int uniqueNumber = arr[0]; /* Initially let the 1st element to be the unique */

	/* Making use of the XOR property
	 * As Equal (same) numbers are XORed Together -> The result of XOR is ZERO
	 * So the remainder of the operation -> Results in finding the Unique Number
	 * Example: arr -> {4,2,4}
	 * 4 ^ 2 = 3 then 3 ^ 4 = 2
	 */
	for(int i = 1; i < size ; i++)
		uniqueNumber ^= arr[i];

	return uniqueNumber;
}
