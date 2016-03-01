#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _linked_list
{
	char name[100];
	struct linked_list *next;
}linked_list;

int add_list(linked_list **, char *);
int remove_list(linked_list **);
void print_list(linked_list *);

void main()
{
	puts("linked list start");

	linked_list *node;

	node = NULL;

	add_list(&node, "list1");
	add_list(&node, "list2");
	add_list(&node, "list3");

	remove_list(&node);

	print_list(node);
}

int remove_list(linked_list **item)
{
	int retval = -1;

	linked_list *current = NULL;
		

	if (NULL == *item)
	{
		puts("list is null");
		return -1;
	}

	current = (*item)->next;
	retval = atoi((*item)->name);
	free(*item);
	*item = current;

	return retval;
}

int add_list(linked_list **item, char * name)
{
	linked_list *current = *item;
	linked_list *temp = NULL;

	if (NULL == current)
	{
		current = malloc(sizeof(linked_list));
		if (NULL == current) return -1;
		strcpy_s(current->name, 100, name);
		current->next = NULL;
		*item = current;
	}
	else
	{
		temp = malloc(sizeof(linked_list));
		if (NULL == temp) return -1;
		strcpy_s(temp->name, 100, name);
		temp->next = (*item);
		(*item) = temp;
	}

	return 0;
}

void print_list(linked_list *item)
{
	if (NULL == item)
	{
		printf("List is NULL \n");
	}
	else
	{
		while (item)
		{
			printf("link name is %s\n", item->name);
			item = item->next;
		}
	}
}