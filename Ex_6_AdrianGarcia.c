//
// Created by Adrian Garcia on 5/9/23.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int option(void) {
    int select = 0;
    do {
        printf("Select an operation\n"
               "1. Roll D6\n"
               "2. Roll D10\n"
               "3. Quit\n");
        if (scanf("%d", &select) != 1 || select < 1 ||
            select > 3) { // if the input is not a number or a number between 1 and 3
            while (getchar() != '\n');  // Clears the buffer
            printf("Invalid input\n");  // And prints Invalid input
        } else {
            return select; // Returns the select number
        }
    } while (select != 1 || select < 1 || select > 3);
    return 0;
}

int d_6(int low, int high) {
    int x = 0;
    srand(time(NULL));
    x = (rand() % (high - low + 1)) + low;
    printf("The number is %d\n", x); // Prints the random number
    return 0;
}

int d_10(int low, int high) {
    int x = 0;
    srand(time(NULL));
    x = (rand() % (high - low + 1)) + low;
    printf("The number is %d\n", x); // Prints the random number
    return 0;
}

int main() {
    int program;
    do {
        program = option();
        if (program == 1) {
            d_6(1, 6);
        }
        if (program == 2) {
            d_10(1, 10);
        }
        if (program == 3) {
            printf("Bye!");
        }
    } while (program != 3);
}
