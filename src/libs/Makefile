# Makefile for JamesM's kernel tutorials.
# The C and C++ rules are already setup by default.
# The only one that needs changing is the assembler 
# rule, as we use nasm instead of GNU as.

LIBS_SOURCES= ctype.o Input_Output.o stdarg.o stdbool.o stddef.o stdint.o string.o

CFLAGS=-nostdlib -nostdinc -fno-builtin -fno-stack-protector -m32 -lgcc
LDFLAGS=-Tlink.ld -m elf_i386
ASFLAGS=-felf32

all: $(LIBS_SOURCES)

clean:
	rm -f *.o kernel

.s.o:
	nasm $(ASFLAGS) $<
