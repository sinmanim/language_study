
#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>	// time()
#include <unistd.h>	// getpid()


void rdInit();

int getRdNum(void);

int main()
{
	int ndx=0;
	int rnd = 0;

	rdInit();

	for (; ; )
	{
		clear_screen();
		printf( "%d %d", ndx, getRdNum() );
		move_cur(1, 0);
		usleep(500);
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
