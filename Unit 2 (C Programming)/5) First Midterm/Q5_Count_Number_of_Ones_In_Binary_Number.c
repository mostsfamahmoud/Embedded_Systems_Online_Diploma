/*
 ============================================================================
 Name        : Q5.c
 Author      : Mostafa Mahmoud
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

unsigned char countOnesInBinary(int num);

/*
C Function to count number of ones in binary number
Test case 1:
Input -> 5
Output -> 2
Explanation: Binary of 5 (0101) So has 2 Ones

Test case 2:
Input -> 15
Output -> 4
*/

int main(void) {

	int num;

	/* Taking the number as input from user */
	printf("Enter an integer number: ");
	fflush(stdout);
	scanf("%d",&num);

	printf("Number of Ones in the given number = %u\n",countOnesInBinary(num));

	return 0;
}

unsigned char countOnesInBinary(int num)
{
	unsigned char count = 0;
	unsigned int mask = 0x80000000;

	for(unsigned char i = 0;i < 32; i++)
	{
		if (num & (mask >> i))
			count++;
	}

	return count;
}
