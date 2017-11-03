#ifndef DOUBLY_LL
#define DOUBLY_LL value
typedef struct node{
	char *val;
	struct node *next,*prev;
}DLL;

DLL* insert(DLL* head, char* val){
	DLL* temp=(DLL*) malloc(sizeof(DLL));
	char *newstr=malloc(sizeof(val));
	newstr=strcpy(newstr,val);
	temp->val=newstr;
	temp->next=NULL;
	temp->prev=NULL;
	if(!head)
		return temp;
	DLL* t=head;
	while(head->next)
		head=head->next;
	temp->prev=head;
	head->next=temp;
	return t;
}

void display(DLL *head){
	while(head){
		printf("%s\n", head->val);
		head=head->next;
	}
}

DLL* do_reverse(DLL *head,DLL *prev){
	if(!head)
		return NULL;
	DLL *temp=do_reverse(head->next,head);
	head->next=head->prev;
	head->prev=prev;
	if(temp)
		return temp;
	return head;
}

DLL* reverse(DLL *head){
	return do_reverse(head,NULL);
}
#endif