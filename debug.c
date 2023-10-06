//
// Created by Adrian Garcia on 6/10/23.
//
#include <stdio.h>
#include <stdarg.h>
#include "debug.h"

static int current_debug_level = 0;

void set_debug_level(int debug_level) {
    if (debug_level >= 0 && debug_level <= 4) {
        current_debug_level = debug_level;
    } else {
        fprintf(stderr, "Error: Debug level must be in the range 0-4.\n");
    }
}

int dprintf(int debug_level, const char *fmt, ...) {
    if (debug_level <= current_debug_level) {
        va_list args;
        va_start(args, fmt);

        fprintf(stderr, "[DBG%d] ", debug_level);
        int result = vfprintf(stderr, fmt, args);

        va_end(args);
        return result;
    } else {
        return 0;
    }
}