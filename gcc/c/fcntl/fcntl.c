

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(void)
{
	char				*filename = "./test.txt";
	int 				fd;
	pid_t				pid;
	struct flock	filelock;
	
	pid = fork();

	switch(pid)
	{
		case -1	:
		{
			printf("자식 프로세스 생성 실패\n");
			return -1;
		}
		
		case 0	:
		{
			printf("자식 : 부모 프로세스를 위해 잠시 대기하겠습니다.\n");
			sleep(1);

			printf("자식 : 파일의 내용을 수정합니다.\n");
			fd = open(filename, O_RDWR | O_CREAT, 0666);

			filelock.l_type	=	F_WRLCK;
			filelock.l_whence	=	SEEK_SET;
			filelock.l_start	=	0;
			filelock.l_len		=	6;

			if(-1 == fcntl(fd, F_SETLKW, &filelock)){
				printf("자식 : 레코드 잠금에 실패해서 forum 을 쓰지 못했습니다.\n");
			}else{
				write(fd, "forum", 6);
			}

			filelock.l_type	=	F_WRLCK;
			filelock.l_whence	=	SEEK_SET;
			filelock.l_start	=	6;
			filelock.l_len		=	7;

			if(-1 == fcntl(fd, F_SETLKW, &filelock)){
				// 여기서는 이 if절을 만족하게 됩니다.
				printf("자식 : 레코드 잠금에 실패해서 falinux를 쓰지 못했습니다.\n");
			}else{
				write(fd, "falinux", 7);
			}

			close(fd);
			break;
		}

		default	:
		{
			printf("부모 : 파일을 열고 레코드를 잠금하겠습니다.\n");
			fd = open(filename, O_RDWR, 0666);
			
			filelock.l_type	=	F_WRLCK;
			filelock.l_whence	=	SEEK_SET;
			filelock.l_start	=	7;
			filelock.l_len		=	7;

			if(-1 != fcntl(fd, F_SETLK, &filelock))
			{
				printf("부모 : 잠금에 성공했으며 3초간 대기합니다.\n");
				sleep(3);
			}
			close(fd);
		}
	}
}


