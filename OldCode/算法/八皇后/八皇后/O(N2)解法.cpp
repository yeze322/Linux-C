#include<cmath>
#include<iostream>
#include<stdio.h>
using namespace std;
#define N 5
int used_colunmn[N]={0};//记录已经占用的列
int a[N+1]={0};
int watch[N+1][N+1]={0};
int loop[N]={0};

void printqueen(int a[],int count)
{
	printf("\n%d:\n\n",count);
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<a[i];j++)
			printf("| ");
		printf("|O");
		for(int j=a[i]+1;j<=N;j++)
			printf("| ");
		printf("|");
		printf("\n");
	}
}

int main()
{
	freopen("queen.txt","w",stdout);
	//for(int i=1;i<=N;i++)\先不考虑有几层先按照5层
	int count=0;
layer1:	for(loop[1]=1;loop[1]<=N;loop[1]++)//qwert就是赋值的值,q是第一排
	{
		memset(a,0,6*sizeof(int));
		a[1]=loop[1];
layer2:	for(loop[2]=1;loop[2]<=N;loop[2]++)
		{
			if(abs(loop[2]-loop[1])<=1)
				continue;//跳出此次
			a[2]=loop[2];
layer3:		for(loop[3]=1;loop[3]<=N;loop[3]++)
			{
				if(loop[3]==loop[1]||(abs(loop[2]-loop[3])<=1))
					continue;
				a[3]=loop[3];
layer4:			for(int r=1;r<=N;r++)
				{
					if(r==loop[1]||r==loop[2]||abs(loop[3]-r)<=1)
						continue;
					a[4]=r;
layer5:				for(int t=1;t<=N;t++)
					{
						if(t==loop[1]||t==loop[2]||t==loop[3]||abs(r-t)<=1)
							continue;
						a[5]=t;
						printqueen(a,++count);
						break;
					}
				}
			}
		}
	}
	printf("total: %d",count);
}//可移植性！把他们放到一个迭代里！
//写这个程序还是很快的，开始对于如何排列一筹莫展，后来想了想不如先用最笨的办法，5层循环嵌套吧
//看来还是应该从简单的模块入手然后再添加复杂的功能。
//这种方法有一个问题就是效率，continue的语句加入使得它们有很多无意义的遍历，目前能简化的是最内层循环，但是感觉意义不大啊
void caculate_queen()
{

}
/*int main()
{
	freopen("queen.txt","w",stdout);
	//for(int i=1;i<=N;i++)\先不考虑有几层先按照5层
	for(int q=1;q<=N;q++)//qwert就是赋值的值
	{
		memset(a,0,6*sizeof(int));
		a[1]=q;
		for(loop[1]=1;loop[1]<=N;loop[1]++)
		{
			if(abs(loop[1]-q)<=1)
				continue;
			a[2]=loop[1];
			for(loop[2]=1;loop[2]<=N;loop[2]++)
			{
				if(loop[2]==q||loop[2]==loop[1]||(abs(loop[1]-loop[2])<=1))
					continue;
				a[3]=loop[2];
				for(int r=1;r<=N;r++)
				{
					if(r==q||r==loop[1]||r==loop[2]||abs(loop[2]-r)<=1)
						continue;
					a[4]=r;
					for(int t=1;t<=N;t++)
					{
						if(t==q||t==loop[1]||t==loop[2]||t==r||abs(r-t)<=1)
							continue;
						a[5]=t;
						printqueen(a,++loop[0]);
					}
				}
			}
		}
	}
	printf("total: %d",loop[0]);
}//可移植性！把他们放到一个迭代里！V1.1*/