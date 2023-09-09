/* Unit3_Lesson3_Lab1
   Created By: Mostafa Mahmoud
   Date: 9/9/2023
   File: linkerScript.ld  
*/
ENTRY(reset) /* Define the entry point of the application */

/* List of the memory sections */
MEMORY
{
	Mem(rwx): ORIGIN = 0x00000000, LENGTH = 64M
}

SECTIONS
{
	. = 0x10000;  /* According to the specs */
	.startup . :
	{
		startup.o(.text)
	}> Mem
	.text :
	{
		*(.text)
	}> Mem
	.data :
	{
		*(.data)
	}> Mem
	.bss :
	{
		*(.bss) *(.COMMON)
	}> Mem
	.rodata :
	{
		*(.rodata)
	}> Mem

	. = . + 0x1000; /* 4KB of stack Memory */
	stack_top = . ;
}