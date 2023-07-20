/*
 ============================================================================
 Name        : EX1.c
 Author      : Mostafa Mahmoud
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/* EX1: C Program to Store Information(name, roll and marks) of a Student Using Structure
In this program, a structure(student) is created which contains name, roll and marks as its data member.
Then, a structure variable(s) is created.
Then, data (name, roll and marks) is taken from user and stored in data members of structure variable s.
Finally, the data entered by user is displayed.

Output:
Enter information of students:
Enter name: Adele
Enter roll number: 21
Enter marks: 334.5

Displaying Information name: Adele
Roll: 21
Marks: 334.50
*/


#include <stdio.h>
#include <stdlib.h>


struct Student
{
	char name[50];
	unsigned int roll;
	double marks;
};

typedef struct Student Student;

int main(void) {

	Student s;
	printf("Enter information of students:\nEnter name: ");
	fflush(stdout);
	gets(s.name);

	printf("Enter roll number: ");
	fflush(stdout);
	scanf("%u",&s.roll);

	printf("Enter marks: ");
	fflush(stdout);
	scanf("%lf",&s.marks);

	printf("\nDisplaying Information:\n");
	printf("Name: %s\nRoll: %u\nMarks: %.2lf\n",s.name,s.roll,s.marks);

	return 0;
}
