#include <stdio.h>
#include <stdlib.h>

void function(int);

int main (int argc, char* argv[]){

	int m=0;
	fputs("�迭�� ũ�⸦ �Է��ϼ���: ", stdout);
	scanf("%d", &m);
	function(m);

	return 0;
}

void function(int i){
	// int array[i];
	int* array=(int*)malloc(sizeof(int)*i);	// ���� �޸� �Ҵ�
	int j;
	if(array==NULL)
	{
		puts("�޸� �Ҵ翡 ����!");
		exit(1);	// �� ������ ���Ḧ �ǹ���
	}

	/* ���� �Ҵ��� �޸� ��� */
	for(j=0; j<i; j++){
		array[j]=j+1;
	}
	for(j=0; j<i; j++){
		printf("%d ", array[j]);
	}
	printf("\n");

	free(array);	// �Ҵ�� �޸� �Ҹ�
}