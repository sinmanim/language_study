#include <stdio.h>

int main(int argc, char* argv[]){

	int state;
	char buf[30];

	FILE* file = fopen( "Test.txt", "rt"); // wt, rt
	if(file == NULL){
		printf("file open error!\n");
		return 1;
	}

//	puts("Don't Worry!");

//	fputs("Don't Worry!\n", stdout);

//	fputs("Don't Worry!\n", file);

	fputs("데이터 입력:", stdout);
	fgets(buf, sizeof(buf), stdin);
	puts(buf);	// 다음줄 

	fgets(buf, sizeof(buf), file);
	puts(buf);


	state = fclose(file);
	if(state!=0){
		printf("file close error!\n");
		return 1;
	}

	return 0;
}