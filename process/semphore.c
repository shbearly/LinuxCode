#include <sys/sem.h>
#include "utilities.h"

int main(int argc, char *argv[])
{
    int i = 0;
    unsigned int pid = 0;
    int sem_id = 0;
    int ret = 0;
    key_t k = 0;
    struct sembuf sem_p = {0, -1, 0};
    struct sembuf sem_v = {0,  1, 0};

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
        ret = semop(sem_id, &sem_p, 1);
        PRINT_ERR(ret);

		printf("%2d: Get right.\n", getpid());

		fflush(stdout);
		sleep(rand() % 3);

        ret = semop(sem_id, &sem_v, 1);
        PRINT_ERR(ret);

		printf("%2d: release right.\n", getpid());
		fflush(stdout);

        sleep(rand() % 3);
	}

	printf("\n%2d: - finished\n", getpid());

    /*
	if(semctl(sem_id, 0, IPC_RMID, sem_union) == -1)
		fprintf(stderr, "Failed to delete semaphore\n");
    */
    
	exit(EXIT_SUCCESS);
}

