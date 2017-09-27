#include <stdio.h>
#include <stdlib.h>
#include "circularq.h"

int main(){
	CQ cq;
	int ch;
	char* s;
	printf("Enter capacity of queue\n");
	scanf("%d",&cq.cap);
	cq.front=cq.rear=-1;
	cq.count=0;
	cq.cap++;
	cq.arr=(char**) malloc(sizeof(char*) * cq.cap);
	while(1){
		printf("1.Add 2.Delete 3.Display 4.Exit\n");
		scanf("%d",&ch);
		switch(ch){
			case 1: printf("Enter string to insert:");
			s=(char*) malloc(sizeof(char) * 100);
			//flushInput();
			//fgets(s,100,stdin);
			scanf("%s",s);
			insertcq(&cq,s);
			break;
			case 2:s = deletecq(&cq);
			if(s){
				printf("%s\n", s);
				free(s);
			}
			break;
			case 3:displaycq(cq);
			break;
			default: break;
			case 4: return 0;
		}
	}
	return 0; 
}