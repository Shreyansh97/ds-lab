#include<stdio.h>
#include<stdlib.h>

typedef struct{
  int sr,sc,dr,dc;
}MOVE;

MOVE *moves,top=-1;
void init(int n){
  moves = (MOVE*)calloc(n,sizeof(MOVE));
}

void push(MOVE m){
  moves[++m]=m;
}

MOVE pop(){
  top--;
  return moves[top+1];
}

void display(){
  int i;
  for(i=0;i<=top;i++)
    printf("(%d,%d) -> (%d,%d)",moves[i].sr,moves[i].sc,moves[i].dr,moves[i].dc);
}

int main(){
  int r,c,**a,i,j,x,y;
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
  printf("Enter ending point:");
  scanf("%d%d",&x,&y);
  a[i][j]=1;
  floodfill(a,r,c,i,j);
  for(i=0;i<r;i++){
    for(j=0;j<c;j++)
      printf("%d ",a[i][j]);
    printf("\n");
  }
  return 0;
}
