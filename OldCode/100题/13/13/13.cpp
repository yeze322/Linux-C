/*13: 第13题 请编写一个函数void fun(int tt[m][n],int pp[n])
tt指向一个m行n列的二维函数组。
求出二维函数组每列中最小元素。
并依次放入pp所指定一维数组中。
二维数组中的数已在主函数中赋予。 */

#include<iostream>
using namespace std;
const int M=4,N=3;

void fun(int tt[M][N],int pp[N])
{
	int min;
	for(int i=0;i<N;i++)
	{
		min=tt[0][i];
		for(int j=0;j<M;j++)
		{
			if(tt[j][i]<min)
				min=tt[j][i];//行和列开始写反了
		}
		pp[i]=min;
	}
}

int main()
{
	int tt[M][N]={{1,4,5},{3,7,1},{2,10,0},{9,9,9}};
	int pp[N];
	fun(tt,pp);
	for(int i=0;i<N;i++)
		cout<<pp[i]<<" ";
	getchar();
}