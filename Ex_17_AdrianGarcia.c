//
// Created by Adrian Garcia on 29/9/23.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 32


bool password_creator(char *password, int size, const char *word) {

    int requiredSize = strlen(word) * 2 + 1;
    if (requiredSize >= size) {
        return false;
    }


    const char random_chars[] = "!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";


    srand(time(NULL));

    int password_count = 0;
    password[password_count] = random_chars[rand() % strlen(random_chars)];
    password_count++;

    for (int i = 0; i < strlen(word) + 1; i++) {
        password[password_count] = word[i];
        password_count++;
        password[password_count] = random_chars[rand() % strlen(random_chars)];
        password_count++;
    }

    password[password_count] = random_chars[rand() % strlen(random_chars)];
    password_count++;
    password[password_count] = '\0';

    return true;
}

int main() {
    char word[MAX_SIZE];
    char password[MAX_SIZE * 2 + 1];

    printf("Enter a word or stop to quit (The word needs to be less 32 char): ");
    scanf("%s", word);

    while (strcmp(word, "stop") != 0) {

        bool result = password_creator(password, sizeof(password), word);

        if (result) {
            printf("Password: %s\n", password);
        } else {
            printf("Password is too long.\n");
        }


        printf("Enter another word or stop to quit: ");
        scanf("%s", word);
    }

    return 0;
}
