//
// Created by root on 5/10/18.
//

#ifndef SRC_MONITOR_H
#define SRC_MONITOR_H

#include "Input_Output.h"
#include "stddef.h"
#include "stdbool.h"
#include "string.h"
#include "stdint.h"
#include "stdarg.h"

void monitor_put(char c);

void monitor_clear();

void monitor_write(char *c);

void printf(const char * format, ...);

int vsprintf(char * buf, const char * fmt, va_list args);


#endif //SRC_MONITOR_H
