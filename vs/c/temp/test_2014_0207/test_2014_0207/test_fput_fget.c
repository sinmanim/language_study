#include "stdio.h"

int main(void){

	char perID[7];
	char name[10];

	fputs("�ֹι�ȣ �� 6 �ڸ��� �Է��ϼ��� :", stdout);
	fgets(perID, sizeof(perID), stdin);

	fflush(stdin);

	fputs("�̸��� �Է��ϼ��� :", stdout);
	fgets(name, sizeof(name), stdin);

	printf("�ֹι�ȣ ���ڸ�: %s\n", perID);
	printf("��           ��: %s\n", name);

	return 0;

}