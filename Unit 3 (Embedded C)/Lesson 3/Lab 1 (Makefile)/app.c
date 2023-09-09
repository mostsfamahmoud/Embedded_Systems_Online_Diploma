#include "uart.h"

// Note: 100 Bytes in decimal -> 64 in hexa

// Stored inside the .data section
unsigned char string_buffer1[100] = "Learn-in-depth:<Mostafa Mahmoud>";

// Stored inside the .rodata section
unsigned char const string_buffer2[100] = "Learn-in-depth:<Mostafa Mahmoud>";

int main(void)
{
    UART_sendString(string_buffer1);

    return 0;
}