/*
 ============================================================================
 Name        : EX3_String.c
 Author      : Mostafa Mahmoud
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
EX3: C Program to Reverse String Without Using Library Function You can only use library function strlen(),
To find the length of the string Output :
Enter the string : Pritesh
Reverse string is : hsetirP
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE   1000

int main(void) {

	char str[MAX_SIZE];

	printf("Enter a string : ");
	fflush(stdout);
	gets(str);

	unsigned int i = 0;                 // Acts as a pointer to the first character
	unsigned int j = strlen(str) - 1;   // Acts as a pointer to the last character

	while(i < j)
	{
		char temp = str[i];
		str[i] = str[j];
		str[j] = temp;

		i++; j--;
	}

	printf("Reverse string is : %s\n",str);

	return 0;
}
