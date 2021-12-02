#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

struct client
{
char name[20];
int user_id;
int pswd;
}c1,c2,c3,c4,c5;

int main(int argc, char* argv[])
{
     
       strcpy(c1.name,"Paddy");
       c1.user_id=1;
       c1.pswd=1;
     
 strcpy(c2.name,"suki");
       c2.user_id=2;
       c2.pswd=2;
     
 strcpy(c3.name,"shinigami");
       c3.user_id=3;
       c3.pswd=3;
      
 strcpy(c4.name,"abhishek");
       c4.user_id=4;
       c4.pswd=4;
     
 strcpy(c5.name,"tuhin");
       c5.user_id=5;
       c5.pswd=5; 
       
	int socket_desc, client_sock, c, read_size;
	struct sockaddr_in server, client;
	int message, i;
	char str[5]="Done", pass[]= "User Found give PASSWORD:", error[]= "Wrong pass word!";

	socket_desc = socket(AF_INET, SOCK_STREAM, 0);
	if (socket_desc == -1) {
		printf("Could not create socket");
	}
	puts("Socket created");

	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(8880);

	if (bind(socket_desc, (struct sockaddr*)&server, sizeof(server)) < 0) {

		perror("bind failed. Error");
		return 1;
	}

	listen(socket_desc, 3);

	puts("Waiting for incoming connections...");
	c = sizeof(struct sockaddr_in);

	client_sock = accept(socket_desc, (struct sockaddr*)&client, (socklen_t*)&c);

	read_size = recv(client_sock, &message, 10 * sizeof(int), 0);
	
	if(read_size>0)
	{

	printf ("Login Details \n");
	if(message==c1.user_id)
	{
		write(client_sock,str ,sizeof(pass) );
		read_size = recv(client_sock, &message, 10 * sizeof(int), 0);
		if (message==c1.pswd)
		{
			printf("Name is %s \n", c1.name);
			printf("User ID is %d\n",c1.user_id);
			printf("Password is %d\n",c1.pswd);
		}
		else 
			write(client_sock,str ,sizeof(error) );
	}
	else if(message==c2.user_id)
	{
		write(client_sock,str ,sizeof(pass) );
		read_size = recv(client_sock, &message, 10 * sizeof(int), 0);
		if (message==c2.pswd)
		{
			printf("Name is %s\n ", c2.name);
			printf("User ID is %d \n",c2.user_id);
			printf("Password is %d\n",c2.pswd);
		}
		else 
			write(client_sock,str ,sizeof(error) );
	}
	else if(message==c3.user_id)
	{
		write(client_sock,str ,sizeof(pass) );
		read_size = recv(client_sock, &message, 10 * sizeof(int), 0);
		if (message==c3.pswd)
		{
			printf("Name is %s \n", c3.name);
			printf("User ID is %d \n",c3.user_id);
			printf("Password is %d \n",c3.pswd);
		}
		else 
			write(client_sock,str ,sizeof(error) );
		
	}	
	else if(message==c4.user_id)
	{
		write(client_sock,str ,sizeof(pass) );
		read_size = recv(client_sock, &message, 10 * sizeof(int), 0);
		if (message==c4.pswd)
		{
			printf("Name is %s \n", c4.name);
			printf("User ID is %d \n",c4.user_id);
			printf("Password is %d \n",c4.pswd);
		}
		else 
			write(client_sock,str ,sizeof(error) );
	}
	else if(message==c5.user_id) 
	{
		write(client_sock,str ,sizeof(pass) );
		read_size = recv(client_sock, &message, 10 * sizeof(int), 0);
		if (message==c5.pswd)
		{
			printf("Name is %s \n", c5.name);
			printf("User ID is %d \n",c5.user_id);
			printf("Password is %d \n",c5.pswd);
		}
		else 
			write(client_sock,str ,sizeof(error) );
	}
	else
		printf("No such client exists\n");
	}
	return 0;
}
