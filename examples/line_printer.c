#include <unix_io.h>
#include <safe_string_arr.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        return 0;
    }

    safe_string_arr_t *a = file_content_as_lines(argv[1]);
    for (size_t i = 0; i < a->size; i++) {
        printf("%ld\t%s\n", i, safe_string_arr_get(a, i));
    }
}
