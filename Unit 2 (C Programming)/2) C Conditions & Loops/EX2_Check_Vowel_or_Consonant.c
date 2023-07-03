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
 EX2: C Program to Check Vowel or Consonant

 AIphabets a, e, i, o and u are known as vowels and all alphabets except these characters are known as consonants. This program asI‹s user to enter a character and checI‹s whether that character is vowel or not.

 Output 1
 Enter an alphabet: i i is a vowel.

 Output 2
 Enter an alphabet: G G is a consonant.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	char ch;

	printf("Enter an alphabet: ");
	fflush(stdout);
	scanf("%c", &ch);

	switch (ch) {
	case 'a':
	case 'A':
	case 'e':
	case 'E':
	case 'i':
	case 'I':
	case 'o':
	case 'O':
	case 'u':
	case 'U':
		printf("%c is a vowel\n", ch);
		break;
	default:
		printf("%c is a consonant\n", ch);
		break;
	}

	return EXIT_SUCCESS;
}
