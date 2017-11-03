#ifndef circularLL
#define circularLL
typedef struct node{
	char val;
	struct node *next;
}NODE;

NODE* insert(NODE* head,char val){
	NODE* ob=(NODE*) malloc(sizeof(NODE));
	ob->val=val;
	ob->next=head;
	if(!head){
		ob->next=ob;
		return ob;
	}
	NODE *temp=head;
	while(temp->next!=head)
		temp=temp->next;
	temp->next=ob;
	return head;
}

void display(NODE *head){
	NODE *h=head;
	while(head && head->next!=h){
		printf("%c\n", head->val);
		head=head->next;
	}
	printf("%c\n", head->val);
}
#endif