#include <unix_io.h>
#include <stdio_utils.h>

int u_input_to_output(int fd1, int fd2) {
    ssize_t n;
    char buffer[IO_BUFFER_SIZE];

    while ((n = read(fd1, buffer, IO_BUFFER_SIZE)) > 0) {
        if ((write(fd2, buffer, n)) != n) {
            return ITO_WRITE_FAIL;
        }
    }

    if (n < 0) {
        return ITO_READ_FAIL;
    }

    return ITO_SUCCESS;
}

int u_stdin_to_stdout(void) {
    return u_input_to_output(STDIN_FILENO, STDOUT_FILENO);
}

int std_input_to_output(FILE *f1, FILE *f2) {
    int c;
    while ((c = fgetc(f1)) != EOF) {
        if (fputc(c, f2) == EOF) {
            return ITO_WRITE_FAIL;
        }
    }

    if (ferror(f1)) {
        return ITO_READ_FAIL;
    }

    return ITO_SUCCESS;
}

int std_stdin_to_stdout(void) {
    return std_input_to_output(stdin, stdout);
}
