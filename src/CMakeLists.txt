cmake_minimum_required(VERSION 3.9)
project(OS)

add_executable(
        src/main/main.c
        src/libs/stdint.h src/boot/boot_info.h src/boot/boot_info.c
        src/libs/stdint.c src/libs/Input_Output.h src/libs/Input_Output.c
        src/libs/string.h src/libs/string.c src/libs/stddef.h /src/libs/stddef.c
        cpu/errno-base.h src/libs/ctype.h src/libs/ctype.c
        src/libs/stdbool.h src/libs/stdbool.c src/monitor/monitor.h
        src/monitor/monitor.c src/libs/stdarg.h src/libs/stdarg.c
        src/cpu/descriptor_tables.h src/cpu/descriptor_tables.c
        src/cpu/isr.h src/cpu/isr.c src/pic/pic.h src/pic/pic.c
        src/pit/pit.h src/pit/pit.c src/memory/memory.h src/memory/memory.c
        src/memory/paging.h src/memory/paging.c)

