#ifndef Multiple_CQ
#define Multiple_CQ
#include <stdio.h>
#include <limits.h>

typedef struct{
	int front,rear,start,end,count;	
}MULTI_CQ;

void insert(int *arr,MULTI_CQ* cq,int elem){
	if(cq->count==(cq->end - cq->start + 1)){
		printf("Queue full\n");
		return;
	}
	cq->count++;
	cq->rear++;
	if(cq->rear >= cq->end)
		cq->rear = cq->rear - cq->end + cq->start;
	arr[cq->rear]=elem;
}

int delete(int *arr,MULTI_CQ* cq){
	if(cq->count <1){
		printf("Queue empty\n");
		return INT_MIN;
	}
	cq->count--;
	cq->front++;
	if(cq->front >= cq->end)
		cq->front -= cq->end - cq->start;
	return arr[cq->front];
}

void display(int *arr,MULTI_CQ cq){
	int i;
	if(cq.front>=cq.rear && cq.count>0){
		for(i=cq.front+1;i<=cq.end;i++)
			printf("%d\n", arr[i]);
		for(i=cq.start;i<=cq.rear;i++)
			printf("%d\n", arr[i]);
	}
	else{
		for(i=cq.front+1;i<=cq.rear;i++)
			printf("%d\n", arr[i]);
	}
}

#endif