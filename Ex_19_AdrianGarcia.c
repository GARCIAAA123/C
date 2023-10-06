//
// Created by Adrian Garcia on 6/10/23.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 40
#define MAX_NAME 40
#define NAME_FILE 80

typedef struct menu_item_ {
    char name[MAX_NAME];
    double price;
} menu_item;


int compare_price(const void *a, const void *b) {
    const menu_item *item_a = (const menu_item *) a;
    const menu_item *item_b = (const menu_item *) b;
    if (item_a->price < item_b->price) return -1;
    else if (item_a->price > item_b->price) return 1;
    else return 0;
}


int compare_name(const void *a, const void *b) {
    const menu_item *item_a = (const menu_item *) a;
    const menu_item *item_b = (const menu_item *) b;
    return strcmp(item_a->name, item_b->name);
}

void Menu(const char *file_input, menu_item *list_menu, int count);

int main(void) {
    char file_name[NAME_FILE];
    menu_item list_menu[MAX_LINES];
    int count = 0;
    printf("File name: ");
    fgets(file_name, NAME_FILE, stdin);
    if (file_name[strlen(file_name) - 1] == '\n') {
        file_name[strlen(file_name) - 1] = '\0';
    }
    Menu(file_name, list_menu, count);
    return 0;
}

void Menu(const char *file_input, menu_item *list_menu, int count) {
    FILE *file;
    file = fopen(file_input, "r");
    if (file == NULL) {
        fprintf(stderr, "'%s' file not found. Try again.", file_input);
    } else {
        int max_lines = MAX_LINES;
        while (count < max_lines) {
            if (fscanf(file, " %[^;];%lf", list_menu[count].name, &list_menu[count].price) == 2) {
                count++;
            } else {
                if (feof(file)) {
                    break;
                } else {
                    fprintf(stderr, "Invalid input in file.\n");
                    break;
                }
            }
        }
        fclose(file);

        int sort_option;
        do {
            printf("Choose sorting order:\n");
            printf("1. Sort by price\n");
            printf("2. Sort by name\n");
            printf("Enter your choice: ");
            scanf("%d", &sort_option);
        } while (sort_option != 1 && sort_option != 2);

        if (sort_option == 1) {
            qsort(list_menu, count, sizeof(menu_item), compare_price);
        } else {
            qsort(list_menu, count, sizeof(menu_item), compare_name);
        }

        for (int i = 0; i < count; i++) {
            printf("%8.2f\t%s\n", list_menu[i].price, list_menu[i].name);
        }
    }
}
