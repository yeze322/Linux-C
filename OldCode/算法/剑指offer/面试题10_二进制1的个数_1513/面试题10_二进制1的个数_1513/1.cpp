#include<stdio.h>
int main()
{
	int n,x;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
		{
			int count=0;
			scanf("%d",&x);
			while(x!=0)
			{
				x=x&(x-1);
				count++;
			}
			printf("%d\n",count);
		}
	}
	return 0;
}