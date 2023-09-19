//
// Created by Adrian Garcia on 18/9/23.
//

#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "limits.h"

#define STR_SIZE 80


/*int main() {
    char filename[STR_SIZE];
    FILE *file;
    int count = 0;
    int low = INT_MAX;
    int high = INT_MIN;

    printf("Enter the filename: ");
    scanf("%s", filename);
    file = fopen(filename, "r");

    if (file == NULL) {
        fprintf(stderr,"Failed to open the file %s\n",filename);
        exit(1);
    } else {
        printf("File opened successfully.\n");
        while (!feof(file)) {
            if(fgets(filename, STR_SIZE, file) != NULL){
                printf("%s",filename);
                count++;
                if (file < low){
                    low = (int) file;
                }
                if (file > high){
                    high = (char) &file;
                }
            }
        }
        printf("The count is: %i\n",count);
        printf("The lowest number is: %i\n", low);
        printf("The highest number is: %i\n", high);
        fclose(file);
        return 0;
    }
}*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define STR_SIZE 80

int main() {
    char filename[STR_SIZE];
    FILE *file;
    int count = 0, num;
    int lowest = INT_MAX, highest = INT_MIN;

    printf("Enter the filename: ");
    scanf("%s", filename);
    file = fopen(filename, "r");

    if (file == NULL) {
        fprintf(stderr, "Failed to open the file %s\n", filename);
        exit(1);
    } else {
        printf("File opened successfully.\n");
        if ((!feof(file))){
            while (fscanf(file, "%d", &num) == 1) {
                printf("%d\n", num);
                count++;
                if (num < lowest) {
                    lowest = num;
                }
                if (num > highest) {
                    highest = num;
                }
            }
        }

        fclose(file);

        if (count > 0) {
            printf("Count of numbers: %d\n", count);
            printf("Lowest number: %d\n", lowest);
            printf("Highest number: %d\n", highest);
        } else {
            printf("No integers found in the file.\n");
        }
    }
    return 0;
}
