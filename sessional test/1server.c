#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h>
#define PORT 4455
int main()
{
	int s, c;
	struct sockaddr_in ser, cli;
	socklen_t addr_size;
	s = socket(AF_INET, SOCK_STREAM, 0);
	ser.sin_family = AF_INET;
	ser.sin_port = htons(PORT);
	ser.sin_addr.s_addr = inet_addr("127.0.0.1");
	bind(s, (struct sockaddr *)&ser, sizeof(ser));
	listen(s, 5);
	addr_size = sizeof(c);
	c = accept(s, (struct sockaddr *)&cli, &addr_size);
	printf("Connection accepted from %s:%d\n", inet_ntoa(cli.sin_addr), ntohs(cli.sin_port));
	char *command = "ls";
	system(command);
	write(c, (void *)command, sizeof(command));

	char file_name[10];
	read(c, (void *)file_name, sizeof(file_name));

	FILE *fi;
	fi = fopen(file_name, "r");
	char ch, file_content[1000];
	int i = 0;
	while (ch != EOF)
	{
		ch = fgetc(fi);
		file_content[i] = ch;
		i++;
	}
	printf("%s", file_content);
	fclose(fi);
	write(c, (void *)file_content, 1000);

	close(c);
	close(s);
}
