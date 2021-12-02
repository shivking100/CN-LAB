#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <netdb.h>
#include <string.h>
#include <netinet/in.h>
#include <stdlib.h>
#define LSIZ 128 
#define RSIZ 10 
int main()
{
    int cs, bs, res;
    cs = socket(AF_INET, SOCK_STREAM, 0);
    char c[25];
    char b[100];
    char line[RSIZ][LSIZ];
    int return_status=0;

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(6012);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    connect(cs, (struct sockaddr *)&server, sizeof(struct sockaddr));
    recv(cs,&b,sizeof(b),0);
    printf("available files");
    printf("%s\n",b);
    printf("Enter the name of the file to send\n");
    scanf("%s", c);
    send(cs, (void *)c, sizeof(c), 0);
    printf("FileName sent to server\n");
    // int n = recv(cs, (void *)&res, sizeof(res), 0);
    // printf("Addition Result: %d", res);

    int received_int = 0;

return_status = read(cs, &received_int, sizeof(received_int));
    recv(cs,&line,sizeof(line),0);

    for(int i=0;i<sizeof(line);i++)
    {
        printf("%s\n",line[i]);
    }

    close(cs);
}