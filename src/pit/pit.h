//
// Created by root on 5/11/18.
//

#ifndef SRC_PIT_H
#define SRC_PIT_H

#include "../libs/stdint.h"

#define PIT_FREQUENCY 1193180

void init_timer(uint32_t frequency);
void disable_timer();

#endif //SRC_PIT_H
