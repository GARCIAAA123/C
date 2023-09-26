//
// Created by Adrian Garcia on 19/9/23.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH 100
#define MAX_LENGTH 80
#define NAME_FILE 80

void UppercaseFile(const char *filename, char lines[MAX_WIDTH][MAX_LENGTH]);

int main(void) {
    char filename[NAME_FILE];
    char lines[MAX_WIDTH][MAX_LENGTH];

    printf("Filename: ");
    fgets(filename, sizeof(filename), stdin);

    if (filename[strlen(filename) - 1] == '\n') {
        filename[strlen(filename) - 1] = '\0'; // Remove the newline character
    }

    UppercaseFile(filename, lines);

    return 0;
}

void UppercaseFile(const char *filename, char lines[MAX_WIDTH][MAX_LENGTH]) {
    int lineCount = 0;
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        fprintf(stderr, "'%s' file not found, try again\n", filename);
        return;
    }

    while (lineCount < MAX_WIDTH && fgets(lines[lineCount], MAX_LENGTH, file) != NULL) {
        lineCount++;
    }

    file = fopen(filename, "w");
    for (int i = 0; i < lineCount; i++) {
        int length = strlen(lines[i]);
        for (int j = 0; j < length; j++) {
            fputc(toupper(lines[i][j]), file);
        }
    }
    printf("Lines: %d", lineCount);
    fclose(file);
}
