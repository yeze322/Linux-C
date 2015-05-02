#include<stdio.h>
#include<stdlib.h>
void cross_easy(int a[],int a_n,int b[],int b_n)
{
	for(int i=0;i<a_n;i++)
	{//flag = a[i]
		for (int j=0;j<b_n;j++)
		{
			if(a[i]==b[j])
			{
				printf("%d ",a[i]);
				b[j]=-1;
				break;
			}
		}//如果，各有两个重复的，就错了.所以我要把b[used]= -1
		//but cannot use it again,but i needn't to use it again
	}
}//another better methosd is sort them first,then do the cross
void quicksort(int a[],int top, int end)
{
	if(top>end)
		return;
	int flag=a[top];
	int i=top,j=end;
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
	quicksort(a,top,i-1);
	quicksort(a,i+1,end);
}
int* cross_aftersort(int a[],int a_n,int b[],int b_n,int *p)
{
	int* index_p=p;
	int flag;
	int index_a=0,index_b=0;
	a[0]<b[0]?flag=a[index_a]:flag=b[index_b];
	while(index_a<a_n&&index_b<b_n)
	{
		while(index_a<a_n&&a[index_a]<flag)//搜索a
			index_a++;
		if(a[index_a]==b[index_b])
		{
			*index_p++=b[index_b];
			index_b++;
			index_a++;
		}	
		flag=a[index_a];
		while(index_b<b_n&&b[index_b]<flag)//搜索b
			index_b++;
		if(b[index_b]==a[index_a])
		{
			*index_p++=a[index_a];
			index_a++;
			index_b++;
		}
		flag=b[index_b];
	}
	return p;
}
int main()
{
	int a[10]={654,32,13,13,64,321,64,31,41,2};
	int b[10]={45,5,32,13,13,6432,164,321,23,1};
	int * cross_array=(int *)malloc(sizeof(int)*(sizeof(a)<sizeof(b)?sizeof(a)-1:sizeof(b)-1));
	quicksort(a,0,sizeof(a)/sizeof(int)-1);
	quicksort(b,0,sizeof(b)/sizeof(int)-1);
	cross_aftersort(a,sizeof(a)/sizeof(int)-1,b,sizeof(b)/sizeof(int)-1,cross_array);

	return 0;
}