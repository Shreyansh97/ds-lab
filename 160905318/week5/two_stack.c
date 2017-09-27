#include <stdio.h>
#include <limits.h>
#include "two_stack.h"

int main(){
	DOUBLE_STACK s;
	int c,num,val;
	printf("Enter capacity of array:\n");
	scanf("%d",&c);
	init(&s,c);
	while(1){
		printf("1. insert 2. delete 3. dispaly 4. exit\n");
		scanf("%d",&c);
		if(c<4)
			printf("Enter stack number(1 or 2):");
		scanf("%d",&num);
		switch(c){
			case 1: printf("Enter value\n");		
			scanf("%d",&val);
			push(&s,num,val);
			break;
			case 2: val=pop(&s,num);
			if(val!=INT_MIN)
				printf("Popped value :%d\n", val);
			break;
			case 3: display(s,num);
			break;
			case 4: return 0;
		}
	}
	return 0;
}