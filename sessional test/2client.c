#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#define PORT 4492

int main()
{
    int sockfd, recv;
    char buff[1024];
    struct sockaddr_in servaddr, cliaddr;
    socklen_t servlen;
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1)
    {
        perror("Socket");
        return 0;
    }

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = INADDR_ANY;

    sendto(sockfd, buff, sizeof(buff), 0, (struct sockaddr *)&servaddr, sizeof(servaddr));
    recv = recvfrom(sockfd, buff, sizeof(buff), 0, (struct sockaddr *)&servaddr, &servlen);
    buff[recv] = 0;

    printf("\nTime=%s\n", buff);
    exit(0);
    return 0;
}