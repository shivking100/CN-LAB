#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main(){
	
	
	// create the server socket
	int server_socket;
	server_socket = socket(AF_INET, SOCK_STREAM, 0);
	
	//define the server address
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(8080);
	server_address.sin_addr.s_addr = INADDR_ANY;
	
	// bind the socket to our specified IP and port
	int bind_sock = bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));
	if(bind_sock<0){
		perror("Bind failed");
		exit(EXIT_FAILURE);
	}
	listen(server_socket, 5);//5 - backlog(how many connections can be waiting for this socket)
	char server_message[256];
	int client_socket;
	client_socket = accept(server_socket, NULL, NULL);
	while(1){
		// receive response
		char client_response[256];
		recv(client_socket, &client_response, sizeof(client_response), 0);
		printf("Client : %s\n",client_response);
		
		if(strcmp(client_response,"exit")==0){
			send(client_socket, "exit", sizeof("exit"), 0);
			close(server_socket);
			return 0;
		}
		// send the message
		printf("Enter your message : ");
		scanf("%s",server_message);
		send(client_socket, server_message, sizeof(server_message), 0);
		
	}
	// close the socket
	close(server_socket);
	return 0;
}
