#include <safe_string_arr.h>

safe_string_arr_t *safe_string_arr_create(void) {
    size_t initial_capacity = 8;
    size_t size = 0;
    safe_string_arr_t *arr = (safe_string_arr_t *) malloc(sizeof(safe_string_arr_t));
    if (arr == NULL) {
        return NULL;
    }
    arr->size = size;
    arr->capacity = initial_capacity;
    arr->strings = (char **) malloc(initial_capacity * sizeof(char *));
    if (arr->strings == NULL) {
        free(arr);
        return NULL;
    }

    return arr;
}

void safe_string_arr_destroy(safe_string_arr_t *arr) {
    if (arr == NULL) {
        return;
    }

    if (arr->strings == NULL || arr->size == 0) {
        goto finish;
    }

    for (size_t i = 0; i < arr->size; i++) {
        if (arr->strings[i] != NULL) {
            free(arr->strings[i]);
        }
    }

    finish:
    free(arr);
}

safe_string_arr_error_t safe_string_arr_add(safe_string_arr_t *arr, const char *str) {
    if (arr == NULL) {
        return SAFE_STRING_ARR_INDEX_ERROR;
    }
    if (arr->size >= arr->capacity) {
        size_t new_capacity = arr->capacity * 2;
        char **new_strings = (char **) realloc(arr->strings, new_capacity * sizeof(char *));
        if (new_strings == NULL) {
            return SAFE_STRING_ARR_MEMORY_ERROR;
        }
        arr->strings = new_strings;
        arr->capacity = new_capacity;
    }

    arr->strings[arr->size] = (char *) malloc((strnlen(str, MAX_STRING_SIZE) + 1) * sizeof(char));
    if (arr->strings[arr->size] == NULL) {
        return SAFE_STRING_ARR_MEMORY_ERROR;
    }

    strncpy(arr->strings[arr->size], str, strnlen(str, MAX_STRING_SIZE) + 1);
    arr->size++;

    return SAFE_STRING_ARR_SUCCESS;
}

safe_string_arr_error_t safe_string_arr_remove(safe_string_arr_t *arr, size_t index) {
    if (arr == NULL) {
        return SAFE_STRING_ARR_INDEX_ERROR;
    }
    if (arr->size <= index || arr->size == 0) {
        return SAFE_STRING_ARR_INDEX_ERROR;
    }

    free(arr->strings[index]);
    for (size_t i = index; i < arr->size - 1; ++i) {
        arr->strings[i] = arr->strings[i + 1];
    }
    arr->size--;

    if (arr->capacity >= arr->size * 8) {
        size_t new_capacity = arr->capacity / 2;
        char **new_strings = (char **) realloc(arr->strings, new_capacity * sizeof(char *));
        if (new_strings == NULL) {
            return SAFE_STRING_ARR_MEMORY_ERROR;
        }
        arr->strings = new_strings;
        arr->capacity = new_capacity;
    }

    return SAFE_STRING_ARR_SUCCESS;
}

const char *safe_string_arr_get(const safe_string_arr_t *arr, size_t index) {
    if (arr == NULL) {
        return NULL;
    }
    if (arr->size <= index) {
        return NULL;
    }

    return arr->strings[index];
}

safe_string_arr_error_t safe_string_arr_set(const safe_string_arr_t *arr, size_t index, const char *str) {
    if (arr == NULL) {
        return SAFE_STRING_ARR_INDEX_ERROR;
    }
    if (index >= arr->size) {
        return SAFE_STRING_ARR_INDEX_ERROR;
    }
    char *new_str = (char *) malloc((strnlen(str, MAX_STRING_SIZE) + 1) * sizeof(char));
    if (new_str == NULL) {
        free(new_str);
        return SAFE_STRING_ARR_MEMORY_ERROR;
    }

    strncpy(new_str, str, strnlen(str, MAX_STRING_SIZE) + 1);
    free(arr->strings[index]);
    arr->strings[index] = new_str;

    return SAFE_STRING_ARR_SUCCESS;
}
