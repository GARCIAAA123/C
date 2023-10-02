#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct node {
    int number;
    struct node *next;
} nnode;


nnode *add(int data, nnode *head) {

    nnode *newNode = (nnode *) malloc(sizeof(nnode));

    if (newNode == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    newNode->number = data;
    newNode->next = head;

    return newNode;
}

int main() {
    nnode *head = NULL;
    int number;
    char input[100];

    printf("Enter a number or type 'end' to stop the program:\n");

    while (strcmp(input, "end\n") != 0) {
        if (fgets(input, sizeof(input), stdin) == NULL) {
            perror("Input error");
            exit(EXIT_FAILURE);
        }
        if (sscanf(input, "%d", &number) == 1) {
            head = add(number, head);
        }
        if (strcmp(input, "stop\n") == 0) {
            printf("Program stopped!\n");
        } else if (sscanf(input, "%d", &number) != 1) {
            printf("Invalid input. Please enter a number or 'stop'.\n");
        }
    }

    printf("Numbers entered:\n");
    nnode *current = head;
    while (current != NULL) {
        printf("%d\n", current->number);
        current = current->next;
    }
    while (head != NULL) {
        nnode *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
