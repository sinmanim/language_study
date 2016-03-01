

#include<stdio.h>
#include<unistd.h>
#include<wait.h>

int main(argc, argv)
int argc;
char** argv;
{
	int counter=1;
	int status;
	pid_t pid;
	pid_t pid_child;

	pid=fork();

	switch(pid)
	{
		case -1 : 
		{
			printf("child process error\n");
			return -1;
		}
		case 0 :
		{
			printf("child : count 5\n");
			while(6>counter)
			{
				printf("count %d\n", counter++);
				sleep(1);
			}
			return 99;
		}
		default : 
		{
			printf("parent : wait child process\n");

			pid_child=wait(&status);

			printf("destroy child process id is %d and ", pid_child);
			if(0==(status&0xff)) {
				printf("normal exit return var is %d\n", status>>8);
			}
			else{
				printf("abnormal exit return var is %d\n", status);
			}
			printf("now work parent\n");

			while(1) {
				printf("parent : %d\n", counter++);
				sleep(1);
			}
		}
	}
}





