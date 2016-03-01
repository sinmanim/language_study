

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main()
{
	int (*myfunc)(const char*);

	myfunc = puts;

	puts("hi~ good");
	myfunc("olleh~");

	myfunc = strlen;

	printf("str length : %d \n", strlen("aa"));
	printf("str2length : %d \n", myfunc("aa"));

}

