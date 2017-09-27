#include<stdio.h>
#include "unsolved3.h"

int main(){
	eq a;
	getdata(&a);
	quadratic(&a);
	print_roots(&a);
	return 0;
}
