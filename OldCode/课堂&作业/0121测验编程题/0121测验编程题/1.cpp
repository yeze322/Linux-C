#include<stdio.h>

int main()
{
	long long int num;
	int single;
ag:	int single_sum=0;
	fflush(stdin);
	scanf("%lld",&num);
	while(num)
	{
		single=num%10;
		printf("%d\n",single);
		single_sum+=single;
		num=num/10;
	}
	printf("%d\n",single_sum);
	goto ag;
	return 0;
}
