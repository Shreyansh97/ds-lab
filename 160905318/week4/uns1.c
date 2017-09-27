#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(){
  STACK S;
  int i;
  char ch;
  printf("Enter capacity of stack:");
  scanf("%d",&(S.cap));
  S.ch = (char*)malloc(S.cap * sizeof(char));
  S.top = -1;
  while(TRUE){
    printf("1. push\n2. pop\n3. display\n4. quit\n");
    scanf("%d",&i);
    switch(i){
      case 1: printf("Enter value\n");
              flushInput();
              scanf("%c",&ch);
              push(&S,ch);
              break;
      case 2: ch = pop(&S);
              if(ch == '\0')
                printf("Stack empty\n");
              else
                printf("Popped item is %c \n",ch);
              break;
      case 3: display(&S);
              break;
      case 4: return 0;
    }
  }
  return 0;
}
