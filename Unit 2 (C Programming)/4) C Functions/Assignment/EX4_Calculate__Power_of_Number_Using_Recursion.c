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
EX4: C program to Calculate the Power of a Number Using Recursion

Output
Enter base number: 3
Enter power number(positive integer): 3
3^3 = 27
*/

#include <stdio.h>
#include <stdlib.h>

long long calculatePower(int base,unsigned int power);

int main(void) {
	int baseNum;
	unsigned int powNum;

	printf("Enter base number: ");
	fflush(stdout);
	scanf("%d",&baseNum);

	printf("Enter power number(positive integer): ");
	fflush(stdout);
	scanf("%u",&powNum);

	long long result = calculatePower(baseNum, powNum);

	printf("%d^%u = %lld",baseNum,powNum,result);
	return 0;
}

long long calculatePower(int base,unsigned int power)
{
	if (power == 0)
		return 1;

	long long val = 0;
	if (power % 2 == 0)
	{
		val = calculatePower(base, power / 2);
		return val * val;
	}
	else
	{
		val = calculatePower(base, (power - 1) / 2);
		return base * val * val;
	}
}
