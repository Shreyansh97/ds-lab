#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#ifndef unsolved3_h
#define unsolved3_h
typedef struct{
	float a,b,c;
	float root1,root2;
	int type;
}eq;

void getdata(eq *a){
	printf("Enter coefficients of x^2, x and constant: ");
	scanf("%f%f%f",&(a->a),&(a->b),&(a->c));
}

void quadratic(eq *a){
	double d = (a->b)*(a->b)-4*(a->a)*(a->c);
	if(d<0){
		a->type = 1;
		d=abs(d);
	}
	else
		a->type = 2;
	d=sqrt(d);
	if(d==0){
		a->root1 = - (a->b) / 2 / (a->a);
		a->root2 = a->root1;
	}
	else if( a->type == 1){
		a->root1 = - (a->b) / 2 / (a->a);
		a->root2 = d;
	}
	else{
		a->root1 = -((a->b)-d)/2/(a->a);
		a->root2 = -((a->b)+d)/2/(a->a);
	}
}

void print_roots(eq *a){
	printf("roots are\n");
	if(a->type == 1){
		printf("%f +i %f\n",a->root1,a->root2);
		printf("%f -i %f\n",a->root1,a->root2);
	}
	else
		printf("%f\n%f\n",a->root1,a->root2);
}
#endif
