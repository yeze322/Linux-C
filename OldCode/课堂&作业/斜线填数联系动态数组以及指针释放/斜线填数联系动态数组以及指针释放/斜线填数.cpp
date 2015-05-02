#include<stdio.h>
#include<stdlib.h>
#define N 5
int** createarray(int n)
{
	int ** arr=(int **)calloc(n*n,sizeof(int));
	for(int i=0;i<n;i++)
	{
		arr[i]=(int *)calloc(n,sizeof(int));
	}
	return arr;
}

void destroyarr(int ** a,int n)
{
	for(int i=0;i<n;i++)
	{
		free(a[i]);
		a[i]=NULL;
	}
	free(a);
	a=NULL;
}
void leanfill(int **a,int &count,int row,int col,int size)//towadr==1向左上 toward==-1向右下
{
	int toward=(row>col?1:-1);
	while(row>=0&&col<size&&col>=0&&row<size)
	{
		a[row][col]=(count>=0?1:-1)*++count;
		row-=toward;
		col+=toward;
	}

}

void print(int **a, int size,bool lpctr1,bool lpctr2)
{
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
			printf("%4d",a[(lpctr1?i:size-1-i)][(lpctr2?size-1-j:j)]);
		printf("\n");
	}
}

int main(int argc,char argv[])
{
	int size;bool lpctr1=0,lpctr2=0;
	while(scanf("%d",&size)!=EOF)
	{
		scanf("%d %d",&lpctr1,&lpctr2);
		int **a=createarray(size);
		int count=0,loop=0;
		while(loop<size)
		{
			leanfill(a,count,loop++,0,size);
			if(loop>=size) break;
			leanfill(a,count,0,loop++,size);
		}
		count=-size*size-1;loop=0;
		while(loop<size-1)
		{
			leanfill(a,count,size-1,size-1-loop++,size);
			if(loop>size) break;
			leanfill(a,count,size-1-loop++,size-1,size);
		}
		print(a,size,lpctr1,lpctr2);
		destroyarr(a,size);
	}
	return 0;
}
