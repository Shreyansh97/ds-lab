#include <stdio.h>
#include <string.h>
#include "exp_tree.h"

int main(){
	char post[100];
	printf("Enter postfix expression: ");
	scanf("%s",post);
	TNODE *root = build_tree(post,strlen(post));
	if(root)
		printf("Value = %d\n", evaluate(root));
	else
		printf("Invalid postfix expression\n");
}