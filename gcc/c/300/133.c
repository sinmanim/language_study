

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main()
{
	int (*myfunc[3])(const char*);

	myfunc[0]=puts;
	myfunc[1]=strlen;
	myfunc[2]=myfunc[1];

	puts("olleh~");
	myfunc[0]("hello~");

	printf("str length : %d\n", strlen("aa"));
	printf("str length : %d\n", myfunc[1]("aa"));
	printf("str length : %d\n", myfunc[2]("aa"));
}


