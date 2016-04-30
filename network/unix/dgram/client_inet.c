#include <stdio.h>   
#include <sys/socket.h>  
#include <sys/types.h>  
#include <netinet/in.h>  
#include <string.h>  
#include <stdlib.h>   
#define SERVPORT 18888                                 
#define MAXDATASIZE 1000   

int main(int argc, char * argv[]) {   
    int sockfd,client_fd,recvbytes;         
    socklen_t addr_size;
    char rcv_buf[MAXDATASIZE] = "";
    char snd_buf[MAXDATASIZE] = "abcdefghijklmn01234566789"; 
    char * val;  
    int serverPort = SERVPORT;
    struct sockaddr_in server_addr;                       
    struct sockaddr_in client_addr;   
    
    if ( argc > 1 ){
        if ( argv[1][0] == 'h' ){
	    printf("#%s help\n", argv[0]);
            printf("#%s port server speed\n", argv[0]);
        }
    }
    
    if ( argc > 1 )
        serverPort = atoi(argv[1]);
    
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1){      
        perror("socket:error");   
        exit(1);   
    }   

    server_addr.sin_family=AF_INET;     
    server_addr.sin_port=htons(serverPort);             
    server_addr.sin_addr.s_addr = INADDR_ANY;         
    memset(&(server_addr.sin_zero),0,8);   

    while(1)   
    {      
        addr_size = sizeof(struct sockaddr);      
  
        if (sendto(sockfd,snd_buf,strlen(snd_buf),0,  
                               (struct sockaddr*)&server_addr,addr_size) == -1)      
        {  
            perror("send: error");   
            exit(1);  
        }  
        printf("send:%s\n",snd_buf);  

        if ((recvbytes=recvfrom(sockfd,rcv_buf,MAXDATASIZE,0,  
                               (struct sockaddr*)&server_addr,&addr_size)) ==-1)   
        {   
            perror("recv: error");   
            exit(1);   
        }  
        rcv_buf[recvbytes]='\0';  
        printf("recv:%s\n",rcv_buf);  

	//break;
    }   

    return 0;                         
}   

