/*第2题 请编写函数fun，它的功能是：
求出1到100之内能被7或者11整除，但不能同时被7和11整除的所有整数
并将他们放在a所指的数组中，通过n返回这些数的个数(!!!)。*/
#include<iostream>
using namespace std;
void fun(int *a,int *n)
{
	int j=0;
	for(int i=1;i<=100;i++)
	{
		if((i%7==0||i%11==0)&&i%77!=0)//不加括号会出事，&&的优先级要高于||、、、、、
		{
			*a++=i;
			*n=++j;
		}
	}
}

int main()
{
	int a[100]={0},N;
	int *n=&N;
	fun(a,n);
	cout<<*n<<"\n\n";
	int i=0;
	while(a[i])
	{
		cout<<a[i++]<<'\n';
	}
	getchar();
	return 0;
}