

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define KOREA "abcd"

char* fstrncpy(char* dest, const char* src, size_t len);

int main(argc, argv)
int argc;
char** argv;
{
	char sDest[50];

	memset(sDest, 0, sizeof(sDest));

	fstrncpy(sDest, KOREA, 4);

	printf("%s \n", sDest);

	return 0;
}

char* fstrncpy(char* dest, const char* src, size_t len)
{
	int length;

	if(dest == NULL || src == NULL)
	{
		if(*dest != '\0') 
		{
			*dest = '\0';
			return NULL;
		}
	}

	for(length=0; length<len; length++)
	{
		printf("%d\n", length);

		*dest++=*src++;
	}

	printf("%d\n", len);
	dest[len] = (int)NULL;

	return dest;
}

	
