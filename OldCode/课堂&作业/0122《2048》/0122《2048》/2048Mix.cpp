#include "2048.h"
extern int a[N][N];

void PrintMatrix()
{
	system("cls");
	printf("\n\n\n			----------1024--------\n");
	printf("\n\n\n			======================\n");
	for(int i=0;i<N;i++)
	{
		printf("			忰");
		for(int j=0;j<N;j++)
			a[i][j]?printf("%3d忰",a[i][j]):printf("   忰");//:printf("     ");
		printf("\n			！！！！！！！！！！！\n");
	}
	printf("\n				！！！by 匚夾\n");
	//printf("\n		======================\n");
}

bool  GrowOneNum()
{
	srand(time(NULL));
	int *position[16]={0};
	int count=0;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			if(a[i][j]==0)
				position[count++]=&a[i][j];
	if(count==0)
	{
		system("cls");
		printf("\n\n		Gameover!");
		system("pause");
		_sleep(1000);
		return 0;
	}
	int fill=rand()%count;
	*position[fill]=2;
	return 1;
}

void Reset(int arr[][N])
{
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			arr[i][j]=0;
	GrowOneNum();
}


bool LeftMix()
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N-1;j++)
		{
			if(a[i][j]==a[i][j+1])
			{
				a[i][j]=a[i][j]*2;
				a[i][j+1]=0;
			}
		}
	}
	MoveLeft();
	return 0;
}

bool RightMix()
{
	for(int i=0;i<N;i++)
	{
		for(int j=N-1;j>0;j--)
		{
			if(a[i][j]==a[i][j-1])
			{
				a[i][j]=a[i][j]*2;
				a[i][j-1]=0;
			}
		}
	}
	MoveRight();
	return 0;
}
bool UpMix()
{
	for(int j=0;j<N;j++)
	{
		for(int i=N-1;i>0;i--)
		{
			if(a[i][j]==a[i-1][j])
			{
				a[i][j]=a[i][j]*2;
				a[i-1][j]=0;
			}
		}
	}
	MoveUp();
	return 0;
}
bool DownMix()
{
	for(int j=0;j<N;j++)
	{
		for(int i=0;i<N-1;i++)
		{
			if(a[i][j]==a[i+1][j])
			{
				a[i][j]=a[i][j]*2;
				a[i+1][j]=0;
			}
		}
	}
	MoveDown();
	return 0;
}