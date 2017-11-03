#ifndef EXP_TREE
#define EXP_TREE
#include <stdlib.h>
#include <ctype.h>
#include "stack.h"

typedef struct _tnode{
	char sym;
	struct _tnode *left,*right;
}TNODE;

int isoperator(char ch){
	return ch=='*' || ch=='+' || ch=='-' || ch=='/';
}

TNODE* build_tree(char *post_exp,int n){
	STACK *st = init();
	int i;
	char ch;
	for(i=0;i<n;i++){
		ch=post_exp[i];
		if(isdigit(ch)){
			TNODE *node = (TNODE*) malloc(sizeof(TNODE));
			node->sym=ch;
			node->left=node->right=NULL;
			push(st,node);
		}
		else if(isoperator(ch)){
			TNODE *b=(TNODE*) pop(st);
			TNODE *a=(TNODE*) pop(st);
			if(a==NULL || b==NULL)
				return NULL;
			TNODE *node = (TNODE*) malloc(sizeof(TNODE));
			node->sym=ch;
			node->left=a;
			node->right=b;
			push(st,node);
		}
		else
			return NULL;
	}
	TNODE *root=pop(st);
	if(!isEmpty(st))
		return NULL;
	return root;
}
int evaluate(TNODE *root){
	if(root==NULL)
		return 0;
	int ans=0;
	if(isoperator(root->sym)){
		int left=evaluate(root->left);
		int right=evaluate(root->right);
		switch(root->sym){
			case '*': ans =left*right;
			break;
			case '/': ans =left/right;
			break;
			case '+': ans =left+right;
			break;
			case '-': ans=left-right;
		}
	}
	else if(isdigit(root->sym))
		ans = root->sym - 48;
	return ans;
}
#endif