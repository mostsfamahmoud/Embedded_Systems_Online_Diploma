/* Unit3_Lesson3_Lab2
   Created By: Mostafa Mahmoud
   Date: 17/9/2023
   File: linkerScript.ld  
*/

/* List of the memory sections */
MEMORY
{
	flash(rx): ORIGIN = 0x08000000, LENGTH = 128K
    sram(rwx): ORIGIN = 0x20000000, LENGTH = 20K
}

SECTIONS
{
	.text :
	{
        *(.vectors*)
		*(.text*)
        *(.rodata)
		_E_Text = . ;

	}> flash
    
	.data :
	{
		_S_Data = . ;
		*(.data)
		*(.data.*)
		_E_Data = . ;

	}> sram AT> flash    /* Means that VMA = SRAM & LMA = Flash */
    
	.bss :
	{
		_S_Bss = . ;
		*(.bss*)
		. = ALIGN(4) ;   /* To make it word addressable */
		_E_Bss = . ;
		. = ALIGN(4) ;
		. = . + 0x1000 ;
		_E_Heap = . ;    /* 4KB of Heap Memory */
		. = ALIGN(4) ;
		. = . + 0x1000 ;
		_stack_top = . ;   /* 4KB of stack Memory */
	}> sram
}