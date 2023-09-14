//
// Created by Adrian Garcia on 13/9/23.
//
#include "stdio.h"
#include "string.h"

#define STR_SIZE 80

int replace_char(char *str, const char *repl) {
    if (strlen(repl) != 2) {
        return 0;
    }
    char old_char = repl[0];
    char new_char = repl[1];
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == old_char) {
            str[i] = new_char;
            count++;
        }

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
    char text[STR_SIZE];
    char change[2];
    printf("Enter your text: ");
    new_line(text);
    printf("Enter two characters for replacement:");
    new_line(change);
    int modifications = replace_char(text, change);
    if (modifications > 0) {
        printf("New text: %s\n", text);
        printf("Number of characters changed: %d\n", modifications);
    } else {
        printf("Not found");
    }
    return 0;
}


