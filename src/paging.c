//
// Created by root on 5/11/18.
//

#include "paging.h"
#include "stddef.h"
#include "memory.h"
#include "monitor.h"

extern uint32_t placement_address;

typedef struct mem_chunk
{
    struct mem_chunk * next_mem_chunk;
    uint32_t frame;
}mem_chunk_t;

typedef struct mem_node
{
    mem_chunk_t * first;
    mem_chunk_t * last;
    uint32_t memory_used;
    uint32_t total_memory;
    uint32_t total_chunks;
}mem_node_t;

static mem_node_t memory;

void init_node_chunks(uint64_t mem_size)
{

    uint32_t chunks = (uint32_t) (mem_size / 0x1000);
    memory.total_memory = chunks * sizeof(mem_chunk_t);
    memory.first = (mem_chunk_t *) kmalloc(sizeof(mem_chunk_t));
    memory.last = memory.first;
    memory.total_chunks = chunks;
    memory.memory_used = 0;

    printf("\nNumero de chunks %d", chunks);
    printf("\nTamanho de cada chunk %d", sizeof(mem_chunk_t));
}

static void set_mem_chunk(uint32_t frame_addr)
{

};

static void clear_mem_chunk(uint32_t frame_addr)
{

}

static bool test_mem_chunk(uint32_t frame_addr)
{

    return false;
}

static uint32_t first_mem_chunk()
{

    return 0;
}

static void alloc_chunk_mem(page_t * page, int is_kernel, int is_write)
{
    if(page->frame != 0)
        return;

    uint32_t idx = first_mem_chunk();

    if(idx == -1)
        return;

    set_mem_chunk(idx * 0x1000);

}


void print_nodes()
{
    mem_chunk_t * ptr;
    ptr = memory.first;
    printf("\nEndereco do primeiro ptr 0x%x", ptr);
    printf("\n Endereco do proximo ptr 0x%x", ptr->next_mem_chunk);
    while((ptr = ptr->next_mem_chunk) != NULL)
    {
        printf("\nEndereco dos chunks 0x%x", ptr);
    }
}


void init_paging(uint64_t mem_size)
{
    init_node_chunks(mem_size);
    print_nodes();
}

void switch_page_directory(page_directory_t * new)
{

}

page_t * get_page(uint32_t address, int make, page_directory_t * dir)
{

    address /= 0x1000;
    uint32_t table_idx = address / 0x1000;

    if(dir->tables[table_idx])
    {
        return &dir->tables[table_idx]->pages[address%1024];
    }
    else if(make)
    {
        return NULL;
    }

}

void page_fault(registers_t regs)
{

}

