#/*************************************************************************/#
#/* Author        : Mostafa Mahmoud                                    	  */#
#/* File          : MakeFile				                              */#
#/* Date          : Sep 14, 2023                                           */#
#/* GitHub        : https://github.com/mostsfamahmoud            		  */#
#/*************************************************************************/#


# Set Tool-Chain (Compiler) Used
CC = arm-none-eabi-

# Set Compiler Flags
# Any Repeated flags for some commands 
# The -mthumb flag is used to indicate that the target architecture should be Thumb mode.
CFLAGS = -mcpu=cortex-m4 -mthumb -gdwarf-2 -g

# Set Includes 
INCS = -I .

# Set Libraries required
LIBS =

# Set .c Wildcard
# Combine all .c files into SRC Enviroment Variable such as (uart.c app.c etc..)
SRC = $(wildcard *.c)
#Set .c OBJ      
OBJ = $(SRC:.c=.o)

# Set .s Wildcard
# Combine all .s files into ASM Enviroment Variable such as (startup.s etc..)
ASM = $(wildcard *.s) 
#Set .s OBJ      
ASOBJ = $(ASM:.s=.o)

# Set Linker Script Name
LinkerScript_Name = CortexM4_linkerScript.ld

# Set Project Name
Project_Name = Unit3_Lesson4_Lab3_CortexM4

all: $(Project_Name).bin
	@echo "====== Build Done ======"
  
# $< -> Used for dependencies
# $@ -> Used for Target
  
#Will be mapped for any target .o with dependencies .s such as (startup.s)
%.o: %.s
	$(CC)as.exe $(CFLAGS) $< -o $@

#Will be mapped for any target .o with dependencies .c such as (uart.c and app.c)
%.o: %.c
	$(CC)gcc.exe -c $(INCS) $(CFLAGS) $< -o $@

$(Project_Name).elf: $(OBJ) $(ASOBJ)
	$(CC)ld.exe -T $(LinkerScript_Name) $(LIBS) $(OBJ) $(ASOBJ) -o $@ -Map=Map_file.map
	cp $(Project_Name).elf $(Project_Name).axf

$(Project_Name).bin: $(Project_Name).elf
	$(CC)objcopy.exe -O binary $< $@

clean_all:
	rm *.o *.elf *.axf *.bin
	@echo "====== All Cleaned ======"

clean:
	rm *.elf *.axf *.bin
	@echo "====== Executable Files Cleaned ======"

clean_obj:
	rm *.o
	@echo "====== Object Files Cleaned ======"