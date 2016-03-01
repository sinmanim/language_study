

/*
** get_host_by_name.c - a hostname lookup demo
*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(argc, argv)
int argc;
char** argv;
{
	struct hostent *h;

	if(argc != 2) {	// error check the command line
		fprintf(stderr, "usage: get_host_by_name address\n");
		exit(1);
	}

	if((h=gethostbyname(argv[1])) == NULL) {	// get the host info
		herror("gethostbyname");
		exit(1);
	}

	printf("Host name : %s\n", h->h_name);
	printf("IP Address : %s\n", inet_ntoa(*((struct in_addr *)h->h_addr)));

	// printf("test argc => %d\n", argc);
	// printf("test argv => %s\n", argv[1]);

	return 0;
}





