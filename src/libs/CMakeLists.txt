cmake_minimum_required(VERSION 3.9)
project(src)

add_executable(
    boot.s
        ../link.ld
        ../main.c
        ../stdint.h boot_info.h boot_info.c ../stdint.c Input_Output.h Input_Output.c ../string.h ../string.c ../stddef.h ../stddef.c ../cpu/errno-base.h ctype.h ctype.c ../stdbool.h ../stdbool.c ../monitor/monitor.h ../monitor/monitor.c ../stdarg.h ../stdarg.c ../cpu/descriptor_tables.h ../cpu/descriptor_tables.c ../cpu/isr.h ../cpu/isr.c ../pic/pic.h ../pic/pic.c ../pit/pit.h ../pit/pit.c ../memory/memory.h ../memory/memory.c ../memory/paging.h ../memory/paging.c)

