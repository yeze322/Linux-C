/*一只青蛙一次可以跳上1级台阶，也可以跳上2级。
求该青蛙跳上一个n级的台阶总共有多少种跳法*/
#include<stdio.h>
#define N 50
int count=0;

void jumponly(int rest)
{
	if(rest==0)
	{
		count++;
		return;
	}
	else if(rest==1)
	{
		count++;
		return;
	}
	jumponly(rest-1);
	jumponly(rest-2);
}
int shitfog(int rest)
{
	if(rest==0)
		return 1;
	else if(rest==1)
		return 1;
	int method;
	method=shitfog(rest-1)+shitfog(rest-2);
	return method;
}


int main()
{
	/*int fog[N+1],i;
	fog[0]=1;
	fog[1]=1;
	for(int i=2;i<=N;i++)
		fog[i]=fog[i-1]+fog[i-2];//迭代*/
	//int num=shitfog(5);
	jumponly(15);
	return 0;
}
//没想到是因为N的取值太大了导致运算不来
//还好我的程序、递归迭代是没问题的
