//#include <async_io.h>
//#include <unistd.h>
//#include <fcntl.h>
//#include <errno.h>
//
//async_io_t *async_open(const char *pathname, int flags) {
//    async_io_t *aio = (async_io_t *) malloc(sizeof(async_io_t));
//    if (aio == NULL) {
//        free(aio);
//        return NULL;
//    }
//    aio->fd = open(pathname, flags);
//    if (aio->fd == -1) {
//        free(aio);
//        return NULL;
//    }
//
//    aio->aiocb.aio_fildes = aio->fd;
//    aio->aiocb.aio_offset = 0;
//    aio->aiocb.aio_buf = NULL;
//
//    return aio;
//}
//
//int async_read(async_io_t *aio, void *buf, size_t count) {
//    aio->aiocb.aio_buf = buf;
//    aio->aiocb.aio_nbytes = count;
//    aio_read(&aio->aiocb);
//    return aio_error(&aio->aiocb);
//}
//
//int async_write(async_io_t *aio, const void *buf, size_t count) {
//    aio->aiocb.aio_buf = (void *) buf;
//    aio->aiocb.aio_nbytes = count;
//    aio_write(&aio->aiocb);
//    return aio_error(&aio->aiocb);
//}
//
//int async_close(async_io_t *aio) {
//    int result = close(aio->fd);
//    free(aio);
//    return result;
//}
//
//int await_read(async_io_t *aio, void *buf, size_t count) {
//    aio->aiocb.aio_buf = buf;
//    aio->aiocb.aio_nbytes = count;
//    aio_read(&aio->aiocb);
//    // TODO: change the prio to the maximum
//    aio->aiocb.aio_reqprio = 10;
//
//    while (aio_error(&aio->aiocb) == EINPROGRESS);
//
//    return aio_error(&aio->aiocb);
//}
//
//int await_write(async_io_t *aio, void *buf, size_t count) {
//    aio->aiocb.aio_buf = buf;
//    aio->aiocb.aio_nbytes = count;
//    aio_write(&aio->aiocb);
//    // TODO: change the prio to the maximum
//    aio->aiocb.aio_reqprio = 10;
//
//    while (aio_error(&aio->aiocb) == EINPROGRESS);
//
//    return aio_error(&aio->aiocb);
//}
