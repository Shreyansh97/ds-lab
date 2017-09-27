#include <stdio.h>
#include <stdlib.h>
//#include "multicq.h"
#include <limits.h>

typedef struct{
	int front,rear,start,end,count;	
}MULTI_CQ;

void insert(int *arr,MULTI_CQ* cq,int elem){
	if(cq->count>=(cq->end - cq->start)){
		printf("Queue full\n");
		return;
	}
	cq->count++;
	cq->rear++;
	if(cq->rear > cq->end)
		cq->rear = cq->rear - cq->end + cq->start -1;
	arr[cq->rear]=elem;
}

int delete(int *arr,MULTI_CQ* cq){
	if(cq->count <1){
		printf("Queue empty\n");
		return INT_MIN;
	}
	cq->count--;
	cq->front++;
	if(cq->front > cq->end)
		cq->front = cq->front - cq->end + cq->start -1;
	return arr[cq->front];
}

void display(int *arr,MULTI_CQ cq){
	printf("Elements are:-\n");
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
	// for(i=0;i<10;i++)
	// 	printf("%d ", arr[i]);
	printf("\n");
}

int main(){
	int num,*arr,cap,i,each;
	printf("Enter capacity and number of stacks\n");
	scanf("%d%d",&cap,&num);
	arr=(int*) malloc(cap * sizeof(int));
	printf("%ld\n", sizeof(arr));
	MULTI_CQ* cq=(MULTI_CQ*) malloc(sizeof(MULTI_CQ) * num);
	each=cap/num;
	cq[0].front=cq[0].rear=-1;
	cq[0].count=cq[0].start=0;
	cq[0].end=each-1;
	for(i=1;i<num;i++){
		cq[i].start=cq[i-1].end+1;
		cq[i].end=cq[i].start+each-1;
		cq[i].front=cq[i].rear=cq[i].start-1;
		cq[i].count=0;
	}
	while(1){
		printf("1. Insert 2. Delete 3. Display 4. Exit\n");
		scanf("%d",&each);
		printf("Enter queue number\n");
		scanf("%d",&i);
		i--;
		if(i<0 || i>= num){
			printf("Invalid queue number\n");
			continue;
		}
		switch(each){
			case 1: printf("Enter number\n");
			scanf("%d",&cap);
			insert(arr,cq+i,cap);
			break;
			case 2: cap=delete(arr,cq+i);
			if(cap!=INT_MIN)
				printf("Deleted :%d\n", cap);
			break;
			case 3: display(arr, cq[i]);
			break;
			case 4: return 0;
			default: break;
		}
	}
	return 0;
}