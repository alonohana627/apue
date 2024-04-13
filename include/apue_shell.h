#ifndef APUE_APUE_SHELL_H
#define APUE_APUE_SHELL_H

#include <linux/rbtree.h>
#include <safe_string_arr.h>

#define MAXLINE_SIZE 256
#define PWD_SIZE 1024

void run_shell(void);

#endif
