#include<stdio.h>
#include "unsolved1.h"
int main(){
  int **m1,**m2,**p,r1,r2,c1,c2,i,j,ch;
  char s[50],a[50];
  printf("1. Matrix Multiplication\n2. Length of string\n3. Copy String\n4. Check Pallindrome string\n5. Tower of hanoi\n");
  scanf("%d",&ch);
  fgets(s,50,stdin);
  switch(ch){
    case 1: m1=inputMatrix(&r1,&c1);
            m2=inputMatrix(&r2,&c2);
            if(c1!=r2){
              printf("Not compatible for multiplication");
              break;
            }
            p=(int**)calloc(r1,sizeof(int*));
            for(i=0;i<r1;i++)
              p[i]=(int*)calloc(c2,sizeof(int));
            multiply(p,m1,m2,r1,c1,c2,0,0,0);
            printf("Multiplied matrix=\n");
            for(i=0;i<r1;i++){
              for(j=0;j<c2;j++)
                printf("%d ",p[i][j]);
              printf("\n");
            }
            break;
    case 2: printf("Enter string\n");
            fgets(s,50,stdin);
            i=length(s);
            printf("Length is %d\n",i);
            break;
    case 3: printf("Enter string\n");
            fgets(s,50,stdin);
            copy(s,a);
            printf("New string:\n%s\n",a);
            break;
    case 4: printf("Enter string\n");
            fgets(s,50,stdin);
            i=length(s);
            j=checkPall(s,s+i-1);
            if(j)
              printf("Pallindrome string\n");
            else
              printf("Not a Pallindrome string\n");
            break;
    case 5: printf("Enter number of disks:");
            scanf("%d",&i);
            j=0;
            toh(i,'A','B','C',&j);
            printf("\nNumber of moves= %d\n",j);
  }
  return 0;
}
