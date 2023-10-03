//
// Created by Adrian Garcia on 2/10/23.
//

#include "stdio.h"
#include "stdlib.h"
#include "time.h"


int main() {
    int number = 0;
    int random_number;
    srand(time(NULL));
    while (number >= 0) {
        printf("Number between 0 and 15 or negative to stop:\n");
        scanf("%d", &number);
        if (number < 0) {
            printf("Program stopped\n");
        } else if (number <= 15) {
            random_number = rand();
            int shifted_number = random_number >> number;
            shifted_number = shifted_number & 0x3F;
            printf("Number no shifted: 0x%X\n",random_number);
            printf("Number shifted: 0x%02X\n", shifted_number);

        }

    }
}