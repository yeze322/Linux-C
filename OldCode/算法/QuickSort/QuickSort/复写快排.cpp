#include<stdio.h>
void quick(int a[],int head,int tail)
{
	if(head>=tail)
		return;
	int flag = a[head];
	int i=head,j=tail;
	while(i<j)
	{
		while(i<j&&a[j]>=flag)
			j--;
		a[i]=a[j];
		while(i<j&&a[i]<=flag)
			i++;
		a[j]=a[i];
	}
	a[i]=flag;
	quick(a,head,i-1);
	quick(a,i+1,tail);
}
void QuickSort_Pro(int a[],int head,int tail)
{
	if(head>=tail)
		return;
	int flag=a[head];
	int i=head,j=tail;
	while(i<j)
	{
		while(i<j&&a[j]>=flag)
			j--;
		a[i]=a[j];
		while(i<j&&a[i]<=flag)
			i++;
		a[j]=a[i];
	}
	a[i]=flag;
	QuickSort_Pro(a,head,j-1);
	QuickSort_Pro(a,j+1,tail);
}
int main()
{
	int a[]={1,5,8,9,446,3213,4,56,897,312,11};
	int length=sizeof(a)/sizeof(a[0]);
	quick(a,0,length-1);
	for(int i=0;i<length;i++)
		printf("%d ",a[i]);
	getchar();
}
