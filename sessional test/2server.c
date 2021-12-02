#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <time.h>
#define PORT 4492

int main()
{
    int socket_fd, recv, bind_status;
    char buff[1024];
    struct sockaddr_in servaddr, cliaddr;
    socklen_t cli_len;
    socket_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (socket_fd == -1)
    {
        perror("Socket");
        return 0;
    }

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = INADDR_ANY;

    bind_status = bind(socket_fd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    if (bind_status == -1)
    {
        perror("Bind()");
        return 0;
    }

    cli_len = sizeof(cliaddr);
    recv = recvfrom(socket_fd, buff, sizeof(buff), 0, (struct sockaddr *)&cliaddr, &cli_len);
    buff[recv] = 0;
    time_t t;
    t = time(NULL);
    snprintf(buff, sizeof(buff), "%s\n", ctime(&t));
    sendto(socket_fd, buff, sizeof(buff), 0, (struct sockaddr *)&cliaddr, sizeof(cliaddr));
    exit(0);
    return 0;
}