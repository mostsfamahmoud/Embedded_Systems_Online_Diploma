/*
 ============================================================================
 Name        : EX2.c
 Author      : Mostafa Mahmoud
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
EX2: C Program to Calculate Average Using Arrays
This program takes n number of element from user(where, n is specified by user),
stores data in an array and calculates the average of those numbers.
Output
Enter the numbers of data: 6
1.		Enter number:	45.3
2.		Enter number:	67.5
3.		Enter number:	-45.6
4.		Enter number:	20.34
5.		Enter number:	33
6.		Enter number:	45.6
Average = 27.69
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	unsigned int numOfElements;

	printf("Enter the numbers of data: ");
	fflush(stdout);
	scanf("%u",&numOfElements);

	float arr[numOfElements];
	unsigned int i ;

	for(i = 0; i < numOfElements; i++)
	{
		printf("%d. Enter number: ",(i + 1));
		fflush(stdout);
		scanf("%f",&arr[i]);
	}

	double avg = 0, sum = 0;

	for(i = 0; i < numOfElements; i++)
		sum += arr[i];

	avg = sum / numOfElements;

	printf("\nAverage = %.2lf\n",avg);

	return 0;
}
