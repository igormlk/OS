//
// Created by root on 5/11/18.
//

#ifndef SRC_PAGING_H
#define SRC_PAGING_H

#include "../libs/stdint.h"
#include "../cpu/isr.h"

typedef struct page
{
    uint32_t present : 1;
    uint32_t rw : 1;
    uint32_t user : 1;
    uint32_t accessed : 1;
    uint32_t dirty : 1;
    uint32_t unused : 1;
    uint32_t frame : 20;
}page_t;

typedef struct page_table
{
    page_t pages[1024];
}page_table_t;

typedef struct page_directory
{
    page_table_t * tables[1024];
    uint32_t tablesPhysical[1024];
    uint32_t physicalAddr;
}page_directory_t;

void init_paging(uint64_t mem_size);

void switch_page_directory(page_directory_t * new_page);

page_t * get_page(uint32_t address, int make, page_directory_t * dir);

void page_fault(registers_t regs);

void debug_mem();


#endif //SRC_PAGING_H
