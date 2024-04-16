#ifndef APUE_UNIX_IO_H
#define APUE_UNIX_IO_H

#include <ioutils.h>
#include <safe_string_arr.h>

#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>
#include <sys/stat.h>

/*
 * UNIX version of file-to-file copy-and-write
 * */
int u_input_to_output(int fd1, int fd2);

/*
 * UNIX version of stdin-to-stdout
 * */
int u_stdin_to_stdout(void);

safe_string_arr_t *get_dir_and_file(char *buf);

char *path_alloc(size_t *sizep);

/*
 * Better Macro Names
 */

#define ReadByOwner S_IRUSR
#define WriteByOwner S_IWUSR
#define ExecByOwner S_IXUSR

#define RWEByOwner S_IRWXU

#define ReadByGroup S_IRGRP
#define WriteByGroup S_IWGRP
#define ExecByGroup S_IXGRP

#define RWEByGroup S_IRWXG

#define ReadByOthers S_IROTH
#define WriteByOthers S_IWOTH
#define ExecByOthers S_IXOTH

#define RWEByOthers S_IRWXO

/*
 * Abstractions and Utilities
 */

void new_file(const char *path);

char *file_content(const char *path);

safe_string_arr_t *file_content_as_lines(const char *path);

bool can_offset(void);

#endif
