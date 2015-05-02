/*第3题 请编写函数void fun(int x,int pp[],int *n)它的功能是：
求出能整除x且不是偶数的各整数，并按从小到大的顺序放在pp所指的数组中
这些除数的个数通过形参n返回。*/
#include<iostream>
using namespace std;

void fun(int x,int pp[],int *n)
{
	for(int i=1;i<=x;i++)
	{
		if(x%i==0&&i%2==1)
		{
			*pp++=i;
			(*n)++;//忘写这个括号了///////////////////////////////////
		}
	}
}

void main()
{
	int x=50,pp[50]={0},t=0;
	int *n=&t;
	fun(x,pp,n);
	cout<<*n<<"\n\n";
	int i=0;
	while(pp[i])
	{
		cout<<pp[i++]<<'\n';
	}
	getchar();
}