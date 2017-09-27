#include <stdio.h>
int add(int *a,int *b){
	int sum=0;
	sum = *a + *b;
	return sum;
}
int main(){
	int a,b,sum;
	printf("Enter two numbers:");
	scanf("%d%d",&a,&b);
	sum = add(&a,&b);
	printf("Sum of %d and %d is %d\n",a,b,sum);
	return 0;
}
