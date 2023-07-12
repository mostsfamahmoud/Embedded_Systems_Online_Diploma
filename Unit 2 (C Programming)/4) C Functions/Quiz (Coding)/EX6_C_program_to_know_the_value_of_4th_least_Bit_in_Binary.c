/*
 ============================================================================
 Name        : EX6.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

/* Write a C program to know the value of the 4th least Bit in Binary */
void printBinary(int num);

unsigned char readBit(int num, unsigned char pos);


int main(void) {

	int num;
	unsigned char bitPosition = 3;

	printf("Enter an Integer in decimal number system : ");
	fflush(stdout);
	scanf("%d",&num);

	printBinary(num);

	printf("\n%hhu th least significant bit is %hhu\n",bitPosition + 1,readBit(num, bitPosition));

	return 0;
}

unsigned char readBit(int num, unsigned char pos){
	return num & (1 << pos);
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
}

