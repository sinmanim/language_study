

/*
** server.c - a stream socket server demo
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>

#define MYPORT 3490	// the port users will be connecting to

#define BACKLOG 10	// how many pending connections queue will hold

/*
void sigchld_handler(int s)
{
	while(wait(NULL) > 0);
}
*/

int main(int argc, char** argv){


	int status = 99;


	printf("%d", status & 0xff );

	return 0;
}




