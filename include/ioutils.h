#ifndef APUE_IOUTILS_H
#define APUE_IOUTILS_H

#define IO_BUFFER_SIZE 4096

typedef enum {
    ITO_SUCCESS = 0,
    ITO_READ_FAIL = 1,
    ITO_WRITE_FAIL = 2
} input_to_output_status;

#endif
