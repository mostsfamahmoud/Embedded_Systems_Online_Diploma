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
EX5:

Write C Program to Find ASCII Value of a Character

#########Console_output######
Enter a character: G
ASCII value of G = 71
#############################
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	char ch;

	printf("Enter a character: ");
	fflush(stdout);
	scanf("%c",&ch);

	printf("ASCII value of %c = %d",ch,ch);

	return EXIT_SUCCESS;
}
