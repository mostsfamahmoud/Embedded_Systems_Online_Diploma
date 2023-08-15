/*
 * main.c
 *
 *  Created on: Aug 11, 2023
 *      Author: mosta
 */

#include <stdio.h>
#include "lifo.h"

#define MAX_SIZE    100

ITEM_TYPE arr[MAX_SIZE];

int main(void)
{
	LIFO_Buf_t buffer1;

	ITEM_TYPE testArr[5] = {10,6,3,5,8};
	ITEM_TYPE value;

	/* Test LIFO Init function */
	if (LIFO_Init(&buffer1, arr, MAX_SIZE) == LIFO_NO_ERROR)
	{
		printf("\n");
		for(uint32 i = 0; i < 5; i++)
		{
			/* Test Push item */
			if (LIFO_Push(&buffer1, testArr[i]) == LIFO_NO_ERROR)
			{
				printf("%u pushed into LIFO\n",*(buffer1.head - 1));
			}
		}
		printf("\n");

		/* Test LIFO Print After Pushing into the LIFO */
		LIFO_Print(&buffer1);
		printf("\n");

		LIFO_Top(&buffer1, &value);
		printf("LIFO TOP value -> %u\n\n",value);

		for(uint32 i = 0; i < 5; i++)
		{
			/* Test Pop item */
			if (LIFO_Pop(&buffer1, &value) == LIFO_NO_ERROR)
			{
				printf("%u popped from LIFO\n", value);
			}
		}
		printf("\n");

		/* Test LIFO Print After Popping from the LIFO */
		LIFO_Print(&buffer1);
		printf("\n");

		for(uint32 i = 0; i < 5; i++)
		{
			/* Test Push item */
			if (LIFO_Push(&buffer1, (i + 1)) == LIFO_NO_ERROR)
			{
				printf("%u pushed into LIFO\n",*(buffer1.head - 1));
			}
		}
		printf("\n");

		/* Test LIFO Print After Pushing another time into the LIFO */
		LIFO_Print(&buffer1);
		printf("\n");

		/* Test LIFO Clear all items */
		LIFO_Clear(&buffer1);
		printf("\n");

		/* Test LIFO Print After Clearing the LIFO */
		LIFO_Print(&buffer1);
	}

	return 0;
}
