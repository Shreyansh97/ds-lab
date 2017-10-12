#ifndef OUT_RES_DQ
#define OUT_RES_DQ
#include <stdio.h>

typedef struct{
	char **arr;
	int front,rear,size;
}DQ;

void insertFront(DQ *dq,char *el){
	if(dq->front==0){
		printf("Queue full from front\n");
		return;
	}
	dq->arr[--dq->front]=el;
}

void insertRear(DQ *dq,char *el){
	if(dq->rear>=dq->size-1){
		printf("Queue full from rear\n");
		return;
	}
	dq->arr[++dq->rear]=el;
}

char* rem(DQ *dq){
	if(dq->front > dq->rear){
		printf("Queue empty\n");
		return NULL;
	}
	return dq->arr[dq->front++];
}

void display(DQ dq){
	printf("The elements are:-\n");
	int i;
	for(i=dq.front;i<=dq.rear;i++)
		printf("%s\n", dq.arr[i]);
}

#endif