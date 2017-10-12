#include <stdio.h>
#include <stdlib.h>
#include "cqueue.h"
#include <limits.h>

int main(){
	int num,prev;
	char ch1,ch2;
	NODE *head1=NULL,*head2=NULL,*head=NULL;
	printf("Enter elements in sorted order in list 2(; to stop)\n");
	ch2='\0';
	ch1='\0';
	while(1){
		scanf("%c",&ch1);
		while(ch1=='\n' || ch1==' ')
			scanf("%c",&ch1);
		if(ch1==';')
			break;
		head1=insert(head1,ch1);
		if(ch1<ch2){
			printf("elements not in sorted order");
			return 0;
		}
		ch2=ch1;
	}
	printf("Enter elements in sorted order in list 2(; to stop)\n");
	ch1=ch2='\0';
	while(1){
		scanf("%c",&ch1);
		while(ch1=='\n' || ch1==' ')
			scanf("%c",&ch1);
		if(ch1==';')
			break;
		head2=insert(head2,ch1);
		if(ch1<ch2){
			printf("elements not in sorted order");
			return 0;
		}
		ch2=ch1;
	}
	NODE *t1=head1,*t2=head2;
	num=prev=0;
	while((t1!=head1 || num==0) && (t2!=head2 || prev==0)){
		if(t1->val < t2-> val){
			head=insert(head,t1->val);
			t1=t1->next;
			num++;
		}
		else{
			head=insert(head,t2->val);
			t2=t2->next;
			prev++;
		}
	}
	while(t1!=head1 || num==0){
		head=insert(head,t1->val);
		t1=t1->next;
		num++;
	}
	while(t2!=head2 || prev==0){
		head=insert(head,t2->val);
		t2=t2->next;
		prev++;
	}
	printf("Sorted:\n");
	display(head);
	return 0;
}