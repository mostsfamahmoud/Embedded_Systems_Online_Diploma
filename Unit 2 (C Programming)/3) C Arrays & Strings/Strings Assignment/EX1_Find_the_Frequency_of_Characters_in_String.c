/*
 ============================================================================
 Name        : EX1_String.c
 Author      : Mostafa Mahmoud
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
Exl: C Program to Find the Frequency of Characters in a String
This program asks user to enter a string and a character and
this program checks how many times that character is repeated in the string entered by user.

Enter a string: This website is awesome.
Enter a character to find frequency: e
Frequency of e = 4
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE   1000

int main(void) {

	char str[MAX_SIZE];

	char ch;  // The character that its frequency required

	printf("Enter a string: ");
	fflush(stdout);
	gets(str);

	printf("Enter a character to find frequency: ");
	fflush(stdout);
	scanf("%c",&ch);

	unsigned int freqCount = 0;

	for(unsigned int i = 0; str[i] != '\0'; i++)
	{
		if(str[i] == ch)
			freqCount++;
	}

	printf("Frequency of %c = %u\n",ch,freqCount);

	return 0;
}
