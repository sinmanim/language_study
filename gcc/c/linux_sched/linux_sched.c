#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <pthread.h>

#include <sys/time.h>
#include <time.h>

int l = 1;
int m = 2;
int n = 3;
int o = 4;

void *run(void *pdata)
{
	int r = *(int *)pdata;
	while (1)
		printf("%d", r);
//		sleep(100);
	
}

int	taskcreate(void* (*start)(void*), void* pArg, void* pData)
{
	//int pthread_create(pthread_t * thread, pthread_attr_t *attr, void * (*start_routine)(void *), void * arg);
	int nErr = 0;
	pthread_t pid;
	nErr = pthread_create(&pid, NULL, start, pArg);

	return nErr;
}

void *manage(void *pdata)
{
	taskcreate(run, (void *)&l, NULL);
	taskcreate(run, (void *)&m, NULL);
	taskcreate(run, (void *)&n, NULL);
	while(1)
	{
		printf("%d", o);	
	}
}	

int main(int argc, char **argv)
{
	//taskcreate(run, NULL, NULL);
	taskcreate(run, (void *)&l, NULL);
	taskcreate(run, (void *)&m, NULL);
	taskcreate(run, (void *)&n, NULL);
	while (1)
	{
		printf("m");
//		sleep(100);
	}
}
