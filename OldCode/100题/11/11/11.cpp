/*11: 下列程序定义了n×n的二维数组，并在主函数中自动赋值。
请编写函数 fun(int a[n][n]),
该函数的功能是：使数组左下半三角元素中的值全部置成0。*/
const int N=3;
#include<iostream>

void fun(int a[][N])
{
	for(int i=0;i<N;i++)
		for(int j=0;j<=i;j++)
			a[i][j]=0;
}

int main()
{
	int a[][N]={{1,2,3},{4,5,6},{7,8,9}};
	fun(a);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			std::cout<<a[i][j]<<" ";
		}
		std::cout<<'\n';
	}
	getchar();
}