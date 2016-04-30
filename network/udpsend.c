#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>

int main(int argc, char *argv[])
{
    int sockfd, err;
    struct addrinfo hints, *res;
    char buf[1024];

    if (argc != 3) {
        fprintf(stderr, "usage: ./udpsend6 <ip> <port>\n");
        exit(1);
    }

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_DGRAM;
    hints.ai_protocol = IPPROTO_UDP;
    if ((err = getaddrinfo(argv[1], argv[2], &hints, &res)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(err));
        exit(1);
    }

    if ((sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol)) < 0) {
        perror("socket");
        exit(1);
    }

    snprintf(buf, sizeof(buf), "hello, I'm %d\n", getpid());
    err =setsockopt(sockfd, SOL_SOCKET, SO_BINDTODEVICE, "eth0", strlen("eth0") + 1);
    assert(err==0);

    while (1) {
        if (sendto(sockfd, buf, strlen(buf), 0, res->ai_addr, res->ai_addrlen) < 0) {
            perror("send");
            exit(1);
        }

        sleep(1);
    }

    freeaddrinfo(res);
    close(sockfd);
    exit(1);
}

