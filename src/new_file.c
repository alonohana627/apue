#include "unix_io.h"

void new_file(const char *path) {
    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;

    int fd = creat(path, mode);
    if (fd == -1) {
        return;
    }
    close(fd);
}
