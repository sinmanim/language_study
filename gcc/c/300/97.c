

#include<stdio.h>
#include<stdlib.h>

void main()
{
	int *buf, n, m;

	buf = (int *)calloc(100, sizeof(int));

	for(n=0; n<100; n++)
	{
		buf[n] = n;
	}

	printf("%d\n", buf[85]);

	free(buf);
}

