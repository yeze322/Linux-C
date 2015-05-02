#include<stdio.h>
#define N 10
int a[N][N]={0};
int count;
void fill_value_around(int line,int column)
{
	if(line>column)
		return;
	else if(line==column)
		a[line][column]=++count;
	int narrow=line;
	int line_record=line,column_record=column;
	for(;line<N-1-narrow;line++)
		a[line][column]=++count;
	for(;column>narrow;column--)
		a[line][column]=++count;
	for(;line>narrow;line--)
		a[line][column]=++count;
	for(;column<N-1-narrow;column++)
		a[line][column]=++count;
	fill_value_around(line+1,column-1);
}

int main()
{
	count=-N*N-1;//若要从里向外，改count=0，printf中间不加负号
	fill_value_around(0,N-1);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
			printf("%4d ",-a[i][j]);
		printf("\n");
	}
	getchar();
}