
/*
============================================================================
Name        : linked_list.c
Author      : seop
Version     :
Copyright   : Your copyright notice
Description : Hello World in C, Ansi-style
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _linked_list
{
	char name[100];

	struct linked_list *next;
}linked_list;

int add_list(linked_list **, char *);
void print_list(linked_list *);

void main()
{
	linked_list *ll;

	ll = NULL;

	add_list(&ll, "link1");
	add_list(&ll, "link2");
	add_list(&ll, "link3");
	print_list(ll);
}

int add_list(linked_list **item, char *value)
{
	linked_list *temp;

	if (NULL == *item)
	{
		*item = (struct linked_list *)malloc(sizeof(linked_list));

		if (NULL == *item) return -1;

		printf("[%d]\n", *item);

		strcpy_s((*item)->name, 100, value);
		(*item)->next = NULL;

	}
	else
	{
		temp = (*item)->next;

		if (NULL == temp)
		{
			puts("NULL");
			temp = (struct linked_list *)malloc(sizeof(linked_list));

			strcpy_s(temp->name, 100, value);
			temp->next = NULL;
			(*item)->next = temp;
		}
		else
		{
			puts("not NULL");

			temp = temp->next;

			if (NULL == temp)
			{
				puts("n NULL");
				temp = (struct linked_list *)malloc(sizeof(linked_list));
				strcpy_s(temp->name, 100, value);
				temp->next = NULL;
			}
			else
			{
				puts("not NULL");
			}
		}
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

