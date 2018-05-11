//
// Created by root on 5/10/18.
//

#ifndef SRC_DESCRIPTOR_TABLES_H
#define SRC_DESCRIPTOR_TABLES_H


#include "stdint.h"


/**               7 6 5  4 3   0
 * ACCESS BYTE = |P|DPL|DT|TYPE| {
 *  P = bit 7
    Is segment present? (1 = Yes)
    DPL = bit 5 e 6
    Descriptor privilege level - Ring 0 - 3.
    DT = quarto bit
    Descriptor type
    Type = do bit 0 ao bit 3
    Segment type - code segment / data segment.
    }
                        7 6 5 4 3      0
    GRANULARITY BYTE = |G|D|0|A|SEGMENT| {
    G = setimo bit
    Granularity (0 = 1 byte, 1 = 1kbyte)
    D = sexto bit
    Operand size (0 = 16bit, 1 = 32bit)
    0 = quinto bit
    Should always be zero.
    A = quarto bit
    Available for system use (always zero).
    Segment lenght = do bit zero ao bit 3
    }
 */

void init_descriptor_tables();

struct gdt_entry_struct
{
    uint16_t limit_low;
    uint16_t base_low;
    uint8_t base_middle;
    uint8_t access; //defines the ring of the segment
    uint8_t granularity;
    uint8_t base_high;
}__attribute__((packed));
typedef struct gdt_entry_struct gdt_entry_t;

struct gdt_ptr_struct
{
    uint16_t limit;
    uint32_t base;
}__attribute__((packed));
typedef struct gdt_ptr_struct gdt_ptr_t;

struct idt_entry_struct
{
    uint16_t base_low;
    uint16_t sel;
    uint8_t always0;
    uint8_t  flags;
    uint16_t base_high;
}__attribute__((packed));
typedef struct idt_entry_struct idt_entry_t;

struct idt_ptr_struct
{
    uint16_t limit;
    uint32_t base;
}__attribute__((packed));

typedef struct idt_ptr_struct idt_ptr_t;

extern void isr0();
extern void isr1();
extern void isr2();
extern void isr3();
extern void isr4();
extern void isr5();
extern void isr6();
extern void isr7();
extern void isr8();
extern void isr9();
extern void isr10();
extern void isr11();
extern void isr12();
extern void isr13();
extern void isr14();
extern void isr15();
extern void isr16();
extern void isr17();
extern void isr18();
extern void isr19();
extern void isr20();
extern void isr21();
extern void isr22();
extern void isr23();
extern void isr24();
extern void isr25();
extern void isr26();
extern void isr27();
extern void isr28();
extern void isr29();
extern void isr30();
extern void isr31();

extern void irq0();
extern void irq1();
extern void irq2();
extern void irq3();
extern void irq4();
extern void irq5();
extern void irq6();
extern void irq7();
extern void irq8();
extern void irq9();
extern void irq10();
extern void irq11();
extern void irq12();
extern void irq13();
extern void irq14();
extern void irq15();



#endif //SRC_DESCRIPTOR_TABLES_H
