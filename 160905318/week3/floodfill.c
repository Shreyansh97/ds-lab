#include<stdio.h>
#include<stdlib.h>

void floodfill(int **a,int r,int c,int i,int j){
  int x,y;
  if(i<0 || i>=r || j<0 || j>=c)
    return;
  for(x=-1;x<2;x++){
    for(y=-1;y<2;y++){
      if((x==0 && y==0) || i+x<0 || i+x>=r || j+y<0 || j+y>=c)
        continue;
      if(a[i+x][j+y]==0){
        a[i+x][j+y]=1;
        floodfill(a,r,c,i+x,j+y);
      }
    }
  }
}

int main(){
  int r,c,**a,i,j;
  printf("Enter number of rows and columns:");
  scanf("%d%d",&r,&c);
  a=(int**)calloc(r,sizeof(int*));
  printf("Enter elements\n");
  for(i=0;i<r;i++){
    a[i]=(int*)calloc(c,sizeof(int));
    for(j=0;j<c;j++)
      scanf("%d",&a[i][j]);
  }
  printf("Enter starting point:");
  scanf("%d%d",&i,&j);
  a[i][j]=1;
  floodfill(a,r,c,i,j);
  for(i=0;i<r;i++){
    for(j=0;j<c;j++)
      printf("%d ",a[i][j]);
    printf("\n");
  }
  return 0;
}
