#include "2048.h"
extern int a[N][N];

bool MoveLeft()
{
	bool move=0;int write;
	for(int i=0;i<N;i++)//up:j 0/N | i N-1/1 =  down j 0/N | i N-1/1
	{
		write=0;
		for(int j=0;j<N;j++)//left i 0/N-1 | j 0 N-2 = right i 0/N-1 | j N-1/1；
		{
			if(a[i][j]!=0)
				a[i][write++]=a[i][j];
		}
		for(int j=write;j<N;j++)
			a[i][j]=0;
	}
	return move;//标记是否移动
}

bool MoveRight()
{
	bool move=0;int write;
	for(int i=0;i<N;i++)//up:j 0/N | i N-1/1 =  down j 0/N | i N-1/1
	{
		write=N-1;
		for(int j=N-1;j>=0;j--)//left i 0/N-1 | j 0 N-2 = right i 0/N-1 | j N-1/1；
		{
			if(a[i][j]!=0)
				a[i][write--]=a[i][j];
		}
		for(int j=write;j>=0;j--)
			a[i][j]=0;
	}
	return move;//标记是否移动
}

bool MoveUp()//!
{
	bool move=0;int write;
	for(int j=0;j<N;j++)//up:j 0/N | i N-1/1 =  down j 0/N | i N-1/1
	{
		write=0;
		for(int i=0;i<N;i++)//left i 0/N-1 | j 0 N-2 = right i 0/N-1 | j N-1/1；
		{
			if(a[i][j]!=0)
				a[write++][j]=a[i][j];
		}
		for(int i=write;i<N;i++)
			a[i][j]=0;
	}
	return move;//标记是否移动
}

bool MoveDown()
{
	bool move=0;int write;
	for(int j=0;j<N;j++)//up:j 0/N | i N-1/1 =  down j 0/N | i N-1/1
	{
		write=N-1;
		for(int i=N-1;i>=0;i--)//left i 0/N-1 | j 0 N-2 = right i 0/N-1 | j N-1/1；
		{
			if(a[i][j]!=0)
				a[write--][j]=a[i][j];
		}
		for(int i=write;i>=0;i--)
			a[i][j]=0;
	}
	return move;//标记是否移动
}