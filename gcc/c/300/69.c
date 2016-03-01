#include<stdio.h>
#include<stdlib.h>

#define TOKEN " "

void main()
{
	char string[100];
	char *pos;

	puts("input string");

	gets(string);

	pos = strpbrk(string, TOKEN);

	while(pos != NULL)
	{
		puts(pos++);

		pos = strpbrk(pos, TOKEN);
	}

}


