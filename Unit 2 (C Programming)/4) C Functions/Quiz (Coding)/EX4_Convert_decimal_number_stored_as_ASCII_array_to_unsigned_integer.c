/*
 ============================================================================
 Name        : EX4.c
 Author      : Mostafa Mahmoud
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE   100

/*********************************************
 ************ Functions Declarations **********
 *********************************************/
unsigned int charArrayToUnsignedInt(char arr[], unsigned int size);
unsigned int stringToUnsignedInt(char* str);
unsigned int charToUnsignedInt(char ch);
void inputArray(char arr[], int n);

/* Convert a decimal number stored as ASCII array to an unsigned integer */

int main(void) {

	/* ASCII array with max size = 100 */
	char arr[MAX_SIZE];
	unsigned int size;

	unsigned char choice;
	printf("Note: Any ASCII array is either array of characters or a string\n");
	printf("Enter (1) for array of characters\nEnter (2) for a string\n");
	fflush(stdout);
	scanf("%c",&choice);
	fflush(stdin); /* Fixing a problem in eclipse */

	switch(choice)
	{
	case '1':
		printf("Enter size of the array of characters (max %d): ",MAX_SIZE);
		fflush(stdout);
		scanf("%u",&size);

		/* Taking the array from user */
		printf("Enter an array of characters: ");
		fflush(stdout);
		inputArray(arr, size);

		printf("The Corresponding Integer = %u\n",charArrayToUnsignedInt(arr, size));
		break;
	case '2':
		printf("Enter a string: ");
		fflush(stdout);
		gets(arr);

		printf("The Corresponding Integer = %u\n",stringToUnsignedInt(arr));
		break;
	default:
		printf("Invalid Input\n");
		break;
	}

	return 0;
}

/*********************************************
 ************ Functions Definitions **********
 *********************************************/
unsigned int charArrayToUnsignedInt(char arr[], unsigned int size)
{
	unsigned int total = 0, num;

	for(unsigned int i = 0; i < size; i++)
	{
		total *= 10;                       /* Move the integer number (total) one digit to the left */
		num = charToUnsignedInt(arr[i]);   /* Convert each character to the corresponding integer */
		total += num;                      /* add it to the total number */
	}

	return total;
}

unsigned int stringToUnsignedInt(char* str)
{
	unsigned int total = 0, num;

	for(unsigned int i = 0; str[i] != '\0'; i++)
	{
		total *= 10;                       /* Move the integer number (total) one digit to the left */
		num = charToUnsignedInt(str[i]);   /* Convert each character to the corresponding integer */
		total += num;                      /* add it to the total number */
	}

	return total;
}

unsigned int charToUnsignedInt(char ch)
{
	if (ch >= '0' && ch <= '9')
		return (unsigned int)(ch - '0');

	/* If character is in the incorrect range then return max value of integer */
	return INT_MAX;
}

void inputArray(char arr[], int n)
{
	for(unsigned int i = 0; i < n; i++)
		scanf(" %c",&arr[i]);
}
