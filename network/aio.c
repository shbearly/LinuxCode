#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <linux/aio_abi.h>
#include <sys/syscall.h>
#include <sys/eventfd.h>

int main()
{      
        int fd = open("aio.c", O_DIRECT|O_RDONLY, 0);
      
        aio_context_t ctx;
        unsigned nr_events = 10;
        memset(&ctx, 0, sizeof(ctx)); // It's necessary.......
        syscall(SYS_io_setup, nr_events, &ctx);
      
        char* buf = valloc (1024);
        struct iocb *iocbpp = (struct iocb *)malloc(sizeof(struct iocb));
        memset(iocbpp, 0, sizeof(struct iocb));
        iocbpp[0].aio_lio_opcode = IOCB_CMD_PREAD; // operation
        iocbpp[0].aio_fildes = fd;
        iocbpp[0].aio_buf = (uint64_t) (uintptr_t)buf;
        iocbpp[0].aio_nbytes = 1024;
        iocbpp[0].aio_offset = 0;
        syscall(SYS_io_submit, ctx, 1, &iocbpp);
      
        struct io_event events[10];
        struct timespec timeout = {1, 100};
        syscall (SYS_io_getevents, ctx, 1, 10, events, &timeout);

        int i;
        for (i=0; i<1024; i++)
        printf ("%c", buf[i]);

        close(fd);      
        syscall (SYS_io_destroy, ctx);
        return 0;
}
