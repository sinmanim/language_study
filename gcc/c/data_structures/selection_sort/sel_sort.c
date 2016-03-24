
#include <stdio.h>

void sel_sort(int array[]);

int main()
{
	int i;
	int buf[10];
	srand(time(NULL));

	for(i=0; i<10; i++)
	{
		buf[i] = (long) rand() % 100 + 1;
		printf("%3d ", buf[i]);
	}
	printf("\n");

	sel_sort(buf);

	return 0;
}

void sel_sort(int array[])
{
	int i, j;
	int temp;
	
	for(i=0; i<10; i++)
	{
		for(j=i; j<10; j++)
		{	
			if(array[j] < array[i]){
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
		
		printf("%3d ", array[i]);
	}

	printf("\n");	
}
