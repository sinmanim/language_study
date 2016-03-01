#include <stdio.h>

int main(int argc, char* argv[]){

	printf("현재 라인 번호: %d \n", __LINE__);
	printf("파일 이름: %s \n", __FILE__);
	printf("컴파일 시간: %s \n", __TIME__);
	printf("컴파일 날짜: %s \n", __DATE__);

	return 0;
}