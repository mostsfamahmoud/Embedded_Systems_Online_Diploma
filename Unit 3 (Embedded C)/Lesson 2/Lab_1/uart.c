#include "uart.h"

/* UART Register */
#define UART0DR     *((volatile unsigned int* const)((unsigned int*)0x101f1000))

void UART_sendString(unsigned char* P_tx_string)
{
    /* Loop until the end of the string */
    while(*P_tx_string != '\0')
    {
        UART0DR = (unsigned int)(*P_tx_string);   /* Transmit char */
        P_tx_string++;                            /* Move to the next char */
    }    
}