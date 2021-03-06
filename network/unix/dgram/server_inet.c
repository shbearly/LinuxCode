#include <stdio.h>   
#include <sys/socket.h>  
#include <sys/types.h>  
#include <netinet/in.h>  
#include <string.h>  
#include <stdlib.h>
#define SERVPORT 18888                                 
#define MAXDATASIZE 3000

int main(int argc, char * argv[]) {   
    int sockfd,client_fd,recvbytes;  
    socklen_t addr_size;
    char rcv_buf[MAXDATASIZE] = "";
    char snd_buf[MAXDATASIZE] ="";  
    char * val;  
    int serverPort = SERVPORT;
    
    
    if ( argc > 1 ){
        if ( argv[1][0] == 'h' ){
	    printf("#%s help\n", argv[0]);
            printf("#%s port\n", argv[0]);
	    exit(1);
        }
    }
    
    if ( argc > 1 )
        serverPort = atoi(argv[1]);
    
    struct sockaddr_in server_addr;                       
    struct sockaddr_in client_addr;                   
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1){      
        perror("socket: error");   
        exit(1);   
    }   
    
    server_addr.sin_family=AF_INET;     
    server_addr.sin_port=htons(serverPort);             
    server_addr.sin_addr.s_addr = INADDR_ANY;         
    memset(&(server_addr.sin_zero),0,8);   

    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr))== -1)   
    {   
        perror("bind: error");   
        exit(1);   
    }     
  
    while(1)   
    {      
        addr_size = sizeof(struct sockaddr);      
  
        if ((recvbytes=recvfrom(sockfd,rcv_buf,MAXDATASIZE,0,  
                               (struct sockaddr*)&client_addr,&addr_size)) ==-1)   
        {   
            perror("recv: error");   
            exit(1);   
        }  
        rcv_buf[recvbytes]='\0';  
        printf("recv:%s\n",rcv_buf);  

        if (sendto(sockfd,rcv_buf,strlen(rcv_buf),0,  
                               (struct sockaddr*)&client_addr,addr_size) == -1)      
        {  
            perror("send: error");   
            exit(1);  
        }  

        printf("send:%s\n",rcv_buf);  
	
	//break;
    }   

    return 0;                         
}   

