

#include<stdio.h>
#include<stdlib.h>

int main(argc, argv)
int argc;
char** argv;
{
	int state;

	FILE * file = fopen("Test.txt", "wt");
	if(NULL==file)
	{
		printf("file open error!\n");
		return 1;
	}

	fputs("Test Seop!", file);

	state=fclose(file);
	if(0!=state)
	{
		printf("file close error!\n");
		return 1;
	}

	return 0;
}
