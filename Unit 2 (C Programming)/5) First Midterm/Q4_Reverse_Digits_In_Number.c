/*
 ============================================================================
 Name        : Q4.c
 Author      : Mostafa Mahmoud
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
C function to reverse digits in number
Test case 1:
Input -> 2457
Output -> 7542

Test case 2:
Input -> 1057
Output -> 7501
*/

#include <stdio.h>
#include <stdlib.h>

int reverseDigits(int num);

int main(void) {

	int num;

	/* Taking the number as input from user */
	printf("Enter an integer number: ");
	fflush(stdout);
	scanf("%d",&num);

	printf("Reversed number = %d\n",reverseDigits(num));

	return 0;
}

int reverseDigits(int num)
{
	int reversed = 0;

	while(num != 0)
	{
		reversed = reversed * 10;
		reversed += num % 10;
		num /= 10;
	}

	if (num < 0)
		reversed = reversed * -1;

	return reversed;
}
