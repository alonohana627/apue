#ifndef APUE_APUE_SHELL_H
#define APUE_APUE_SHELL_H

#include <safe_string_arr.h>

#define MAXLINE_SIZE 256

/*
 * Splits args by spaces and returns them as string array
 */
safe_string_arr_t *get_args(char *args);

void run_shell(void);

#endif
