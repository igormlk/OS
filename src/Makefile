# Makefile for JamesM's kernel tutorials.
# The C and C++ rules are already setup by default.
# The only one that needs changing is the assembler 
# rule, as we use nasm instead of GNU as.

SUBDIRS = boot cpu libs memory monitor pic pit main

BOOT_OBJ = $(patsubst %.o,boot/%.o, boot.o boot_info.o)
CPU_OBJ = $(patsubst %.o,cpu/%.o, descriptor_tables.o gdt.o idt.o interrupts.o isr.o)
LIBS_OBJ = $(patsubst %.o,libs/%.o, ctype.o Input_Output.o stdarg.o stdbool.o stddef.o stdint.o string.o)
MEMORY_OBJ = $(patsubst %.o,memory/%.o, memory.o paging.o)
MONITOR_OBJ = $(patsubst %.o,monitor/%.o, monitor.o)
PIC_OBJ = $(patsubst %.o,pic/%.o, pic.o)
PIT_OBJ = $(patsubst %.o,pit/%.o, pit.o)
MAIN_OBJ = $(patsubst %.o,main/%.o, main.o)

CFLAGS=-nostdlib -nostdinc -fno-builtin -fno-stack-protector -m32 -lgcc
LDFLAGS=-Tlink.ld -m elf_i386
ASFLAGS=-felf32

.PHONY: subdirs $(SUBDIRS)

subdirs: $(SUBDIRS)
$(SUBDIRS):
	$(MAKE) -C $@
boot:link

clean:
	rm -f *.o kernel

link:
	ld $(LDFLAGS) -o kernel $(MAIN_OBJ) $(BOOT_OBJ) $(CPU_OBJ) $(LIBS_OBJ) $(MEMORY_OBJ) $(MONITOR_OBJ) $(PIC_OBJ) $(PIT_OBJ)

.s.o:
	nasm $(ASFLAGS) 
