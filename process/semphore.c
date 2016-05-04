#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/sem.h>
#include <errno.h>

union semun
{
	int val;
	struct semid_ds *buf;
	unsigned short *arry;
};

static int semaphore_p();
static int semaphore_v();

#define PRINT_ERR(ret) \
    if ( ret < 0 ){  \
        printf("Call is fail at line %d, function:%s, ret:%d -- %s\n", __LINE__, __FUNCTION__, ret, strerror(errno)); \
        exit(-1); \
    }

int main(int argc, char *argv[])
{
    char message = 'X';
    int i = 0;
    key_t k = 0;
    unsigned int pid = 0;
    int ret = 0;
    struct sembuf sem_p = {0, -1, 0};
    struct sembuf sem_v = {0,  1, 0};

    int sem_id = 0;

    k = ftok("/proc/uptime", 1);
    PRINT_ERR(k)
    
	sem_id = semget(k, 1, 0666 | IPC_CREAT);
    PRINT_ERR(sem_id);

	ret = semctl(sem_id, 0, SETVAL, 2);
    PRINT_ERR(ret);

    pid = fork();
    pid = fork();
    
	for(i = 0; i < 4; ++i)
	{
        if(semop(sem_id, &sem_p, 1) == -1)
        {
            fprintf(stderr, "semaphore_p failed\n");
            return 0;
        }

		printf("%2d: Get right.\n", getpid(), message);

		fflush(stdout);
		sleep(rand() % 3);

        if(semop(sem_id, &sem_v, 1) == -1)
        {
            fprintf(stderr, "semaphore_v failed\n");
            return 0;
        }

		printf("%2d: release right.\n", getpid());

	}

	printf("\n%2d: - finished\n", getpid());

    /*
	if(semctl(sem_id, 0, IPC_RMID, sem_union) == -1)
		fprintf(stderr, "Failed to delete semaphore\n");
    */
    
	exit(EXIT_SUCCESS);
}

