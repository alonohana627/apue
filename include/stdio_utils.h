#ifndef APUE_STDIO_UTILS_H
#define APUE_STDIO_UTILS_H

#include <ioutils.h>
#include <stdio.h>
/*
 * C Standard Library version of file-to-file copy-and-write
 * */
int std_input_to_output(FILE *f1, FILE *f2);


/*
 * C Standard Library version of stdin-to-stdout
 * */
int std_stdin_to_stdout(void);

#endif
