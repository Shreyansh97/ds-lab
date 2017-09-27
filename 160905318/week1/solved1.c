#include <stdio.h>
#include "selection_sort_fun.h"
int main(){
	int a[100];
	int i,n;
	printf("Enter number of elements: ");
	scanf("%d",&n);
	printf("Enter elements: ");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	exchange(a,n);
	printf("Sorted list by selection sort:\n");
	for(i=0;i<n;i++)
		printf("%d\t", a[i]);
	return 0;
}