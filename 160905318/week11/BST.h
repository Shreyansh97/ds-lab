#ifndef BST
#define BST
#include <stdlib.h>
#include "queue.h"

typedef struct tnode{
	int data;
	struct tnode *right,*left;
}TNODE;

TNODE* insert_node(TNODE* root,int data){
	TNODE *temp_root;
	if(root==NULL){
		temp_root = (TNODE*) malloc(sizeof(TNODE));
		temp_root->data = data;
		temp_root->right = NULL;
		temp_root->left = NULL;
		return temp_root;
	}
	if(data < root->data)
		root->left = insert_node(root->left,data);
	else if(data > root->data)
		root->right = insert_node(root->right,data);
	return root;
}

TNODE* remove_node(TNODE* root,int data){
	if(root==NULL);
	else if(data<root->data)
		root->left=remove_node(root->left,data);
	else if(data>root->data)
		root->right=remove_node(root->right,data);
	else{
		TNODE *temp;
		if(root->left == NULL)
			temp=root->right;
		else if(root->right == NULL)
			temp=root->left;
		else if(root->right->left==NULL){
			temp=root->right;
			temp->left=root->left;
		}
		else{
			temp=root->right;
			TNODE *prev=root->right;
			while(temp->left != NULL){
				prev=temp;
				temp=temp->left;
			}
			prev->left=temp->right;
			temp->right=root->right;
			temp->left=root->left;
		}
		free(root);
		return temp;
	}
	return root;
}

void level_order_traverse(TNODE *root){
	Q_NODE* q=queue_init();
	TNODE *curr;
	if(!root)
		return;
	queue_insert(q,root);
	while(has_elem(q)){
		curr=(TNODE*) queue_remove(q);
		printf("%d ",curr->data);
		if(curr->left)
			queue_insert(q,curr->left);
		if(curr->right)
			queue_insert(q,curr->right);
	}
	printf("\n");
}
#endif