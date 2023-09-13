/*************************************************************************/
/* Author        : Mostafa Mahmoud                                    	  */
/* File          : Startup.s for ARM Cortex M3				                              */
/* Date          : Sep 10, 2023                                           */
/* GitHub        : https://github.com/mostsfamahmoud            		  */
/*************************************************************************/

/* Note: SRAM Starts at address 0x20000000 */

.section .vectors

.word 0x20001000           // Stack Top address
.word _reset               // 1. Reset
.word _Vector_Handler      // 2. NMI Handler
.word _Vector_Handler      // 3. HardFault Handler
.word _Vector_Handler      // 4. MemManage Handler
.word _Vector_Handler      // 5. BusFault Handler
.word _Vector_Handler      // 6. UsageFault Handler
.word _Vector_Handler      // 7. Reserved
.word _Vector_Handler      // 8. Reserved
.word _Vector_Handler      // 9. Reserved
.word _Vector_Handler      // 10. Reserved
.word _Vector_Handler      // 11. SVCall
.word _Vector_Handler      // 12. Debug Monitor
.word _Vector_Handler      // 13. Reserved
.word _Vector_Handler      // 14. PendSV
.word _Vector_Handler      // 15. SysTick
.word _Vector_Handler      // 16. IRQ0
.word _Vector_Handler      // 17. IRQ1
.word _Vector_Handler      // 18. IRQ2

                           /* On to IRQ67 */

.section .text

_reset:
    bl main
    b .
    
.thumb_func      /* To enable thumb instructions */

_Vector_Handler:
    b _reset