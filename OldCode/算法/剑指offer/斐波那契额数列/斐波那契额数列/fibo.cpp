#include<stdio.h>
long long int create_fibo(int n)
{
	long long int a0=1,a1=1;
	if(n==0)
		return a0;
	else if(n==1)
		return a0;
	for(int i=1;i<n-1;i++)
	{
		long long int temp=a1;
		a1=a0+a1;
		a0=temp;
	}
	return a1;
}
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		printf("%lld\n",create_fibo(n));
	}
	return 0;
}