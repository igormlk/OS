//
// Created by root on 5/10/18.
//

#ifndef SRC_BOOT_INFO_H
#define SRC_BOOT_INFO_H

#include "../libs/stdint.h"

struct multiboot {
    uint32_t flags;
    uint32_t low_mem;
    uint32_t high_mem;
    uint32_t boot_device;
    uint32_t cmdline;
    uint32_t mods_count;
    uint32_t mods_addr;
    struct {
        uint32_t num;
        uint32_t size;
        uint32_t addr;
        uint32_t shndx;
    } elf_sec;
    uint64_t mmap_length;
    uint64_t mmap_addr;
    uint64_t drives_length;
    uint64_t drives_addr;
    uint64_t config_table;
    uint64_t boot_loader_name;
    uint64_t apm_table;
    uint64_t vbe_control_info;
    uint64_t vbe_mode_info;
    uint64_t vbe_mode;
    uint64_t vbe_interface_seg;
    uint64_t vbe_interface_off;
    uint64_t vbe_interface_len;
};

#endif //SRC_BOOT_INFO_H
