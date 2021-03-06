//
// Created by root on 5/11/18.
//

#ifndef SRC_PIC_H
#define SRC_PIC_H

#include "../libs/Input_Output.h"

#define PIC1 0x20
#define PIC2 0xA0
#define PIC1_COMMAND PIC1
#define PIC1_DATA (PIC1 + 1)
#define PIC2_COMMAND PIC2
#define PIC2_DATA (PIC2 + 1)

#define ICW1_ICW4 0x01
#define ICW1_SINGLE 0x02
#define ICW1_INTERVAL 0x04
#define ICW1_LEVEL 0x08
#define ICW1_INIT 0x10

#define ICW4_8086 0x01
#define ICW4_AUTO  0x02
#define ICW4_BUF_SLAVE 0x08
#define ICW4_BUF_MASTER 0x0C
#define ICW4_SFNM 0x10

#define OCW2_EOI 0x20

void init_pic(uint8_t offset_pic1, uint8_t offset_pic2);

void reset_slave_pic();
void reset_master_pic();

#endif //SRC_PIC_H
