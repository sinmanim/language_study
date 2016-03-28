
#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef struct node
{
	int item;
	struct node *link;
} stack;

stack *top = NULL;

void push(int item)
{
	stack *temp;
	temp = (stack *) malloc( sizeof(stack) );
	
	temp->item = item;
	temp->link = top;
	top = temp;	
}

int pop()
{
	stack *temp;
	int item;
	
	temp = top;	
	item = temp->item;
	top = temp->link;
	
	free(temp);		

	return item;
}

int isEmpty()
{
	if(!top){
		printf("top is null\n");
		return 1;
	}
	return 0;
}

int main(argc, argv)
int argc;
char** argv;
{
	int value;
	
	push(20);
	push(40);
	push(30);
	push(50);
	push(60);

	while(!isEmpty())
	{
		value = pop();
		printf("pop -> %d \n", value); 
	}

	return 0;
}


