#include<stdio.h>
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		printf("%lld\n",1ll<<(n));
	}
}
