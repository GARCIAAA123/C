//
// Created by Adrian Garcia on 19/9/23.
//

#include "stdio.h"
#include "string.h"
#include "limits.h"

#define STR_SIZE 80


int file_handling(int *count, int *lowest, int *highest);

int new_line(char *name) {
    fgets(name, STR_SIZE, stdin);
    if (name[strlen(name) - 1] == '\n') {
        name[strlen(name) - 1] = '\0';
    }
    return 0;
}

int main() {
    int count = 0;
    int lowest = INT_MAX;
    int highest = INT_MIN;

    if (file_handling(&count, &lowest, &highest) == 0) {
        if (count == 0) {
            printf("File is empty\n");
        } else {
            printf("Count of numbers: %d\n", count);
            printf("Lowest number: %d\n", lowest);
            printf("Highest number: %d\n", highest);
        }
    }

    return 0;
}

int file_handling(int *count, int *lowest, int *highest) {
    char filename[STR_SIZE];
    FILE *file;
    int num = 0;

    printf("Enter the filename: ");
    scanf("%s", filename);
    file = fopen(filename, "r");

    if (file == NULL) {
        fprintf(stderr, "Failed to open the file %s\n", filename);
        return 1;
    } else {
        printf("File opened successfully.\n");
        new_line((char *) file);
        while (fscanf(file, "%d", &num) == 1) {
            printf("%d\n", num);
            (*count)++;
            if (num < *lowest) {
                *lowest = num;
            }
            if (num > *highest) {
                *highest = num;
            }
        }

        fclose(file);
        return 0;
    }
}

