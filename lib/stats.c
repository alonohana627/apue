#include <stats.h>
#include <stdio.h>

inline long get_posix_version(void) {
    return sysconf(_SC_VERSION);
}

inline long get_xsi_version(void) {
    return sysconf(_SC_XOPEN_VERSION);
}

inline long get_openmax(void) {
    return sysconf(_SC_OPEN_MAX);
}

inline long get_maxargs(void) {
    return sysconf(_SC_ARG_MAX);
}

void pretty_stats_print(void) {
    printf("POSIX Version: %zu\n", get_posix_version());
    printf("XSI Version: %zu\n", get_xsi_version());
    printf("Maximum opened files: %zu\n", get_openmax());
    printf("Maximum arguments per `exec` function: %zu\n", get_maxargs());
}
