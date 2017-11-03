#ifndef SETS
#define SETS
#include "circular_ll.h"

int isPresent(NODE *head,char val){
	NODE* temp=head;
	if(!head)
		return 0;
	if(temp->val==val)
		return 1;
	temp=temp->next;
	while(temp!=head){
		if(temp->val==val)
			return 1;
		temp=temp->next;
	}
	return 0;
}

NODE* unio(NODE* head1,NODE* head2){
	NODE *t1=head1,*t2=head2;
	NODE *head=NULL;
	if(t1){
		head=insert(head,t1->val);
		t1=t1->next;
		while(t1!=head1){
			if(!isPresent(head,t1->val))
				head=insert(head,t1->val);
			t1=t1->next;
		}
	}
	if(t2){
		if(!isPresent(head,t2->val))
			head=insert(head,t2->val);
		t2=t2->next;
		while(t2!=head2){
			if(!isPresent(head,t2->val))
				head=insert(head,t2->val);
			t2=t2->next;
		}
	}
	return head;
}

NODE* intersection(NODE *head1,NODE *head2){
	NODE *t=head2;
	if(!head1 || !head2)
		return NULL;
	NODE *head=NULL;
	if(isPresent(head1,t->val) && !isPresent(head,t->val))
		head=insert(head,t->val);
	t=t->next;
	while(t!=head2){
		if(isPresent(head1,t->val) && !isPresent(head,t->val))
			head=insert(head,t->val);
		t=t->next;
	}
	return head;
}

#endif