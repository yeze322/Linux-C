#include<stdio.h>
#include<stdlib.h>
void bubbledown(int a[],int N)
{
	int swap=0;
	int read=0,donum=0;
	for(int i=N;i>=0;i--)
	{
		for(int j=0;j<i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
			donum++;
		}
	}
}
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int *a=(int *)malloc(sizeof(int)*n);
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		bubbledown(a,n);
		for(int i=0;i<n;i++)
		{
			printf("%d ",a[i]);
		}
		putchar('\n');
		free(a);
	}
}
