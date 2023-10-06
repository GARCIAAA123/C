//
// Created by Adrian Garcia on 6/10/23.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "debug.h"


int main() {
    srand(time(NULL));
    int debug_level;

    printf("Enter debug level (0-4): ");
    scanf("%d", &debug_level);

    if (debug_level < 0 || debug_level > 4) {
        fprintf(stderr, "Error: Debug level must be in the range 0-4.\n");
        return 1;
    }

    set_debug_level(debug_level);

    for (int i = 1; i <= 5; i++) {
        int random_debug_level = rand() % 5;
        int numerical_arg = i;

        dprintf(random_debug_level, "This is message %d with debug level %d\n", numerical_arg, random_debug_level);
    }

    return 0;
}