#include<stdio.h>
bool comparebig1(int a,int b)
{
	return a>b?1:0;
}

bool comparesamll1(int a,int b)
{
	return a>b?0:1;
}

void bubble(int a[],int top,int end,bool cmpstyle)
{
	bool (*p)(int,int);
	if(cmpstyle)
		p=comparebig1;
	else
		p=comparesamll1;
	for(int i=end;i>=0;i--)
		for(int j=0;j<i;j++)
		{
			if(p(a[j],a[j+1]))
			{
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}

}

int main()
{
	int a[10]={9,8,7,6,5,4,1,2,3,0};
	bubble(a,0,9,1);
	return 0;
}
