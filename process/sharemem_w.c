#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>
#include "utilities.h"

int main(int argc, char** argv)
{
	int shm_id,i;
	key_t key;
	char temp;
	people *p_map;
	char* name = "/dev/shm/myshm2";

    
	key = ftok(name,0);
    PRINT_ERR(key)

	shm_id=shmget(key,4096,IPC_CREAT|0666);
	printf("shm_id:%d\n",shm_id);
    PRINT_ERR(shm_id)

    //SHM_RDONLY, RDWR by default
	p_map=(people*)shmat(shm_id,NULL,0);
    PRINT_ERR((int)p_map)

    temp='a';
	printf("%08x\n", p_map);

    for(i = 0;i<10;i++)
	{
		temp+=1;
		memcpy((*(p_map+i)).name,&temp,1);
		(*(p_map+i)).age=20+i;
	}
	while(1);

    ret = shmdt(p_map);
    PRINT_ERR(shm_id)

    return 0;
}

