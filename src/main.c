#include "stdint.h"
#include "boot_info.h"
#include "string.h"
#include "monitor.h"
#include "descriptor_tables.h"
#include "pit.h"
#include "memory.h"
#include "paging.h"

static void cli()
{
    asm volatile("cli");
}

static void sti()
{
    asm volatile("sti");
}


int main(struct multiboot *mboot_ptr)
{
    monitor_clear();
    printf("Hello World\n");
    printf("MultiBoot Info Drives Addr: 0x%x \n",mboot_ptr->drives_addr);
    printf("MultiBoot Info High Memory: 0x%x \n",mboot_ptr->high_mem);
    printf("MultiBoot Info Low Memory: 0x%x \n",mboot_ptr->low_mem);
    printf("MultiBoot Info VBE Mode: 0x%x \n",mboot_ptr->vbe_mode);
    printf("MultiBoot Info MemoryMap Address: 0x%x \n",mboot_ptr->mmap_addr);
    printf("MultiBoot Info MemoryMap Length: 0x%x \n",mboot_ptr->mmap_length);
    printf("MultiBoot Info BootDevice: 0x%x \n",mboot_ptr->boot_device);
    printf("MultiBoot Info ConfigTable: 0x%x \n",mboot_ptr->config_table);
    init_descriptor_tables();
    init_timer(0xFFFF);
    uint64_t mem_size = (mboot_ptr->high_mem << 31) | mboot_ptr->low_mem ;
    mem_size *= 1024;
    init_paging(mem_size);
    printf("\nTotal Memory 0x%d", mem_size);

    //sti();


    return 0;
}

