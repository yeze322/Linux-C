#include<stdio.h>
#include<windows.h>
#define N 5
int a[N][N]={0};
int count;

void lean_fill(int toward,int line,int column)
{
	while(line<N&&column<N&&line>=0&&column>=0)
	{
		a[line][column]=++count;
		line=line+toward;
		column=column-toward;
	}
}
int main()
{
	count=0;
	int line=0,column=0;
	int flag=1;
	for(int i=0;i<N;)
	{
		flag=-flag;
		lean_fill(flag,i++,0);
		flag=-flag;
		lean_fill(flag,0,i++);
	}
	count=-N*N-1;
	flag=-1;
	for(int i=N-1;i>0;)
	{
		flag=-flag;
		lean_fill(flag,i--,N-1);
		flag=-flag;
		lean_fill(flag,N-1,i--);
	}
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(a[i][j]<0)
				a[i][j]*=-1;
			Sleep(100);
			printf("%4d ",a[i][j]);
		}
		printf("\n");
	}
	getchar();
}