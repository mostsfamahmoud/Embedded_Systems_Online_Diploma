/*
 ============================================================================
 Name        : Q9.c
 Author      : Mostafa Mahmoud
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
 C Function to reverse words in string
 Test case :
 Input -> mohamed gamal
 Output -> gamal mohamed
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE   100

void reverseWords(char str[]);

int main(void) {

	char str[SIZE];

	printf("Enter a String (max %d): ", SIZE);
	fflush(stdout);
	gets(str);

	reverseWords(str);

	printf("After Word Reversing: %s\n", str);

	return 0;
}

void reverseWords(char str[]) {

	int len = strlen(str);

	/* To get the index (position) of the white space in the string given
	 * pos stops at the position of the white space */
	unsigned int pos;
	for (pos = 0; str[pos] != ' '; pos++);

	/* Defining two array to represent both words */
	unsigned int FW_Size = pos, SW_Size = len - (pos + 1);

	char firstWord[FW_Size], secondWord[SW_Size];

	unsigned int i, j;
	unsigned int k = pos + 1; /* k represents the start of the second word in the given string */

	/* First Word stores all characters till the White space */
	for (i = 0; i < FW_Size; i++)
		firstWord[i] = str[i];

	/* Second Word stores all characters after the white space
	 * and till the null terminator of the string (excluded) */
	for (i = 0; i < SW_Size; i++)
		secondWord[i] = str[i + k];

	/* Swapping the two words and adding the white space in the middle of them */
	for (i = 0; i < SW_Size; i++)
		str[i] = secondWord[i];

	/* Store the white space in index (i) then increment it
	 * to point to the position at which the first word will be stored */
	str[i++] = ' ';

	for (j = 0; j < FW_Size; j++)
		str[j + i] = firstWord[j];

}
