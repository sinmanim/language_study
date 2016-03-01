

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _LINKED_LIST
{
	char name[100];
	
	struct LINKED_LIST *next;
}LINKED_LIST;

int add_list(LINKED_LIST **, char *);
int remove_list(LINKED_LIST **);
void print_list(LINKED_LIST *); 

void main()
{
	LINKED_LIST *ll;

	ll = NULL;
	
	add_list(&ll, "link1");
	add_list(&ll, "link2");
	print_list(ll);
}

int add_list(LINKED_LIST **item, char *value)
{
	LINKED_LIST *p_item;

	if(NULL == *item)
	{
		puts("test1");
		*item = (struct LINKED_LIST *)malloc(sizeof(LINKED_LIST));

		if(NULL == *item) return -1;

		strcpy((*item)->name, value); 
		printf("testseop %s\n", (*item)->name);
		(*item)->next = NULL;
	}
	else
	{
		puts("test2");
		while((*item)->next) *item = (*item)->next;

		p_item = (struct LINKED_LIST *)malloc(sizeof(LINKED_LIST));
		
		if(NULL == p_item) return -1;

		strcpy(p_item->name, value);
		p_item->next = NULL;
		(*item)->next = &p_item;
	}

	return 0;
}

int remove_list(LINKED_LIST **item)
{

	return 0;
}

void print_list(LINKED_LIST *item)
{
	if(NULL == item) 
	{
		printf("List is NULL \n");
	}
	else
	{
		while(item)
		{
			printf("link name is %s", item->name);
			item = item->next;
		}
	}
}
