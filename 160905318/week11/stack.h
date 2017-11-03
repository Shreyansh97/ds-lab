#ifndef POINTER_STACK
#define POINTER_STACK
#include <stdlib.h>

typedef struct stack{
	void *data;
	struct stack *next;
}STACK;

STACK* init(){
	STACK* head=(STACK*) malloc(sizeof(STACK));
	head->data=NULL;
	head->next=NULL;
	return head;
}

void push(STACK* head,void *data){
	STACK* node=(STACK*) malloc(sizeof(STACK));
	node->data=data;
	node->next=head->next;
	head->next=node;
}

void* peek(STACK *head){
	if(head->next)
		return head->next->data;
	return NULL;
}

void* pop(STACK *head){
	if(!head->next)
		return NULL;
	void* data=head->next->data;
	free(head->next);
	head->next=head->next->next;
	return data;
}

int isEmpty(STACK *head){
	return head->next==NULL;
}

#endif