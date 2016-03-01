
#include "util.h"


void move_cur(int x, int y)
{
	printf("\033[%dd\033[%dG", y, x);
}

void clear_screen()
{
	printf("\033[2J\n");
}

