//
// Created by Adrian Garcia on 22/09/2023.
//

#include <stdio.h>
#include <string.h>

# define MAX_LINES 40
# define MAX_NAME 40
# define NAME_FILE 80

typedef struct menu_item_ {
    char name[MAX_NAME];
    double price;
} menu_item;

void Menu(const char* file_input,  menu_item *list_menu);

int main(void) {
    char file_name[NAME_FILE];
    menu_item list_menu[MAX_LINES];
    printf("File name: ");
    fgets(file_name, NAME_FILE, stdin);
    if (file_name[strlen(file_name) - 1] == '\n') {
        file_name[strlen(file_name) - 1] = '\0';
    }
    Menu(file_name, list_menu);
    return 0;
}
void Menu(const char* file_input, menu_item *list_menu){
    int count = 0;
    FILE *file;
    file = fopen(file_input, "r");
    if (file == NULL) {
        fprintf(stderr, "'%s' file not found try again", file_input);
    }else{
        while (count < MAX_LINES) {
            if (fscanf(file, " %[^;];%lf",list_menu[count].name, &list_menu[count].price )==2){
                count++;
            }
        }
        fclose(file);

        for(int i = 0; i < count; i++){
            printf("%8.2f\t%s\n", list_menu[i].price, list_menu[i].name);
        }
    }
}