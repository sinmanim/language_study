

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void main()
{
	int i;
	int dRand;

	srand((unsigned int)time(NULL));

	for(i=0; i<10; i++)
	{
		dRand = rand()%150 + 1;
		printf("randon num is %d \n", dRand);
	}
}


