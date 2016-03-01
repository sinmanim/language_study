

#include<stdio.h>
#include<stdlib.h>

int main(vodi)
{
	int state;

	/* 파일의 개방 */
	FILE *file = fopen("./fopen.c", "wt");
	if(file==NULL)
	{
		printf("file open error!\n");
		return 1;
	}

	/* 파일의 종결 */
	state = fclose(file);
	if(state!=0)
	{
		printf("file close error!\n");
		return 1;
	}

	return 0;
}
