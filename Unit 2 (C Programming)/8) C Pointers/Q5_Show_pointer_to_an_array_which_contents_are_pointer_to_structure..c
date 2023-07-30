/*
 ============================================================================
 Name        : Q5.c
 Author      : Mostafa Mahmoud
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
Q5:
Write a program in C to show a pointer to an array which contents are pointer to structure.

Expected Output :
Employee Name : Alex
Employee ID : 1002
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE  20

struct SEmployee
{
	char name[20];
	unsigned int ID;
};

typedef struct SEmployee Employee;

int main(void) {

	int size;
	Employee emp[MAX_SIZE];
	Employee *PtrArr[MAX_SIZE];        /* PtrArr -> Array of Pointers to Structures of Max_SIZE defined by a Macro */

	printf("Enter number of Employees (Max: %d): ",MAX_SIZE);
	fflush(stdout);
	scanf("%d",&size);

	/* Taking all employees' information from user */
	for(unsigned int i = 0; i < size; i++)
	{
		printf("\n-------- Employee %d --------\n", i + 1 );
		printf("Enter name: ");
		fflush(stdout); fflush(stdin);
		gets(emp[i].name);

		printf("Enter ID: ");
		fflush(stdout);
		scanf("%u",&emp[i].ID);
	}

	/* Assigning each pointer in (PtrArr) array to point to the corresponding employee struct inside (emp) array*/
	for(unsigned int i = 0; i < size; i++)
	{
		PtrArr[i] = &emp[i];
	}

	/* Ptr2Arr -> Pointer to array of (size) pointers to struct of type Employee
	 * Where size -> any integers between 0 and Max_SIZE */
	Employee *(*Ptr2Arr)[size] = &PtrArr;

	printf("\n----------- Displaying Employee Information -----------");
	for(unsigned int i = 0; i < size; i++)
	{
		printf("\n%d) Employee name: %s\n", i + 1, (*(*Ptr2Arr + i))->name);
		printf("   Employee ID: %u\n",(*(*Ptr2Arr + i))->ID);
	}

	return 0;
}
