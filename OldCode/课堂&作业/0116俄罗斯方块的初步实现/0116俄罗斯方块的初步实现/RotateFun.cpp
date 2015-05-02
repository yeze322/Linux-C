#ifndef _FUN_
#define _FUN_
#include "bricks.h"
#endif // !_FUN_
int brick[N][N][N]={
	{1,0,0,	1,0,0,	1,1,0},
	{0,0,0,	0,1,0,	1,1,1},
	{1,1,0,	1,1,0,	0,0,0}
};//L
/*int brick2[N][N]={
};//T
int brick3[N][N]={
};//¿Ú
int brick*/
//int **p[N]={(int**)brick1,(int**)brick2,(int**)brick3};
void BasicBrick(bool q,bool e,int &which)
{
	/*int brick1[N][N]={0};
	for(int i=0;i<N;i++)
		brick1[i][0]=1;
	brick1[2][1]=1;*/
	putchar('\n');
	int tct=time(NULL)%15;
	if(tct==0)
		which=rand()%3;
	for(int i=0;i<tct;i++)
		putchar('\n');
	int TI=(rand()%10);
	for(int i=(q?0:N-1);(q?i<N:i>=0);i+=(q?1:-1)){
		for(int k=0;k<TI%8;k++) putchar(' ');
		for(int j=(e?0:N-1);(e?j<N:j>=0);j+=(e?1:-1)){
			printf((q^e?brick[which][i][j]:brick[which][j][i])?"¡ö":"  ");
		}
		putchar('\n');
	}
	putchar('\n');
	return;
}