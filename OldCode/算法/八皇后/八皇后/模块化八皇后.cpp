#include<cmath>
#include<iostream>
#include<stdio.h>
#include<time.h>
using namespace std;
#define N 8
int used_colunmn[N]={0};//记录已经占用的列
int a[N+1]={0};
int loop[N+1]={0};

void printqueen(int a[],int count)
{
	printf("\n%d:\n\n",count);//count之前多写了一个++，这个++不会继承下去，所以表现的就是整体的标号+1了
	for(int i=1;i<=N;i++)
	{
		printf(" _");
	}
	printf("\n");
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<a[i];j++)
			printf("|_");
		printf("|O");
		for(int j=a[i]+1;j<=N;j++)
			printf("|_");
		printf("|");
		printf("\n");
	}
}
bool ifexsist(int layer)//loop[2]==q||loop[2]==loop[1]||(abs(loop[1]-loop[2])<=1)
{
	bool judge=0;//坐标（x,y）.本点（loop[layer],layer）,前面的点：（a[i],i）
	if(layer!=1&&abs(loop[layer]-a[layer-1])<=1)
		return 0;
	for(int i=1;i<layer;i++)
	{
		if(a[i]==loop[layer])//注意后边的变量是loop
			return 0;
		if(abs(loop[layer]-a[i])==abs(layer-i))//不在一条斜线上
			return 0;
		//else //这个else加的…………真是一坨屎
	}
	return 1;
}

void guess_queen(int layer)
{
	if(layer>N) return;
	for(loop[layer]=1;loop[layer]<=N;loop[layer]++)//for循环迭代,loop值被修改了！！//设计的没问题
	{		
		if(layer==1)
			memset(a,0,(N+1)*sizeof(int));
		else
		{
			if(!ifexsist(layer))
				continue;//leave
		}
		a[layer]=loop[layer];
		if(layer==N)
		{
			printqueen(a,++loop[0]);
			continue;//开始没加continue,但是影响不大
		}
		guess_queen(layer+1);
	}
}
int main()
{
	time_t start_tm = clock();
	freopen("queen.txt","w",stdout);
	printf("%d皇后问题——————\n",N);
	guess_queen(1);
	printf("\ntime = %d\n",clock()-start_tm);
}
//ifexist 犯了大错，else写的不是地方我还以为那个函数没问题
//皇后终于调试完了，加了一个对角线条件，开始还以为写错了
//这个计算的方法有缺点，不能求出排除对称的、旋转的解！
//另外算法复杂度为n^n,不知道最好的解法速度如何？