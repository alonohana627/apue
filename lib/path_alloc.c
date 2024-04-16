#include  <unix_io.h>
#include <limits.h>

/*
 * Since APUE is done on Linux, and I don't care about other POSIX-compliant OSs, I use PATH_MAX
 */
static long pathmax = PATH_MAX;

char *path_alloc(size_t *sizep) {
    char *ptr;
    size_t size;

    size = pathmax + 1;
    if ((ptr = (char *) malloc(size * sizeof(char))) == NULL) {
        return ptr;
    }

    *sizep = size;
    return ptr;
}
