/*
 * This is the source file "lifo.c" for a LIFO (Last-In-First-Out) stack implementation.
 * It provides functions to initialize, push, pop, check status, print contents, and clear the LIFO stack.
 * The LIFO stack is implemented using a simple buffer.
 *
 * Created on: Aug 11, 2023
 * Author: Mostafa Mahmoud
*/

#include "lifo.h"  // Include the header file for the LIFO library
#include <stdio.h>  // Include standard I/O functions

/***********************************************************
 ******************* Function Definitions ******************
 ***********************************************************/

/* Function to initialize a LIFO stack.
   Parameters:
     lifoBuf_Ptr: Pointer to the LIFO buffer structure.
     buf: Pointer to the memory buffer for LIFO storage.
     buf_size: Size of the memory buffer.
   Returns:
     LIFO_Status indicating success or an error condition.
*/
LIFO_Status LIFO_Init(LIFO_Buf_t *lifoBuf_Ptr, ITEM_TYPE *buf, sint32 buf_size)
{
    // Check if the buffer assigned to the LIFO is NULL or if LIFO structure is invalid
    if (buf == NULL || LIFO_Is_Null(lifoBuf_Ptr)) {
        printf("LIFO_Init failed -> NULL is passed\n");
        return LIFO_NULL;
    }

    // Check if the buf_size is positive
    if (buf_size <= 0) {
        printf("LIFO_Init failed -> LIFO Length smaller than or equal 0\n");
        return LIFO_INVALID_LENGTH;
    }

    // Assign both base and head pointers to the first location of the buffer
    lifoBuf_Ptr->base = buf;
    lifoBuf_Ptr->head = buf;

    lifoBuf_Ptr->count = 0;        // Initialize items count to 0
    lifoBuf_Ptr->length = buf_size;  // Assign buffer size to LIFO length

    printf("LIFO_Init Passed\n");
    return LIFO_NO_ERROR;
}

/* Function to push an item onto the LIFO stack.
   Parameters:
     lifoBuf_Ptr: Pointer to the LIFO buffer structure.
     item: The item to be pushed.
   Returns:
     LIFO_Status indicating success or an error condition.
*/
LIFO_Status LIFO_Push(LIFO_Buf_t *lifoBuf_Ptr, ITEM_TYPE item)
{
    // Check if the LIFO is NULL
    if (LIFO_Is_Null(lifoBuf_Ptr)) {
        printf("LIFO_Push failed -> NULL is passed\n");
        return LIFO_NULL;
    }

    // Check if the LIFO is full
    if (LIFO_Is_Full(lifoBuf_Ptr)) {
        printf("LIFO_Push failed -> LIFO FULL\n");
        return LIFO_FULL;
    }

    *(lifoBuf_Ptr->head) = item;  // Insert the item at the address pointed by the head pointer
    lifoBuf_Ptr->head++;         // Increment the pointer to point to the next location
    lifoBuf_Ptr->count++;        // Increment items count

    return LIFO_NO_ERROR;
}

/* Function to pop an item from the LIFO stack.
   Parameters:
     lifoBuf_Ptr: Pointer to the LIFO buffer structure.
     itemPtr: Pointer to store the popped item.
   Returns:
     LIFO_Status indicating success or an error condition.
*/
LIFO_Status LIFO_Pop(LIFO_Buf_t *lifoBuf_Ptr, ITEM_TYPE *itemPtr)
{
    // Check if the LIFO is NULL or if item pointer is uninitialized
    if (LIFO_Is_Null(lifoBuf_Ptr) || !itemPtr) {
        printf("LIFO_Pop failed -> NULL is passed\n");
        return LIFO_NULL;
    }

    // Check if the LIFO is empty
    if (LIFO_Is_Empty(lifoBuf_Ptr)) {
        printf("LIFO_Pop failed -> LIFO EMPTY\n");
        return LIFO_EMPTY;
    }

    lifoBuf_Ptr->head--;            // Decrement the pointer to point to the previous location
    *itemPtr = *(lifoBuf_Ptr->head);  // Get the item at the address pointed by the head pointer
    lifoBuf_Ptr->count--;           // Decrement items count

    return LIFO_NO_ERROR;
}

/* Function to get the top item from the LIFO stack without popping.
   Parameters:
     lifoBuf_Ptr: Pointer to the LIFO buffer structure.
     topPtr: Pointer to store the top item.
   Returns:
     LIFO_Status indicating success or an error condition.
*/
LIFO_Status LIFO_Top(const LIFO_Buf_t *lifoBuf_Ptr, ITEM_TYPE *topPtr)
{
    // Check if the LIFO is NULL or if top pointer is uninitialized
    if (LIFO_Is_Null(lifoBuf_Ptr) || !topPtr) {
        printf("LIFO_Top failed -> NULL is passed\n");
        return LIFO_NULL;
    }

    // Check if the LIFO is empty
    if (LIFO_Is_Empty(lifoBuf_Ptr)) {
        printf("LIFO_Top failed -> LIFO EMPTY\n");
        return LIFO_EMPTY;
    }

    *topPtr = *(lifoBuf_Ptr->head - 1);  // Get the item in the previous address of the head pointer

    return LIFO_NO_ERROR;
}

/* Function to check if the LIFO structure is invalid (NULL pointers).
   Parameters:
     lifoBuf_Ptr: Pointer to the LIFO buffer structure.
   Returns:
     TRUE if the LIFO structure is invalid, FALSE otherwise.
*/
boolean LIFO_Is_Null(const LIFO_Buf_t *lifoBuf_Ptr)
{
    if (lifoBuf_Ptr == NULL || lifoBuf_Ptr->base == NULL || lifoBuf_Ptr->head == NULL)
        return TRUE;

    return FALSE;
}

/* Function to check if the LIFO stack is empty.
   Parameters:
     lifoBuf_Ptr: Pointer to the LIFO buffer structure.
   Returns:
     TRUE if the LIFO stack is empty, FALSE otherwise.
   Note:
   	 If you want to use this function, you have to use LIFO_Is_Null first
*/
boolean LIFO_Is_Empty(const LIFO_Buf_t *lifoBuf_Ptr)
{
    if (lifoBuf_Ptr->count == 0)
        return TRUE;

    return FALSE;
}

/* Function to check if the LIFO stack is full.
   Parameters:
     lifoBuf_Ptr: Pointer to the LIFO buffer structure.
   Returns:
     TRUE if the LIFO stack is full, FALSE otherwise.
   Note:
   	   If you want to use this function, you have to use LIFO_Is_Null first
*/
boolean LIFO_Is_Full(const LIFO_Buf_t *lifoBuf_Ptr)
{
    if (lifoBuf_Ptr->count == lifoBuf_Ptr->length)
        return TRUE;

    return FALSE;
}

/* Function to print the contents of the LIFO stack.
   Parameters:
     lifoBuf_Ptr: Pointer to the LIFO buffer structure.
*/
void LIFO_Print(const LIFO_Buf_t *lifoBuf_Ptr)
{
    if (LIFO_Is_Null(lifoBuf_Ptr)) {
        printf("LIFO_Print failed -> NULL is passed\n");
        return;
    }

    // Check if the LIFO is empty
    if (LIFO_Is_Empty(lifoBuf_Ptr)) {
        printf("LIFO_Print failed -> LIFO EMPTY\n");
        return;
    }

    ITEM_TYPE *tempPtr = NULL;

    printf("-------- LIFO Print --------\n");

    for (tempPtr = lifoBuf_Ptr->base; tempPtr < lifoBuf_Ptr->head; tempPtr++) {
        printf("-> %u ", *tempPtr);
    }

    printf("\nLIFO_Print Passed\n");
}

/* Function to clear the contents of the LIFO stack.
   Parameters:
     lifoBuf_Ptr: Pointer to the LIFO buffer structure.
   Returns:
     LIFO_Status indicating success or an error condition.
*/
LIFO_Status LIFO_Clear(LIFO_Buf_t *lifoBuf_Ptr)
{
    if (LIFO_Is_Null(lifoBuf_Ptr)) {
        printf("LIFO_Clear failed -> NULL is passed\n");
        return LIFO_NULL;
    }

    // Check if the LIFO is empty
    if (LIFO_Is_Empty(lifoBuf_Ptr)) {
        printf("LIFO_Clear failed -> LIFO is already EMPTY\n");
        return LIFO_EMPTY;
    }

    lifoBuf_Ptr->head = lifoBuf_Ptr->base;
    lifoBuf_Ptr->count = 0;

    printf("LIFO_Clear Passed\n");
    return LIFO_NO_ERROR;
}
