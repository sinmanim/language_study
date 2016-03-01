#include "stdio.h"

int main()
{

	// random number generator

	int i;

	srand(time(NULL));
	for(i=1;i<=15;i++){
		printf("%f n \n",rand()%10+1.);
	}
}