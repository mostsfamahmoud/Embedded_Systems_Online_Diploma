/*******************************************************************************
 * @project        : Lab3_ClockConfigurations
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

/* Define memory-mapped base addresses for RCC (Reset and Clock Control) and Port A */
#define RCC_BASE       0x40021000
#define PORTA_BASE     0x40010800

// RCC Registers
#define RCC_CR         *((volatile uint32 *)(RCC_BASE + 0x00))   // Clock control register
#define RCC_CFGR       *((volatile uint32 *)(RCC_BASE + 0x04))   // Clock configuration register
#define RCC_APB2ENR    *((volatile uint32 *)(RCC_BASE + 0x18))   // APB2 peripheral clock enable register (RCC_APB2ENR)

// GPIOx Registers
#define GPIOA_CRH      *((volatile uint32 *)(PORTA_BASE + 0x04)) // Port configuration register high (GPIOx_CRH) (x=A..G)
#define GPIOA_ODR      *((volatile uint32 *)(PORTA_BASE + 0x0C)) // Port output data register (GPIOx_ODR) (x=A..G)

/********************* COMMON_MACROS ****************************/

/* Macros for bit manipulation in registers */
#define SET_BIT(REG, Bit_Number)    REG |= (1 << Bit_Number)
#define CLEAR_BIT(REG, Bit_Number)  REG &= ~(1 << Bit_Number)
#define TOGGLE_BIT(REG, Bit_Number) REG ^= (1 << Bit_Number)

/*********************** Definitions ****************************/
#define RCC_IOPAEN 2
#define PIN_13     13

/* Union for easy access to individual GPIO pins */
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
		volatile uint32          : 16; // Reserved
	} Pin;

} R_ODR_t;

/* Union for easy access to RCC_CFGR bit fields */
typedef union{
	volatile uint32 all_fields;

	struct{
		volatile uint32 SW       : 2;  // System clock switch
		volatile uint32 SWS      : 2;  // System clock switch status
		volatile uint32 HPRE     : 4;  // AHB prescaler
		volatile uint32 PPRE1    : 3;  // APB low-speed prescaler (APB1)
		volatile uint32 PPRE2    : 3;  // APB high-speed prescaler (APB2)
		volatile uint32 ADCPRE   : 2;  // ADC prescaler
		volatile uint32 PLLSRC   : 1;  // PLL entry clock source
		volatile uint32 PLLXTPRE : 1;  // HSE divider for PLL entry
		volatile uint32 PLLMUL   : 4;  // PLL multiplication factor
		volatile uint32 USBPRE   : 1;  // USB prescaler
		volatile uint32          : 1;  // Reserved
		volatile uint32 MCO      : 3;  // Microcontroller clock output
	} field;

} R_RCC_CFGR_t;

/* Union for easy access to RCC_CR bit fields */
typedef union{
	volatile uint32 all_fields;

	struct{
		volatile uint32 HSION    : 1;  // Internal high-speed clock enable
		volatile uint32 HSIRDY   : 1;  // Internal high-speed clock ready flag
		volatile uint32          : 1;  // Reserved
		volatile uint32 HSITRIM  : 5;  // Internal high-speed clock trimming
		volatile uint32 HSICAL   : 8;  // Internal high-speed clock calibration
		volatile uint32 HSEON    : 1;  // HSE clock enable
		volatile uint32 HSERDY   : 1;  // External high-speed clock ready flag
		volatile uint32 HSEBYP   : 1;  // External high-speed clock bypass
		volatile uint32 CSSON    : 1;  // Clock security system enable
		volatile uint32          : 4;  // Reserved
		volatile uint32 PLLON    : 1;  // PLL enable
		volatile uint32 PLLRDY   : 1;  // PLL clock ready flag
	} field;

} R_RCC_CR_t;

/********************* Global Variables **************************/
volatile R_ODR_t* R_ODR = (volatile R_ODR_t*)(PORTA_BASE + 0x0C);

volatile R_RCC_CR_t* R_RCC_CR = (volatile R_RCC_CR_t*)(RCC_BASE + 0x00);

volatile R_RCC_CFGR_t* R_RCC_CFGR = (volatile R_RCC_CFGR_t*)(RCC_BASE + 0x04);

/********************* Function Definitions **************************/


/* Lab Requirements:
 * Configure Board to run with the Following rates:
 * APB1 Bus frequency 16MHZ
 * APB2 Bus frequency 16MHZ
 * AHB frequency 32 MHZ
 * SysClk 32 MHZ
 * Use only internal HSI_RC
 */

/* Function to configure clock settings as per lab requirements */
void CLK_setConfig()
{
	/* Bit 16 PLLSRC: PLL entry clock source
	Set and cleared by software to select PLL clock source. This bit can be written only when
	PLL is disabled.
	0: HSI oscillator clock / 2 selected as PLL input clock
	1: HSE oscillator clock selected as PLL input clock */
	//RCC_CFGR |= 0b0 << 16;          // Method 1
	R_RCC_CFGR->field.PLLSRC = 0b0;

	/* Bits 21:18 PLLMUL: PLL multiplication factor
	These bits are written by software to define the PLL multiplication factor. These bits can be
	written only when PLL is disabled.
	Caution: The PLL output frequency must not exceed 72 MHz.
	0000: PLL input clock x 2
	0001: PLL input clock x 3
	0010: PLL input clock x 4
	0011: PLL input clock x 5
	0100: PLL input clock x 6
	0101: PLL input clock x 7
	0110: PLL input clock x 8 (Required to make PLLClk 32 MHZ therefore SYSCLK becomes 32 MHZ)
	 */
	//RCC_CFGR |= 0b0110 << 18;          // Method 1
	R_RCC_CFGR->field.PLLMUL = 0b0110;

	/* Bit 24 PLLON: PLL enable
	Set and cleared by software to enable PLL.
	Cleared by hardware when entering Stop or Standby mode. This bit can not be reset if the
	PLL clock is used as system clock or is selected to become the system clock.
	0: PLL OFF
	1: PLL ON */
	//RCC_CR |= 0b1 << 24;          // Method 1
	R_RCC_CR->field.PLLON = 0b1;

	/* Bits 1:0 SW: System clock switch
	Set and cleared by software to select SYSCLK source.
	Set by hardware to force HSI selection when leaving Stop and Standby mode or in case of
	failure of the HSE oscillator used directly or indirectly as system clock (if the Clock Security System is enabled).
	00: HSI selected as system clock
	01: HSE selected as system clock
	10: PLL selected as system clock (Required in this Lab)
	11: not allowed */
	//RCC_CFGR |= 0b10 << 0;          // Method 1
	R_RCC_CFGR->field.SW = 0b10;      // Method 2

	/* Bits 7:4 HPRE: AHB prescaler
	Set and cleared by software to control the division factor of the AHB clock.
	0xxx: SYSCLK not divided (Required to make AHB frequency 32 MHZ as SYSCLK)
	1000: SYSCLK divided by 2
	1001: SYSCLK divided by 4
	1010: SYSCLK divided by 8
	1011: SYSCLK divided by 16
	1100: SYSCLK divided by 64
	1101: SYSCLK divided by 128
	1110: SYSCLK divided by 256
	1111: SYSCLK divided by 512 */
	//RCC_CFGR |= 0b0000 << 4;          // Method 1
	R_RCC_CFGR->field.HPRE = 0b0000;    // Method 2

	/* Bits 10:8 PPRE1: APB low-speed prescaler (APB1)
	Set and cleared by software to control the division factor of the APB low-speed clock
	(PCLK1).
	Warning: the software has to set correctly these bits to not exceed 36 MHz on this domain.
	0xx: HCLK not divided
	100: HCLK divided by 2  (Required to make APB1 Bus frequency 16 MHZ)
	101: HCLK divided by 4
	110: HCLK divided by 8
	111: HCLK divided by 16 */
	//RCC_CFGR |= 0b100 << 8;           // Method 1
	R_RCC_CFGR->field.PPRE1 = 0b100;    // Method 2

	/* Bits 13:11 PPRE2: APB high-speed prescaler (APB2)
	Set and cleared by software to control the division factor of the APB high-speed clock
	(PCLK2).
	0xx: HCLK not divided
	100: HCLK divided by 2  (Required to make APB2 Bus frequency 16 MHZ)
	101: HCLK divided by 4
	110: HCLK divided by 8
	111: HCLK divided by 16 */
	//RCC_CFGR |= 0b101 << 11;          // Method 1
	R_RCC_CFGR->field.PPRE2 = 0b100;    // Method 2
}

/********************************************************
 * @brief  The application entry point.
 * @retval int
 ********************************************************/
int main(void)
{
	volatile uint32 i; // Loop Iterator

	/* Configure clock settings */
	CLK_setConfig();

	/* Enable clock for GPIOA (PORTA) */
	SET_BIT(RCC_APB2ENR, RCC_IOPAEN);

	/* Configure Pin 13 of GPIOA as an output (mode = 2) */
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
