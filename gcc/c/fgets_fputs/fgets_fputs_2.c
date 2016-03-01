

#include<stdio.h>
#include<stdlib.h>


int main(argc, argv)
int argc;
char** argv;
{

	char input[50];

	printf("input data ");

//	scanf("%s", input);

	fgets(input, sizeof(input), stdin);

	printf("result is %s \n", input);

	return 0;
}

