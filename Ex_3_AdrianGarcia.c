//
// Created by Adrian Garcia on 5/9/23.
//
//
// Created by Adrian Garcia on 26/8/23.
//
#include <stdio.h>


int main() {
    int Students;
    printf("How many students: "); // Ask how many students
    scanf("%d", &Students);

    int grades[Students]; // Creates an array with the amount of students asked previously
    for (int i = 0; i < Students; i++) {
        grades[i] = -1;  // Starts on -1
    }

    int id;
    while (1) {
        printf("Enter student number (1 - %d) or 0 to stop: ", Students);
        scanf("%d", &id);

        if (id == 0) { // If the id equals 0 exit the while loop
            break;
        } else if (id < 1 || id > Students) { // If id does not match the number of students or it is less than 1
            printf("Invalid student number!\n");
            continue;
        }

        int grade;
        while (1) {
            printf("Enter grade (0 - 5) for student %d or -1 to cancel: ", id);
            scanf("%d", &grade);

            if (grade >= 0 && grade <= 5) { // Checks that the grade it is between 0 and 5
                grades[id - 1] = grade;
                break;
            } else if (grade != -1) { // If it is not between 0 or 5
                printf("Invalid grade!\n");
            } else {
                break;
            }
        }
    }

    printf("Student\tGrade\n");
    for (int i = 0; i < Students; i++) { // Prints the whole list
        printf("%d\t", i + 1);
        if (grades[i] == -1) {
            printf("\tN/A\n");
        } else {
            printf("\t%d\n", grades[i]);
        }
    }

    return 0;
}

