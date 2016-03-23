

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *link;
};

typedef struct node list_node;
typedef struct list_node *list_ptr;

int main()
{
	list_node a, b, c;
	a.data = 'a';
	b.data = 'b';
	c.data = 'c';

	a.link = b.link = c.link = NULL;

	a.link = &b;
	b.link = &c;

	printf("%c \n", a.link->link->data);
	
	return 0;
}

