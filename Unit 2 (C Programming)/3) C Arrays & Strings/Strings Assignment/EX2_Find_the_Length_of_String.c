/*
 ============================================================================
 Name        : EX2_String.c
 Author      : Mostafa Mahmoud
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
EX2: C Program to Find the Length of a String
You can use standard library function strlen() to find the length of a string
but, this program computes the length of a string manually without using strlen() function.
Output
Enter a string: Programiz
Length of string: 9
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE   1000

int main(void) {

	char str[MAX_SIZE];
	unsigned int count = 0;

	printf("Enter a string: ");
	fflush(stdout);
	gets(str);

	unsigned int i = 0;

	while(str[i] != '\0')
	{
		count++;
		i++;
	}

	printf("Length of string: %d\n",count);

	return 0;
}
