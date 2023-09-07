//
// Created by Adrian Garcia on 5/9/23.
//
#include <stdlib.h>
#include <time.h>
#include "stdio.h"

void print_numbers(const int *array, int count){
    for (int i = 0; i < count; ++i) {
        printf("%8d\n",array[i]);
    }
}

int main(){
    int array[15];
    int count = 15;
    srand(time(NULL));
    for (int i =0; i < count; ++i) {
        array[i] = rand() % 100;
    }
    print_numbers(array, count);
}