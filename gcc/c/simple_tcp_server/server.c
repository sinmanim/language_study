

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/wait.h>
#include<signal.h>

#define MYPORT 3490	// the port users will be connecting to

#define BACKLOG 10	// how many pending connections queue will hold

void sigchld_handler(int s)
{
	while(wait(NULL) > 0);
}

void init_handler(int s)
{
	printf("\t init start\n");
}

int main(argc, argv)
int argc;
char** argv;
{
	int sockfd, new_fd;	// listen on sock_fd, new connection on new_fd
	// struct linger ling;
	struct sockaddr_in my_addr;	// my address information
	struct sockaddr_in their_addr;	// connector's address information
	int sin_size;
	struct sigaction sa, sig_init;
	int yes=1;
	int ret;

	if((sockfd=socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror("socket");
		return 1;
	}

	if(setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1) {
		perror("setsockopt_reuseaddr");
		return 1;
	}

	// ling.l_onoff = 1;
	// ling.l_linger = 0;

	// if(setsockopt(sockfd, SOL_SOCKET, SO_LINGER, (char*)&ling, sizeof(ling))
	//																							==	-1) {
	//	perror("setsockopt_linger");
	//	return 1;
	// }

	my_addr.sin_family = AF_INET;			// host byte order
	my_addr.sin_port = htons(MYPORT);	// short, network byte order
	my_addr.sin_addr.s_addr = htonl(INADDR_ANY); // automatically fill with my IP
	//my_addr.sin_port = htons(atoi(argv[1]));	// manual port
	// my_addr.sin_addr.s_addr = inet_addr("127.0.0.1");	// manual IP
	bzero(&(my_addr.sin_zero), 8);		// zero the rest of the struct

	if(bind(sockfd, (struct sockaddr *)&my_addr, sizeof(struct sockaddr)) 
																								== -1) {
		perror("bind");
		return 1;
	}

	if(listen(sockfd, BACKLOG) == -1) {
		perror("listen");
		return 1;
	}

	sa.sa_handler = sigchld_handler;	// reap all dead processes
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	if(sigaction(SIGCHLD, &sa, NULL) == -1) {
		perror("sigaction");
		return 1;
	}

	sig_init.sa_handler = init_handler;
	sigemptyset(&sig_init.sa_mask);
	//if(sigaction(SIGINT, &sig_init, NULL) == -1) {
	//	perror("sigaction_init");
	//	return 1;
	//}

	while(1) {	// main accept() loop
		sin_size = sizeof(struct sockaddr_in);
		if((new_fd = accept(sockfd, (struct sockaddr *)&their_addr,
																		&sin_size)) == -1) {
			perror("accept");
			continue;
		}
		printf("server: got connection from %s\n",
														inet_ntoa(their_addr.sin_addr));

		ret = fork();

		if(0==ret) {	// this is child process	
			printf("this is child process\n");
			close(sockfd);	// child doesn't need the listener
			if(send(new_fd, "Hello, world!\n", 14, 0) == -1)
				perror("send");
			close(new_fd);
			printf("child process exit\n");
			return 1;
		}
		else {	// this is parent process
			printf("this if parent process\n");
		}

		printf("\t process : %d, parent process : %d, try to close\n"
																	, getpid(), getppid());
		close(new_fd);	// parent doesn't need this
	}

	return 0;
}




