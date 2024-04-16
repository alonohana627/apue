#include <unix_io.h>
#include <libgen.h>
#include <stdio.h>

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

char *file_content(const char *path) {
    ssize_t bytes_read;
    size_t total_bytes_read = 0;
    size_t buffer_size = IO_BUFFER_SIZE;
    int fd = open(path, O_RDONLY);

    if (fd == -1) {
        return NULL;
    }

    char *content = (char *) malloc(buffer_size);
    if (content == NULL) {
        close(fd);
        return NULL;
    }

    while ((bytes_read = read(fd, content + total_bytes_read, buffer_size - total_bytes_read)) > 0) {
        total_bytes_read += bytes_read;
        if (total_bytes_read == buffer_size) {
            buffer_size *= 2;
            char *temp = realloc(content, buffer_size);
            if (temp == NULL) {
                close(fd);
                free(content);
                return NULL;
            }
            content = temp;
        }
    }

    close(fd);

    if (bytes_read == -1) {
        free(content);
        return NULL; // Return NULL if read operation fails
    }

    content[total_bytes_read] = '\0';

    return content;
}

safe_string_arr_t *file_content_as_lines(const char *path) {
    char *raw_file_content;
    safe_string_arr_t *arr;

    raw_file_content = file_content(path);
    if (raw_file_content == NULL) {
        return NULL;
    }

    arr = split_by_lines(raw_file_content);
    free(raw_file_content);
    return arr;
}

bool can_offset(void) {
    return lseek(STDIN_FILENO, 0, SEEK_CUR) != -1;
}
