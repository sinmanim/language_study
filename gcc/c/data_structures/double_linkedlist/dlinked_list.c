
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	char name[20];
	struct node *left, *right;
} NODE;

NODE *start, *end;

NODE* make_node()
{
	NODE *p = NULL;
	p = (NODE *) malloc(sizeof(NODE));	

	if(NULL == p){
		perror("memory is full : ");
		return NULL;
	}
	
	return p;
}

void make_dlist()
{
	int i;
	NODE *tail, *temp; 
	char buf[5][10] = { "test", "is", "started", "now", "success" };
	char con[20] = {};	

	start = end = make_node();
	
	for(i=0; i<5; i++)
	{
		strcpy(con, buf[i]);
		if( start == end ) {
			tail = start;
			temp = make_node();
		}
		else{
			tail = end->left;
 			temp = end;
		}		
		end = make_node();
		strcpy(temp->name, con);
		temp->left = tail;
		temp->right = end;
		tail->right = temp;	
		end->left = temp;
	}
}

int main()
{
	NODE *p;
	
	make_dlist();

	p=start->right;
	while(p!=end)
	{
		printf("%s -> ", p->name);
		p=p->right;
	}	

	printf("\n");

	return 0;
}



