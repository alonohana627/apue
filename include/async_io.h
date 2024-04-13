#ifndef APUE_ASYNC_IO_H
#define APUE_ASYNC_IO_H

/* Minimal Async IO lib that works on literally files
 *
 */

#include <aio.h>
#include <stdlib.h>

typedef struct {
    int fd;
    struct aiocb aiocb;
} async_io_t;

async_io_t *async_open(const char *pathname, int flags);

int async_read(async_io_t *aio, void *buf, size_t count);

int async_write(async_io_t *aio, const void *buf, size_t count);

int async_close(async_io_t *aio);

int await_read(async_io_t *aio, void *buf, size_t count);

int await_write(async_io_t *aio, const void *buf, size_t count);

#endif
