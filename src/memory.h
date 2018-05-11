//
// Created by root on 5/11/18.
//

#ifndef SRC_MEMORY_H
#define SRC_MEMORY_H


#include "stdint.h"

uint32_t kmalloc(uint32_t size);
uint32_t kmalloc_a(uint32_t size);
uint32_t kmalloc_p(uint32_t size, uint32_t * phys);
uint32_t kmalloc_pa(uint32_t size, uint32_t * phys);

#endif //SRC_MEMORY_H
