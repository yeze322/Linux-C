#include<stdio.h>
#include<stdlib.h>
void binary_of_rotate(int *a,int begin,int end,int &min)
{
	if(begin>end)
		return;
	int p=begin,q=end;
	int flag=(begin+end)/2;
	if(a[flag]<min)
		min=a[flag];
	if(a[flag]>a[end])
		binary_of_rotate(a,flag,end,min);
	else if(a[flag]<=a[end])
		binary_of_rotate(a,begin,flag,min);
}

int stupidway(int a[],int begin,int end)
{
	int i;
	for(i=begin;i<end;i++)
	{
		if(a[i-1]>a[i])
			break;
	}
	return a[i];
}

int main()
{
	int n;
	while(scanf(" %d",&n)!=EOF)
	{
		int *a=(int *)malloc(sizeof(int)*n);
		int min=0x11111111;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		if(a[0]<a[n-1]||n==1)
		{
			printf("%d\n",a[0]);
		}
		else
		{
			printf("%d\n",stupidway(a,1,n-1));
		}
		free(a);
	}
}