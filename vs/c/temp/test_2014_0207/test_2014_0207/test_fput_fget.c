#include "stdio.h"

int main(void){

	char perID[7];
	char name[10];

	fputs("주민번호 앞 6 자리를 입력하세요 :", stdout);
	fgets(perID, sizeof(perID), stdin);

	fflush(stdin);

	fputs("이름을 입력하세요 :", stdout);
	fgets(name, sizeof(name), stdin);

	printf("주민번호 앞자리: %s\n", perID);
	printf("이           름: %s\n", name);

	return 0;

}