

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

int ncount;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *do_loop(void* data)
{
	int i;
	int id = *((int *)data);
	int mydata;

	printf("id=%d\n", id);

	for(i = 0; i<10; i++)
	{
		// mutex lock
		pthread_mutex_lock(&mutex);
		
		// critical section
		printf("thread %d : %d\n", id, ncount);
		mydata = ncount;
		mydata++;
	   usleep(1000*10);
		ncount = mydata;

		pthread_mutex_unlock(&mutex);
		usleep(1000*10);
	}

	return;
}


int main()
{
	int thr_id;
	pthread_t p_thread[3];
	int status;
	int i;
	ncount = 0;

	// 쓰레드를 생성한다.
	for(i=0; i<3; i++)
	{
		thr_id = pthread_create(&p_thread[i], NULL, do_loop, (void *)&i);
		printf("test i=%d\n", i);
	}

	for(i=0; i<3; i++)
	{
		pthread_join(p_thread[i], (void**) &status);
	}

	status = pthread_mutex_destroy(&mutex);
	printf("programming is end\n");

	return 0;
}

