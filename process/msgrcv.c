#include "utilities.h"
#include <sys/ipc.h>
#include <sys/msg.h>

#define BUFSIZE 256

int creat_msg_queue()
{
        key_t key;
        int proj_id;
        int msqid;

        struct msqid_ds buffer;

        proj_id=2;
        key=ftok("/proc/1/cmdline",proj_id);
        if(key==-1){
                perror("cannot generate the IPC key");
                return -1;
        }

        msqid=msgget(key,IPC_CREAT | 0660);
        if(msqid==-1){
                perror("cannot create message queue resource");
                return -1;
        }

	return msqid;
}

typedef struct {
        long mtype;
        char mtext[BUFSIZ];
}msg_info;

int recv_msg(int msqid,int msg_type,char* msg)
{
	int result;
	msg_info buffer;

	result=msgrcv(msqid,&buffer,sizeof(buffer),msg_type,0);
        PRINT_ERR(result)

	strcpy(msg,buffer.mtext);	

	return result;
}

int main(int argc,char* argv[])
{
	char buf[BUFSIZ];
	int msqid;
	int msg_type;
	int result;

        msqid = creat_msg_queue();
	msg_type=100;
	printf("msqid is :%d, msg type is:%d\n", msqid, msg_type);
	
	result=recv_msg(msqid,msg_type,buf);
	if(result==-1){
		printf("cannot get message");
		return -1;
	}else
		printf("message queue id: %d message type : %d message : %s\n",msqid,msg_type,buf);

	//If not remove, this message queue will be in kernel forever
	result =msgctl(msqid, IPC_RMID, NULL);
	PRINT_ERR(result)

	return 0;
}
