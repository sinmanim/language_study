
#include "sum.h"
#include "sub.h"
#include "mul.h"
#include "div.h"
#include <stdio.h>

int main( int argc, char **argv)
{
	int a;
	int b;

	a = atoi(argv[1]);
	b = atoi(argv[2]);

	printf("test a=%d and b=%d\n", a, b);

	printf("sum is %d\n", sum(a, b));
	printf("sub is %d\n", sub(a, b));
	printf("mul is %d\n", mul(a, b));
	printf("div is %d\n", div(a, b));
	
	return 0;
}

