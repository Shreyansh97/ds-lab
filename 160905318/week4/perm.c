#include<stdio.h>

typedef struct el{
  char *ch;
  int l;
  int i;
  struct el *next;
}ELE;

void push(ELE* top,ELE* ob){
  ob->next=top;
  top=ob;
}

ELE pop(ELE* top){
  if(top==NULL)
    return NULL;
  ELE ob=*top;
  top = top->next;
  return ob;
}

int main(){
  char ch[100];
}
