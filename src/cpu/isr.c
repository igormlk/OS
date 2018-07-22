//
// Created by root on 5/11/18.
//

#include "isr.h"
#include "../monitor/monitor.h"
#include "../pic/pic.h"

isr_t interrupt_handlers[256];

void register_interrupt_handler(uint8_t n, isr_t handler)
{
    printf("Handler registrada numero %d \n", n);
    interrupt_handlers[n] = handler;
}

// This gets called from our ASM interrupt handler stub.
void isr_handler(registers_t regs)
{
    printf("Interrupcao recebida, %d \n", regs.int_no);
}

void irq_handler(registers_t regs)
{
    if(regs.int_no >= 40)
        reset_slave_pic();

    reset_master_pic();

    if(interrupt_handlers[regs.int_no] != NULL)
    {
        isr_t handler = interrupt_handlers[regs.int_no];
        handler(regs);
    }

}