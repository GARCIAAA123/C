#include <stdio.h>
#include <string.h>

#define NAME 100
#define MAX_SUBJECTS 100
#define LINE_MAX 256

int isNameValid(const char *name) {
    int hasAlpha = 0;
    for (int i = 0; name[i]; i++) {
        if ((name[i] >= 'a' && name[i] <= 'z') || (name[i] >= 'A' && name[i] <= 'Z')) {
            hasAlpha = 1;
        }
        if (name[i] == '\n') {
            return 0;
        }
    }
    return hasAlpha;
}

int isNumber(const char *input) {
    for (int i = 0; input[i]; i++) {
        if (input[i] < '0' || input[i] > '9') {
            return 0;
        }
    }
    return 1;
}

char getGrade(int score) {
    if (score >= 90 && score <= 100) {
        return '5';
    } else if (score >= 80) {
        return '4';
    } else if (score >= 70) {
        return '3';
    } else if (score >= 60) {
        return '2';
    } else if (score >= 50) {
        return '1';
    } else {
        return '0';
    }
}

float calculateAverage(char grades[], int count) {
    float totalGrade = 0;
    for (int i = 0; i < count; i++) {
        totalGrade += grades[i] - '0';
    }
    return totalGrade / count;
}

int main() {
    char name[NAME];
    int subjects;
    int count = 0;
    int scores[MAX_SUBJECTS];
    char grades[MAX_SUBJECTS];

    printf("Welcome to the Student Grade Calculator!\n");

    do {
        printf("Please enter your name (letters only): ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0';
        if (!isNameValid(name)) {
            printf("Invalid input. Name must contain only letters and cannot be empty.\n");
        }
    } while (!isNameValid(name));

    int tempSubjects;
    do {
        printf("How many subjects do you want to calculate grades for? ");
        char input[NAME];
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';
        if (!isNumber(input) || sscanf(input, "%d", &tempSubjects) != 1 || tempSubjects <= 0) {
            printf("Invalid input. Please enter a valid positive number.\n");
        } else {
            subjects = tempSubjects;
        }
    } while (subjects <= 0);

    FILE *file = fopen("report.txt", "w");
    if (file) {
        fprintf(file, "------------------------------------------\n");
        fprintf(file, "Student: %s\n", name);
        fprintf(file, "------------------------------------------\n");
        fprintf(file, "Subject                  Score       Grade\n");

        while (count < subjects) {
            char course[NAME];
            int score;

            do {
                printf("Enter subject %d name: ", count + 1);
                fgets(course, sizeof(course), stdin);
                course[strcspn(course, "\n")] = '\0';
                if(!isNameValid(course)){
                    printf("Invalid input.Name must contain only letters and cannot be empty.\n");
                }
            } while (!isNameValid(course));

            do {
                printf("Enter your score for %s (0-100): ", course);
                char input[NAME];
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = '\0';
                if (!isNumber(input) || sscanf(input, "%d", &score) != 1 || score < 0 || score > 100) {
                    printf("Invalid input. Score must be between 0 and 100.\n");
                }
            } while (score < 0 || score > 100);

            scores[count] = score;
            grades[count] = getGrade(score);
            fprintf(file, "%-25s %d%% %10c\n", course, score, grades[count]);
            count++;
        }

        float average = calculateAverage(grades, subjects);
        fprintf(file, "\n");
        fprintf(file, "Average Grade: %.2f\n", average);
        fprintf(file, "------------------------------------------\n");

        fclose(file);
    } else {
        printf("Failed to open the file for writing.\n");
    }

    file = fopen("report.txt", "r");
    if (file) {
        char line[LINE_MAX];
        while (fgets(line, sizeof(line), file)) {
            printf("%s", line);
        }
        fclose(file);
    } else {
        printf("Failed to open the file for reading.\n");
    }

    return 0;
}
