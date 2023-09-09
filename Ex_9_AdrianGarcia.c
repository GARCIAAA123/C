//
// Created by Adrian Garcia on 7/9/23.
//
#include "stdio.h"
#include "time.h"
#include "stdlib.h"

int find_first(const unsigned int *array, unsigned int what) {
    for (int i = 0; array[i] != 0; i++) {
        if (array[i] == what) {
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
    if (what == 0) {
        printf("Bye!");
        return;
    }
    int result = find_first(array, what);
    if (result != -1) {
        printf("Found at the index [%i]", result);
    } else {
        printf("Not found");
    }

}

int main() {
    unsigned int array[20];
    int count = 19;
    array[19] = 0;
    srand(time(NULL));
    for (int i = 0; i < count; ++i) {
        array[i] = rand() % 20 + 1;
    }
    print_numbers(array, count);
}
