#include <stdio.h>
#include <string.h>

int calculateChecksum(const char *line) {
    int checksum = 0;
    for (int i = 1; line[i] != '*' && line[i] != '\0'; i++) {
        checksum ^= line[i];
    }
    return checksum;
}

int main() {
    char filename[256];
    printf("Enter the file name: ");
    scanf("%255s", filename);

    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    char line[1024];
    for (int lineNum = 0; fgets(line, sizeof(line), file); lineNum++) {
        if (line[0] == '$') {
            char *asterisk = strchr(line, '*');
            if (asterisk != NULL) {
                int expectedChecksum;
                if (sscanf(asterisk + 1, "%2X", &expectedChecksum) == 1) {
                    int calculatedChecksum = calculateChecksum(line);

                    if (calculatedChecksum == expectedChecksum) {
                        printf("[ OK ] %s", line);
                    } else {
                        printf("[FAIL] %s", line);
                    }
                }
            }
        }
    }

    fclose(file);

    return 0;
}
