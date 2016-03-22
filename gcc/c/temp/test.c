
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



























void test(int** array, int size);

void main(void)
{
	int buf[10] = {1,2,3,4,5,6,7,8,};
	int *bufC = &buf;
	test(&bufC, 10);
}

void test(int** array, int size)
{
	int i;
	//printf("%d ", (*array)[3]);

	int *tt = (int*) malloc(size*sizeof(int));
	//int tt[10]={};

	memcpy(tt, &(*array), size*sizeof(int));

	for(i=0; i<10; i++)
	{	
		printf("%d ", tt[i]);
	}

	free(tt);
}







