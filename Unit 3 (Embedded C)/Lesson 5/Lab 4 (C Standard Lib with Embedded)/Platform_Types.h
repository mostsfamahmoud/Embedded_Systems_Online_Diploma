/************************************
 * Platform_Types.h
 *
 * AUTOSAR Specification of Platform Types
 *
 * Created on: Aug 5, 2023
 *
 * Author: Mostafa Mahmoud
 ************************************/

#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_

/***********************************************************************************************
 *************************************** Symbol definitions **************************************
 ************************************************************************************************/
#ifndef GENERAL_TYPES
#define CPU_TYPE_8          8
#define CPU_TYPE_16         16
#define CPU_TYPE_32         32
#define CPU_TYPE_64         64
#define MSB_FIRST           0
#define LSB_FIRST           1
#define HIGH_BYTE_FIRST     0
#define LOW_BYTE_FIRST      1
#endif

/*
CPU_TYPE_8 – Indicating a 8 bit processor
CPU_TYPE_16 – Indicating a 16 bit processor
CPU_TYPE_32 – Indicating a 32 bit processor
CPU_TYPE_64 – Indicating a 64 bit processor
*/
#ifndef CPU_TYPE
#define CPU_TYPE          CPU_TYPE_32
#endif

/*
MSB_FIRST – The most significant bit is the first bit of the bit sequence.
LSB_FIRST – The least significant bit is the first bit of the bit sequence
*/
#ifndef CPU_BIT_ORDER
#define CPU_BIT_ORDER     LSB_FIRST
#endif

/*
HIGH_BYTE_FIRST – Within uint16, the high byte is located before the low byte. (Big Endian)
LOW_BYTE_FIRST – Within uint16, the low byte is located before the high byte. (Little Endian)
*/
#ifndef CPU_BYTE_ORDER
#define CPU_BYTE_ORDER     LOW_BYTE_FIRST
#endif

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef NULLPTR
#define NULLPTR  (VoidPtr)0
#endif

/***********************************************************************************************
 *************************************** Type definitions **************************************
 ************************************************************************************************/

typedef unsigned char            boolean;          // Range: 0..255 – 0x00..0xFF

typedef unsigned char            uint8;            // Range: 0..255 – 0x00..0xFF
typedef unsigned short           uint16;           // Range: 0..65535 – 0x0000..0xFFFF
typedef unsigned long            uint32;           // Range: 0..4294967295 – 0x00000000..0xFFFFFFFF
typedef unsigned long long       uint64;           // Range: 0..18446744073709551615 – 0x0000000000000000..0xFFFFFFFFFFFFFFFF

typedef signed char              sint8;            // Range: -128..+127 – 0x80..0x7F
typedef signed short             sint16;           // Range: -32768..+32767 – 0x8000..0x7FFF
typedef signed long              sint32;           // Range: -2147483648..+2147483647 – 0x80000000..0x7FFFFFFF
typedef signed long long         sint64;           // Range: -9223372036854775808..9223372036854775807 – 0x8000000000000000..0x7FFFFFFFFFFFFFFF

typedef float                    float32;          // Range: -3.4028235e+38 .. +3.4028235e+38
typedef double                   float64;          // Range: -1.7976931348623157e+308 .. +1.7976931348623157e+308

/* Optimized integer data types */
typedef unsigned char            uint8_least;
typedef unsigned short           uint16_least;
typedef unsigned long            uint32_least;

typedef signed char              sint8_least;
typedef signed short             sint16_least;
typedef signed long              sint32_least;

/* This standard AUTOSAR type shall be a void pointer
 * Note: This type shall be used for buffers that contain data returned to the caller
 */
typedef void*                    VoidPtr;

/* This standard AUTOSAR type shall be a void pointer to const.
 * Note: This type shall be used for buffers that are passed to the callee.
 */
typedef const void*              ConstVoidPtr;


#endif /* PLATFORM_TYPES_H_ */
