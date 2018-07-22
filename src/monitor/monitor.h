//
// Created by root on 5/10/18.
//

#ifndef SRC_MONITOR_H
#define SRC_MONITOR_H

#include "../libs/Input_Output.h"
#include "../libs/stddef.h"
#include "../libs/stdbool.h"
#include "../libs/string.h"
#include "../libs/stdint.h"
#include "../libs/stdarg.h"

void monitor_put(char c);

void monitor_clear();

void monitor_write(char *c);

void printf(const char * format, ...);

int vsprintf(char * buf, const char * fmt, va_list args);


#endif //SRC_MONITOR_H
