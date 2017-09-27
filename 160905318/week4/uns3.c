#include<stdio.h>
#include<stdlib.h>
#include "stack.h"

int main(){
  STACK S;
  int n;
  char ch;
  printf("Enter number:");
  scanf("%d",&n);
  S.cap = sizeof(int)*8;
  S.top = -1;
  S.ch = (char*)malloc(S.cap*sizeof(char));
  while(n>0){
    push(&S,(n&1)+48);
    n>>=1;
  }
  printf("Binary representation is: ");
  ch=pop(&S);
  while(ch!='\0'){
    printf("%c",ch);
    ch = pop(&S);
  }
  printf("\n");
  return 0;
}
