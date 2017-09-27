#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "stack.h"

int main(){
	STACK s;
	s.top=-1;
	s.cap=100;
	s.arr=(int*) malloc(sizeof(int)*s.cap);
	int l,i,num1,num2;
	char exp[100],ch;
	printf("Enter prefix expression\n Single digit operand and operators only\n");
	scanf("%s",exp);
	l=strlen(exp);
	for(i=l-1;i>=0;i--){
		ch=exp[i];
		if(ch<='9' && ch >='0')
			push(&s,ch&15);
		else{
			if(s.top<1){
				printf("Invalid prefix expression\n");
				return 0;
			}
			num1=pop(&s);
			num2=pop(&s);
			switch(ch){
				case '-':push(&s,num1-num2);
				break;
				case '+':push(&s,num1+num2);
				break;
				case '*':push(&s,num1*num2);
				break;
				case '/':push(&s,num1/num2);
				break;
				case '^':
				case '$': push(&s,pow(num1,num2));
				break;
				default: printf("Invalid prefix expression\n");
				return 0;
			}
		}
	}
	if(s.top==0)
		printf("Ans:%d\n", pop(&s));
	else
		printf("Invalid prefix expression\n");
	return 0;
}