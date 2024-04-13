#include <apue_shell.h>

#include <sys/wait.h>
#include <unistd.h>

#include <stdio.h>

static void sigint_cb(int);

void run_shell(void) {
    char buf[MAXLINE_SIZE];
    char pwd[PWD_SIZE];

    pid_t pid;
    int status;

    if(signal(SIGINT, sigint_cb) == SIG_ERR){
        printf("Could not register SIGINT to the shell\n");
    }

    getcwd(pwd, PWD_SIZE);
    printf("%s: %% ", pwd);

    while (fgets(buf, MAXLINE_SIZE, stdin) != NULL) {
        if (buf[strnlen(buf, MAXLINE_SIZE) - 1] == '\n') {
            buf[strnlen(buf, MAXLINE_SIZE) - 1] = 0;
        }

        pid = fork();
        if (pid < 0) {
            printf("Fork Error\n");
            return;
        } else if (pid == 0) { /* child */
            safe_string_arr_t *splited_args = split_by_space(buf);
            execvp(splited_args->strings[0], splited_args->strings);
            printf("Couldn't execute %s\n", buf);
            return;
        }

        pid = waitpid(pid, &status, 0);
        if (pid < 0) {
            printf("WaitPID Error\n");
            return;
        }

        getcwd(pwd, PWD_SIZE);
        printf("%s: %% ", pwd);
    }
}

void sigint_cb(int signo) {
    printf("\n=========================\n");
    printf("Shut Down: %d\n", signo);
    printf("=========================\n");
    exit(0);
}
