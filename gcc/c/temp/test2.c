
#include <stdio.h>

void function(int temp[6])
{
	printf("%d \n", temp[2]);
}

int main()
{
 int array[5]={};

 function(array);

 //printf("array[0][4] = %d\n", array[0][4]);

 return 0;
}

