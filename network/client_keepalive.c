/* client.c */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
//#include "wrap.h"

#define MAXLINE 80
#define SERV_PORT 8000

int main(int argc, char *argv[])
{
	struct sockaddr_in servaddr;
	char buf[MAXLINE];
	int sockfd, n;
	unsigned long long i;

	if ( argc < 2 )
		return;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	inet_pton(AF_INET, argv[1], &servaddr.sin_addr);
	servaddr.sin_port = htons(SERV_PORT);

	connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

	i = 0;
	while (sprintf(buf, "%lu", i) > 0) {
		write(sockfd, buf, strlen(buf));
		n = read(sockfd, buf, MAXLINE);
		if (n == 0){
			printf("the other side has been closed.\n");
		}else{
			printf("Send:%lu ", i);
			printf("Recv:%s. \n", buf);
		}

		sleep(3);
		i++;
	}

	close(sockfd);
	return 0;
}
