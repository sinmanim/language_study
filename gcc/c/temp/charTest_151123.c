

#include<stdio.h>
#include<stdlib.h>

void printString(char* str);

int main(argc, argv)
int argc;
char **argv;
{
	char *testStr = "abced";

	printString(testStr);

	return 0;
}

void printString(char* str)
{
	puts("printString Start");
	
	int idx=0;

	while(*str != NULL)
	{
		printf("%c", *str);
		str++;
		idx++;
	}
	puts(" ");
}
