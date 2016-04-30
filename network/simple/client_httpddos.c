/* client.c */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <errno.h>
#include <stdio.h>
#include <sys/time.h>
#include <arpa/inet.h>
#include <time.h>
#include <stdlib.h>

//#include "wrap.h"

#define MAXLINE 80
#define SERV_PORT 80

#define CRLN      "\r\n"

#define OPTIONS \
"Host: %s"CRLN \
"Cache-Control: no-cache"CRLN \
"User-Agent: Mu Dynamics/HTTP"CRLN \
"Content-Type: text/html"CRLN \
"Content-Length: 0"CRLN""CRLN

#define BAD_CONNECT \
"CONNECT %s:80 HTTP/1.1" 

#define BAD_GET \
"GET / HTTP/1.1" 
    
#define BAD_OPTION \
"OPTIONS / HTTP/1.1"

#define BAD_TRACE \
"TRACE / HTTP/1.1" 

#define BAD_PUT \
"PUT / HTTP/1.1"

#define BAD_DELETE \
"DELETE / HTTP/1.1" 

enum CONNECTTYPE{
    ENDING = 0,
    BADTCP = 1,
    BADCONNECT,
    BADGET,
    BADOPTION,    
    BADTRACE,
    BADPUT,
    BADDELETE,
    BADMULTIA,
    BADMULTIZ,
    BADMULTIGET,
    BADMULTICONNECT,
    BADMULTIAOPTION,
    BADMULTIZOPTION,
    BADMULTIGETOPTION,
    BADMULTICONNECTOPTION,
    BADNOMETHOD
};

struct message {
    enum CONNECTTYPE type;
    char * message;
    int times; //how many times of message to send
};

struct test{
    struct message  message;
    int times;
};

struct test tests[] = 
{   
    { { BADTCP,                   "" ,            1},  6},
    { { BADCONNECT,               BAD_CONNECT ,   1},  2},
    { { BADGET,                   BAD_GET ,       1},  2},
    { { BADOPTION,                BAD_OPTION ,    1},  3},
    { { BADTRACE,                 BAD_TRACE ,     1},  2},
    { { BADPUT,                   BAD_PUT ,       1},  6},
    { { BADDELETE,                BAD_DELETE ,    1},  6},
    { { BADNOMETHOD,              OPTIONS ,       1},  6},
    { { BADMULTIA,                "A",         2896}, 10},
    { { BADMULTIZ,                "Z",         2896}, 10},
    { { BADMULTIGET,              BAD_GET,      120},  6},
    { { BADMULTICONNECT,          BAD_CONNECT,  120},  6},
    { { BADMULTIAOPTION,          "A",         2896}, 10},
    { { BADMULTIZOPTION,          "Z",         2896}, 10},
    { { BADMULTIGETOPTION,        BAD_GET,      120},  6},
    { { BADMULTICONNECTOPTION,    BAD_CONNECT,  120},  6},
    { { ENDING, "", 0}, 0}
};

char messageSent[10240] = {0};
char *host_name = "10.0.0.1";
int  connection_interval    = 25;

char * produceMessage(struct message * pMessage)
{
    int i = 0;
    struct timeval  currTime;
    int realtimes = 0;
    
    if ( !pMessage ) return NULL;

    gettimeofday(&currTime, NULL);

    //times will be randomized by factor: 0.6,0.7,0.8,0.9,1
    realtimes = ( pMessage->times*(currTime.tv_usec%5 + 6)) / 10; 

    switch(pMessage->type){
        case BADTCP:
            messageSent[0] = 0;
            break;
        case BADCONNECT:
            messageSent[0] = 0;
            sprintf(&messageSent[strlen(messageSent)], pMessage->message, host_name);
            strcat(messageSent, CRLN);
            sprintf(&messageSent[strlen(messageSent)], OPTIONS, host_name);
            break;
        case BADGET:
        case BADOPTION:
        case BADTRACE:
        case BADPUT:
        case BADDELETE:
            messageSent[0] = 0;
            strcat(messageSent, pMessage->message);
            strcat(messageSent, CRLN);
            sprintf(&messageSent[strlen(messageSent)], OPTIONS, host_name);
            break;
        case BADMULTIA:
        case BADMULTIZ:
        case BADMULTIGET:
            messageSent[0] = 0;
            for(i=0; i<realtimes; i++)
                strcat(messageSent, pMessage->message);
            break;
        case BADMULTICONNECT:
            messageSent[0] = 0;
            for(i=0; i<realtimes; i++)
                sprintf(&messageSent[strlen(messageSent)], pMessage->message, host_name);
            break;
        case BADMULTIAOPTION:
        case BADMULTIZOPTION:
        case BADMULTIGETOPTION:
            messageSent[0] = 0;
            for(i=0; i<realtimes; i++)
                strcat(messageSent, pMessage->message);

            strcat(messageSent, CRLN);
            sprintf(&messageSent[strlen(messageSent)], OPTIONS, host_name);
            break;

        case BADMULTICONNECTOPTION:
            messageSent[0] = 0;
            for(i=0; i<realtimes; i++)
                sprintf(&messageSent[strlen(messageSent)], pMessage->message, host_name);

            strcat(messageSent, CRLN);
            sprintf(&messageSent[strlen(messageSent)], OPTIONS, host_name);
            break;
        case BADNOMETHOD:            
            messageSent[0] = 0;
            sprintf(&messageSent[strlen(messageSent)], OPTIONS, host_name);
            break;
    }

    return NULL;
}

int main(int argc, char *argv[])
{
    struct sockaddr_in servaddr;
    char buf[MAXLINE];
    int sockfd, n;
    struct linger m_sLinger;
    int ret = 0;
    int i=0, j=0;
    int len = 0;
    int loops = 10000;
    int totaltimes = 0;
    struct  timespec                sleepTime = {0};
    int connectionNum = 0;

    sleepTime.tv_sec    = 0;
    sleepTime.tv_nsec   = (connection_interval) * (1000000000L / 1000);

    if ( (argc>1 ) && (strcmp(argv[1], "help") == 0 ) ){
        printf("\n#cmd interval hostname\n\n");
        return 1;
    }

    if ( argc >= 2 ) connection_interval=atoi(argv[1]);
    if ( argc >= 3 ) host_name = argv[2];

    while(loops--){
        i = 0;
        while(tests[i].times){
            produceMessage(&tests[i].message);
            printf("sending :\n%s\n\n", messageSent);
            totaltimes++;

            for( j=0; j<tests[i].times; j++){
                sockfd = socket(AF_INET, SOCK_STREAM, 0);

                bzero(&servaddr, sizeof(servaddr));
                servaddr.sin_family = AF_INET;
                inet_pton(AF_INET, host_name, &servaddr.sin_addr);
                servaddr.sin_port = htons(SERV_PORT);

                ret = connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
                if ( ret != 0 ){
                    printf("Error when connecting.\n");
                    return 0;
                }

                ret = 0;
                len = strlen(messageSent);
                while( (ret += write(sockfd, messageSent, len )) < len );

                /* Force to send reset pkt */
                m_sLinger.l_onoff=1;
                m_sLinger.l_linger=0;
                ret = setsockopt(sockfd, SOL_SOCKET, SO_LINGER, (void*)&m_sLinger, sizeof(m_sLinger) );
                if ( ret != 0 ){
                    printf("Error When setting option.errno:%s\n",strerror(errno) );
                    return 0;
                }
                
                close(sockfd);
               
                if ( connection_interval )
                  nanosleep(&sleepTime, NULL);
            }
            i++;
            connectionNum++;
            printf("connectionNum:%d\n",connectionNum);
       }
       //getchar();
    }
    
    printf("totaltimes: %d\n",totaltimes);
    return 0;
}


