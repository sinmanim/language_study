#include <sys/socket.h>
#include <sys/stat.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define MAXLINE 1024

void *thread_func(void *arg);

int main(int argc, char **argv)
{	
	int listenfd, sockfd;
	int th_id;
	int socklen;
	int sockOpt=1;
	struct sockaddr_in sockaddr;	

	pthread_t thread_t;

	if(argc !=2)
	{
		printf("Usage : %s [port]\n", argv[0]);
		return 1;
	}

	if((listenfd = socket(PF_INET, SOCK_STREAM, 0)) < 0)
	{
		perror("socket error");
		return 1;
	}
	if(setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &sockOpt, sizeof(sockOpt)) < 0) {
		perror("error : setsockopt");
		close(listenfd);
		return -1;
	}

	memset((void *)&sockaddr,0x00,sizeof(sockaddr));
	sockaddr.sin_family = AF_INET;
	sockaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	sockaddr.sin_port = htons(atoi(argv[1]));
	
	if(bind(listenfd, (struct sockaddr *)&sockaddr, sizeof(sockaddr)) == -1)
	{
		perror("bind error");
		return 1;
	}
	if(listen(listenfd, 5) == -1)
	{
		perror("listen error");
		return 1;
	}

	while(1)
	{
		printf("client wait ... \n");

		sockfd = accept(listenfd, (struct sockaddr *)&sockaddr, &socklen);
		if(sockfd == -1)
		{
			perror("accept error");
			return 1;
		}
		th_id = pthread_create(&thread_t, NULL, thread_func, (void *)&sockfd);
		if(th_id != 0)
		{
			perror("Thread Create Error");
			return 1;
		}
		pthread_detach(thread_t);
	}
}

void *thread_func(void *arg)
{
	int sockfd;
	int readn, writen;
	char buf[MAXLINE];
	sockfd = *((int *)arg);

	readn = read(sockfd, buf, MAXLINE);
	if(readn <= 0)
	{
		perror("Read Error\n");
		return NULL;
	}

	printf("received ... \n");
	printf("data is => %s\n", buf);
	
	writen = write(sockfd, buf, readn);
	if(readn != writen)
	{
		printf("write error %d : %d\n", readn, writen);
		return NULL;
	}
	
	close(sockfd);

	printf("exit thread\n");

	//pthread_exit(0);
	return ((void *) 0);
}
