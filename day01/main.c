#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

size_t check_string_for_number(const char *slice, size_t *result) {
    if (strstr(slice, "one") != NULL) {
        *result = 1;
        return 1;
    } else if (strstr(slice, "two") != NULL) {
        *result = 2;
        return 1;
    } else if (strstr(slice, "three") != NULL) {
        *result = 3;
        return 1;
    } else if (strstr(slice, "four") != NULL) {
        *result = 4;
        return 1;
    } else if (strstr(slice, "five") != NULL) {
        *result = 5;
        return 1;
    } else if (strstr(slice, "six") != NULL) {
        *result = 6;
        return 1;
    } else if (strstr(slice, "seven") != NULL) {
        *result = 7;
        return 1;
    } else if (strstr(slice, "eight") != NULL) {
        *result = 8;
        return 1;
    } else if (strstr(slice, "nine") != NULL) {
        *result = 9;
        return 1;
    } else {
        return 0;
    }
}

size_t get_first_number(const char *slice, size_t index, size_t *result) {
    size_t string_match = 0;

    if (check_string_for_number(slice, &string_match) != 0) {
        *result = string_match;
        return 1;
    } else if (isdigit(slice[index])) {
        *result = slice[index] - 48;
        return 1;
    }

    return 0;
}

int main() {
    FILE *fp;
    char buffer[64] = "";
    size_t total = 0;

    fp = fopen("input.txt", "r");

    while(fgets(buffer, sizeof(buffer), fp) != NULL) {
        for (size_t i = 1; i < strlen(buffer); ++i) {
            size_t match = 0;
            char slice[i + 1];
            strlcpy(slice, buffer, sizeof(slice));

            if (get_first_number(slice, i - 1, &match) != 0) {
                total += match * 10;
                break;
            }
        }

        for (size_t i = 1; i < strlen(buffer) + 1; ++i) {
            size_t match = 0;
            char slice[i + 1];
            char *start_of_slice = buffer + strlen(buffer) - i;
            strlcpy(slice, start_of_slice, sizeof(slice));

            if (get_first_number(slice, 0, &match) != 0) {
                total += match;
                break;
            }
        }
    }

    printf("total: %zu\n", total);
    
    return 0;
}
