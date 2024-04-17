#ifndef APUE_STDIO_UTILS_H
#define APUE_STDIO_UTILS_H

#include <stdio.h>
#include <ioutils.h>
#include <safe_string_arr.h>

/*
 * C Standard Library version of file-to-file copy-and-write
 * */
int std_input_to_output(FILE *f1, FILE *f2);


/*
 * C Standard Library version of stdin-to-stdout
 * */
int std_stdin_to_stdout(void);

int create_new_file(const char *path);

safe_string_arr_t *mingrep(const char *path, const char *pattern);

#endif
