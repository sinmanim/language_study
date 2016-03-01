

#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>

int main()
{
	int ret;
	int state;

	int child;

	child=fork();

	if(0==child) {
		while(1);
	}
	else {
		ret = wait(&state);
	}

	printf("ret is %d\n", ret);

	return 0;
}

