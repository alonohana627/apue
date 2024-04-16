#include <unix_io.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        return 0;
    }

    safe_string_arr_t *arr = file_content_as_lines(argv[1]);
    if (arr == NULL) {
        return 1;
    }

    for (size_t i = 0; i < arr->size; i++) {
        if (is_match(safe_string_arr_get(arr, i), argv[2])) {
            printf("%zu:\t%s\n", i, safe_string_arr_get(arr, i));
        }
    }

    safe_string_arr_destroy(arr);
}