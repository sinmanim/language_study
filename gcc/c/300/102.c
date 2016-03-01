

#include<stdio.h>
#include<stdlib.h>

void main()
{
	char test1[100] = "1234567890";
	char test2[100] = "1234567890";

	puts(test1);
	memcpy(test1+4, test1+2, 5);
	puts(test1);

	puts(test2);
	memmove(test2+4, test2+2, 5);
	puts(test2);

}
