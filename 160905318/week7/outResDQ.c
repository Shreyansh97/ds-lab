#include <stdio.h>
#include <stdlib.h>
#include "outResDQ.h"

int main(){
	DQ dq;
	int cap;
	char *s;
	printf("Enter capacity:");
	scanf("%d",&cap);
	dq.arr = (char**) malloc(sizeof(char*)*cap);
	dq.front=0;
	dq.rear=-1;
	dq.size=cap;
	while(1){
		printf("1. insert front 2. insert rear 3. delete 4. display 5. exit\n");
		scanf("%d",&cap);
		if(cap==1 || cap==2){
			printf("Enter string:");
			s=(char*) malloc(sizeof(char)*100);
			scanf("%s",s);
		}
		switch(cap){
			case 1:insertFront(&dq,s);
			break;
			case 2:insertRear(&dq,s);
			break;
			case 3: s=rem(&dq);
			if(s)
				printf("Deleted:%s\n", s);
			break;
			case 4: display(dq);
			break;
			case 5: return 0;
			default: break;
		}
	}
}