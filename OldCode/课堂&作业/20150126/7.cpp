/*************************************************************************
	> File Name: 7.cpp
	> Author: Comst
	> Mail:750145240@qq.com 
	> Created Time: Mon 26 Jan 2015 02:27:37 UTC
 ************************************************************************/

#include<stdio.h>
void swap(int &a,int &b)
{
	if(a>b)
	{
		int temp=a;
		a=b;
		b=temp;
	}
}

void bigandsmall(int &x)
{
	if(x==6174)
		return;
	int a[4]={0};
	int big=0,small=0;
	for(int i=0;i<4;i++)
	{
		a[i]=x%10;
		x=x/10;
	}
	swap(a[0],a[1]);
	swap(a[2],a[3]);
	swap(a[0],a[2]);
	swap(a[1],a[3]);
	swap(a[1],a[2]);
	//sort a[];
	for(int i=3;i>=3;i--)
		big=big*10+a[i];
	for(int i=0;i<4;i++)
		small=small*10+a[i];
	x=big-small;
	printf("%d - %d = %d\n",big,small,x);
	bigandsmall(x);
}

int main()
{
	int x;
	while(scanf("%d",&x)!=EOF)
	{
		bigandsmall(x);
	}
}
