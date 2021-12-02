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

int main(){

	int clientSocket, ret;
	struct sockaddr_in serverAddr;
	char buffer[1024];
	char line[MAX_MSG],line2[MAX_MSG];

	clientSocket = socket(AF_INET, SOCK_STREAM, 0);
	if(clientSocket < 0){
		printf("[-]Error in connection.\n");
		exit(1);
	}
	printf("[+]Client Socket is created.\n");

	memset(&serverAddr, '\0', sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(PORT);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	ret = connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
	if(ret < 0){
		printf("[-]Error in connection.\n");
		exit(1);
	}
	printf("[+]Connected to Server.\n");

	while(1){
		printf("Client: \t");

        printf("Enter 1st number : ");

        scanf("%s", line);
        send(clientSocket, line, strlen(line) + 1, 0);

        printf("data sent (%s)\n", line);

        printf("Enter 2nd number : ");

        scanf("%s", line2);

        send(clientSocket, line2, strlen(line2) + 1, 0);

		// scanf("%s", &buffer[0]);
		// send(clientSocket, buffer, strlen(buffer), 0);

		if(strcmp(line, ":exit")==0||strcmp(line2, ":exit") == 0){
			close(clientSocket);
			printf("[-]Disconnected from server.\n");
			exit(1);
		}

		// if(recv(clientSocket, buffer, 1024, 0) < 0){
		// 	printf("[-]Error in receiving data.\n");
		// }else{
		// 	printf("Server: \t%s\n", buffer);
		// }
	}

	return 0;
}
