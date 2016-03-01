

#include<stdio.h>
#include<stdlib.h>

#define KOREA "대한민국"

char* fstrcpy(char* dest, const char* src);

int main(argc, argv)
int argc;
char** argv;
{
	char sDest[50];

	fstrcpy(sDest, KOREA);

	printf("%s \n", sDest);

	return 0;
}

char* fstrcpy(char* dest, const char* src)
{
	if(dest == NULL || src == NULL)
	{
		if(*dest != '\0') 
		{
			*dest = '\0';
			return NULL;
		}
	}

	do
	{
		*dest++=*src;
	}while(*src++ != '\0');

	return dest;
}

	
