#ifndef APUE_STATS_H
#define APUE_STATS_H

#include <unistd.h>
#include <errno.h>
#include <limits.h>

void pretty_stats_print(void);

long get_posix_version(void);

long get_xsi_version(void);

long get_openmax(void);

long get_maxargs(void);

#endif
