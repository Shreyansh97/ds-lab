#ifndef PRIORITY_Q
#define PRIORITY_Q
#include <stdio.h>
#include <limits.h>

typedef struct{
	int data;
	int priority;
}ELEMENT;

typedef struct{
	ELEMENT *arr;
	int cap,size;
}PQ;

void init(PQ *pq,int cap){
	pq->arr = (ELEMENT*) malloc(sizeof(ELEMENT)*cap);
	pq->cap = cap;
	pq->size = 0;
}

int parent(int i){
	return (i-1)>>1;
}

int leftChild(int i){
	return (i<<1)+1;
}

int rightChild(int i){
	return (i<<1)+2;
}

void swap(PQ *pq,int i,int j){
	ELEMENT temp=pq->arr[i];
	pq->arr[i]=pq->arr[j];
	pq->arr[j]=temp;
}

void minHeapify(PQ *pq,int i){
	int min=i;
	int lc=leftChild(i);
	int rc=rightChild(i);
	if(lc<pq->size && pq->arr[lc].priority < pq->arr[min].priority)
		min=lc;
	if(rc<pq->size && pq->arr[rc].priority < pq->arr[min].priority)
		min=rc;
	if(min!=i){
		swap(pq,i,min);
		minHeapify(pq,min);
	}
}

void pqinsert(PQ *pq,ELEMENT x){
	if(pq->size < pq-> cap){
		pq->arr[pq->size++] = x;
		minHeapify(pq,parent(pq->size-1));
	}
	else
		printf("Queue full\n");
}

ELEMENT pqmindelete(PQ *pq){
	if(pq->size<1){
		printf("Queue empty\n");
		ELEMENT x={0,INT_MIN};
		return x;
	}
	ELEMENT x=pq->arr[0];
	pq->size--;
	if(pq->size>0){
		pq->arr[0]=pq->arr[pq->size];
		minHeapify(pq,0);
	}
	return x;
}

#endif