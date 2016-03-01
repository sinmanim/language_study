#include <stdio.h>

struct person{
	char name[20];
	char phone[20];
	struct data* info;
};

struct data{
	char a[20];
	char b[30];
};

int main(int argc, char* argv[]){

	struct person man={ "shin", "01022112133" };
	struct data info={ "aA", "bB" }; 
	
	struct person* test;
	
	test=&man;
	
	test.info = &info;

	printf("test %s\n", test->name);
	printf("test %s\n", test->phone);
	printf("test %s\n", test->info->b);

	return 0;
}