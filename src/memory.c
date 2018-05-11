//
// Created by root on 5/11/18.
//

#include "memory.h"
#include "stddef.h"

#define ALIGN_ADDRESS 0xFFFFF000
#define BLOCK_SIZE_ADDR 0x1000

extern uint32_t end;

uint32_t placement_address = (uint32_t) &end;

static uint32_t kmalloc_original(uint32_t size, int align, uint32_t * phys)
{

    if(align && (placement_address & ALIGN_ADDRESS))
    {
        placement_address &= ALIGN_ADDRESS;
        placement_address += BLOCK_SIZE_ADDR;
    }

    if(phys)
    {
        *phys = placement_address;
    }

    uint32_t tmp = placement_address;
    placement_address += size;
    return tmp;
}

uint32_t kmalloc(uint32_t size)
{
    return kmalloc_original(size,0,NULL);
}

uint32_t kmalloc_a(uint32_t size)
{
    return kmalloc_original(size,1,NULL);
}

uint32_t kmalloc_p(uint32_t size, uint32_t * phys)
{
    return kmalloc_original(size,0,phys);
}

uint32_t kmalloc_pa(uint32_t size, uint32_t * phys)
{
    return kmalloc_original(size,1,phys);
}
