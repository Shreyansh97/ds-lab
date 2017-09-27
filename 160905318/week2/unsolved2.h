#include <stdio.h>
#ifndef unsolved2_h
#define unsolved2_h

//Function to demonstrate passing pointers
void increment(int *a){
	(*a)++;
}

//Function to demonstrate returning pointer from a function
int* linear(int* a,int val,int size){
	int i;
	for(i=0;i<size;i++)
		if(*(a+i) == val)
			return (a+i);
	return NULL;
}

//Using pointer to a pointer
void printMatrix(int** p,int row,int col){
	int i,j;
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			printf("%d\t",*(*(p+i)+j));
		}
		printf("\n");
	}
}

#endif
