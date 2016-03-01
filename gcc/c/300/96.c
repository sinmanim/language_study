

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main()
{
	char *string = "this is a test str";
	char *buf;

	buf = malloc(sizeof(char)*100);

	memset(buf, 0, sizeof(char)*100);

	/*
	while(*string)
	{
		*buf++ = *string++;
	}
	*/

	strcpy(buf, string);

	puts(buf);

	free (buf);

	puts(buf);
}
