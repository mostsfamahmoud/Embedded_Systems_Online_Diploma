#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/* Macro to Swap 2 Bytes */
#define Swap2Bytes(data)          ( ((data & 0x00FF) << 8) | ((data & 0xFF00) >> 8) )

/* Macro to Swap 2 Nibbles */
#define Swap2Nibbles(data)        ( ((data & 0x0F) << 4) | ((data & 0xF0) >> 4) )

/* Macro to Convert One Endian to Another */
#define Swap_Endian_32bit(data)   ( ((data & 0xFF) << 24) | ((data & 0xFF00) << 8) | ((data & 0xFF0000) >> 8) | ((data & 0xFF000000) >> 24) )

int main()
{
    /* Test Swap 2 bytes */
    uint16_t value_16bit = 0xABCD;
    printf("\nValue before: %x\n", value_16bit);
    value_16bit = Swap2Bytes(value_16bit);
    printf("Value After : %x\n", value_16bit);

    /* Test Swap 2 Nibbles */
    uint8_t value_8bit = 0xAB;
    printf("\nValue before: %x\n", value_8bit);
    value_8bit = Swap2Nibbles(value_8bit);
    printf("Value After : %x\n", value_8bit);

    /* Test Convert Endian */
    uint32_t littleEndianValue = 0xABCD1234;
    printf("\nValue in Little Endian: %x\n", littleEndianValue);
    uint32_t bigEndianValue = Swap_Endian_32bit(littleEndianValue);
    printf("Value in Big Endian: %x\n", bigEndianValue);

    return 0;
}