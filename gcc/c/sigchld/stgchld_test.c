
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

void z_handler()
{
	pid_t child;
	int state;

	child=waitpid(-1, &state, WNOHANG);

	printf("\t destroy child process id=%d \n", child);
	printf("\t destroy child process return var=%d \n", WEXITSTATUS(state));
}

int global_var=0;

int main(argc, argv)
int argc;
char** argv;
{
	pid_t fork_ret, child;
	int local_var =0;
	int state;

	struct sigaction sa;
	sa.sa_handler=z_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags=0;

	state=sigaction(SIGCHLD, &sa, 0);

	if(state!=0) {
		puts("sigaction() error\n");
		exit(1);
	}

	fork_ret=fork();

	if(fork_ret<0) {
		printf("fork() error\n");
		exit(1);
	}
	else if(fork_ret==0) {
		global_var++;
		local_var++;
		printf("CHILD - my PID : %d parent's PID :%d \n", getpid(), getppid());
	}
	else {
		global_var+=5;
		local_var+=5;
		printf("PARENT - my PID : %d child's PID : %d \n", getpid(), fork_ret);

		sleep(5);
	}

	printf("\t global_var : %d \n", global_var);
	printf("\t local_var : %d \n", local_var);

	return 0;
}

