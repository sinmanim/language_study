

#include<stdio.h>
#include<stdlib.h>

void main()
{
	int x=0;
	int y=0;

	int *buf[2];

	buf[0] = &x;
	buf[1] = &y;

	*buf[0] = 5;
	*buf[1] = 10;

	printf("%d\n", *buf[0]);
	printf("%d\n", *buf[1]);
}

