/*******************************************************************************
 * @project        : Lab1_TogglePin
 * @file           : main.c
 * @author         : Mostafa Mahmoud
 * @brief          : Main program body
 *******************************************************************************/

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

/*********************** Includes **************************/
#include "Platform_Types.h"

/********************* Required Registers **************************/
#define RCC_BASE       0x40021000
#define PORTA_BASE     0x40010800

#define RCC_APB2ENR    *((volatile uint32 *)(RCC_BASE + 0x18))   // APB2 peripheral clock enable register (RCC_APB2ENR)
#define GPIOA_CRH      *((volatile uint32 *)(PORTA_BASE + 0x04)) // Port configuration register high (GPIOx_CRH) (x=A..G)
#define GPIOA_ODR      *((volatile uint32 *)(PORTA_BASE + 0x0C)) // Port output data register (GPIOx_ODR) (x=A..G)

/********************* COMMON_MACROS ****************************/
#define SET_BIT(REG, Bit_Number)    REG |= (1 << Bit_Number)
#define CLEAR_BIT(REG, Bit_Number)  REG &= ~(1 << Bit_Number)
#define TOGGLE_BIT(REG, Bit_Number) REG ^= (1 << Bit_Number)

/*********************** Definitions ****************************/
#define RCC_IOPAEN 2
#define PIN_13     13

typedef union{
	volatile uint32 all_fields;

	struct{
		volatile uint32 P_0      : 1;
		volatile uint32 P_1      : 1;
		volatile uint32 P_2      : 1;
		volatile uint32 P_3      : 1;
		volatile uint32 P_4      : 1;
		volatile uint32 P_5      : 1;
		volatile uint32 P_6      : 1;
		volatile uint32 P_7      : 1;
		volatile uint32 P_8      : 1;
		volatile uint32 P_9      : 1;
		volatile uint32 P_10     : 1;
		volatile uint32 P_11     : 1;
		volatile uint32 P_12     : 1;
		volatile uint32 P_13     : 1;
		volatile uint32 P_14     : 1;
		volatile uint32 P_15     : 1;
		volatile uint32 reserved : 16;
	} Pin;

} R_ODR_t;

/********************* Global Variables **************************/
volatile R_ODR_t* R_ODR = (volatile R_ODR_t*)(PORTA_BASE + 0x0C); // Stored in .data Section

/********************************************************
 * @brief  The application entry point.
 * @retval int
 ********************************************************/
int main(void)
{
	volatile uint32 i; // Loop Iterator

	SET_BIT(RCC_APB2ENR, RCC_IOPAEN);
	GPIOA_CRH &= 0xFF0FFFFF; // Clear bits from bit20 to bit23
	GPIOA_CRH |= 0x00200000; // Set bits from bit20 to bit23 with value 2

	while(1)
	{
		R_ODR->Pin.P_13 = 1;           /* Set Pin 13 */
		for (i = 0; i < 5000; i++);
		R_ODR->Pin.P_13 = 0;           /* Clear Pin 13 */
		for (i = 0; i < 5000; i++);
	}

	//CLEAR_BIT(GPIOA_ODR, PIN_13); // Initially LED is OFF
	//while (1)
	//{
	//  for (i = 0; i < 5000; i++);
	//  TOGGLE_BIT(GPIOA_ODR, PIN_13); // Toggle LED
	//  for (i = 0; i < 5000; i++);
	//}

	return 0;
}
