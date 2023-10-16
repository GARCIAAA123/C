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

void inputStudentInfo(char name[NAME]) {
    do {
        printf("Please enter your name (letters only): ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0';
        if (!isNameValid(name)) {
            printf("Invalid input. Name must contain only letters and cannot be empty.\n");
        }
    } while (!isNameValid(name));
}

int inputSubjectCount() {
    char input[NAME];
    int subjects;
    do {
        printf("How many subjects do you want to calculate grades for? ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';
        if (!isNumber(input) || sscanf(input, "%d", &subjects) != 1 || subjects <= 0) {
            printf("Invalid input. Please enter a valid positive number.\n");
        }
    } while (!isNumber(input) || sscanf(input, "%d", &subjects) != 1 || subjects <= 0);
    return subjects;
}

void inputSubjectScores(int subjects, char courseNames[][NAME], int scores[MAX_SUBJECTS]) {
    for (int i = 0; i < subjects; i++) {
        do {
            printf("Enter subject %d name: ", i + 1);
            fgets(courseNames[i], sizeof(courseNames[i]), stdin);
            courseNames[i][strcspn(courseNames[i], "\n")] = '\0';
            if (!isNameValid(courseNames[i])) {
                printf("Invalid input. Name must contain only letters and cannot be empty.\n");
            }
        } while (!isNameValid(courseNames[i]));

        do {
            printf("Enter your score for %s (0-100): ", courseNames[i]);
            char input[NAME];
            fgets(input, sizeof(input), stdin);
            input[strcspn(input, "\n")] = '\0';
            if (!isNumber(input) || sscanf(input, "%d", &scores[i]) != 1 || scores[i] < 0 || scores[i] > 100) {
                printf("Invalid input. Score must be between 0 and 100.\n");
            }
        } while (scores[i] < 0 || scores[i] > 100);
    }
}

int main() {
    char name[NAME];
    int subjects;
    int scores[MAX_SUBJECTS];
    char grades[MAX_SUBJECTS];
    char courseNames[MAX_SUBJECTS][NAME];

    printf("Welcome to the Student Grade Calculator!\n");

    inputStudentInfo(name);
    subjects = inputSubjectCount();

    FILE *file = fopen("report.txt", "w");
    if (file) {
        fprintf(file, "------------------------------------------\n");
        fprintf(file, "Student: %s\n", name);
        fprintf(file, "------------------------------------------\n");
        fprintf(file, "Subject                  Score       Grade\n");

        inputSubjectScores(subjects, courseNames, scores);

        for (int i = 0; i < subjects; i++) {
            grades[i] = getGrade(scores[i]);
            fprintf(file, "%-25s %3d%% %11c\n", courseNames[i], scores[i], grades[i]);
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
