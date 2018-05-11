cmake_minimum_required(VERSION 3.9)
project(src)

add_executable(
    boot.s
    link.ld
    main.c
        stdint.h boot_info.h boot_info.c stdint.c Input_Output.h Input_Output.c string.h string.c stddef.h stddef.c errno-base.h ctype.h ctype.c stdbool.h stdbool.c monitor.h monitor.c stdarg.h stdarg.c descriptor_tables.h descriptor_tables.c isr.h isr.c pic.h pic.c pit.h pit.c memory.h memory.c paging.h paging.c)
