#include<stdio.h>
int main()
{
	int M,N;
	int a[10][10];
	int b[10][10];
	int line[10]={0};
	while(scanf("%d",&M)!=EOF&&M!=0&&scanf("%d",&N)!=EOF)
	{
		int count=0;
		for(int i=0;i<M;i++)
			for(int j=0;j<N;j++)
			{
				scanf("%d",&a[i][j]);
			}
		for(int i=0;i<M;i++)
			for(int j=0;j<N;j++)
			{
				scanf("%d",&b[i][j]);
			}
	
		int i,j;
		for(i=0;i<M;i++)
		{
			for(j=0;j<N;j++)
			{
				if((a[i][j]+b[i][j])!=0)
					break;
			}
			if(j==N)
				count++;
		}
		for(i=0;i<N;i++)
		{
			for(j=0;j<M;j++)
			{
				if((a[j][i]+b[j][i])!=0)
					break;
			}
			if(j==M)
				count++;
		}
		printf("%d\n",count);
	}
	return 0;
}