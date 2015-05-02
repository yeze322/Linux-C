#include<stdio.h>
int main()
{
	int n;
	long long int fog[71];
	while(scanf("%d",&n)!=EOF)
	{
		fog[0]=1;//a=1;
		fog[1]=1;//b=1
		for(int i=2;i<=n;i++)
			fog[i]=fog[i-1]+fog[i-2];//µü´ú*//b=a+b,a=b-a;
		printf("%lld\n",fog[n]);//printf b
	}
	return 0;//int num=shitfog(5);
}