#ifndef two_stack
#define two_stack
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
typedef struct {
	int* arr;
	int top1;
	int top2;
	int cap;
}DOUBLE_STACK;

void init(DOUBLE_STACK *S, int cap){
	S->top1=-1;
	S->top2=cap;
	S->cap=cap;
	S->arr=(int*) malloc(sizeof(int)*cap);
}

void push(DOUBLE_STACK *S,int num,int val){
	if(S->top1>=S->top2-1){
		printf("Stack full\n");
		return;
	}
	if(num==1)
		S->arr[++S->top1]=val;
	else
		S->arr[--S->top2]=val;
}

int pop(DOUBLE_STACK *S,int num){
	if((num==1 && S->top1<0) || (num==2 && S->top2>=S->cap)) {
		printf("Stack empty\n");
		return INT_MIN;
	}
	if(num==1)
		return S->arr[S->top1--];
	return S->arr[S->top2++];
}

void display(DOUBLE_STACK S,int num){
	int i;
	if(num==1)
		for(i=0;i<=S.top1;i++)
			printf("%d ", S.arr[i]);
	else
		for(i=S.cap-1;i>=S.top2;i--)
			printf("%d ", S.arr[i]);
	printf("\n");
}

#endif