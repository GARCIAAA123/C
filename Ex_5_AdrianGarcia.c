//
// Created by Adrian Garcia on 5/9/23.
//
#include <stdio.h>

int read_range(int low, int high) {
    int number = 0;
    do {
        printf("Roll a dice and  enter your result.\n"
               "Enter a number between 1 and 6: ");
        if (scanf("%d", &number) != 1 || number < low || number > high) {
            while (getchar() != '\n');
            printf("Invalid input\n");
        } else {
            return number;
        }
    } while (number != 1 || number < low || number > high);
}

int main() {
    printf("Let's play!");
    for (int i = 0; i < 3; ++i) {
        int rolls = read_range(1, 6);
        if (rolls == 6) {
            printf("I got 6. It is a tie!\n");
        } else {
            printf("I got %d. I win!\n", rolls + 1);
        }
    }
    printf("Better luck next time. Bye!");
}
