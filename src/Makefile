# Makefile for JamesM's kernel tutorials.
# The C and C++ rules are already setup by default.
# The only one that needs changing is the assembler 
# rule, as we use nasm instead of GNU as.

SOURCES=boot.o main.o boot_info.o stdint.o string.o Input_Output.o stddef.o ctype.o stdbool.o\
monitor.o stdarg.o descriptor_tables.o gdt.o interrupts.o isr.o idt.o pic.o pit.o memory.o\
paging.o

CFLAGS=-nostdlib -nostdinc -fno-builtin -fno-stack-protector -m32
LDFLAGS=-Tlink.ld -m elf_i386
ASFLAGS=-felf32

all: $(SOURCES) link 

clean:
	rm -f *.o kernel

link:
	ld $(LDFLAGS) -o kernel $(SOURCES)

.s.o:
	nasm $(ASFLAGS) $<
