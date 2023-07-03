/*
 ============================================================================
 Name        : EX5.c
 Author      : Mostafa Mahmoud
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
EX5: C Program to Check Whether a Character is an Alphabet or not
This program takes a character from user and checks whether that character is an alphabet or not.

Output 1
Enter a character: *
* is not an alphabet

Output 2
Enter a character: K
K is an alphabet
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	char ch;

	printf("Enter a character: ");
	fflush(stdout);
	scanf("%c",&ch);

	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		printf("%c is an alphabet\n",ch);
	else
		printf("%c is not an alphabet\n",ch);

	return EXIT_SUCCESS;
}
