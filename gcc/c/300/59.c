

#include<stdio.h>
#include<stdlib.h>

#define SKY "sky"

void main()
{
	int ret;

	char input_string[10];

	puts("start");

	do
	{
		scanf("%s", input_string);

		ret = strcmp(input_string, SKY);

		if(0 == ret)
		{
			puts("end");
			break;
		}

		printf("%s\n", input_string);
	}while(1);
}
