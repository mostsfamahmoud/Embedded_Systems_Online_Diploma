/************************************
 * Platform_Types.h
 *
 * AUTOSAR Specification of Platform Types
 *
 * Created on: Aug 5, 2023
 *
 * Author: Mostafa Mahmoud
 ************************************/

 /*********************** Includes **************************/

#include "Platform_Types.h"

/********************* Required Registers **************************/
#define RCC_BASE   0x40021000
#define PORTA_BASE 0x40010800

#define RCC_APB2ENR *((volatile uint32 *)(RCC_BASE + 0x18))
#define GPIOA_CRH   *((volatile uint32 *)(PORTA_BASE + 0x04))
#define GPIOA_ODR   *((volatile uint32 *)(PORTA_BASE + 0x0C))

/********************* COMMON_MACROS ****************************/
#define SET_BIT(REG, Bit_Number) REG |= (1 << Bit_Number)
#define CLEAR_BIT(REG, Bit_Number) REG &= ~(1 << Bit_Number)
#define TOGGLE_BIT(REG, Bit_Number) REG ^= (1 << Bit_Number)

/*********************** Definitions ****************************/
#define RCC_IOPAEN 2
#define PIN_13 13

typedef union{
  volatile uint32 all_fields;

  struct{
    volatile uint32 reserved : 13;
    volatile uint32 P_13     : 1;
  } Pin;

} R_ODR_t;

/********************* Global Variables **************************/

volatile R_ODR_t* R_ODR = (volatile R_ODR_t*)(PORTA_BASE + 0x0C); // Stored in .data Section
uint8 g_variables[3] = {1, 2, 3};      
uint8 const constVariables[3] = {1, 2, 3}; // Stored in .rodata Section
uint8 bss_Variables[3];                    // Stored in .bss Section

/********************* Interrupt Handler Implementation **************************/

extern void NMI_Handler(void)
{
    /* User Implementation */
}

extern void SysTick_Handler(void)
{
    /* User Implementation */
}

/********************************************************
 * @brief  The application entry point.
 * @retval int
 ********************************************************/
int main(void)
{
  SET_BIT(RCC_APB2ENR, RCC_IOPAEN);
  GPIOA_CRH &= 0xFF0FFFFF; // Clear bits from bit20 to bit23
  GPIOA_CRH |= 0x00200000; // Set bits from bit20 to bit23 with value 2
  uint32 i;

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
