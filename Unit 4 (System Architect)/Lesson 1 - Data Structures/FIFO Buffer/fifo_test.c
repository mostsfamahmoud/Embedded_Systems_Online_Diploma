/*
 ============================================================================
 Name        : fifo_test.c
 Author      : Mostafa Mahmoud
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include "fifo.h"

#define MAX_SIZE    100

ITEM_TYPE arr[MAX_SIZE];

int main(void)
{
	FIFO_Buf_t buffer1;

	ITEM_TYPE testArr[5] = {3,6,9,5,7};
	ITEM_TYPE value;

	/* Test FIFO Init function */
	if (FIFO_Init(&buffer1, arr, MAX_SIZE) == FIFO_NO_ERROR)
	{
		printf("\n");
		for(uint32 i = 0; i < 5; i++)
		{
			/* Test Enqueue item */
			if (FIFO_Enqueue(&buffer1, testArr[i]) == FIFO_NO_ERROR)
			{
				printf("%u enqueued into FIFO\n",*(buffer1.head - 1));
			}
		}
		printf("\n");

		/* Test FIFO Print After inserting into the FIFO */
		FIFO_Print(&buffer1);
		printf("\n");

		FIFO_Top(&buffer1, &value);
		printf("FIFO TOP value -> %u\n\n",value);

		for(uint32 i = 0; i < 5; i++)
		{
			/* Test Dequeue item */
			if (FIFO_Dequeue(&buffer1, &value) == FIFO_NO_ERROR)
			{
				printf("%u dequeued from FIFO\n", value);
			}
		}
		printf("\n");

		/* Test FIFO Print After removing from the FIFO */
		FIFO_Print(&buffer1);
		printf("\n");

		for(uint32 i = 0; i < 5; i++)
		{
			/* Test Enqueue item */
			if (FIFO_Enqueue(&buffer1, (i + 1)) == FIFO_NO_ERROR)
			{
				printf("%u enqueued into FIFO\n",*(buffer1.head - 1));
			}
		}
		printf("\n");

		/* Test FIFO Print After inserting another time into the FIFO */
		FIFO_Print(&buffer1);
		printf("\n");

		/* Test FIFO Clear all items */
		FIFO_Clear(&buffer1);
		printf("\n");

		/* Test FIFO Print After Clearing the FIFO */
		FIFO_Print(&buffer1);
	}

	return 0;
}

