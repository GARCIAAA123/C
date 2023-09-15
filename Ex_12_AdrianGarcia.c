//
// Created by Adrian Garcia on 15/9/23.
//

#include "stdio.h"
#include "string.h"

#define STR_SIZE 80

int count_words(const char *str, const char *word) {
    int count = 0;
    const char *ptr = str;
    while ((ptr = strstr(ptr, word)) != NULL) {
        count++;
        ptr += strlen(word);
    }
    return count;

}

int new_line(char *name) {
    fgets(name, STR_SIZE, stdin);
    if (name[strlen(name) - 1] == '\n') {
        name[strlen(name) - 1] = '\0';
    }
    return 0;
}

int main() {
    char string[STR_SIZE];
    char letter[STR_SIZE];
    printf("Let's find!\n");
    do {
        printf("Enter a string:\n");
        new_line(string);
        printf("Enter a letter to find or type stop to quit:\n");
        new_line(letter);
        int count = count_words(string, letter);
        printf("Number of letters found: %i\n", count);
    } while ((strcmp(letter, "stop") != 0));
    return 0;
}