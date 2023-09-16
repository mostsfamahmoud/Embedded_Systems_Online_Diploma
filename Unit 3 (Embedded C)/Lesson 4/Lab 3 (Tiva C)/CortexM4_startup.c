/********************************************************
 * CortexM4_startup.c
 *
 * C Startup Code for ARM Cortex M3
 *
 * Created on: Sep 14, 2023
 *
 * Author: Mostafa Mahmoud
 ********************************************************/

#include "Platform_Types.h"

 /************************** External Symbols ****************************/

extern int main(void); /* extern Symbol to main function */


/* Note:
Symbols are npt treated as variables in C 
As they point to an address in memory but don't have space for themselves in memory like variables
To access them use & to get the address pointed by them 
*/
  
extern uint32 _E_Text;
extern uint32 _S_Data;
extern uint32 _E_Data;
extern uint32 _S_Bss;
extern uint32 _E_Bss;

/******************* Interrupt Handler Declarations ******************/

void Reset_Handler(void);

// Weak default handler
void Default_Handler(void) __attribute__((weak));

// Individual interrupt handlers with weak aliases to Default_Handler
void NMI_Handler(void) __attribute__((weak, alias("Default_Handler")));
void HardFault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void MemManage_Handler(void) __attribute__((weak, alias("Default_Handler")));
void BusFault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void UsageFault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void SVC_Handler(void) __attribute__((weak, alias("Default_Handler")));
void DebugMon_Handler(void) __attribute__((weak, alias("Default_Handler")));
void PendSV_Handler(void) __attribute__((weak, alias("Default_Handler")));
void SysTick_Handler(void) __attribute__((weak, alias("Default_Handler")));
void WWDG_Handler(void) __attribute__((weak, alias("Default_Handler")));
void PVD_Handler(void) __attribute__((weak, alias("Default_Handler")));
void Tamper_Handler(void) __attribute__((weak, alias("Default_Handler")));
void RTC_Handler(void) __attribute__((weak, alias("Default_Handler")));
void Flash_Handler(void) __attribute__((weak, alias("Default_Handler")));
void RCC_Handler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI0_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI2_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI3_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI4_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel2_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel3_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel4_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel5_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel6_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel7_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));

// Add more interrupt handlers following the same pattern if needed


/* Reserve 4KB for stack Memory 
   stack_top is an uninitialized array stored inside .bss section
   static -> to make it unaccessable by other files (Protection)
*/
static uint32 stack_top[1024];

/* g_ptr2Func_Vectors -> Global array of const pointers to functions that takes nothing and returns void  */
void (* const g_ptr2Func_Vectors[])() __attribute__((section(".vectors"))) = {

    (void (*)())  ((uint32)stack_top + sizeof(stack_top)),
    &Reset_Handler,         // -3 Reset
    &NMI_Handler,           // -2 NMI
    &HardFault_Handler,     // -1 HardFault
    &MemManage_Handler,     // 0 Memory Management
    &BusFault_Handler,      // 1 BusFault
    &UsageFault_Handler,    // 2 UsageFault
    NULLPTR,                //   Reserved
    NULLPTR,                //   Reserved
    NULLPTR,                //   Reserved
    NULLPTR,                //   Reserved  
    &SVC_Handler,           // 3 SVCall
    &DebugMon_Handler,      // 4 Debug Monitor
    NULLPTR,                //   Reserved  
    &PendSV_Handler,        // 5 PendSV
    &SysTick_Handler,       // 6 SysTick
    &WWDG_Handler,          // 7 WWDG (Window WatchDog)
    &PVD_Handler,			      // 8 PVD through EXTI Line detection interrupt
    &Tamper_Handler,		    // 9 Tamper interrupt
    &RTC_Handler,			      // 10 RTC global interrupt
    &Flash_Handler,		      // 11 Flash global interrupt
    &RCC_Handler,			      // 12 RCC global interrupt

    // External Interrupts
    &EXTI0_IRQHandler,       // 13 External Line 0 Interrupt
    &EXTI1_IRQHandler,       // 14 External Line 1 Interrupt
    &EXTI2_IRQHandler,       // 15 External Line 2 Interrupt
    &EXTI3_IRQHandler,       // 16 External Line 3 Interrupt
    &EXTI4_IRQHandler,       // 17 External Line 4 Interrupt

    // DMA1 Interrupts
    &DMA1_Channel1_IRQHandler, // 18 DMA1 Channel 1 global Interrupt
    &DMA1_Channel2_IRQHandler, // 19 DMA1 Channel 2 global Interrupt
    &DMA1_Channel3_IRQHandler, // 20 DMA1 Channel 3 global Interrupt
    &DMA1_Channel4_IRQHandler, // 21 DMA1 Channel 4 global Interrupt
    &DMA1_Channel5_IRQHandler, // 22 DMA1 Channel 5 global Interrupt
    &DMA1_Channel6_IRQHandler, // 23 DMA1 Channel 6 global Interrupt
    &DMA1_Channel7_IRQHandler, // 24 DMA1 Channel 7 global Interrupt
};


/******************* Interrupt Handler Definitions ******************/

void Reset_Handler(void)
{
    uint32 i;
    uint8* pSrc = NULLPTR;
    uint8* pDest = NULLPTR;

    /* Move the .data section at runtime from Flash to SRAM */

    uint32 Data_Size = (uint8*)(&_E_Data) - (uint8*)(&_S_Data);
    pSrc = (uint8*)(&_E_Text);
    pDest = (uint8*)(&_S_Data);

    for (i = 0; i < Data_Size; i++, pSrc++, pDest++)
    {
        *(uint8*)pDest = *(uint8*)pSrc;
    }

    /* Reserve space in SRAM for .bss section at runtime and initialize it with ZEROs */

    uint32 Bss_Size = (uint8*)&_E_Bss - (uint8*)&_S_Bss;
    pDest = (uint8*)(&_S_Bss);

    for (i = 0; i < Bss_Size; i++, pDest++)
    {
        *(uint8*)pDest = (uint8)0;
    }

    /* Jump to main() */
    main();
}

void Default_Handler(void)
{
    Reset_Handler();
}

