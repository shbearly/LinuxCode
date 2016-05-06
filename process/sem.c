#include <sys/shm.h>
#include <sys/sem.h>
#include <semaphore.h>
#include "utilities.h"


int main(int argc, char *argv[])
{
    int i = 0;
    int ret = 0;
    pid_t pid = 0;

    key_t key;
    char temp;
    int shm_id;
    
    sem_t * plock;

    key = ftok(SHARED_MEM,0);
    PRINT_ERR(key)

    shm_id=shmget(key,4096,IPC_CREAT|0666);
    PRINT_ERR(shm_id)

    //SHM_RDONLY, RDWR by default
    plock=(sem_t *)shmat(shm_id,NULL,0);
    PRINT_ERR((void *)plock==(void *)-1?-1:1)
    
    ret = sem_init(plock, 1, 1);
    PRINT_ERR(ret)

    pid = fork();
    pid = fork();

    printf("%d : try to get right.\n", getpid());
    fflush(stdout);

    ret = sem_wait(plock);
    PRINT_ERR(ret)

    printf("%d : Got right.\n", getpid());
    fflush(stdout);

    printf("%d : sleep for a while.\n", getpid());
    fflush(stdout);
    sleep(random()%4);

    ret = sem_post(plock);
    PRINT_ERR(ret)

    printf("%d : Released right.\n", getpid());
    fflush(stdout);

    exit(EXIT_SUCCESS);
}

