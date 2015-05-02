/*请编写一个函数void fun(int m,int k,int xx[])
该函数的功能是：将大于整数m且紧靠m的k个质数存入xx所指的数组中*/
#include<iostream>
using namespace std;

int ifprime(int n)
{
	int t=0;
	for(int i=2;i<n;i++)
		if(n%i==0)
			t++;
	return (!t);
}//如果是质数，返回1

void fun(int m,int k,int xx[])
{
	int t=0;
	m++;
	while(t<k)//答案以m*m为界。是错误的！
	{
		if(ifprime(m))//如果是质数
		{
			//cout<<m<<"~~~";
			xx[t++]=m;
			//t++;
		}
		m++;
	}
}

int main()
{
	int m=12,k=8,xx[100]={0};
	fun(m,k,xx);

	for(int i=0;i<k;i++)
		cout<<xx[i]<<'~';
	getchar();
}