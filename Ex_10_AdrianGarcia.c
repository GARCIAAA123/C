//
// Created by Adrian Garcia on 13/9/23.
//
#include "stdio.h"
#include "string.h"

#define STR_SIZE 80


int main() {
    char text[STR_SIZE];
    do {
        printf("Enter a string(Type stop to stop): ");
        fgets(text, 80, stdin);
        if (text[strlen(text) - 1] == '\n') {
            text[strlen(text) - 1] = '\0';
        }
        if (strcmp(text, "stop") != 0) {
            printf("Your input: %s\n", text);
            printf("Lenght: %lu\n", strlen(text));
        }
    } while (strcmp(text, "stop") != 0);
    printf("Bye!");
    return 0;
}