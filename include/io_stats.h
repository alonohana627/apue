#ifndef APUE_IO_STATS_H
#define APUE_IO_STATS_H

#include "safe_string_arr.h"

void print_error(int err, char *path);

safe_string_arr_t *entries_in_folder(char *path);

int simple_print_entries_in_folder(char *path);

#endif
