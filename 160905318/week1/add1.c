#include <stdio.h>
#include <stdlib.h>

int main(){
	int n,r;
	int a[201];
	printf("Enter number of random numbers: ");
	scanf("%d",&n);
	for(r=0;r<201;r++)
		a[r]=0;
	while(n-->0){
		r=rand() % 201;
		a[r]++;
	}
	for(r=0;r<201;r++)
		printf("%d generated %d times\n", r-100, a[r]);
	return 0;
}