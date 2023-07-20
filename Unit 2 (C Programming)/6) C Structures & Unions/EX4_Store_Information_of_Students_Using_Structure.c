/*
 ============================================================================
 Name        : EX4.c
 Author      : Mostafa Mahmoud
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/* EX4:C Program to Store Information of Students Using Structure
In this program, a structure(student) is created which contains name, roll and marks as its data member.
Then, an array of structure of 10 elements is created.
Then, data(name, roll and marks) for 10 elements is asked to user and stored in array of structure.
Finally, the data entered by user is displayed.

Output:
Enter information:
For roll number 1
Enter name: Tom
Enter marks: 98

For roll number 2
Enter name: Jerry
Enter marks: 89

Displaying information of students:
Information for roll number 1:
Name: Tom
Marks: 98
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE   10

struct Student
{
	char name[30];
	float marks;
};

typedef struct Student Student;

int main(void) {

	Student students[SIZE];

	printf("Enter information:\n");
	for(unsigned int i = 0; i < SIZE; i++)
	{
		printf("For roll number %d\n", i + 1);
		fflush(stdin);
		printf("Enter name: ");
		fflush(stdout);
		gets(students[i].name);

		printf("Enter marks: ");
		fflush(stdout);
		scanf("%f",&students[i].marks);

		printf("\n");
	}

	printf("Displaying information of students:\n");
	for(unsigned int i = 0; i < SIZE; i++)
	{
		printf("Information for roll number %d:\n", i + 1);
		printf("Name: %s\n",students[i].name);
		printf("Marks: %0.1f\n",students[i].marks);
		printf("\n");
	}

	return 0;
}
