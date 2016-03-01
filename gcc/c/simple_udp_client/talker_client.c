

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>

#define MYPORT 4950	// the port users will be connecting to 

int main(argc, argv)
int argc;
char** argv;
{
	int sockfd;
	struct sockaddr_in their_addr;	// connector's address information
	struct hostent *he;
	int numbytes;

	if(argc != 3) {
		fprintf(stderr, "usage: talker hostname message\n");
		return 1;
	}

	if((he=gethostbyname(argv[1])) == NULL) {	// get the host info
		perror("gethostbyname");
		return 1;
	}

	if((sockfd=socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
		perror("socket");
		return 1;
	}

	their_addr.sin_family=AF_INET;	// host byte order
	their_addr.sin_port=htons(MYPORT);	// short, network byte order
	their_addr.sin_addr=*((struct in_addr *)he->h_addr);
	bzero(&(their_addr.sin_zero), 8);	// zero the rest of the struct

	if((numbytes=sendto(sockfd, argv[2], strlen(argv[2]), 0, (struct
						sockaddr*)&their_addr, sizeof(struct sockaddr))) == -1) {
		perror("recvfrom");
		return 1;
	}

	printf("send %d bytes to %s\n", numbytes, 
														inet_ntoa(their_addr.sin_addr));
	close(sockfd);

	return 0;
}

