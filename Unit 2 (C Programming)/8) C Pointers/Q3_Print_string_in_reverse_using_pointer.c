/*
 ============================================================================
 Name        : Q3.c
 Author      : Mostafa Mahmoud
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
Q3:
Write a program in C to print a string in reverse using a pointer
The Alphabets are :
Test Data :
Input a string : w3resource
Expected Output :
Pointer : Print a string in reverse order :
------------------------------------------------
Input a string : w3resource
Reverse of the string is : ecruoser3w
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE  20

int main(void) {

	char str[SIZE];
	char reversedStr[SIZE];

	/* Taking the string as input from user */
	printf("Input a string : ");
	fflush(stdout);
	gets(str);

	unsigned int len = strlen(str);

	/* p_str -> Pointer to char to point to the 1st char in the original string
	 * p_revstr -> Pointer to char to point to the 1st char in the reversed string
	 */
	char *p_str = str;
	char *p_revstr = reversedStr;

	/* Updating p_str till reaching the end of the original string (Null Terminator) */
	while(*p_str != '\0')   p_str++;

	/* Move only one step back to make p_str point to the last char of the original string */
	p_str--;

	for(unsigned int i = 0; i < len; i++)
	{
		/* Store the content of the original string into the reversed but in reversed order
		 * Using Pointers */
		*p_revstr = *p_str;

		p_revstr++; /* Increment p_revstr to point to the next char in the reversed string */
		p_str--;    /* decrement p_str to point to the previous char in the original string */
	}

	*p_revstr = '\0'; /* Adding the Null terminator at the end of the reversed string */

	/* Displaying the output */
	printf("\nReverse of the string is : %s\n",reversedStr);

	return 0;
}
