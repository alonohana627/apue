#ifndef APUE_UNIX_IO_H
#define APUE_UNIX_IO_H

#include <ioutils.h>
#include <unistd.h>

/*
 * UNIX version of file-to-file copy-and-write
 * */
int u_input_to_output(int fd1, int fd2);

/*
 * UNIX version of stdin-to-stdout
 * */
int u_stdin_to_stdout(void);

#endif
