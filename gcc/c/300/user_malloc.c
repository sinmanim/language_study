

#include<stdio.h>
#include<stdlib.h>

void user_malloc(int * num);

void main()
{
	int *ptr;
	user_malloc(ptr);

	*ptr = 8;
	printf("%d\n", *ptr);
	
}

void user_malloc(int *num)
{
	num = (int *)malloc(sizeof(int));
}
