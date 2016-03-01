

#include<stdio.h>
#include<stdlib.h>

int main(argc, argv)
int argc;
char** argv;
{
	char inChar[100];

	puts("start");

	scanf("%s", inChar); 
	printf("%s\n", inChar);
	
	puts("end");

	return 0;
}
