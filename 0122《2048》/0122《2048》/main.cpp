#include "2048.h"
int a[N][N]={0};
int main()
{	
	char ch;int c=0;
	bool (*p)();
	bool (*q)();
res:
	Reset(a);
	while(GrowOneNum())
	{
		PrintMatrix();
reinput:
		ch=getch();
		if(ch=='4'||ch=='a')
		{
			p=MoveLeft;
			q=LeftMix;
		}
		else if(ch=='6'||ch=='d')
		{
			p=MoveRight;
			q=RightMix;
		}
		else if(ch=='8'||ch=='w')
		{
			p=MoveUp;
			q=UpMix;
		}
		else if(ch=='2'||ch=='s')
		{
			p=MoveDown;
			q=DownMix;
		}
		else 
			goto reinput;
		p();q();
	}
	goto res;
}
