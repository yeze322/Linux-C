/*我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。
请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？*/
#include<stdio.h>
int count=0;

int cover_resursive(int size)
{
	if(size==0)
		return ++count;
	if(size==1)
		return ++count;
	cover_resursive(size-2);
	cover_resursive(size-1);
	return count;
}

int cover_iteration(int size)
{
	return 0;
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		long long int a=1,b=1;
		while(n-1)
		{
			a=a+b;
			b=a-b;
			n--;
		}
		printf("%lld\n",a);
	}
	return 0;
}
