

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

//pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *do_loop(void * data)
{
	int i;
	
	//pthread_mutex_lock(&mutex);

	i = *((int *)data);
	printf("id=%d\n", i);

	//pthread_mutex_unlock(&mutex);

	return;
}

void main()
{
	int j, k;
	pthread_t p_thread[3];

	for(j=0; j<3; j++)
	{
		printf("for j=%d\n", j);
		pthread_create(&p_thread[j], NULL, do_loop, (void *)&j);
	}

	for(k=0; k<3; k++)
	{
		pthread_join(p_thread[k], NULL);
	}

	puts("end");
}
