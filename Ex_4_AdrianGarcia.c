//
// Created by Adrian Garcia on 5/9/23.
//
#include <stdio.h>

int read_integer(void) {
    int number;
    do {
        printf("Enter positive numbers or negative to stop: ");
        if (scanf("%d", &number) != 1) {
            while (getchar() != '\n');
            printf("Invalid input\n");
        } else {
            return number; // Return the entered number
        }
    } while (number <= 0);
    return 0;
}

int main() {
    int count = 0;
    float sum = 0;
    int number;
    do {
        number = read_integer();
        if (number < 0) {
            printf("You entered %d positive numbers. The average is: %.3f\n", count, sum / count);
        } else {
            sum = sum + number;
            count++;
        }
    } while (number >= 0);
}