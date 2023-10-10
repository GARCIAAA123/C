//
// Created by Adrian Garcia on 6/10/23.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "debug.h"

int main() {
    srand(time(NULL));
    int Level_Debug;

    printf("Enter debug level (0-4): ");
    scanf("%d", &Level_Debug);

    if (Level_Debug < 0 || Level_Debug > 4) {
        fprintf(stderr, "Error: Debug level must be in the range 0-4.\n");
        return 1;
    }

    set_debug_level(Level_Debug);

    for (int i = 1; i <= 5; i++) {
        int Random_Level = rand() % 5;
        int numerical_arg = i;

        dprintf(Random_Level, "This is message %d with debug level %d\n", numerical_arg, Random_Level);
    }

    return 0;
}
