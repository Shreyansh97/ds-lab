#ifndef stack_h
#define stack_h
#include<stdio.h>
#include <limits.h>
typedef struct{
  int *arr;
  int top;
  int cap;
}STACK;

typedef enum{FALSE = 0,TRUE = 1} BOOL;

void flushInput(){
  int c;
  while((c=fgetc(stdin))!=EOF && c!='\n');
}

BOOL isFull(STACK S){
  if(S.cap-S.top<2)
    return TRUE;
  return FALSE;
}

BOOL isEmpty(STACK S){
  if(S.top==-1)
    return TRUE;
  return FALSE;
}
void push(STACK *S,int c){
  if(isFull(*S)==TRUE){
    printf("Stack Full\n");
    return;
  }
  S->arr[++S->top]=c;
}

int pop(STACK *S){
  if(isEmpty(*S)==TRUE)
    return INT_MIN;
  S->top--;
  return S->arr[S->top+1];
}

void display(STACK *S){
  int i;
  printf("Elements of the stack are:\n");
  for(i=0;i<=S->top;i++)
    printf("%d ",S->arr[i]);
  printf("\n");
}
#endif