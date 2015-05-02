#include "box.h"
char map[M][N+1];
int man[2];
void init()
{
	strncpy(map[0],"111111110000",N);
	strncpy(map[1],"180023310000",N);
	strncpy(map[2],"100000011100",N);
	strncpy(map[3],"100020000010",N);
	strncpy(map[4],"100020010001",N);
	strncpy(map[5],"102200010110",N);
	strncpy(map[6],"190003011100",N);
	strncpy(map[7],"111111110000",N);

	man[0]=1;man[1]=1;
}//地图编辑。1-wall 2-box 3-destination 9-mushroom...

void swap(char &a,char &b)
{
	char temp=a;
	a=b;b=temp;
}
void display()
{
	putchar('\n');
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++)
		{
			if(map[i][j]=='1')//man -> 8; wall -> 1; blan -> 0; box-> 2; des-> 3; finish->4
				printf("■");
			else if(map[i][j]=='0')
				printf("  ");
			else if(map[i][j]=='8')//map=man
				printf(" M");
			else if(map[i][j]=='2')
				printf(" o");
			else if(map[i][j]=='4')
				printf(" %c",1);
			else if(map[i][j]=='9')
				printf(" %c",3);
			else if(map[i][j]=='s')
				printf(" %c",12);
			else//map=3
				printf(" X");
		}
		putchar('\n');
	}
	printf("next move?<w,a,s,d to MOVE,- to RESET>");
}
void judge();
int manwalk(char act)//加入箱子规则
{
	int a=0,b=0,reca,recb;
	switch(act)
	{
	case 'a':a=0;b=-1;break;
	case 's':a=1;b=0;break;
	case 'w':a=-1;b=0;break;
	case 'd':a=0;b=1;break;
	}//根据动作选择位移方向
	reca=a;recb=b;
	a=man[0]+a;b=man[1]+b;//要走到的地方
	if(a<M&&b<N&&a>=0&&b>=0&&map[a][b]!='1')//不超界、不碰墙//\不和目的地重合
	{
		/*if(map[a][b]=='3')
		return -1;*/
		if(map[a-reca][b-recb]=='8'||map[a-reca][b-recb]=='s')//是人//superman
		{
			if(map[a][b]=='1'&&map[a-reca][b-recb]=='s')
			{
				map[a][b]='s';
				map[a-reca][b-recb]=' ';
				man[0]=a;man[1]=b;
			}
			//superman destroy the wall!!
			if(map[a][b]=='0')
			{
				swap(map[a][b],map[a-reca][b-recb]);
				display();
				man[0]=a;man[1]=b;
				return 1;//1代表可以走 0 代表不能走 -1 代表到达终点
			}
			else if(map[a][b]=='2')//碰到箱子。
			{
				if(map[a+reca][b+recb]=='0')//下一个没有阻力
				{
					swap(map[a+reca][b+recb],map[a][b]);
					swap(map[a-reca][b-recb],map[a][b]);
					man[0]=a;man[1]=b;
				}
				else if(map[a+reca][b+recb]=='3')//到终点了
				{
					swap(map[a-reca][b-recb],map[a][b]);
					map[a-reca][b-recb]='0';
					map[a+reca][b+recb]='4';
					man[0]=a;man[1]=b;
				}
			}
			//把箱子推出终点
			else if(map[a][b]=='4')
			{
				if(map[a+reca][b+recb]=='0')//下一个没阻力
				{
					map[a+reca][b+recb]='2';
					map[a-reca][b-recb]='0';
					map[a][b]=='3';
					man[0]=a;man[1]=b;
				}
				else if(map[a+reca][b+recb]=='3')//下一个是终点
				{
					map[a-reca][b-recb]='0';
					map[a+reca][b+recb]='4';
					man[0]=a;man[1]=b;
				}
			}
			else if(map[a][b]=='3')
			{
				map[a][b]='4';
				map[a-reca][b-recb]='0';
				man[0]=a;man[1]=b;
			}
			//开个挂。。
			else if(map[a][b]='9')
			{
				map[a][b]='s';	
				map[a-reca][b-recb]='0';
				man[0]=a;man[1]=b;
			}
		}
		//人和终点重合
		else if(map[a-reca][b-recb]=='4')//
		{
			if(map[a][b]=='0')
			{
				map[a][b]='8';
				map[a-reca][b-recb]='3';
				man[0]=a;man[1]=b;
			}
			else if(map[a][b]=='2')//碰到箱子
			{
				if(map[a+reca][b+recb]=='0')//下一个没有阻力
				{
					map[a+reca][b+recb]='2';
					map[a-reca][b-recb]='3';
					map[a][b]='8';
					man[0]=a;man[1]=b;
				}//f
				else if(map[a+reca][b+recb]=='3')//到终点了
				{
					map[a-reca][b-recb]='3';
					map[a+reca][b+recb]='4';
					map[a][b]='8';
					man[0]=a;man[1]=b;
				}
			}
			else if(map[a][b]=='3')//到终点了
			{
				map[a-reca][b-recb]='3';
				map[a][b]='4';
				man[0]=a;man[1]=b;
			}
		}

	}
	else if(a<M&&b<N&&a>=0&&b>=0&&map[a][b]=='1'&&map[a-reca][b-recb]=='s')
	{
		map[a-reca][b-recb]='0';
		map[a][b]='s';
		man[0]=a;man[1]=b;
	}

	else return 0;
}