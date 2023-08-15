/*
 ============================================================================================
 Name        : Student_DB_test.c
 Author      : Mostafa Mahmoud
 Created on  : Aug 13, 2023
 Version     : 1.0
 Description : This is the main test program for the Student Database Management System.
 	 	 	   It allows users to interact with the database using a menu-driven interface.
 	 	 	   Users can perform various actions such as adding, deleting, viewing, and
 	 	 	   managing student records.
 ============================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Student_DB.h" // Include the header file that contains function declarations and data structures

extern Student* gpFirstStudent; // Declare the global variable for the first student node in the linked list

int main()
{
    uint8 choice; // Variable to store user's menu choice
    uint32 num; // Variable to store the number of students
    sint32 index; // Variable to store the index for node retrieval

    while(1) // Infinite loop to keep the program running
    {
        choice = displayOptions(); // Display the menu options and get user's choice

        switch(choice)
        {
        case 1:
            addStudent(); // Call the function to add a new student
            break;
        case 2:
            deleteStudent(); // Call the function to delete a student
            break;
        case 3:
            viewStudents(); // Call the function to view all students' records
            break;
        case 4:
            deleteAllStudents(); // Call the function to delete all students' records
            break;
        case 5:
            num = getStudentCount_Iterative(); // Call the function to get student count iteratively
            DPRINTF("\nStudents Count: %lu\n",num); // Display the count of students
            break;
        case 6:
            num = getStudentCount_Recursive(gpFirstStudent); // Call the function to get student count recursively
            DPRINTF("\nStudents Count: %lu\n",num); // Display the count of students
            break;
        case 7:
            DPRINTF("\nEnter Node Index (ZERO-Based): ");
            scanf("%ld",&index);
            getNodeFromStart(index); // Call the function to get a node from the start by index
            break;
        case 8:
            DPRINTF("\nEnter Node Index (from the end): ");
            scanf("%ld",&index);
            getNodeFromEnd(index); // Call the function to get a node from the end by index
            break;
        case 9:
            getMiddleStudent(); // Call the function to get the middle student
            break;
        case 10:
            reverseStudentList(); // Call the function to reverse the order of students in the list
            break;
        case 11:
            detectLoop(); // Call the function to detect if there's a loop in the linked list
            break;
        case 12:
            DPRINTF("\nProgram ended\n");
            return 0; // Exit the program
        default:
            DPRINTF("\nWrong Option | Try again\n"); // Display an error message for invalid menu options
            break;
        }
    }

    return 0; // Return 0 to indicate successful program execution
}
