#include "io_stats.h"

#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

void print_error(int err, const char *path) {
    switch (err) {
        case EACCES:
            printf("Error: Access Denied for %s\n", path);
            return;
        case EBADF:
            printf("Error: fd is not a valid fd for reading %s\n", path);
            return;
        case ENFILE:
            printf("Error: maximum opened files reached when tried to open %s\n", path);
            return;
        case ENOANO:
            printf("Error: Directory does not exist, or name is an empty string %s\n", path);
            return;
        case ENOMEM :
            printf("Error: Insufficient memory to complete the operation %s\n", path);
            return;
        case ENOTDIR :
            printf("Error: Not a dir %s\n", path);
            return;
        default:
            printf("Unknown Error in %s\n", path);
    }
}

safe_string_arr_t *entries_in_folder(const char *path) {
    DIR *dp;
    struct dirent *dirp;
    safe_string_arr_t *arr = safe_string_arr_create();

    if (arr == NULL) {
        return NULL;
    }

    if ((dp = opendir(path)) == NULL) {
        print_error(errno, path);
        return NULL;
    }

    while ((dirp = readdir(dp)) != NULL) {
        safe_string_arr_add(arr, dirp->d_name);
    }

    closedir(dp);
    return arr;
}

int simple_print_entries_in_folder(char *path) {
    safe_string_arr_t *files = entries_in_folder(path);
    if (files == NULL) {
        return ENOMEM;
    }
    for (size_t i = 0; i < files->size; i++) {
        /*Not safe, I hate Null check, might make C optional type FFS*/
        printf("%s\n", safe_string_arr_get(files, i));
    }

    safe_string_arr_destroy(files);
    return errno;
}
