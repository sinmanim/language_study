#include<stdio.h>
#include<stdlib.h>

#define TOKEN " a"

void main()
{
	char string[100];
	char *token;

	puts("input string");

	gets(string);

	token = strtok(string, TOKEN);

	while(token != NULL)
	{
		puts(token);

		token = strtok(NULL, TOKEN);
	}

}


