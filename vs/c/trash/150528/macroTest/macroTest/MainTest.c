#include <stdio.h>

int main(int argc, char* argv[]){

	printf("���� ���� ��ȣ: %d \n", __LINE__);
	printf("���� �̸�: %s \n", __FILE__);
	printf("������ �ð�: %s \n", __TIME__);
	printf("������ ��¥: %s \n", __DATE__);

	return 0;
}