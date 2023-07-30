/*
 ============================================================================
 Name        : Q2.c
 Author      : Mostafa Mahmoud
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
Q2:
Write a program in C to print all the alphabets using a pointer.
Expected Output :
The Alphabets are :
Expected Output :
A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	char * charPtr = NULL;           /* To avoid the occurrence of Wild Pointer */

	char ch = 'A';
	charPtr = &ch;

	unsigned char count, numOfAlphabets = ('Z' - 'A') + 1;

	printf("The Alphabets are :\n");
	for(count = 0; count < numOfAlphabets; count++)
	{
		printf("%c ",*charPtr);

		/* Same as *charPtr = *charPtr + 1
		 * Means that each iteration, the value of ch is incremented (indirectly using charPtr pointer) by 1
		 * To store the next alphabet
		 */
		(*charPtr)++;
	}
	printf("\n");

	return 0;
}


















