#include "stdio.h"
#include "string.h"

int main(void){

	char str[100];

	while (1)
	{
		fgets(str, sizeof(str), stdin);
		printf("문자열의 길이: %d \n", strlen(str));
	}

	return 0;

}