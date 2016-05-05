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
    int ret = 0;
    
    key = ftok(SHARED_MEM,0);
    PRINT_ERR(key)

    shm_id=shmget(key,4096,IPC_CREAT|0666);
    PRINT_ERR(shm_id)

    //SHM_RDONLY, RDWR by default
    p_map=(people*)shmat(shm_id,NULL,0);
    PRINT_ERR((void *)p_map==(void *)-1?-1:1)

    temp='a';

    for(i = 0;i<10;i++)
    {
        memcpy((*(p_map+i)).name,&temp,1);
        (*(p_map+i)).age=20+i;
        temp+=1;
    }

    while(1);

    //The shared memory will be detached when exit by default.
    //ret = shmdt(p_map);
    //PRINT_ERR(ret)

    return 0;
}

