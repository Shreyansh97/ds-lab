#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DoublyLinkedList.h"

int main(){
	DLL *head=NULL;
	int ch;
	char s[100];
	while(1){
		printf("1. insert 2. reverse 3. display 4. exit\n");
		scanf("%d",&ch);
		switch(ch){
			case 1: printf("Enter string\n");
			scanf("%s",s);
			head=insert(head,&s[0]);
			break;
			case 2: head=reverse(head);
			break;
			case 3: display(head);
			break;
			case 4: return 0;
		}
	}
	return 0;
}