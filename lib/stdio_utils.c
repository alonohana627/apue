#include <stdio_utils.h>
#include <errno.h>

int create_new_file(const char *path) {
    FILE *fp;
    int err;

    if ((fp = fopen(path, "w")) == NULL) {
        err = errno;
        return err;
    }

    return fclose(fp);
}

safe_string_arr_t *mingrep(const char *path, const char *pattern) {
    FILE *fp;
    safe_string_arr_t *arr;
    char line_buf[IO_BUFFER_SIZE];

    if ((fp = fopen(path, "r+")) == NULL) {
        fclose(fp);
        return NULL;
    }

    arr = safe_string_arr_create();
    if (arr == NULL) {
        goto error;
    }

    while (fgets(line_buf, IO_BUFFER_SIZE, fp) != NULL) {
        if (is_match(line_buf, pattern)) {
            safe_string_arr_add(arr, line_buf);
        }
    }

    fclose(fp);
    return arr;

    error:
    safe_string_arr_destroy(arr);
    fclose(fp);
    return NULL;
}
