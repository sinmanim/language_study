

#include<stdio.h>
#include<stdlib.h>

struct person
{
	char name[20];
	char phone[20];
};

int main(argc, argv)
int argc;
char** argv;
{
	struct person man = {"Thomas", "353-00xx"};
	struct person* pMan;
	pMan = &man;

	// 구조체 변수를 이용한 출력
	printf("name		: %s\n", man.name);
	printf("phone		: %s\n", man.phone);

	// 구조체 포인터를 이용한 출력1
	printf("aName		: %s\n", (*pMan).name);
	printf("aPhone		: %s\n", (*pMan).phone);

	// 구조체 포인터를 이용한 출력2
	printf("pName		: %s\n", pMan->name);
	printf("pPhone		: %s\n", pMan->phone);

	return 0;
}
