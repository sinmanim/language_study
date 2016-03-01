

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#ifndef MAX_BUF
#define MAX_BUF 100
#endif

int enqueue(int value);
int dequeue(int* value);

typedef struct tagStruct
{
	int buf[MAX_BUF];
	int head;
	int tail;
}QUEUE;

QUEUE s;

void main()
{
	char temp[100], temp2[100];
	int value1, value2;

	int index;

	char *op = "-+*/%";

	s.head = 0;
	s.tail = 0;

	puts("input value ex) 4*5");
	puts("enter is exit");

	while(1)
	{
		memset(temp, 0, sizeof(temp));
		memset(temp2, 0, sizeof(temp2));
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
			printf("debug val %d %d\n", value1, value2);
			
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

		if(-1 == enqueue(value1))
		{
			puts("더 이상 저장할 수 없습니다");
		}
		else
		{
			printf("%s = %d, s.tail = %d\n\n", temp, value1, s.tail);
		}
	}

	value1=0;

	while(1)
	{
		if(-1 == dequeue(&value2)) break;

		printf("%d\n", value2);
	}

}

int enqueue(int value)
{
	if(MAX_BUF==s.tail) return -1;
	s.buf[s.tail++] = value;
	return 0;
}

int dequeue(int* value)
{
	if(s.tail<=s.head || MAX_BUF==s.head) return -1;
	*value = s.buf[s.head++];
	return 0;
}

