#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "sets.h"

int main(){
	char ch1;
	NODE *head1=NULL,*head2=NULL,*head=NULL;
	printf("Enter elements in list 1(; to stop)\n");
	ch1='\0';
	while(1){
		scanf("%c",&ch1);
		while(ch1=='\n' || ch1==' ')
			scanf("%c",&ch1);
		if(ch1==';')
			break;
		head1=insert(head1,ch1);
	}
	printf("Enter elements in list 2(; to stop)\n");
	ch1='\0';
	while(1){
		scanf("%c",&ch1);
		while(ch1=='\n' || ch1==' ')
			scanf("%c",&ch1);
		if(ch1==';')
			break;
		head2=insert(head2,ch1);
	}
	head=unio(head1,head2);
	printf("Union of the 2 sets:-\n");
	display(head);
	head=intersection(head1,head2);
	printf("intersection of the 2 sets:-\n");
	display(head);
	return 0;
}