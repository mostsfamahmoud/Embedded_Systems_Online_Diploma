/*
 ============================================================================
 Name        : Student_DB.h
 Author      : Mostafa Mahmoud
 Version     : 1.0
 Description : Student Database Management System using Linked List
 ============================================================================
 */

#ifndef STUDENT_DB_H_
#define STUDENT_DB_H_

#include "Platform_Types.h"

/***********************************************
 *********** Preprocessors Directives ***********
 ***********************************************/

#define NAME_LENGTH    40

#define SUCCESS        (boolean)1
#define FAILURE        (boolean)0

#define DPRINTF(...)       printf(__VA_ARGS__); \
	                       fflush(stdout); \
	                       fflush(stdin)

/***********************************************
 *************** Type Definitions **************
 ***********************************************/

typedef struct {
	uint32 id;
	uint8 name[NAME_LENGTH];
	float32 height;
}StudentData;

struct StudentNode{
	StudentData data;
	struct StudentNode* pNext;
};

typedef struct StudentNode Student;

/***********************************************************
 *************** Function Declarations (APIs) **************
 ***********************************************************/

void fillRecord(StudentData* studentData);

boolean addStudent(void);

boolean deleteStudent(void);

boolean viewStudents(void);

boolean deleteAllStudents(void);

uint8 displayOptions(void);

boolean getNodeFromStart(sint32 index);

uint32 getStudentCount_Iterative(void);

uint32 getStudentCount_Recursive(Student* pCurrentStudent);

boolean getNodeFromEnd(sint32 index);

boolean getMiddleStudent(void);

boolean detectLoop(void);

boolean reverseStudentList(void);


#endif /* STUDENT_DB_H_ */
