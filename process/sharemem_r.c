#include <sys/shm.h>
#include <unistd.h>
#include "utilities.h"

int main(int argc, char** argv)
{
    int shm_id,i;
    key_t key;
    people *p_map;
    int ret = 0;
    
    key = ftok(SHARED_MEM,0);
    PRINT_ERR(key)
        
    shm_id = shmget(key,4096,/*IPC_CREAT*/0666);	
    PRINT_ERR(shm_id)
        
    p_map = (people*)shmat(shm_id,NULL,0);
    PRINT_ERR((void *)p_map==(void *)-1?-1:1)

    for(i = 0;i<10;i++)
    {
        printf( "name:%s\n",(*(p_map+i)).name );
        printf( "age %d\n",(*(p_map+i)).age );
    }
    
    ret = shmdt(p_map);
    PRINT_ERR(ret)

    return 0;
}

