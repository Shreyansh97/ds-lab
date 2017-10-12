#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include <limits.h>

int main(){
	NODE *head=NULL;
	int c,num;
	while(1){
		printf("1. Insert 2. Delete 3. Display 4. Exit\n");
		scanf("%d",&c);
		switch(c){
			case 1: printf("Enter number:");
			scanf("%d",&num);
			insert(&head,num);
			break;
			case 2: num=pop(&head);
			if(num!=INT_MIN)
				printf("Deleted:%d\n", num);
			break;
			case 3: display(head);
			break;
			case 4: return 0;
		}
	}
}