

#include<stdio.h>
#include<stdlib.h>

void ftest(int len);

void main()
{
	ftest(0);	

}

void ftest(int len)
{
	int length;

	for(length=0; length<10; length++)
	{
		puts("test");
	}
}
