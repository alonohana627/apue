#include <unix_io.h>
#include <libgen.h>

safe_string_arr_t *get_dir_and_file(char *buf) {
    char *filename;
    char *dname;
    safe_string_arr_t *arr;

    arr = safe_string_arr_create();

    if (arr == NULL) {
        return NULL;
    }

    filename = basename(buf);
    dname = dirname(buf);

    safe_string_arr_add(arr, filename);
    safe_string_arr_add(arr, dname);

    return arr;
}
