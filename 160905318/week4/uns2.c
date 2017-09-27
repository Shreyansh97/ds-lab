#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

int main(){
  char str[100],c;
  int l,i;
  STACK S;
  printf("Enter string\n");
  fgets(str,100,stdin);
  l=strlen(str)-1;
  S.cap = l/2;
  S.top = -1;
  S.ch = (char*)malloc(S.cap * sizeof(char));
  for(i=l-S.cap;i<l;i++)
    push(&S,str[i]);
  c=pop(&S);
  for(i=0;c!='\0';i++){
    if(c!=str[i]){
      printf("Not pallindrome\n");
      return 0;
    }
    c = pop(&S);
  }
  printf("Pallindrome\n");
  return 0;
}
