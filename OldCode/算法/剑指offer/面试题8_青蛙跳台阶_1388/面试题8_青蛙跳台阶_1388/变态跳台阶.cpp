/*变态跳台阶*/
/*一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。
求该青蛙跳上一个n级的台阶总共有多少种跳法。n<=50*/

#include<stdio.h>
#include<math.h>
int main()
{
	long long int fogshit[51];
	fogshit[0]=1;
	fogshit[1]=1;
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		/*long long int sum=0;
		for(int i=1;i<=n;i++)
		{
			sum=sum+fogshit[i-1];
			fogshit[i]=sum;
		}*/
		printf("%lld\n",pow((long long int)2,(long long int)n));
	}
	return 0;
}
				