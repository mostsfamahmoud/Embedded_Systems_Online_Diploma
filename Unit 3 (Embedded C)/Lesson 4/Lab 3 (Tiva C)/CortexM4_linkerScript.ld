/* Unit3_Lesson3_Lab2
   Created By: Mostafa Mahmoud
   Date: 14/9/2023
   File: CortexM4_linkerScript.ld  
*/

/* List of the memory sections */
MEMORY
{
	flash(rx): ORIGIN = 0x00000000, LENGTH = 512M
    sram(rwx): ORIGIN = 0x20000000, LENGTH = 512M
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
		_E_Data = . ;

	}> sram AT> flash    /* Means that VMA = SRAM & LMA = Flash */
    
	.bss :
	{
		_S_Bss = . ;
		*(.bss*)
		. = ALIGN(4) ;   /* To make it word addressable */
		_E_Bss = . ;
        
	}> sram
}