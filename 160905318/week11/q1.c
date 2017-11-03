#include <stdio.h>
#include "BST.h"

int main(){
	TNODE *root=NULL;
	int choice,data;
	printf("1. insert element 2. remove element 3. print level order 4. exit\n");
	while(1){
		printf("Enter choice:");
		scanf("%d",&choice);
		switch(choice){
			case 1: printf("Enter data:");
			scanf("%d",&data);
			root = insert_node(root,data);
			break;
			case 2: printf("Enter data:");
			scanf("%d",&data);
			root = remove_node(root,data);
			break;
			case 3: printf("Level order traversal:-\n");
			level_order_traverse(root);
			break;
			case 4: return 0;
		}
	}
	return 0;
}