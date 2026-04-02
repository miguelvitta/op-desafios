#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdlib.h>

#define SIZE_BUFFER 256

/// @brief Returned when a NULL pointer is passed where a valid pointer is
/// required.
#define ERR_NULL -1

/// @brief Returned when malloc fails.
#define ERR_ALLOC -2

/// @brief Returned when input is malformed, out of range, or unreadable.
#define ERR_INPUT -3


int get_int(const char *prompt, int *result);
size_t get_string(const char *prompt, char *buffer, size_t size);
void get_expression();


#endif // FUNCTIONS_H