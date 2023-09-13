/* Unit3_Lesson3_Lab2
   Created By: Mostafa Mahmoud
   Date: 10/9/2023
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
	}> flash
    
	.data :
	{
		*(.data)
	}> flash
    
	.bss :
	{
		*(.bss*) 
	}> sram
}