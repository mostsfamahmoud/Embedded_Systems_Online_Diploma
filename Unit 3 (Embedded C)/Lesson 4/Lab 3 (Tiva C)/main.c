/************************************
 * Platform_Types.h
 *
 * AUTOSAR Specification of Platform Types
 *
 * Created on: Sep 14, 2023
 *
 * Author: Mostafa Mahmoud
 ************************************/

 /*********************** Includes **************************/

#include "Platform_Types.h"

/********************* Required Registers **************************/
#define SYSCTL_BASE   0x400FE000
#define GPIOF_BASE    0x40025000

#define SYSCTL_RCGC2_R      (*((volatile uint32 *)(SYSCTL_BASE + 0x108)))
#define GPIO_PORTF_DATA_R   (*((volatile uint32 *)(GPIOF_BASE + 0x3FC)))
#define GPIO_PORTF_DIR_R    (*((volatile uint32 *)(GPIOF_BASE + 0x400)))
#define GPIO_PORTF_DEN_R    (*((volatile uint32 *)(GPIOF_BASE + 0x51C)))

/********************* COMMON_MACROS ****************************/
#define SET_BIT(REG, Bit_Number)    REG |= (1 << Bit_Number)
#define CLEAR_BIT(REG, Bit_Number)  REG &= ~(1 << Bit_Number)
#define TOGGLE_BIT(REG, Bit_Number) REG ^= (1 << Bit_Number)

/*********************** Definitions ****************************/
#define PIN_3      3

/********************************************************
 * @brief  The application entry point.
 * @retval int
 ********************************************************/
int main(void)
{
	volatile uint32 delayCount;  /* To disable compiler optimization */

	SYSCTL_RCGC2_R = 0x20;       /* Enable GPIO PORTF */
    
    /* Delay to make sure that GPIOF is Up and Running */
	for (delayCount = 0; delayCount < 200; delayCount++);

	SET_BIT(GPIO_PORTF_DIR_R, PIN_3);  /* Set Pin3_PortF as Output pin */
	SET_BIT(GPIO_PORTF_DEN_R, PIN_3);  /* Enable Pin3_PortF as Digital I/O */

	CLEAR_BIT(GPIO_PORTF_DATA_R, PIN_3);  /* Initially Turn the LED Off AT PF3 */

	while(1)
	{
		for (delayCount = 0; delayCount < 20000; delayCount++);
		TOGGLE_BIT(GPIO_PORTF_DATA_R, PIN_3);                   /* Toggle the LED at PF3 */
		for (delayCount = 0; delayCount < 20000; delayCount++);
	}

	return 0;
}
