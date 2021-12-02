#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define MAX_MSG 100

#define PORT 4444

int main()
{

	int sockfd, ret;
	struct sockaddr_in serverAddr; // to store the server info

	int newSocket;
	struct sockaddr_in newAddr; //to store client info

	socklen_t addr_size;

    int n, num1, num2, sum;

	char buffer[1024];
	pid_t childpid;
    char line[MAX_MSG],line2[MAX_MSG];

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
	{
		printf("[-]Error in connection.\n");
		exit(1);
	}
	printf("[+]Server Socket is created.\n");

	memset(&serverAddr, '\0', sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(PORT);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	ret = bind(sockfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr));
	if (ret < 0)
	{
		printf("[-]Error in binding.\n");
		exit(1);
	}
	printf("[+]Bind to port %d\n", 4444);

	if (listen(sockfd, 10) == 0)
	{
		printf("[+]Listening....\n");
	}
	else
	{
		printf("[-]Error in binding.\n");
	}

	while (1)
	{
		newSocket = accept(sockfd, (struct sockaddr *)&newAddr, &addr_size);
		if (newSocket < 0)
		{
			exit(1);
		}
		printf("Connection accepted from %s:%d\n", inet_ntoa(newAddr.sin_addr), ntohs(newAddr.sin_port));

		if ((childpid = fork()) == 0)
		{
			close(sockfd);

			while (1)
			{
				// recv(newSocket, buffer, 1024, 0);

                memset(line, 0x0, MAX_MSG);

            n = recv(newSocket, line, MAX_MSG, 0);

            num1 = atoi(line);

            n = recv(newSocket, line2, MAX_MSG, 0);

            num2 = atoi(line2);

            sum = num1 + num2;

            printf("%d", sum);

				if (strcmp(line, ":exit") == 0||strcmp(line2, ":exit") == 0)
				{
					printf("Disconnected from %s:%d\n", inet_ntoa(newAddr.sin_addr), ntohs(newAddr.sin_port));
					break;
				}
				else
				{
					// printf("Client: %s\n", buffer);
					// send(newSocket, buffer, strlen(buffer), 0);
					// bzero(buffer, sizeof(buffer));
				}
			}
		}
	}

	close(newSocket);

	return 0;
}