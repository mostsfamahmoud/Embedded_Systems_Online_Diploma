/*
 ============================================================================
 Name        : EX1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


/*
Write a C program takes string from the user and
check if it the same username or not

Output if Identical:
Enter  a string : marco
Enter your name : Marco
Identical

Output if Different:
Enter a string : Bolis
Enter your name : Pavly
Different
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

int main(void) {

	char username[100], str[100];

	printf("Enter  a string : ");
	fflush(stdout);
	gets(str);

	printf("Enter your name : ");
	fflush(stdout);
	gets(username);

	char compareResult = stricmp(username,str);

	if (compareResult == 0)
		printf("Identical\n");
	else
		printf("Different\n");

	return 0;
}
