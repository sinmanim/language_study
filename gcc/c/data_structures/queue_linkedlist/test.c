
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int key;
} element;

typedef struct queue *queue_ptr;
typedef struct queue{
	element item;
	queue_ptr link;
};

void insertq( queue_ptr *front, queue_ptr *rear, element e )
{
	queue_ptr temp;
	temp = (queue_ptr) malloc(sizeof(struct queue));
	
	if(!temp){
		printf("Memory is full! \n");
		return;
	}

	temp->item = e;
	temp->link = NULL;

	if(*front){
		(*rear)->link = temp;	
	}
 	else{
		(*front) = temp;
	}
	*rear = temp;
}

int deleteq( queue_ptr *front )
{
	queue_ptr temp = *front;
	element e;

	if(!(*front)){
		printf("queue is empty! \n");
		return -1;
	}

	e = (*front)->item;
	(*front) = temp->link;
	free(temp);
	
	return e.key;	
}

int main()
{
	int ret;

	queue_ptr front=NULL;
	queue_ptr rear=NULL;

	element x;

	x.key = 50;

	insertq(&front, &rear, x);
	insertq(&front, &rear, x);
	insertq(&front, &rear, x);
	
	printf("Begin Queue Test ... \n");
	
	while(!front == NULL)
	{	
		//printf("check \n");
		ret = deleteq(&front);
		printf("value = %d\n", ret);
	}

	return 0;
}
