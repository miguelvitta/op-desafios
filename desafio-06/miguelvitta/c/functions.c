
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "functions.h"

/* Helper: Skip whitespace characters */
static void skip_whitespace(const char **str) {
    while (**str == ' ' || **str == '\t') {
        (*str)++;
    }
}

/* Helper: Check if only whitespace/newline remains */
static int is_valid_end(const char *str) {
    skip_whitespace(&str);
    return (*str == '\n' || *str == '\0');
}

int get_int(const char *prompt, int *result) {
    char buffer[SIZE_BUFFER];

    printf("%s", prompt);

    if (!fgets(buffer, sizeof(buffer), stdin)) {
        fprintf(stderr, "Error reading input.\n");
        return ERR_INPUT;
    }

    char *endptr = NULL;
    long value = strtol(buffer, &endptr, 10);

    if (endptr == buffer) {
        return ERR_INPUT;
    }

    if (value > INT_MAX || value < INT_MIN) {
        return ERR_INPUT;
    }

    if (!is_valid_end(endptr)) {
        return ERR_INPUT;
    }

    *result = (int)value;
    return 0;
}

size_t get_string(const char *prompt, char *buffer, size_t size) {
    printf("%s", prompt);

    /* Clamp size to INT_MAX for fgets safety */
    int safe_size = (size > INT_MAX) ? INT_MAX : (int)size;

    if (fgets(buffer, safe_size, stdin) == NULL) {
        return 0;
    }

    buffer[strcspn(buffer, "\n")] = '\0';

    return strlen(buffer);
}


