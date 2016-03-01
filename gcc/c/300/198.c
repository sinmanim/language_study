

#include<stdio.h>
#include<stdlib.h>

#define COUNT 100

#if defined COUNT
#undef COUNT
#define COUNT 99
#else
#define COUNT 88
#endif

#warning "test seop"

#error "error seop"

void main()
{
	printf("COUNT is %d\n", COUNT);
}


