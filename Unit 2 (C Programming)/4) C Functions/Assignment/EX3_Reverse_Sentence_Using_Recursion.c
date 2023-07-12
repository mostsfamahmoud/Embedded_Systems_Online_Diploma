/*
 ============================================================================
 Name        : EX3.c
 Author      : Mostafa Mahmoud
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
EX3: C program to Reverse a Sentence Using Recursion
Output
Enter a sentence: margorp emosewa
awesome program
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE   100

void reverseSentence(char str[],int low, int high);

int main(void) {

	char str[SIZE];
	printf("Enter a sentence: ");
	fflush(stdout);
	gets(str);

	/* 0 -> Index of the first character of the sentence
	 * strlen(str) - 1 -> Index of the last character in the sentence (Without touching the '\0')
	 * str is passed here by address so its actual content will be reversed
	 */
	reverseSentence(str, 0, strlen(str) - 1);

	printf("%s\n",str);

	return 0;
}

/* Decrease and Conquer Algorithm */
void reverseSentence(char str[],int low, int high)
{
	/* low  -> Acts as a pointer to (Index of) the first character in the substring
	 * high -> Acts as a pointer to (Index of) the last character in the substring
	 * In case (low) becomes greater or equal (high) then QUIT and return
	 */
	if (low < high)
	{
		/* Swapping the first and last characters of the substring */
		char temp = str[low];
		str[low] = str[high];
		str[high] = temp;

		/* Recursive step with subproblem size = (n - 2) each time
		 * Where n = (high - low + 1) -> No. of characters inside each substring
		 */
		reverseSentence(str, low + 1, high - 1);
	}
}
