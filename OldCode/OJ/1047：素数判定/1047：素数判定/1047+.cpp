#include<stdio.h>
bool ifprime(int a)
{
	if(a<=1)
		return 0;
	for(int i=2;i<a;i++)
	{
		if(a%i==0)
			return 0;
	}
	return 1;
}

int main()
{
	int num;
	while((scanf("%d",&num)!=EOF))
	{
		printf(ifprime(num)?"yes\n":"no\n");
	}
}
