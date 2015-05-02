#include<stdio.h>
#define N 10

void snake(bool fromout)
{
	int a[N][N];
	int start=(fromout?0:-N*N-1);
	for(int k=0;k<N/2;k++)
	{
		int i=k,j=k;
		for(j=k;j<N-k-1;j++)
			a[i][j]=++start;
		for(i=k;i<N-k-1;i++)
			a[i][j]=++start;
		for(j;j>k;j--)
			a[i][j]=++start;
		for(i;i>k;i--)
			a[i][j]=++start;
	}
	//print
	for(int i=N-1;i>=0;i--)
	{
		for(int j=0;j<N;j++)
			printf("%4d",(fromout?1:-1)*a[j][i]);
		printf("\n");
	}
}
int main()
{
	snake(0);
	printf("\n\n");
	snake(1);
	return 0;
}
