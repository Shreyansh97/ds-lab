#include<stdio.h>
#include<stdlib.h>

void print(int *a,int size){
	printf("In forward direction \n");
	int size1=size;
	while(size-->0){
		printf("%d ",*a);
		a++;
	}
	a--;
	printf("\nIn backward direction\n");
	while(size1-->0){
		printf("%d ",*a);
		a--;
	}
	printf("\n");
}
int main(){
	int *a,size,i;
	printf("Number of elements:");
	scanf("%d",&size);
	a=(int*)malloc(size*sizeof(int));
	printf("Enter elements:");
	for(i=0;i<size;i++){
		scanf("%d",a+i);
	}
	print(a,size);
	return 0;
}
