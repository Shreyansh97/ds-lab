#ifndef unsolved_h
#define unsolved_h
int sum(int a[],int n){
	int s=0,i;
	for(i=0;i<n;i++)
		s+=a[i];
	return s;
}

int linear(int a[],int len,int key){
	int i;
	for(i=0;i<len;i++)
		if(a[i]==key)
			return i;
	return -1;
}

//a=b+c
void matrix_sum(int a[][100],int b[][100],int c[][100],int m,int n){
	int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			a[i][j]=b[i][j]+c[i][j];
		}
	}
}

int max(int a[],int n){
	int big=a[0],i;
	for(i=1;i<n;i++)
		if(a[i]>big)
			big = a[i];
	return big;
}	
#endif