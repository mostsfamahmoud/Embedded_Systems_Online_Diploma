/*
 ============================================================================
 Name        : EX6.c
 Author      : Mostafa Mahmoud
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/* C program to find size of both Union and Structure that have the same members */

#include <stdlib.h>
#include <stdio.h>

union job {	//defining a union
	char name[32];
	float salary;
	int worker_no;
} u;
struct jobl {
	char name[32];
	float salary;
	int worker_no;
} s;

int main() {
	printf("size of union = %llu", sizeof(u));
	printf("\nsize of structure = %llu", sizeof(s));
	return 0;
}

