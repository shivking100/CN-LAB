#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <errno.h>
#define PORT 4455
extern int errno;
int main()
{
	int id;
	struct sockaddr_in ser;
	id = socket(AF_INET, SOCK_STREAM, 0);
	ser.sin_family = AF_INET;
	ser.sin_port = htons(PORT);
	ser.sin_addr.s_addr = inet_addr("127.0.0.1");
	connect(id, (struct sockaddr *)&ser, sizeof(ser));
	char *a;
	read(id, (void *)a, sizeof(a));
	system(a);
	char file_name[10];
	int n;
	printf("\n choose any one of the txt file ");
	scanf("%d", &n);
	switch (n)
	{
	case 1:
		strcpy(file_name, "ARP.txt");
		break;
	case 2:
		strcpy(file_name, "DHCP.txt");
		break;
	case 3:
		strcpy(file_name, "ICMP.txt");
		break;
	default:
		printf("\nWrong Entry");
		break;
	}
	printf("%s", file_name);
	write(id, (void *)file_name, sizeof(file_name));
	//  FILE *fi;
	// fi=fopen(file_name,"r");
	// char ch,file_content[1000];
	// int i=0;
	// while(ch!=EOF){
	// 	ch=fgetc(fi);
	// 	file_content[i]=ch;
	// 	i++;
	// }
	// printf("%s",file_content);
	// fclose(fi);
	// write(id,(void *)file_content,sizeof(file_content));

	char file_content[1000];
	read(id, (void *)file_content, 1000);
	printf("%s", file_content);

	close(id);
}
