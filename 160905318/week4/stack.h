#ifndef stack_h
#define stack_h
#include<stdio.h>
typedef struct{
  char *ch;
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
void push(STACK *S,char c){
  if(isFull(*S)==TRUE){
    printf("Stack Full\n");
    return;
  }
  S->ch[++S->top]=c;
}

char pop(STACK *S){
  if(isEmpty(*S)==TRUE)
    return '\0';
  S->top--;
  return S->ch[S->top+1];
}

void display(STACK *S){
  int i;
  printf("Elements of the stack are:\n");
  for(i=0;i<=S->top;i++)
    printf("%c ",S->ch[i]);
  printf("\n");
}



#endif
