
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void test(int* array, int size);

void main(void)
{
	int buf[10] = {1,2,3,4,5,6,7,8,};
	test(buf, sizeof(buf)/sizeof(int));
}

void test(int* array, int size)
{
	int i;

	for(i=0; i<size; i++)
	{	
		printf("%d ", array[i]);
	}

	printf("\n");
}







