#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#define PRINT_ERR(ret) \
    if ( ret < 0 ){  \
        printf("Call is fail at line %d, function:%s, ret:%d -- %s\n", __LINE__, __FUNCTION__, ret, strerror(errno)); \
        exit(-1); \
    }

typedef struct{
    char name[4];
    int age;
} people;

#define SHARED_MEM "/dev/shm/myshm2"
