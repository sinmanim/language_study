
#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>		// time()
#include <unistd.h>	// getpid()


void rdInit();

int getRdNum(void);

int main()
{
	int ndx=0;
	int rnd = 0;

	rdInit();

	clear_screen();
	move_cur(0, 0);
   clear_screen();	


	for (ndx=0; ndx<5; ndx++)
	{
		printf( "%d %d\n", ndx, getRdNum() );
	}

	return 0;
}

void rdInit()
{
	srand( (unsigned) time(NULL) + (unsigned) getpid() );
}

int getRdNum()
{
	int randomNum= 0;

	randomNum = rand() %100 + 1;

	return randomNum;
}
