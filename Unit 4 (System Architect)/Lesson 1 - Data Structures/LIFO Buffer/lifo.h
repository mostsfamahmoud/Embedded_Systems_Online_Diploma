/*
 * lifo.h
 *
 * Created on: Aug 11, 2023
 * Author: Mostafa Mahmoud
 */

#ifndef LIFO_H_
#define LIFO_H_

#include "lifo_cfg.h"

/***********************************************
 *************** Type Definitions **************
 ***********************************************/

typedef struct {

	uint32 length;       /* The Max Length of the LIFO Buffer */
	uint32 count;        /* The total number of elements in the buffer */
	ITEM_TYPE* base;        /* Pointer to the base address of the buffer in memory */
	ITEM_TYPE* head;        /* Pointer to the current address inside the buffer */

}LIFO_Buf_t;

typedef enum{
	LIFO_NO_ERROR,
	LIFO_INVALID_LENGTH,
	LIFO_FULL,
	LIFO_EMPTY,
	LIFO_NULL          /* LIFO doesn't exist (invalid base address)*/
}LIFO_Status;

/***********************************************************
 *************** Function Declarations (APIs) **************
 ***********************************************************/

LIFO_Status LIFO_Init(LIFO_Buf_t* lifoBuf_Ptr, ITEM_TYPE* buf, sint32 buf_size);

LIFO_Status LIFO_Push(LIFO_Buf_t* lifoBuf_Ptr, ITEM_TYPE item);

LIFO_Status LIFO_Pop(LIFO_Buf_t* lifoBuf_Ptr, ITEM_TYPE* itemPtr);

LIFO_Status LIFO_Top(const LIFO_Buf_t* lifoBuf_Ptr, ITEM_TYPE* topPtr);

boolean LIFO_Is_Null(const LIFO_Buf_t* lifoBuf_Ptr);

boolean LIFO_Is_Full(const LIFO_Buf_t* lifoBuf_Ptr);

boolean LIFO_Is_Empty(const LIFO_Buf_t* lifoBuf_Ptr);

void LIFO_Print(const LIFO_Buf_t* lifoBuf_Ptr);

LIFO_Status LIFO_Clear(LIFO_Buf_t *lifoBuf_Ptr);



#endif /* LIFO_H_ */
