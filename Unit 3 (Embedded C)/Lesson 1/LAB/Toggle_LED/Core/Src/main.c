/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/

#include "Platform_Types.h"

#define RCC_BASE       0x40021000
#define PORTA_BASE     0x40010800

#define RCC_APB2ENR     *((volatile uint32*)(RCC_BASE + 0x18))
#define GPIOA_CRH       *((volatile uint32*)(PORTA_BASE + 0x04))
#define GPIOA_ODR       *((volatile uint32*)(PORTA_BASE + 0x0C))

/*********** COMMON_MACROS ***********/
#define SET_BIT(REG, Bit_Number)         REG |= (1<<Bit_Number)
#define CLEAR_BIT(REG, Bit_Number)       REG &= ~(1<<Bit_Number)
#define TOGGLE_BIT(REG, Bit_Number)      REG ^= (1<<Bit_Number)

#define RCC_IOPAEN         2
#define PIN_13             13
/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
	SET_BIT(RCC_APB2ENR,RCC_IOPAEN);
	GPIOA_CRH &= 0xFF0FFFFF;           // Clear bits from bit20 to bit23
	GPIOA_CRH |= 0x00200000;           // Set bits from bit20 to bit23 with value 2

	CLEAR_BIT(GPIOA_ODR,PIN_13);       // Initially LED is OFF
	while(1)
	{
		for(uint32 i = 0; i < 5000; i++);
		TOGGLE_BIT(GPIOA_ODR,PIN_13);   // Toggle LED
		for(uint32 i = 0; i < 5000; i++);
	}
}


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
