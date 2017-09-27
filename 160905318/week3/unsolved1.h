#include<stdio.h>
#include<stdlib.h>
#ifndef unsolved1_h
#define unsolved1_h

int** inputMatrix(int *r,int *c){
  int **p,i,j;
  printf("Enter number of rows and columns of matrix:");
  scanf("%d%d",r,c);
  p=(int**)calloc(*r,sizeof(int*));
  printf("Enter elements\n");
  for(i=0;i<*r;i++){
    p[i]=(int*)calloc(*c,sizeof(int));
    for(j=0;j<*c;j++)
      scanf("%d",&p[i][j]);
  }
  return p;
}

void multiply(int** p,int** m1,int **m2,int x,int y,int z,int i,int j,int k){
  if(k==y){
    j++;
    k=0;
  }
  if(j==z){
    i++;
    j=0;
  }
  if(i==x)
    return;
  p[i][j]+=m1[i][k]*m2[k][j];
  multiply(p,m1,m2,x,y,z,i,j,k+1);
}

int length(char* s){
  if(*s == '\0')
    return 0;
  if(*s == '\n')
    return length(s+1);
  return 1+length(s+1);
}

void copy(char* s,char* c){
  *c = *s;
  if(*s == '\0')
    return;
  copy(s+1,c+1);
}

int checkPall(char* s,char *p){
  if(p<=s)
    return 1;
  if(*p != *s)
    return 0;
  return checkPall(s+1,p-1);
}

void toh(int n,char s,char i,char d,int *count){
  if(n<1)
    return;
  toh(n-1,s,d,i,count);
  printf("%c -> %c\n",s,d);
  toh(n-1,i,s,d,count);
  (*count)++;
}
#endif
