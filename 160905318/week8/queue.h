#include <stdio.h>
#include <limits.h>
#ifndef queue
#define queue
typedef struct node{
	int val;
	struct node *next;
}NODE;

void insert(NODE **head,int val){
	NODE* ob=(NODE*) malloc(sizeof(NODE));
	ob->val=val;
	ob->next=NULL;
	NODE* temp=*head;
	if(!*head){
		*head=ob;
		return;
	}
	else{
		while(temp->next)
			temp=temp->next;
		temp->next=ob;
	}
}
int pop(NODE **head){
	int n=INT_MIN;
	if(*head){
		n=(*head)->val;
		*head=(*head)->next;
	}
	return n;
}

void display(NODE *head){
	while(head){
		printf("%d\n", head->val);
		head=head->next;
	}
}
#endif