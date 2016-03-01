

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#ifndef MAX_BUF
#define MAX_BUF 100
#endif

int push(int value);
int pop(int* value);

typedef struct tagStruct
{
	int buf[MAX_BUF];
	int top;
	int bottom;
}STACK;

STACK s;

void main()
{
	char temp[100], temp2[100];
	int value1, value2;

	int index;

	char *op = "-+*/%";

	s.top = MAX_BUF;

	puts("input value ex) 4*5");
	puts("enter is exit");

	while(1)
	{
		memset(temp, 0, sizeof(temp));
		scanf("%s", temp);

		if(!strcmp(temp, "exit"))
		{
			puts("sum after shutdown...");
			break;
		}
		else
		{
			index = strcspn(temp, op);

			memcpy(temp2, temp, index);

			value1 = atoi(temp2);
			value2 = atoi(&temp[index+1]);
			printf("debug val %d %d", value1, value2);
			
			printf("debug %c\n", temp[index]); 

			switch(temp[index])
			{
				case '-' : value1 -= value2; break;
				case '+' : value1 += value2; break;
				case '*' : value1 *= value2; break;
				case '/' : value1 /= value2; break;
				case '%' : value1 %= value2; break;
				default : 
							  puts("잘못된 연산 입니다");
							  continue;
			}
		}

		if(-1 == push(value1))
		{
			puts("더 이상 저장할 수 없습니다");
		}
		else
		{
			printf("%s = %d, s.top = %d\n\n", temp, value1, s.top);
		}
	}

	value1=0;

	while(1)
	{
		if(-1 == pop(&value2)) break;

		printf("%d\n", value2);
	}

}

int push(int value)
{
	if(0==s.top) return -1;
	s.buf[--s.top] = value;
	return 0;
}

int pop(int* value)
{
	if(MAX_BUF==s.top) return -1;
	*value = s.buf[s.top++];
	return 0;
}

