#ifndef APUE_IO_STATS_H
#define APUE_IO_STATS_H

#include "safe_string_arr.h"

void print_error(int err, const char *path);

safe_string_arr_t *entries_in_folder(const char *path);

int simple_print_entries_in_folder(char *path);

void enhanced_ls(const char *path);

void full_file_info(const char *path);

#endif
