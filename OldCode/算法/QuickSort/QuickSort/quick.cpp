#include<iostream>
using namespace std;
void QuickSort(int a[],int head,int tail)
{
	if(head>=tail)
		return;
	int flag=a[head];
	int i=head,j=tail;//two pointer,i and j,
	//use a[head] as a temp container, swich it and number
	while(i<j)
	{
		while(i<j)//j-- until a[j] < flag swap
		{
			if(a[j]<flag)
			{
				a[i]=a[j];//
				/*a[j]=a[j]^a[i];
				a[i]=a[j]^a[i];
				a[j]=a[j]^a[i];*/
				break;
			}
			j--;
		}
		while(i<j)
		{
			if(a[i]>flag)
			{
				a[j]=a[i];//
				/*a[i]=a[i]^a[j];
				a[j]=a[i]^a[j];
				a[i]=a[i]^a[j];*/
				break;
			}
			i++;

		}	//i++ until a[i]>flag; swap
	}//remember to judge : if i>j	//when j in front of i, stop
	//repeat and recurse
	a[i]=flag;//
	QuickSort(a,head,j-1);
	QuickSort(a,j+1,tail);
}
void QuickSort_Pro(int a[],int head,int tail)
{
	if(head>=tail)
		return;
	int flag=a[head];
	int i=head,j=tail;//two pointer,i and j,
	//use a[head] as a temp container, swich it and number
	while(i<j)
	{
		while(i<j&&a[j]>=flag)//j-- until a[j] < flag swap
			j--;
		a[i]=a[j];
		while(i<j&&a[i]<=flag)
			i++;
		a[j]=a[i];//i++ until a[i]>flag; swap
	}//remember to judge : if i>j	//when j in front of i, stop
	//repeat and recurse
	a[i]=flag;
	QuickSort_Pro(a,head,j-1);
	QuickSort_Pro(a,j+1,tail);
}//这个的改动就是把if内嵌了，代码更加简洁
int main()
{
	int a[8]={4,9,5,2,7,3,6,8};
	QuickSort_Pro(a,0,7);
	for(int i=0;i<8;i++)
		cout<<a[i]<<" ";
	getchar();
}
//总结一下，出错的地方是边界条件，还有j+1写成了j++这样的问题。
//对比之后发现有一个没必要的操作，就是三个异或的地方。同时while内嵌入if不如先if再while的效率高。明显感觉内层两个while没啥用。