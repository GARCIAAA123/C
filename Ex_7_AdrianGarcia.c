//
// Created by Adrian Garcia on 5/9/23.
//
#include <stdbool.h>
#include "stdio.h"

bool read_positive(int *value){
    int number;
    do {
        printf("Enter positive numbers or negative to stop: ");
        if (scanf("%d", &number) != 1 || number < 0) {
            while (getchar() != '\n');
            printf("Invalid input\n");
            return false;
        } else {
            *value = number;
            return true;
        }
    } while (number <= 0);
}

int main(){
    int x;
    int count = 0;
    do {
        bool correct = read_positive(&x);
        if(correct){
            printf("You didn't get it right. I have %d euros\n", x*2 + 20);
        } else{
            count++;
        }
    } while (count < 3);
    printf("I give up! See you later");
}
