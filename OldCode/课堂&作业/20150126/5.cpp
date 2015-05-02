#include<stdio.h>
int factorsum(int num)
{
	if(num<=1)
		return -1;
	int sum=0;
	for(int i=1;i<num;i++)
		if(num%i==0)
			sum+=i;
	return sum;
}

int main()
{
	for(int i=2;i<=3000;i++)
	{
		int pair=factorsum(i);
		if(i==factorsum(pair))
			printf("%d -- %d is a pair.\n",i,pair);
	}
	return 0;
}
