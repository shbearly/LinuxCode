#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <time.h>
#include <errno.h>
#include <unistd.h>
//#include "wrap.h"
#define MAXLINE 80
#define SERV_PORT 8000

char * myaddr( unsigned int addr )
{
	static char buf[64] = {0};
	unsigned int la = ntohl(addr);
	sprintf(buf, "%lu.%lu.%lu.%lu", la>>24, (la&0xFFFFFF)>>16, (la&0xFFFF)>>8, la&0xFF);
	return buf;
}
int main(void)
{
	struct sockaddr_in servaddr, cliaddr;
	socklen_t cliaddr_len;
	int listenfd, connfd;
	char buf[MAXLINE];
	char str[INET_ADDRSTRLEN];
	int n;
	unsigned long long i;
	time_t t, t2;
	char * pstr;

	listenfd = socket(AF_INET, SOCK_STREAM, 0);
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(SERV_PORT);
	bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
	listen(listenfd, 20);
	printf("Accepting connections ...\n");
	while (1) {
		cliaddr_len = sizeof(cliaddr);
		connfd = accept(listenfd,
				(struct sockaddr *)&cliaddr, &cliaddr_len);
		time(&t);
		pstr = myaddr(cliaddr.sin_addr.s_addr);
		printf("A new connection from %s :", pstr);
		printf("%d at ", ntohs(cliaddr.sin_port));
		printf("%s.\n", ctime(&t));
		fflush(stdout);
		while (1) {
			time(&t);
			n = read(connfd, buf, MAXLINE);
			time(&t2);
			if ( ( t2 - t ) > 6 ){
				printf("\n!!!!Read too long time(%d Seconds). Reboot may happen at %s .\n", t2-t, ctime(&t2));
			}

			if (n == 0) {
				time(&t);
				printf("the other side has been closed at %s.\n", ctime(&t));
				fflush(stdout);
				break;
			}
			if (n < 0) {
				time(&t);
				printf("Connection read error:%s at %s.\n", strerror(errno), ctime(&t));
				fflush(stdout);
				break;
			}
			i = atoi(buf)+1;
		 	sprintf(buf, "%lu", i );
			write(connfd, buf, strlen(buf));
                        printf(".");
			fflush(stdout);
		}
		close(connfd);
	}
}

