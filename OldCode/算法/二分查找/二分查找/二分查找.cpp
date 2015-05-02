#include<stdio.h>
void binary_chop(int a[],int &mark,int num,int begin,int end)
{
	if(begin>end||mark!=-1)
		return;
	int p=begin,q=end;
	int flag=(begin+end)/2;
	if(a[flag]==num)
	{
		mark=flag;
		return;
	}
	else
	{
		binary_chop(a,mark,num,begin,flag-1);
		binary_chop(a,mark,num,flag+1,end);
	}
}
int main()
{
	int index_find=-1;
	int a[10]={12,5,123,231,123,213,454,3253,12,456};
	binary_chop(a,index_find,213,0,9);
	printf("%d",index_find);
	return 0;
}