#ifndef Circular_Q
#define Circular_Q
#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char **arr;
	int front,rear,cap,count;
}CQ;

void insertcq(CQ* cq,char* st){
	if(cq->count == cq->cap-1){
		printf("Queue full\n");
		return;
	}
	cq->rear=(cq->rear+1)%cq->cap;
	cq->count++;
	cq->arr[cq->rear]=st;
}

char* deletecq(CQ* cq){
	char *s;
	if(cq->count<=0){
		printf("Queue empty\n");
		return NULL;
	}
	cq->front = (cq->front+1)%cq->cap;
	cq->count--;
	return cq->arr[cq->front];
}

void displaycq(CQ cq){
	int i;
	printf("The circular queue contains:-\n");
	if(cq.front>cq.rear){
		for(i=cq.front+1;i<cq.cap;i++)
			printf("%s\n", cq.arr[i]);
		for(i=0;i<=cq.rear;i++)
			printf("%s\n", cq.arr[i]);
	}
	else{
		for(i=cq.front+1;i<=cq.rear;i++)
			printf("%s\n", cq.arr[i]);
	}
}

#endif