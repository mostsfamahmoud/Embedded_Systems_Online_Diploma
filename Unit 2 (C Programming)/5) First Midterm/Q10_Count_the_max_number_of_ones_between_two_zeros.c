/*
 ============================================================================
 Name        : Q10.c
 Author      : Mostafa Mahmoud
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

/*
C function to count the max number of ones between two zeros
Test case 1:
Input -> 14 (01110)
Output -> 3

Test case 2:
Input -> 110 (0110 1110)
Output -> 3
*/

void printBinary(int num);
unsigned char CountOnesBetweenTwoZeros(int num);

int main(void) {

	int num;

	printf("Enter an Integer in decimal number system : ");
	fflush(stdout);
	scanf("%d",&num);

	printBinary(num);

	printf("\nMax number of Ones between two Zeros in number %d :\n%u\n",num,CountOnesBetweenTwoZeros(num));

	return 0;
}

unsigned char CountOnesBetweenTwoZeros(int num)
{
	unsigned int mask = 0x80000000;
	unsigned char zeroFlag = 0;
	unsigned char maxCountOnes = 0, countOnes = 0;

	for(char i = 0; i < 32; i++)
	{
		if (num & (mask >> i))
		{
			if (zeroFlag)
				countOnes++;
		}
		else
		{
			if (zeroFlag == 0)
				zeroFlag = 1;

			if (countOnes > maxCountOnes)
				maxCountOnes = countOnes;

			countOnes = 0;
		}
	}
	return maxCountOnes;
}

void printBinary(int num)
{
	printf("%d in binary number system is : ",num);
	for(char i = 31; i >= 0; i--)
	{
		if (num & (1 << i))
			printf("1");
		else
			printf("0");
	}
	printf("\n");
}
