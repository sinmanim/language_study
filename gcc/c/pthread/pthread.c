

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

void *t_function(void* data)
{
	int id;
	int i=0;

	id = *((int*)data);

	while(1)
	{
		printf("(%lu) %d : %d\n", pthread_self(), id, i);
		i++;
		if(5 == i)
		{
			return (void*)i;
		}
		sleep(1);
	}
}

void main()
{
	pthread_t p_thread[2];
	int thr_id;
	int status;
	int a = 1;
	int b = 2;

//	puts("hello world");

	thr_id = pthread_create(&p_thread[0], NULL, t_function, (void*)&a);
	if(0 > thr_id)
	{
		perror("thread create error : ");
		return;
	}
	
	thr_id = pthread_create(&p_thread[1], NULL, t_function, (void*)&b);
	if(0 > thr_id)
	{
		perror("thread create error : ");
		return;
	}

	pthread_join(p_thread[0], (void**) &status);
	printf("p_thread[0] : %d\n", status);
	
	pthread_join(p_thread[1], (void**) &status);
	printf("p_thread[1] : %d\n", status);

	return;
}
