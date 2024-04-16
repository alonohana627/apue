#include <io_stats.h>
#include <stdio.h>
#include <sys/stat.h>

char *_file_type(mode_t mode) {
    char *ret;
    if (S_ISREG(mode)) {
        ret = "Regular File";
    } else if (S_ISDIR(mode)) {
        ret = "Directory";
    } else if (S_ISCHR(mode)) {
        ret = "Character Special";
    } else if (S_ISBLK(mode)) {
        ret = "Block Special";
    } else if (S_ISFIFO(mode)) {
        ret = "FIFO File";
    } else if (S_ISLNK(mode)) {
        ret = "Symbolic Link";
    } else if (S_ISSOCK(mode)) {
        ret = "Socket";
    } else {
        ret = "Unknown";
    }
    return ret;
}

void enhanced_ls(const char *path) {
    safe_string_arr_t *files;
    struct stat buf;
    char *curFile;

    files = entries_in_folder(path);
    if (files == NULL) {
        return;
    }

    for (size_t i = 0; i < files->size; i++) {
        curFile = (char *) safe_string_arr_get(files, i);
        if (curFile == NULL) {
            continue;
        }
        if (stat(curFile, &buf) < 0) {
            continue;
        }

        printf("%s\t%s\t%ldB\n", curFile, _file_type(buf.st_mode), buf.st_size);
    }
}
