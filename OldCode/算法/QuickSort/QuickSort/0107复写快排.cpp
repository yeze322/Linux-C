#include<stdio.h>
void quicksort(int a[],int top,int end)
{
	if(top>end)
		return;
	//等于的情况，是没有必要的，后边也会跳出
	int flag=a[top];
	int head=top,tail=end;	
	while(head<tail)
	{
		while(a[tail]>=flag&&head<tail)
			tail--;
		a[head]=a[tail];
		while(a[head]<=flag&&head<tail)
			head++;
		a[tail]=a[head];
	}
	a[tail]=flag;
	quicksort(a,top,tail-1);
	quicksort(a,tail+1,end);
}
int main()
{
	int a[10]={7,243,54,1,0,323,12,546,879,123};
	quicksort(a,0,9);
	getchar();
}//本次问题：循环结构基本对，但是错误的加入了一个head<=tail的等于号，边界条件没有考虑好啊。
//试想，head==tail,会发生什么？对，while语句一直运行！
//同样的，在内层while循环里，也不能加等号，因为相等后，会再次移位，整个过程会错位！
