

#include<stdio.h>
//#include<ctype.h>

void main()
{
	char *string ="this 1 is 2 a  3 test string";
	char buf[100]={0,};

	int count=0;

	while(*string)
	{
		if(isalpha(*string)){
			buf[count++]=*string;
		}

		string++;
	}

	puts(buf);
}

