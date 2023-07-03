/*
 ============================================================================
 Name        : EX2.c
 Author      : Mostafa Mahmoud
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


/*
EX2:

Write C Program to Print a Integer Entered by a User
i should see the Console as following:
##########Console-output###
Enter a integer: 25
You entered: 25
###########################
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int num;

	printf("Enter a integer: ");
	fflush(stdout);
	scanf("%d",&num);

	printf("You entered: %d", num);

	return EXIT_SUCCESS;
}
