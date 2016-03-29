
#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *link;
};
typedef struct node list_node;
typedef list_node* list_ptr;

list_ptr create(int n)
{
	list_ptr first = NULL;
	list_ptr temp = NULL;	
	int i;
	
	for(i=0; i<n; i++)
	{
		temp = (list_ptr) malloc(sizeof(list_node));
		temp->data = (i+1);
		temp->link = first;
		first = temp;
	}
	return first;
}
	
void print_list(list_ptr ptr)
{
	printf("The list contains: ");
	while(NULL != ptr)
	{
		printf("%4d", ptr->data);
		ptr = ptr->link;
	}
	printf("\n");
}

void insertlast(list_ptr ptr)
{
	list_ptr temp = NULL;
	list_ptr last = ptr;
	
	while(last->link)
	{
		last = last->link;
	}	
	
	temp = (list_ptr) malloc(sizeof(list_node));
	temp->data = 7;
	temp->link = NULL;

	last->link = temp;	
}

list_ptr insertfirst(list_ptr ptr)
{
	list_ptr temp, first;
	
	temp = (list_ptr) malloc(sizeof(list_node));
	temp->data = 0;
	temp->link = ptr;
	first = temp;

	return first;	
}

void insertfirst2(list_ptr *ptr)
{
	list_ptr temp;
	
	temp = (list_ptr) malloc(sizeof(list_node));
	temp->data = -1;
	temp->link = *ptr;
	*ptr = temp; 
}

int main(void)
{
	list_ptr ptr = NULL;
	
	ptr = create(6);
	print_list(ptr);
	
	insertlast(ptr);
	print_list(ptr);
	
	ptr = insertfirst(ptr);
	print_list(ptr);

	insertfirst2(&ptr);
	print_list(ptr);

	return 0;
}


