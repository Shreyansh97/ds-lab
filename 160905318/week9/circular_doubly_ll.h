#ifndef CIRCULAR_DOUBLE_LL
#define CIRCULAR_DOUBLE_LL

typedef struct node{
	char val;
	struct node *prev,*next;
}DLL;

DLL* init(){
	DLL *head=(DLL*) malloc(sizeof(DLL));
	head->val=0;
	head->prev=head;
	head->next=head;
	return head;
}

void insert(DLL* head,char val){
	if(!head)
		return;
	DLL *ob=(DLL*) malloc(sizeof(DLL));
	ob->val=val;
	ob->next=head;
	ob->prev=head->prev;
	head->prev=ob;
	ob->prev->next=ob;
}

void input(DLL* head){
	int flag=0;
	char ch='\0';
	while(1){
		scanf("%c",&ch);
		if(ch>='0' && ch<='9'){
			flag=1;
			insert(head,ch-48);
		}
		else if(flag)
			return;
	}
}

//displays the LL in reverse order
void show(DLL* head){
	if(!head)
		return;
	DLL *temp=head->prev;
	while(temp!=head){
		printf("%d",temp->val);
		temp=temp->prev;
	}
	printf("\n");
}

DLL* add(DLL *head1,DLL *head2){
	DLL* head=init();
	int carry=0;
	DLL *t1=head1->prev,*t2=head2->prev;
	while(t1!=head1 && t2!=head2){
		int sum=(t1->val+t2->val+carry);
		insert(head,(char)(sum%10));
		carry=sum/10;
		t1=t1->prev;
		t2=t2->prev;
	}
	while(t1!=head1){
		carry+=t1->val;
		insert(head,(char)(carry%10));
		carry/=10;
		t1=t1->prev;
	}
	while(t2!=head2){
		carry+=t2->val;
		insert(head,(char)(carry%10));
		carry/=10;
		t2=t2->prev;
	}
	while(carry>0){
		insert(head,(char)(carry%10));
		carry/=10;
	}
	return head;
}


#endif