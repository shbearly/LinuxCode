

#define PRINT_ERR(int ret) \
    if ( ret < 0 ){  \
        printf("Call is fail at line %d, function:%s, ret:%d -- %s\n", __LINE__, __FUNCTION__, ret, strerror(errno)); \
        exit(-1); \
    }

typedef struct{
    char name[4];
    int age;
} people;

