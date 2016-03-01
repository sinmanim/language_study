

#include<stdio.h>
#include<stdlib.h>

int main(argc, argv)
int argc;
char*argv[];
{
	int state;				// error 체크 변수
	int i, j;				// for 루프 변수
	int a=0, b=0, c=0;	// fscanf 변수
	char c1=0, c2=0;		// fscanf 변수

	char* pState;	// while 전용
	char str[20];	// while 전용

	/* 쓰기 전용 파일 개방 */
	FILE * file = fopen("Test.txt", "wt");
	if(NULL==file)
	{
		printf("file open error!\n");
		return 1;
	}

	/* fprintf 함수의 활용 */
	for(i=2; i<10; i++)
	{
		for(j=1; j<10; j++)
		{
			fprintf(file, "%d * %d = %d \n", i, j, i*j);
		}
	}

	/* 파일의 종결 */
	state = fclose(file);
	if(0!=state)
	{
		printf("file close error!\n");
		return 1;
	}

	/* 읽기 전용 파일 개방 */
	file = fopen("Test.txt", "rt");
	if(NULL==file)
	{
		printf("file open error!\n");
		return 1;
	}

	/* fscanf 함수의 활용 */
	/*
	for(i=2; i<10; i++)
	{
		for(j=1; j<10; j++)
		{
			fscanf(file, "%d %c %d %c %d", &a, &c1, &b, &c2, &c);
			printf("%d %c %d %c %d \n", a, c1, b, c2, c);
		}
	}
	*/

	/* 파일 끝까지 읽는 방법 */
	while(1)
	{
		pState = fgets(str, sizeof(str), file);
		if(NULL==pState)
		{
			break;
		}
		fputs(str, stdout);
	}

	/* 파일의 종결 */
	state = fclose(file);
	if(0!=state)
	{
		printf("file close error!\n");
		return 1;
	}

	return 0;
}

