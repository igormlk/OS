//
// Created by root on 5/11/18.
//

#include "pic.h"
#include "../monitor/monitor.h"

void io_wait_pic()
{
    for(int i = 0; i < 200; i++);
}

void init_pic(uint8_t offset_pic1, uint8_t offset_pic2)
{

    //ICW1 Initialization command 1
    uint8_t command = ICW1_ICW4 | ICW1_INIT;
    outByte(PIC1_COMMAND, command);
    outByte(PIC2_COMMAND, command);
    io_wait_pic();
    //ICW2 Command 2
    outByte(PIC1_DATA, offset_pic1);
    outByte(PIC2_DATA, offset_pic2);
    io_wait_pic();
    //ICW3 Command 3 define qual pino é anexado ao pic slave
    outByte(PIC1_DATA, 0x04);
    outByte(PIC2_DATA, 0x02);
    command = ICW4_8086;
    io_wait_pic();
    //ICW4 Command 4, define o pic para operar no modo 8086
    outByte(PIC1_DATA,command);
    outByte(PIC2_DATA,command);
    io_wait_pic();
    //Operation Control Word 1
    outByte(PIC1_DATA,0x00);
    outByte(PIC2_DATA,0x00);
    io_wait_pic();
    printf("PIC INICIALIZADO\n");

}

void reset_slave_pic() {
    outByte(PIC2_COMMAND, OCW2_EOI);
    io_wait_pic();
}

void reset_master_pic() {
    outByte(PIC1_COMMAND, OCW2_EOI);
    io_wait_pic();
}


