
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void test(int *array, int size);

void main(void)
{
	int buf[8][10] = {1,2,3,4,5,6,7,8};
	printf("%d \n", sizeof(buf)/sizeof(int));
	test( buf[0], sizeof(buf)/sizeof(int));
}

void test(int *array, int size)
{
	int i, j;

	for(i=0; i<size; i++)
	{
		printf("[%01d] ", *(array++));
	}

	printf("\n");
}







