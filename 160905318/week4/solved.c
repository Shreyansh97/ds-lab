#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "stack.h"

int main(){
  char exp[100],c;
  int l,i;
  STACK S;
  printf("Enter expression\n");
  scanf("%s",exp);
  l=strlen(exp);
  S.cap = l;
  S.top = -1;
  S.ch=(char*)malloc(S.cap * sizeof(char));
  for(i=0;i<l;i++){
    if(exp[i]=='(')
      push(&S,'(');
    else if(exp[i]==')'){
      c=pop(&S);
      if(c=='\0'){
        printf("Invalid\n");
        return 0;
      }
    }
  }
  if(S.top>=0)
    printf("Invalid\n");
  else
    printf("Valid\n");
  return 0;
}
