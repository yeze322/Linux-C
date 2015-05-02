#include<stdio.h>
#define N 5
#define total 100
int main()
{
	int a[total]={0};
	int add=0;
	int human=total;
	for(int i=0;i<total;i++)
	{
		if(a[i]!=-1)
			add++;
		if(add==N)
		{
			a[i]=-1;
			human--;
			add=0;
			if(human==0)
			{
				human=i;
				break;
			}
		}
		if(i==total-1)
			i=-1;
	}
	printf("the last one:%d",human);

	return 0;
}