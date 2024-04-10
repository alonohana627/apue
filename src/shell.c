#include <apue_shell.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

safe_string_arr_t *get_args(char *args) {
    int begin = 0;
    int end = 0;
    char *copy;
    char *tmp;
    safe_string_arr_t *splited_args = safe_string_arr_create();

    for (copy = args; *copy != '\0'; copy++) {
        end++;
        if (*copy == ' ') {
            tmp = (char *) malloc((end - begin-1) * sizeof(char));
            if (tmp == NULL) {
                safe_string_arr_destroy(splited_args);
                free(tmp);
                return NULL;
            }

            strncpy(tmp, args + begin, end - begin-1);
            safe_string_arr_add(splited_args, tmp);
            begin = end;
        }
    }

    tmp = (char *) malloc((end - begin) * sizeof(char));
    strncpy(tmp, args + begin, end - begin);
    safe_string_arr_add(splited_args, tmp);

    return splited_args;
}

void run_shell(void) {
    char buf[MAXLINE_SIZE];
    pid_t pid;
    int status;

    printf("%% ");

    while (fgets(buf, MAXLINE_SIZE, stdin) != NULL) {
        if (buf[strnlen(buf, MAXLINE_SIZE) - 1] == '\n') {
            buf[strnlen(buf, MAXLINE_SIZE) - 1] = 0;
        }

        pid = fork();
        if (pid < 0) {
            printf("Fork Error\n");
            return;
        } else if (pid == 0) { /* child */
            safe_string_arr_t *splited_args = get_args(buf);
            execvp(splited_args->strings[0], splited_args->strings);
            printf("Couldn't execute %s\n", buf);
            return;
        }

        pid = waitpid(pid, &status, 0);
        if (pid < 0) {
            printf("WaitPID Error\n");
            return;
        }
        printf("%% ");
    }
}
