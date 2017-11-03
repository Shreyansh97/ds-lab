#include <stdio.h>
#include <stdlib.h>
#include "circular_doubly_ll.h"

int main(){
	DLL *head1=init();
	DLL *head2=init();
	printf("Enter number 1:\n");
	input(head1);
	printf("Enter number 2:\n");
	input(head2);
	DLL* head=add(head1,head2);
	printf("Sum is:-\n");
	show(head);
	return 0;
}