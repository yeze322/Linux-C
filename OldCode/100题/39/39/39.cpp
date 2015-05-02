/* 第39题 请编写函数fun，该函数的功能是：
移动一维数组中的内容，若数组中有n个整数，
要求把下标从0到p(p小于等于n－1)的数组元素平移到数组的最后。*/
#include<iostream>
using namespace std;
const int n=10;
void move(int a[],int n,int p)
{
	for(int i=0;i<=p;i++)//开始写的是while（*p），但是遇到了*p=0的时候，自动结束循环。这是一个值得注意的问题 
		*(a+n+i)=a[i];
	for(int i=0;i<n;i++)
		a[i]=a[i+p+1];//*newhead++;
}

int main()
{
	int a[n]={1,2,3,4,5,6,7,8,9};
	int p=3;
	move(a,n,p);
	for(int i=0;i<n;i++)
		cout<<a[i]<<'~';
	getchar();
}