

#include<stdio.h>
#include<stdlib.h>

#define ENTER 10

int main(argc, argv)
int argc;
char** argv;
{
	char inChar;

	puts("start");

	do
	{
		inChar = getchar();
		printf("%c", inChar);
	}while(inChar != 'q');

	puts("end");

	return 0;
}
