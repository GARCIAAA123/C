//
// Created by Adrian Garcia on 6/10/23.
//

#include <stdio.h>
#include <string.h>

int calculate_checksum(const char *line) {
    int checksum = 0;
    for (int i = 1; line[i] != '*' && line[i] != '\0'; i++) {
        checksum ^= line[i];
    }
    return checksum;
}

int main() {
    char input_filename[256];
    printf("Enter the file name: ");
    scanf("%255s", input_filename);

    FILE *input_file = fopen(input_filename, "r");

    if (input_file == NULL) {
        perror("Error opening file");
        return 1;
    }

    char current_line[1024];
    for (int line_num = 0; fgets(current_line, sizeof(current_line), input_file); line_num++) {
        if (current_line[0] == '$') {
            char *asterisk_position = strchr(current_line, '*');
            if (asterisk_position != NULL) {
                int expected_checksum;
                if (sscanf(asterisk_position + 1, "%2X", &expected_checksum) == 1) {
                    int calculated_checksum = calculate_checksum(current_line);

                    if (calculated_checksum == expected_checksum) {
                        printf("[ OK ] %s", current_line);
                    } else {
                        printf("[FAIL] %s", current_line);
                    }
                }
            }
        }
    }

    fclose(input_file);

    return 0;
}
