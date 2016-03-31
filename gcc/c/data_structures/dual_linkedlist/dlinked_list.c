
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	char name[20];
	node *left, *right; // left 이전 노드, right 다음 노드
} NODE;

NODE *start, *end;

NODE* make_node()
{
	NODE *p = NULL;
	p = (NODE *) malloc(sizeof(NODE));	

	if(NULL = p){
		perror("memory is full : ");
		return NULL;
	}
	
	return p;
}

void make_dlist()
{
	char buf[5] = { "test", "is", "started", "now", "success" };
}

int main()
{


	return 0;
}



