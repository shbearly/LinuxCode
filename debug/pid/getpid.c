#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define EMPTY_STRING "NULL"
 char * getparent_cmd_string(int pid)
{
	static char str[1024] = {0};
	int    ppid = 0;
	int    myPid = 0;
	char   fileName[64] = {0};
	const char * pStr = NULL;
	FILE  *fd = NULL;
	int i = 0;

	if ( pid == 0 )
		myPid = getpid();
	else
		myPid = pid;
	
	sprintf(fileName, "/proc/%d/status",myPid);
	fd = fopen(fileName, "r");
	if ( fd <= 0 ){
		printf("error open myPid status file in sysevent.\n");
		return EMPTY_STRING;
	}
	
	while(pStr = fgets(str, sizeof(str)-1, fd ))
	{
		if ( !pStr )
			break;
		
		if( strstr(str, "PPid:" ) )
			break;
	}

	fclose(fd);

	if ( pStr == NULL ){
		printf("error get ppid in sysevent.\n");
		return EMPTY_STRING;
	}

	i = strlen("PPid:");
	while( str[i] && ( (str[i]==' ') || (str[i]=='\t') ) )
		i++;

	if ( !str[i]){
		printf("error get ppid string in sysevent.\n");
		return EMPTY_STRING;
	}

	ppid = atoi(&str[i]);
	if ( ppid < 1 ){
		printf("error get ppid integer in sysevent.\n");
		return EMPTY_STRING;
	}

	sprintf(fileName, "/proc/%d/cmdline", ppid);

	fd = fopen(fileName, "r");
	if ( fd <= 0 ){
		printf("error open cmdline file in sysevent.\n");
		return EMPTY_STRING;
	}

	pStr = fgets(str, sizeof(str)-1, fd );
	fclose(fd);

	if ( pStr == NULL ){
		printf("error get cmd line in sysevent.\n");
		return EMPTY_STRING;
	}

	if ( strstr(str,"/bin/sh") || strstr(str,"/bin/bash")){
                printf("not right:%s\n",str);
 		return getparent_cmd_string(ppid);
        }
        else
                return str;
}

int main(int argc, char * argv[])
{
   
    //printf("my pparent is :%s:%s.\n", getenv("CMDLINE")==NULL?"":getenv("CMDLINE"), getenv("LINENO")==NULL?"":getenv("LINENO") );
    printf("result: %s\n", getparent_cmd_string(0) );

    return 1;
}
