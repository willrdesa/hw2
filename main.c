#include "convert.c"
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("a2_test.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file\n");
        return 1;
    }

    char line[256];
    int count = 0;
    int pass_count = 0;
    while (fgets(line, sizeof(line), file) != NULL) {
        //Skips comments and blank lines
        if (line[0] == '#' || line[0] == '\n' || strlen(line) < 3) continue;

        char big_buffer[100];
        char small_buffer[33];
        char* token = strtok(line, " ");
        count++;
        printf("Test %d: %s", count, token);

        if (strcmp(token, "oct_to_bin") == 0) {
            token = strtok(NULL, " ");
            char* n = token;
            token = strtok(NULL, " ");
            char* expected = token;
            expected[strlen(expected) - 2] = '\0';
            oct_to_bin(n, big_buffer);
            printf("(%s) -> Expected: %s, Got: %s ", n, token, big_buffer);
            char* pass;
            if (strcmp(expected, big_buffer) == 0) {
                pass = "PASS";
                pass_count++;
            } else pass = "FAIL";
            printf("[%s] \n", pass);
        }

        else if (strcmp(token, "oct_to_hex") == 0) {
            token = strtok(NULL, " ");
            char* n = token;
            token = strtok(NULL, " ");
            char* expected = token;
            expected[strlen(expected) - 2] = '\0';
            oct_to_hex(n, big_buffer);
            printf("(%s) -> Expected: %s, Got: %s ", n, token, big_buffer);
            char* pass;
            if (strcmp(expected, big_buffer) == 0) {
                pass = "PASS";
                pass_count++;
            } else pass = "FAIL";
            printf("[%s] \n", pass);
        }

        else if (strcmp(token, "hex_to_bin") == 0) {
            token = strtok(NULL, " ");
            char* n = token;
            token = strtok(NULL, " ");
            char* expected = token;
            expected[strlen(expected) - 2] = '\0';
            hex_to_bin(n, big_buffer);
            printf("(%s) -> Expected: %s, Got: %s ", n, token, big_buffer);
            char* pass;
            if (strcmp(expected, big_buffer) == 0) {
                pass = "PASS";
                pass_count++;
            } else pass = "FAIL";
            printf("[%s] \n", pass);
        }

        else if (strcmp(token, "to_sign_magnitude") == 0) {
            token = strtok(NULL, " ");
            int n = atoi(token);
            token = strtok(NULL, " ");
            char* expected = token;
            expected[strlen(expected) - 2] = '\0';
            to_sign_magnitude(n, big_buffer);
            printf("(%d) -> Expected: %s, Got: %s ", n, token, big_buffer);
            char* pass;
            if (strcmp(expected, big_buffer) == 0) {
                pass = "PASS";
                pass_count++;
            } else pass = "FAIL";
            printf("[%s] \n", pass);
        }

        else if (strcmp(token, "to_ones_complement") == 0) {
            token = strtok(NULL, " ");
            int n = atoi(token);
            token = strtok(NULL, " ");
            char* expected = token;
            expected[strlen(expected) - 2] = '\0';
            to_ones_complement(n, big_buffer);
            printf("(%d) -> Expected: %s, Got: %s ", n, token, big_buffer);
            char* pass;
            if (strcmp(expected, big_buffer) == 0) {
                pass = "PASS";
                pass_count++;
            } else pass = "FAIL";
            printf("[%s] \n", pass);
        }

        else if (strcmp(token, "to_twos_complement") == 0) {
            token = strtok(NULL, " ");
            int n = atoi(token);
            token = strtok(NULL, " ");
            char* expected = token;
            expected[strlen(expected) - 2] = '\0';
            to_twos_complement(n, big_buffer);
            printf("(%d) -> Expected: %s, Got: %s ", n, token, big_buffer);
            char* pass;
            if (strcmp(expected, big_buffer) == 0) {
                pass = "PASS";
                pass_count++;
            } else pass = "FAIL";
            printf("[%s] \n", pass);
        }
    }
    fclose(file);
    printf("\nSummary: %d/%d tests passed", pass_count, count);
}