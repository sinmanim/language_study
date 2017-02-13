#include <sys/socket.h> 
#include <sys/stat.h> 
#include <arpa/inet.h> 
#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h>
#include <string.h> 
 
#define MAXBUF  2048 

int main(int argc, char **argv) 
{ 
	int server_sockfd, client_sockfd; 
	int client_len, n; 
	char buf[MAXBUF], cbuf[10]; 
	struct sockaddr_in clientaddr, serveraddr; 
 
	if(argc != 2)
	{
		printf("Usage : %s [port]\n", argv[0]); 
		exit(0);	
	}

	client_len = sizeof(clientaddr); 

	// .. ...   
	if ((server_sockfd = socket (AF_INET, SOCK_STREAM, 0)) < 0) 
	{ 
		perror("socket error : "); 
		exit(0); 
	} 

	// ... ... ....
	bzero(&serveraddr, sizeof(serveraddr)); 
	serveraddr.sin_family = AF_INET; 
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY); 
	serveraddr.sin_port = htons(atoi(argv[1])); 
	bind (server_sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)); 

	// .. .. .... ....
	listen(server_sockfd, 5); 
 
	while(1) 
	{ 
		memset(buf, 0x00, MAXBUF); 
		client_sockfd = accept(server_sockfd, (struct sockaddr *)&clientaddr, &client_len); 
		while(1)
		{
			if ((n = read(client_sockfd, buf, MAXBUF)) <= 0) 
			{ 
				close(client_sockfd); 
				break;
			} 
			
			printf("received ... \n");
			printf("data is => %s\n", buf);
			memset(cbuf, 0x00, 10);
			strncpy(cbuf, buf, 9);

			if (write(client_sockfd, cbuf, 10) <=0) 
			{ 
				perror("write error : "); 
				close(client_sockfd); 
				break;
			} 

			printf("send... \n");			

		}
		close(client_sockfd); 
	} 
} 
