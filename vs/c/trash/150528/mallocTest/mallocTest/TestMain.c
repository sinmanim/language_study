
#include <stdio.h>
#include <stdlib.h>

void function(int);

int main (int argc, char* argv[]){

	int m=0;
	fputs("배열의 크기를 입력하세요: ", stdout);
	scanf("%d", &m);
	function(m);

	return 0;
}

void function(int i){
	// int array[i];
	int* array=(int*)malloc(sizeof(int)*i);	// 동적 메모리 할당
	int j;
	if(array==NULL)
	{
		puts("메모리 할당에 실패!");
		exit(1);	// 비 정상적 종료를 의미함
	}

	/* 동적 할당한 메모리 사용 */
	for(j=0; j<i; j++){
		array[j]=j+1;
	}
	for(j=0; j<i; j++){
		printf("%d ", array[j]);
	}
	printf("\n");

	free(array);	// 할당된 메모리 소멸
}