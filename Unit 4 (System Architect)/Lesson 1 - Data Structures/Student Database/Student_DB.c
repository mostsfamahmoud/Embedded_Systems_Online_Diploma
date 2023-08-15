/*
 ============================================================================
 Name        : Student_DB.c
 Author      : Mostafa Mahmoud
 Version     : 1.0
 Description : Student Database Management System using Linked List
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Student_DB.h"  // Include the header file that contains the necessary declarations

/************************************************************************************
 ******************************** Global Variables **********************************
 ***********************************************************************************/

// Global variable to store the first student in the linked list
Student* gpFirstStudent = NULL;

/*************************************************************************************
 ******************************** Function Definitions *******************************
 *************************************************************************************/

/*******************************************************
 * Function: fillRecord
 * Description: Takes user input to fill student record data.
 * Parameters:
 *   studentData: Pointer to a StudentData structure where the data will be stored.
 * Returns: void
 *******************************************************/
void fillRecord(StudentData* studentData)
{
    char tempText[NAME_LENGTH]; // Temporary character array for input

    DPRINTF("\nEnter Student Full Name: "); // Display prompt for full name input
    gets(studentData->name); // Read and store the student's full name

    DPRINTF("\nEnter Student ID: "); // Display prompt for student ID input
    gets(tempText); // Read a string input for student ID
    studentData->id = atoi(tempText); // Convert the string to an integer and store as student ID

    DPRINTF("\nEnter Student Height: "); // Display prompt for student height input
    gets(tempText); // Read a string input for student height
    studentData->height = atof(tempText); // Convert the string to a floating-point and store as student height
}


/*******************************************************
 * Function: addStudent
 * Description: Adds a new student to the database.
 * Returns:
 *   SUCCESS if the student is successfully added,
 *   FAILURE if memory allocation fails.
 *******************************************************/
boolean addStudent(void)
{
    Student* pNewStudent = (Student*) malloc(sizeof(Student)); // Allocate memory for a new student node

    if (pNewStudent)
    {
        if (gpFirstStudent == NULL)
            gpFirstStudent = pNewStudent; // If it's the first student, assign it as the head of the list
        else
        {
            Student* pLastStudent = gpFirstStudent;

            while(pLastStudent->pNext)
                pLastStudent = pLastStudent->pNext;

            pLastStudent->pNext = pNewStudent; // Add the new student at the end of the list
        }

        fillRecord(&pNewStudent->data); // Fill the student record with data

        pNewStudent->pNext = NULL; // Set the next pointer of the new student to NULL

        DPRINTF("\nStudent is added successfully\n");
        return SUCCESS; // Return success status
    }

    // If memory allocation failed, return failure status
    /* pNewStudent == NULL means that No space available in HEAP to allocate this new student */
    return FAILURE;
}


/*******************************************************
 * Function: addStudent
 * Description: Adds a new student to the database.
 * Returns:
 *   SUCCESS if the student is successfully added,
 *   FAILURE if memory allocation fails.
 *******************************************************/
boolean deleteStudent(void)
{
    Student* pPrevStudent  = NULL; // Pointer to the previous student node
    Student* pCurrentStudent = gpFirstStudent; // Pointer to the current student node

    if (gpFirstStudent) /* List has records to search in it */
    {
        uint32 studentId;
        DPRINTF("\nEnter Student ID to be deleted: ");
        scanf("%lu",&studentId); // Input the ID of the student to be deleted

        // Search for the student to be deleted
        while((pCurrentStudent->pNext != NULL) && (pCurrentStudent->data.id != studentId))
        {
            pPrevStudent = pCurrentStudent;
            pCurrentStudent = pCurrentStudent->pNext;
        }

        // If the student with the given ID is not found
        if (pCurrentStudent->data.id != studentId)
        {
            DPRINTF("\nThe ID selected is not found\n");
            return FAILURE; // Return failure status
        }

        // Update the linked list pointers to remove the student
        if (pPrevStudent == NULL)
            gpFirstStudent = pCurrentStudent->pNext; // If it's the first student
        else
            pPrevStudent->pNext = pCurrentStudent->pNext; // If it's not the first student

        free(pCurrentStudent); // Free the memory of the deleted student
        pCurrentStudent = NULL; // Set the pointer to NULL

        DPRINTF("\nStudent with the selected ID is removed successfully\n");
        return SUCCESS; // Return success status
    }

    // If the list is empty, print a failure message
    DPRINTF("\nThe list is Empty\n");
    return FAILURE; // Return failure status
}


/*******************************************************
 * Function: viewStudents
 * Description: Displays all students' records in the database.
 * Returns:
 *   SUCCESS if the records are successfully displayed,
 *   FAILURE if the list is empty.
 *******************************************************/
boolean viewStudents(void)
{
    uint32 count = 0; // Counter to keep track of the record number
    Student* pCurrentStudent = gpFirstStudent; // Pointer to the current student being viewed

    if (gpFirstStudent) /* List has records to view */
    {
        while(pCurrentStudent)
        {
            DPRINTF("\nRecord Number: %lu", count + 1); // Display the record number
            DPRINTF("\nID: %lu", pCurrentStudent->data.id); // Display the student's ID
            DPRINTF("\nName: %s", pCurrentStudent->data.name); // Display the student's name
            DPRINTF("\nHeight: %.2f\n", pCurrentStudent->data.height); // Display the student's height

            pCurrentStudent = pCurrentStudent->pNext; // Move to the next student node
            count++; // Increment the record number counter
        }
        return SUCCESS; // Return success status
    }

    // If the list is empty, print a failure message
    DPRINTF("\nThe list is Empty\n");
    return FAILURE; // Return failure status
}


/*******************************************************
 * Function: deleteAllStudents
 * Description: Deletes all students' records from the database.
 * Returns:
 *   SUCCESS if all students are successfully deleted,
 *   FAILURE if the list is empty.
 *******************************************************/
boolean deleteAllStudents(void)
{
    Student* pCurrentStudent = gpFirstStudent; // Pointer to the current student being processed

    if (gpFirstStudent) /* List has records to delete */
    {
        while(pCurrentStudent)
        {
            gpFirstStudent = pCurrentStudent->pNext; // Move the start pointer to the next student

            free(pCurrentStudent); // Free the memory allocated for the current student
            pCurrentStudent = pCurrentStudent->pNext; // Move to the next student

            // The loop will iterate until all students are deleted
        }

        DPRINTF("\nAll Students are removed successfully\n"); // Print success message
        return SUCCESS; // Return success status
    }

    // If the list is empty, print a failure message
    DPRINTF("\nThe list is Empty\n");
    return FAILURE; // Return failure status
}


/*******************************************************
 * Function: displayOptions
 * Description: Displays a menu and returns user's choice.
 * Returns: User's selected option (1 to 12).
 *******************************************************/
uint8 displayOptions(void)
{
    uint8 choice;

    DPRINTF("===================================");
    DPRINTF("\nChoose one of the following Options:");
    DPRINTF("\n\t 1: Add Student ");
    DPRINTF("\n\t 2: Delete Student ");
    DPRINTF("\n\t 3: View Students ");
    DPRINTF("\n\t 4: Delete All Students ");
    DPRINTF("\n\t 5: Get Students count (Using Iteration)");
    DPRINTF("\n\t 6: Get Students count (Using Recursion)");
    DPRINTF("\n\t 7: Get Node from the start");
    DPRINTF("\n\t 8: Get Node from the end");
    DPRINTF("\n\t 9: Get Middle student");
    DPRINTF("\n\t 10: Reverse students List");
    DPRINTF("\n\t 11: Is List Cyclic ?");
    DPRINTF("\n\t 12: Exit");
    DPRINTF("\n Enter Option Number: ");

    scanf("%hhu",&choice);

    DPRINTF("===================================");

    return choice;
}

/*******************************************************
 * Function: getNodeFromStart
 * Description: Retrieves a student's information by index from the beginning of the list.
 * Parameters:
 *   index: Index of the student to retrieve.
 * Returns:
 *   SUCCESS if the student information is retrieved,
 *   FAILURE if the index is out of bounds or the list is empty.
 *******************************************************/
boolean getNodeFromStart(sint32 index)
{
    uint32 count = 0; // Counter to keep track of the current node index
    Student* pCurrentStudent = gpFirstStudent; // Pointer to the current student node

    if (index < 0)
    {
        DPRINTF("\nInvalid Index\n"); // Display error message for negative index
        return FAILURE; // Return failure status
    }

    if (gpFirstStudent) /* List has records to view */
    {
        while(pCurrentStudent)
        {
            if (index == count)
            {
                DPRINTF("\n Record Index: %lu",index); // Display the index of the found student
                DPRINTF("\n\t ID: %lu",pCurrentStudent->data.id); // Display student ID
                DPRINTF("\n\t Name: %s",pCurrentStudent->data.name); // Display student name
                DPRINTF("\n\t Height: %.2f\n",pCurrentStudent->data.height); // Display student height

                return SUCCESS; // Return success status
            }

            pCurrentStudent = pCurrentStudent->pNext; // Move to the next student node
            count++; // Increment the index counter
        }

        if (count <= index)
        {
            DPRINTF("\nIndex out of bound\n"); // Display error message for out-of-bounds index
        }

        return FAILURE; // Return failure status
    }

    // If the list is empty, print a failure message
    DPRINTF("\nThe list is Empty\n");
    return FAILURE; // Return failure status
}


/*******************************************************
 * Function: getStudentCount_Iterative
 * Description: Counts the number of students in the database using an iterative approach.
 * Returns: The count of students.
 *******************************************************/
uint32 getStudentCount_Iterative(void)
{
    uint32 count = 0; // Counter to keep track of the number of students
    Student* pCurrentStudent = gpFirstStudent; // Pointer to the current student node

    if (gpFirstStudent) /* List has records */
    {
        while(pCurrentStudent)
        {
            count++; // Increment the counter for each student node
            pCurrentStudent = pCurrentStudent->pNext; // Move to the next student node
        }
        return count; // Return the total number of students
    }

    // If the list is empty, print a failure message
    DPRINTF("\nThe list is Empty\n");
    return 0; // Return 0 as the count
}


/*******************************************************
 * Function: getStudentCount_Recursive
 * Description: Counts the number of students in the database using a recursive approach.
 * Parameters:
 *   pCurrentStudent: Pointer to the current student node.
 * Returns: The count of students.
 *******************************************************/
uint32 getStudentCount_Recursive(Student* pCurrentStudent)
{
    if (pCurrentStudent == NULL)
        return 0;

    return getStudentCount_Recursive(pCurrentStudent->pNext) + 1;
}

/*******************************************************
 * Function: getNodeFromEnd
 * Description: Retrieves a student's information by index from the end of the list.
 * Parameters:
 *   index: Index of the student to retrieve.
 * Returns:
 *   SUCCESS if the student information is retrieved,
 *   FAILURE if the index is out of bounds or the list is empty.
 *******************************************************/
boolean getNodeFromEnd(sint32 index)
{
    uint32 count; // Counter to keep track of the current node index
    Student* pMain = gpFirstStudent; // Pointer to the main pointer traversing the list
    Student* pRef = gpFirstStudent; // Pointer to the reference pointer for index calculation

    if (index <= 0)
    {
        DPRINTF("\nInvalid Index\n"); // Display error message for non-positive index
        return FAILURE; // Return failure status
    }

    if (gpFirstStudent) /* List has records */
    {
        for(count = 0; count < (index - 1); count++)
        {
            pRef = pRef->pNext; // Move the reference pointer to calculate the offset

            if (pRef == NULL)
            {
                DPRINTF("\nIndex out of bound\n"); // Display error message for out-of-bounds index
                return FAILURE; // Return failure status
            }
        }

        while(pRef->pNext)
        {
            pRef = pRef->pNext; // Move the reference pointer to the end
            pMain = pMain->pNext; // Move the main pointer by the calculated offset
        }

        DPRINTF("\n Record Index from the end: %lu",index); // Display the index of the found student
        DPRINTF("\n\t ID: %lu",pMain->data.id); // Display student ID
        DPRINTF("\n\t Name: %s",pMain->data.name); // Display student name
        DPRINTF("\n\t Height: %.2f\n",pMain->data.height); // Display student height

        return SUCCESS; // Return success status
    }

    // If the list is empty, print a failure message
    DPRINTF("\nThe list is Empty\n");
    return FAILURE; // Return failure status
}


/*******************************************************
 * Function: getMiddleStudent
 * Description: Retrieves the information of the middle student in the list.
 * Returns:
 *   SUCCESS if the middle student information is retrieved,
 *   FAILURE if the list is empty.
 *******************************************************/
boolean getMiddleStudent(void)
{
    uint32 count = 0; // Counter to keep track of the number of nodes traversed
    Student* pFast = gpFirstStudent; // Pointer that moves two nodes at a time
    Student* pSlow = gpFirstStudent; // Pointer that moves one node at a time

    if (gpFirstStudent) /* List has records to view */
    {
        while(pFast && pFast->pNext)
        {
            pFast = pFast->pNext->pNext; // Move the fast pointer by two nodes
            pSlow = pSlow->pNext; // Move the slow pointer by one node
            count++; // Increment the counter for each traversal
        }

        DPRINTF("\n Record Middle Index: %lu",count); // Display the index of the middle student
        DPRINTF("\n\t ID: %lu",pSlow->data.id); // Display student ID
        DPRINTF("\n\t Name: %s",pSlow->data.name); // Display student name
        DPRINTF("\n\t Height: %.2f\n",pSlow->data.height); // Display student height

        return SUCCESS; // Return success status
    }

    // If the list is empty, print a failure message
    DPRINTF("\nThe list is Empty\n");
    return FAILURE; // Return failure status
}


/*******************************************************
 * Function: detectLoop
 * Description: Detects if there's a loop in the linked list.
 * Returns:
 *   FAILURE if a loop is detected,
 *   SUCCESS if no loop is detected or the list is empty.
 *******************************************************/
boolean detectLoop(void)
{
    Student* pFast = gpFirstStudent; // Pointer that moves two nodes at a time
    Student* pSlow = gpFirstStudent; // Pointer that moves one node at a time

    if (gpFirstStudent) /* List has records to view */
    {
        while(pSlow && pFast && pFast->pNext)
        {
            pFast = pFast->pNext->pNext; // Move the fast pointer by two nodes
            pSlow = pSlow->pNext; // Move the slow pointer by one node

            if (pSlow == pFast)
            {
                DPRINTF("\nLoop Detected\n"); // Display loop detected message
                return FAILURE; // Return failure status
            }
        }

        DPRINTF("\nList has no Loops\n"); // Display no loop message
        return SUCCESS; // Return success status
    }

    // If the list is empty, print a failure message
    DPRINTF("\nThe list is Empty\n");
    return FAILURE; // Return failure status
}


/*******************************************************
 * Function: reverseStudentList
 * Description: Reverses the order of students in the list.
 * Returns:
 *   SUCCESS if the list is successfully reversed,
 *   FAILURE if the list is empty.
 *******************************************************/
boolean reverseStudentList(void)
{
    Student* pPrevStudent = NULL; // Pointer to the previous student
    Student* pCurrentStudent = gpFirstStudent; // Pointer to the current student
    Student* pNextStudent = gpFirstStudent; // Pointer to the next student

    if (gpFirstStudent) /* List has records to view */
    {
        while(pCurrentStudent)
        {
            pNextStudent = pCurrentStudent->pNext; // Save the next student pointer
            pCurrentStudent->pNext = pPrevStudent; // Reverse the next pointer
            pPrevStudent = pCurrentStudent; // Move the previous pointer to the current student
            pCurrentStudent = pNextStudent; // Move the current pointer to the next student
        }

        gpFirstStudent = pPrevStudent; // Update the list head to the last student

        DPRINTF("\nList is reversed successfully\n"); // Display success message
        return SUCCESS; // Return success status
    }

    // If the list is empty, print a failure message
    DPRINTF("\nThe list is Empty\n");
    return FAILURE; // Return failure status
}
