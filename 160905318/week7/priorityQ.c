#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "priorityQ.h"

int main(){
	PQ pq;
	int cap,ch;
	ELEMENT x;
	printf("Enter capacity:");
	scanf("%d",&cap);
	init(&pq,cap);
	while(1){
		printf("1. insert 2. remove 3. exit\n");
		scanf("%d",&ch);
		switch(ch){
			case 1: printf("Enter value:");
			scanf("%d",&(x.data));
			printf("Enter priority:");
			scanf("%d",&(x.priority));
			pqinsert(&pq,x);
			break;
			case 2: x = pqmindelete(&pq);
			if(x.priority != INT_MIN)
				printf("Data:%d\nPriority:%d\n", x.data,x.priority);
			break;
			case 3: return 0;
			default: break;
		}
	}
}