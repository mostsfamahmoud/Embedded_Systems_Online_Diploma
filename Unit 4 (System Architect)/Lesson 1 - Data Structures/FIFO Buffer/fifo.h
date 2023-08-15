/*
 * This is the header file "fifo.h" for a FIFO (First-In-First-Out) buffer implementation.
 *
 * Created on: Aug 11, 2023
 * Author: Mostafa Mahmoud
 */

#ifndef FIFO_H_
#define FIFO_H_

#include "fifo_cfg.h"

/***********************************************
 *************** Type Definitions **************
 ***********************************************/

#define CIRCULAR_QUEUE

typedef struct {

	uint32 length; /* The Max Length of the FIFO Buffer */
	uint32 count; /* The total number of elements in the buffer */
	ITEM_TYPE *base; /* Pointer to the base address of the buffer in memory */
	ITEM_TYPE *head; /* Pointer to the next address inside the buffer to be written (Write Pointer) */
	ITEM_TYPE *tail; /* Pointer to the next address inside the buffer to be read (Read Pointer) */

} FIFO_Buf_t;

typedef enum {
	FIFO_NO_ERROR,
	FIFO_INVALID_LENGTH,
	FIFO_FULL,
	FIFO_EMPTY,
	FIFO_NULL    /* FIFO doesn't exist */
} FIFO_Status;

/***********************************************************
 *************** Function Declarations (APIs) **************
 ***********************************************************/

/* Function to initialize a FIFO buffer.
 Parameters:
 fifoBuf_Ptr: Pointer to the FIFO buffer structure.
 buf: Pointer to the memory buffer for FIFO storage.
 buf_size: Size of the memory buffer.
 Returns:
 FIFO_Status indicating success or an error condition.
 */
FIFO_Status FIFO_Init(FIFO_Buf_t *fifoBuf_Ptr, ITEM_TYPE *buf, sint32 buf_size);

/* Function to enqueue an item into the FIFO buffer.
 Parameters:
 fifoBuf_Ptr: Pointer to the FIFO buffer structure.
 item: The item to be enqueued.
 Returns:
 FIFO_Status indicating success or an error condition.
 */
FIFO_Status FIFO_Enqueue(FIFO_Buf_t *fifoBuf_Ptr, ITEM_TYPE item);

/* Function to dequeue an item from the FIFO buffer.
 Parameters:
 fifoBuf_Ptr: Pointer to the FIFO buffer structure.
 itemPtr: Pointer to store the dequeued item.
 Returns:
 FIFO_Status indicating success or an error condition.
 */
FIFO_Status FIFO_Dequeue(FIFO_Buf_t *fifoBuf_Ptr, ITEM_TYPE *itemPtr);

/* Function to get the top item from the FIFO buffer without dequeuing.
 Parameters:
 fifoBuf_Ptr: Pointer to the FIFO buffer structure.
 topPtr: Pointer to store the top item.
 Returns:
 FIFO_Status indicating success or an error condition.
 */
FIFO_Status FIFO_Top(const FIFO_Buf_t *fifoBuf_Ptr, ITEM_TYPE *topPtr);

/* Function to check if the FIFO structure is invalid (NULL pointers).
 Parameters:
 fifoBuf_Ptr: Pointer to the FIFO buffer structure.
 Returns:
 TRUE if the FIFO structure is invalid, FALSE otherwise.
 */
boolean FIFO_Is_Null(const FIFO_Buf_t *fifoBuf_Ptr);

boolean FIFO_Is_Full(const FIFO_Buf_t *fifoBuf_Ptr);

boolean FIFO_Is_Empty(const FIFO_Buf_t *fifoBuf_Ptr);

/* Function to print the contents of the FIFO buffer.
 Parameters:
 fifoBuf_Ptr: Pointer to the FIFO buffer structure.
 */
void FIFO_Print(const FIFO_Buf_t *fifoBuf_Ptr);

/* Function to clear the contents of the FIFO buffer.
 Parameters:
 fifoBuf_Ptr: Pointer to the FIFO buffer structure.
 Returns:
 FIFO_Status indicating success or an error condition.
 */
FIFO_Status FIFO_Clear(FIFO_Buf_t *fifoBuf_Ptr);

#endif /* FIFO_H_ */
