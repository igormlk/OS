//
// Created by root on 5/10/18.
//

#include "stdint.h"

#ifndef SRC_INPUT_OUTPUT_H
#define SRC_INPUT_OUTPUT_H


void outByte(uint16_t port, uint8_t value);
uint8_t inByte(uint16_t port);
uint16_t inWord(uint16_t port);


#endif //SRC_INPUT_OUTPUT_H
