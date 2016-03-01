#include<stdio.h>
#include<stdlib.h>

typedef struct _node
{
	int value;
	struct _node* next;
}node;

typedef node* nptr;

typedef struct _list
{
	int count;
	nptr head;
}list;

void init(list* lptr);
void insert(list* lptr, int value, int position);
void delete(list* lptr, int position);
int search(list* lptr, int value);
void modify(list* lptr, int value, int position);
void print_list(list* lptr);





void init(list* lptr)
{
	// initialize the list
	lptr->count = 0;
	lptr->head = NULL;
}

void insert(list* lptr, int value, int position)
{
	int i;
	// insert value to proper position 
	if (position < 1 || position >(lptr->count) + 1)
	{
		printf("Position Out of Bound\n");
		return;
	}
	nptr new_nptr = (node*)malloc(sizeof(node));
	new_nptr->value = value;

	if (position == 1)
	{
		new_nptr->next = lptr->head;
		lptr->head = new_nptr;
	}
	else
	{
		nptr tmp = lptr->head;
		
		for (i = 1; i < position - 1; i++)
		{
			tmp = tmp->next;
		}
		new_nptr->next = tmp->next;
		tmp->next = new_nptr;
	}
	lptr->count++;
}

void delete(list* lptr, int position)
{
	int i;
	// delete value to proper position 
	if (position < 1 || position >(lptr->count) + 1)
	{
		printf("cannot delte position [%d]", position);
		return;
	}

	nptr tmp = lptr->head;

	if (1 == position)
	{
		lptr->head = tmp->next;
		free(tmp);
		tmp = NULL;
	}
	else
	{
		for (i = 1; i < position - 1; i++)
		{
			tmp = tmp->next;
		}

		nptr tmp2 = tmp->next;
		tmp->next = tmp2->next;
		free(tmp2);
		tmp2 = NULL;
	}
	lptr->count--;
}

int search(list* lptr, int value)
{
	nptr tmp = lptr->head;
	int i = 1;
	while(tmp != NULL)
	{
		if (value == tmp->value) break;
		i++;
		tmp = tmp->next;
	}
	if (i > lptr->count)
	{
		printf("the value %d is not exist", value);
		return -1;
	}
	else
	{
		printf("the value %d is position %d", value, i);
		return i;
	}
}

void modify(list* lptr, int value, int position)
{
	int i=0;

	if (position<1 || position>lptr->count)
	{
		printf("position is out of bound");
		return;
	}

	nptr tmp = lptr->head;

	for (i = 1; i < position; i++)
	{
		tmp = tmp->next;
	}
	
	tmp->value = value;
}

void print_list(list* lptr)
{
	nptr tmp = lptr->head;

	while (tmp)
	{
		printf("value is %d", tmp->value);
		tmp = tmp->next;
	}

	printf("\n");
	printf("Total: %d value(s)\n", lptr->count);
}