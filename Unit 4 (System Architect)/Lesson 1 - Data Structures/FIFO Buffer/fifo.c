/*
 * This is the source file "fifo.c" for a FIFO (First-In-First-Out) buffer implementation.
 * It provides functions to initialize, enqueue, dequeue, check status, print contents, and clear the FIFO buffer.
 * The FIFO can be implemented as a normal queue or a circular queue based on the CIRCULAR_QUEUE macro.
 *
 * Created on: Aug 11, 2023
 * Author: Mostafa Mahmoud
 */

#include "fifo.h"  // Include the header file for the FIFO library
#include <stdio.h>  // Include standard I/O functions

/***********************************************************
 ******************* Function Definitions ******************
 ***********************************************************/

/* Function to initialize a FIFO buffer.
 Parameters:
 fifoBuf_Ptr: Pointer to the FIFO buffer structure.
 buf: Pointer to the memory buffer for FIFO storage.
 buf_size: Size of the memory buffer.
 Returns:
 FIFO_Status indicating success or an error condition.
 */
FIFO_Status FIFO_Init(FIFO_Buf_t *fifoBuf_Ptr, ITEM_TYPE *buf, sint32 buf_size)
{
	// Check if the buffer assigned to the FIFO is NULL or if FIFO structure is invalid
	if (buf == NULL || FIFO_Is_Null(fifoBuf_Ptr)) {
		printf("FIFO_Init failed -> NULL is passed\n");
		return FIFO_NULL;
	}

	// Check if the buf_size is positive
	if (buf_size <= 0) {
		printf("FIFO_Init failed -> FIFO Length smaller than or equal 0\n");
		return FIFO_INVALID_LENGTH;
	}

	// Assign base, head, and tail pointers to the first location of the buffer
	fifoBuf_Ptr->base = buf;
	fifoBuf_Ptr->head = buf;
	fifoBuf_Ptr->tail = buf;

	fifoBuf_Ptr->count = 0;        // Initialize items count to 0
	fifoBuf_Ptr->length = buf_size;  // Assign buffer size to FIFO length

	printf("FIFO_Init Passed\n");
	return FIFO_NO_ERROR;
}

/* Function to enqueue an item into the FIFO buffer.
 Parameters:
 fifoBuf_Ptr: Pointer to the FIFO buffer structure.
 item: The item to be enqueued.
 Returns:
 FIFO_Status indicating success or an error condition.
 */
FIFO_Status FIFO_Enqueue(FIFO_Buf_t *fifoBuf_Ptr, ITEM_TYPE item)
{
	// Check if the FIFO is NULL
	if (FIFO_Is_Null(fifoBuf_Ptr)) {
		printf("FIFO_Enqueue failed -> NULL is passed\n");
		return FIFO_NULL;
	}

	// Check if the FIFO is full
	if (FIFO_Is_Full(fifoBuf_Ptr)) {
		printf("FIFO_Enqueue failed -> FIFO FULL\n");
		return FIFO_FULL;
	}

	*(fifoBuf_Ptr->head) = item; // Insert the item at the address pointed by the head pointer
	fifoBuf_Ptr->count++;         // Increment items count

#ifndef CIRCULAR_QUEUE
    fifoBuf_Ptr->head++;  // Increment the pointer to point to the next location

#else  // Circular Queue
	if ((fifoBuf_Ptr->head + 1) == (fifoBuf_Ptr->base + fifoBuf_Ptr->length))
	{
		fifoBuf_Ptr->head = fifoBuf_Ptr->base; // Return pointer to the base address of the buffer to start over
	}
	else
		fifoBuf_Ptr->head++; // Increment the pointer to point to the next location
#endif

	return FIFO_NO_ERROR;
}

/* Function to dequeue an item from the FIFO buffer.
 Parameters:
 fifoBuf_Ptr: Pointer to the FIFO buffer structure.
 itemPtr: Pointer to store the dequeued item.
 Returns:
 FIFO_Status indicating success or an error condition.
 */
FIFO_Status FIFO_Dequeue(FIFO_Buf_t *fifoBuf_Ptr, ITEM_TYPE *itemPtr)
{
	// Check if the FIFO is NULL or if item pointer is uninitialized
	if (FIFO_Is_Null(fifoBuf_Ptr) || !itemPtr) {
		printf("FIFO_Dequeue failed -> NULL is passed\n");
		return FIFO_NULL;
	}

	// Check if the FIFO is empty
	if (FIFO_Is_Empty(fifoBuf_Ptr)) {
		printf("FIFO_Dequeue failed -> FIFO EMPTY\n");
		return FIFO_EMPTY;
	}

	*itemPtr = *(fifoBuf_Ptr->tail); // Get the item at the address pointed by the tail pointer
	fifoBuf_Ptr->count--;             // Decrement items count

#ifndef CIRCULAR_QUEUE

    fifoBuf_Ptr->tail++;  // Increment the tail pointer to point to the next location

#else  // Circular Queue
	if ((fifoBuf_Ptr->tail + 1) == (fifoBuf_Ptr->base + fifoBuf_Ptr->length))
	{
		fifoBuf_Ptr->tail = fifoBuf_Ptr->base; // Return pointer to the base address of the buffer to start over
	}
	else
		fifoBuf_Ptr->tail++; // Increment the tail pointer to point to the next location
#endif

	return FIFO_NO_ERROR;
}

/* Function to get the top item from the FIFO buffer without dequeuing.
 Parameters:
 fifoBuf_Ptr: Pointer to the FIFO buffer structure.
 topPtr: Pointer to store the top item.
 Returns:
 FIFO_Status indicating success or an error condition.
 */
FIFO_Status FIFO_Top(const FIFO_Buf_t *fifoBuf_Ptr, ITEM_TYPE *topPtr)
{
	// Check if the FIFO is NULL or if top pointer is uninitialized
	if (FIFO_Is_Null(fifoBuf_Ptr) || !topPtr) {
		printf("FIFO_Top failed -> NULL is passed\n");
		return FIFO_NULL;
	}

	// Check if the FIFO is empty
	if (FIFO_Is_Empty(fifoBuf_Ptr)) {
		printf("FIFO_Top failed -> FIFO EMPTY\n");
		return FIFO_EMPTY;
	}

	*topPtr = *(fifoBuf_Ptr->tail); // Get the item at the address pointed by the tail pointer

	return FIFO_NO_ERROR;
}

/* Function to check if the FIFO structure is invalid (NULL pointers).
 Parameters:
 fifoBuf_Ptr: Pointer to the FIFO buffer structure.
 Returns:
 TRUE if the FIFO structure is invalid, FALSE otherwise.
 */
boolean FIFO_Is_Null(const FIFO_Buf_t *fifoBuf_Ptr) {
	if (fifoBuf_Ptr == NULL || fifoBuf_Ptr->base == NULL
			|| fifoBuf_Ptr->head == NULL || fifoBuf_Ptr->tail == NULL)
		return TRUE;

	return FALSE;
}

/* Function to check if the FIFO buffer is empty.
 Parameters:
 fifoBuf_Ptr: Pointer to the FIFO buffer structure.
 Returns:
 TRUE if the FIFO buffer is empty, FALSE otherwise.
 Note:
  If you want to use this function, you have to use FIFO_Is_Null first
 */
boolean FIFO_Is_Empty(const FIFO_Buf_t *fifoBuf_Ptr)
{
	if (fifoBuf_Ptr->count == 0)
		return TRUE;

	return FALSE;
}

/* Function to check if the FIFO buffer is full.
 Parameters:
 	 fifoBuf_Ptr: Pointer to the FIFO buffer structure.
 Returns:
 	 TRUE if the FIFO buffer is full, FALSE otherwise.
 Note:
  	 If you want to use this function, you have to use FIFO_Is_Null first
 */
boolean FIFO_Is_Full(const FIFO_Buf_t *fifoBuf_Ptr)
{
	if (fifoBuf_Ptr->count == fifoBuf_Ptr->length)
		return TRUE;

	return FALSE;
}

/* Function to print the contents of the FIFO buffer.
 Parameters:
 fifoBuf_Ptr: Pointer to the FIFO buffer structure.
 */
void FIFO_Print(const FIFO_Buf_t *fifoBuf_Ptr)
{
	if (FIFO_Is_Null(fifoBuf_Ptr)) {
		printf("FIFO_Print failed -> NULL is passed\n");
		return;
	}

	// Check if the FIFO is empty
	if (FIFO_Is_Empty(fifoBuf_Ptr)) {
		printf("FIFO_Print failed -> FIFO EMPTY\n");
		return;
	}

	ITEM_TYPE *tempPtr = NULL;

	printf("-------- FIFO Print --------\n");

#ifndef CIRCULAR_QUEUE

    for (tempPtr = fifoBuf_Ptr->tail; tempPtr < fifoBuf_Ptr->head; tempPtr++)
        printf("%u\t", *tempPtr);

#else  // Circular Queue
	tempPtr = fifoBuf_Ptr->tail;
	while (tempPtr != fifoBuf_Ptr->head)
	{
		printf("%u <- ", *tempPtr);

		if ((tempPtr + 1) == (fifoBuf_Ptr->base + fifoBuf_Ptr->length))
			tempPtr = fifoBuf_Ptr->base; // Return pointer to the base address of the buffer to start over
		else
			tempPtr++;  // Increment tail pointer to point to the next location
	}
#endif

	printf("\nFIFO_Print Passed\n");
}

/* Function to clear the contents of the FIFO buffer.
 Parameters:
 fifoBuf_Ptr: Pointer to the FIFO buffer structure.
 Returns:
 FIFO_Status indicating success or an error condition.
 */
FIFO_Status FIFO_Clear(FIFO_Buf_t *fifoBuf_Ptr)
{
	if (FIFO_Is_Null(fifoBuf_Ptr)) {
		printf("FIFO_Clear failed -> NULL is passed\n");
		return FIFO_NULL;
	}

	// Check if the FIFO is empty
	if (FIFO_Is_Empty(fifoBuf_Ptr)) {
		printf("FIFO_Clear failed -> FIFO is already EMPTY\n");
		return FIFO_EMPTY;
	}

	fifoBuf_Ptr->head = fifoBuf_Ptr->base;
	fifoBuf_Ptr->tail = fifoBuf_Ptr->base;
	fifoBuf_Ptr->count = 0;

	printf("FIFO_Clear Passed\n");
	return FIFO_NO_ERROR;
}
