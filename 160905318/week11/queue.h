#ifndef NODE_QUEUE
#define NODE_QUEUE
#include <stdlib.h>

typedef struct qnode{
	void *data;
	struct qnode *next;
}Q_NODE;

Q_NODE* queue_init(){
	Q_NODE* head=(Q_NODE*) malloc(sizeof(Q_NODE));
	head->data=NULL;
	head->next=NULL;
	return head;
}

void queue_insert(Q_NODE *q,void *data){
	Q_NODE* node=(Q_NODE*) malloc(sizeof(Q_NODE));
	node->data=data;
	node->next=q->next;
	q->next=node;
}

void* queue_remove(Q_NODE *q){
	if(!q->next)
		return NULL;
	Q_NODE *temp=q;
	while(temp->next->next)
		temp=temp->next;
	void* data=temp->next->data;
	temp->next=NULL;
	return data;
}

int has_elem(Q_NODE *q){
	return q->next!=NULL;
}

#endif