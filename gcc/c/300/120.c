

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct tagAddress
{
	char name[30];
	char phone[20];
	char address[100];
};

void main()
{
	struct tagAddress ad;
	struct tagAddress *pad;

	pad = &ad;

	strcpy((*pad).name, "홍길동");
	strcpy((*pad).phone, "20-1234-5678");
	strcpy((*pad).address, "서울시 양천구");

	printf("name : %s \n", pad->name);
	printf("phone : %s \n", pad->phone);
	printf("address : %s \n", pad->address);
}




