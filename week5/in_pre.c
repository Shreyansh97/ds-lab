#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "char_stack.h"

int getPrecedance(char ch){
	switch(ch){
		case '^':return 2;
		case '*':
		case '/':return 1;
		case '+':
		case '-':return 0;
		default: return -1;
	}
}
int main(){
	STACK s;
	char infix[100],prefix[100],ch;
	printf("Enter infix expression\n");
	scanf("%s",infix);
	int l,i,h=0,t;
	l=strlen(infix);
	s.top=-1;
	s.cap=l;
	s.ch=(char*) malloc(sizeof(char)*l);
	for(i=l-1;i>=0;i--){
		ch=infix[i];
		if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9'))
			prefix[h++]=ch;
		else if(ch==')')
			push(&s,'(');
		else if(ch=='('){
			while(peek(&s)!='(')
				prefix[h++]=pop(&s);
			pop(&s);
		}
		else if(ch=='^'){
			while(getPrecedance(peek(&s))==getPrecedance(ch))
				prefix[h++]=pop(&s);
			push(&s,ch);
		}
		else{
			t=getPrecedance(ch);
			if(t==-1){
				printf("Invalid symbol in infix\n");
				return 0;
			}
			while(getPrecedance(peek(&s))>t){
				prefix[h++]=pop(&s);
			}
			push(&s,ch);
		}
	}
	while(isEmpty(s)==FALSE){
		prefix[h++]=pop(&s);
	}
	prefix[h]='\0';
	for(i=0;i<h/2;i++){
		ch=prefix[i];
		prefix[i]=prefix[h-i-1];
		prefix[h-i-1]=ch;
	}
	printf("prefix expression:%s\n", prefix);
	return 0;
}