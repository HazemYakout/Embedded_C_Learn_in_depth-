# Define the compiler and assembler
CC = arm-none-eabi-gcc
AS = arm-none-eabi-as
LD = arm-none-eabi-ld
OBJCOPY = arm-none-eabi-objcopy

# Define the target and source files
TARGET = learn-in-depth
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
SRCAS = $(wildcard *.s)
OBJAS = $(SRCAS:.s=.o)
# Define the linker script
LDSCRIPT = linker_script.ld

# Others 
CFLAGS = -mcpu=arm926ej-s -g
INCS = -I.

# Define the build rules
.PHONY: all clean clean_all
all: $(TARGET).bin
	@echo ">>>Building is done<<<"

%.o: %.s
	$(AS) $(CFLAGS) $< -o $@

%.o: %.c
	$(CC) -c $(INCS) $(CFLAGS) $< -o $@

$(TARGET).elf: $(OBJ) $(OBJAS)
	$(LD) $(OBJ) $(OBJAS) -T $(LDSCRIPT) -o $@

$(TARGET).bin: $(TARGET).elf
	$(OBJCOPY) -O binary $< $@

clean_all:
	rm -f *.o *.elf *.bin *.map

clean:
	rm -f *.o *.elf *.bin
