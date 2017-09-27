#include <stdio.h>
#include <stdlib.h>
#include "unsolved2.h"

int main(){
	int ch,a,s,i,j;
	int *p,*b,**mat;
	printf("enter 1 to increment a number, 2 for linear search and 3 to print a matrix:");
	scanf("%d",&ch);
	switch(ch){
		case 1: printf("Enter a number:");
		scanf("%d",&a);
		increment(&a);
		printf("Incremented using pointer. new value = %d\n",a);
		break;
		case 2: printf("Enter size of array:");
		scanf("%d",&a);
		p=(int*)calloc(a,sizeof(int));
		printf("Enter searching number:");
		scanf("%d",&s);
		printf("Enter elements:");
		for(i=0;i<a;i++)
			scanf("%d",p+i);
		b=linear(p,s,a);
		if(b==NULL)
			printf("Not found\n");
		else
			printf("Found at position %d\n",b-p);
		break;
		case 3:printf("Enter number of rows and columns:");
		scanf("%d%d",&a,&s);
		mat=(int**)calloc(a,sizeof(int*));
		for(i=0;i<a;i++)
			*(mat+i)=(int*)calloc(s,sizeof(int));
		printf("Enter elements row-wise\n");
		for(i=0;i<a;i++)
		{
			for(j=0;j<s;j++)
				scanf("%d",*(mat+i)+j);
		}
		printf("Matrix printed using pointer to pointer\n");
		printMatrix(mat,a,s);
		break;
		default:printf("Wrong choice\n");
	}
	return 0;
}
