
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

void bubble_sort(int array[], int length);

void print(int array[]);

int main()
{
	int i, buf[10];
	srand(time(NULL));	

	for(i=0; i<10; i++)
	{
		buf[i] = (long) rand() % 100 + 1;
		printf("%3d ", buf[i]);
	}

	printf("\n");

	bubble_sort(buf, 10);

	print(buf);

	return 0;
}

void bubble_sort(int array[], int length)
{
	int i, j;
	int next;
	
	for(i = length-1; i>0; i--)
	{	
		for(j=0; j<i; j++)
		{
			if(array[j] > array[j+1]){
				next = array[j];
				array[j] = array[j+1];
				array[j+1] = next;
			}
		}
	}
}

void print(int array[])
{
	int i;

	for(i=0; i<MAX; i++)
	{
		printf("%3d ", array[i]);
	}
	printf("\n");
}




















