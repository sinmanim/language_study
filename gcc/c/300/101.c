

#include<stdio.h>
#include<stdlib.h>

void main()
{
	char test[100]="123";
	char test2[100]="123";

	strcpy(&test[4], "abc");
	strcpy(&test2[4], "efg");

	if(0==strcmp(test, test2))
	{
		puts("match");
	}

	if(0==memcmp(test, test2, 7))
	{
		puts("match");
	}
	else
	{
		puts("not match");
	}
}


