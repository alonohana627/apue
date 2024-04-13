#ifndef APUE_SAFE_STRING_ARR_H
#define APUE_SAFE_STRING_ARR_H
#define MAX_STRING_SIZE 2048

#include <stdlib.h>
#include <stddef.h>
#include <string.h>

typedef enum {
    SAFE_STRING_ARR_SUCCESS,
    SAFE_STRING_ARR_MEMORY_ERROR,
    SAFE_STRING_ARR_INDEX_ERROR
} safe_string_arr_error_t;

typedef struct {
    char **strings;
    size_t size;
    size_t capacity;
} safe_string_arr_t;

safe_string_arr_t *safe_string_arr_create(void);

void safe_string_arr_destroy(safe_string_arr_t *arr);

safe_string_arr_error_t safe_string_arr_add(safe_string_arr_t *arr, const char *str);

safe_string_arr_error_t safe_string_arr_remove(safe_string_arr_t *arr, size_t index);

const char *safe_string_arr_get(const safe_string_arr_t *arr, size_t index);

safe_string_arr_error_t safe_string_arr_set(const safe_string_arr_t *arr, size_t index, const char *str);

/* extras */
safe_string_arr_t *split_by_char(char *args, char c);

safe_string_arr_t *split_by_space(char *args);

safe_string_arr_t *split_by_lines(char *args);

safe_string_arr_t *match_regex(char *input, const char *pattern, size_t max_matches);

#endif
