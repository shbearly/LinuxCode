#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>
#include "utilities.h"

int main(int argc, char** argv)
{
	int shm_id,i;
	key_t key;
	people *p_map;
	char* name = "/dev/shm/myshm2";
    
	key = ftok(name,0);
    PRINT_ERR(key)
        
	shm_id = shmget(key,4096,/*IPC_CREAT*/0666);	
    PRINT_ERR(shm_id)
        
	p_map = (people*)shmat(shm_id,NULL,0);
    PRINT_ERR((int)p_map)

	for(i = 0;i<10;i++)
	{
		printf( "name:%s\n",(*(p_map+i)).name );
		printf( "age %d\n",(*(p_map+i)).age );
	}
    
	ret = shmdt(p_map);
    PRINT_ERR((int)p_map)

    return 0;
}

