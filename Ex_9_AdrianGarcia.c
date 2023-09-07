//
// Created by Adrian Garcia on 7/9/23.
//
#include "stdio.h"
#include "time.h"
#include "stdlib.h"

int find_first(const unsigned int *array, unsigned int what) {
    for (int i = 0; what != 0; i++) {
        if (array[i] == what) {
            printf("Found index [%i]", i);
            return i;
        }
    }
    return -1;
}


void print_numbers(const int *array, int count) {
    int what;
    for (int i = 0; i <= count; ++i) {
        printf("%d\n", array[i]);
    }
    printf("Enter a number or 0 to STOP:\n");
    scanf("%d", &what);
    find_first(array, what);
}

int main() {
    int array[20];
    int count = 19;
    array[19] = 0;
    srand(time(NULL));
    for (int i = 0; i < count; ++i) {
        array[i] = rand() % 20 + 1;
    }
    print_numbers(array, count);
}




