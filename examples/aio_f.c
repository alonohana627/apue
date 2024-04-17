#include <async_io.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>

int main(void){
    async_io_t *aio = async_open("./a.txt", O_WRONLY | O_CREAT | O_TRUNC);
    const char *data = "This is a test data.";

    int result = await_write(aio, data, strlen(data));
    if (result != 0) {
        async_close(aio);
        return 1;
    }

    while (aio_error(&aio->aiocb) == EINPROGRESS){
        printf("sleeping\n");
        sleep(1);
    }

    if ((result = aio_error(&aio->aiocb)) != 0) {
        perror("Error writing to file asynchronously");
        async_close(aio);
        return 1;
    }

    printf("Data has been written to the file asynchronously.\n");

    // Close the file
    async_close(aio);

    return 0;
}
