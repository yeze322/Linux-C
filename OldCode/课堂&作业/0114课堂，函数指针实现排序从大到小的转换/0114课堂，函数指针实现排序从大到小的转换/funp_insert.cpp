#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
void insert_increase(int a[],int flag,bool increase)
{
	int i=flag-1;
	while((increase?a[flag]<a[i]:a[flag]>a[i])&&i>=0)
	{
		assert(i>=0);
		i--;
	}
	i++;
	int temp=a[flag];
	for(int j=flag;j>i;j--)
		a[j]=a[j-1];
	a[i]=temp;
}

void insertsort(int *a,int len,bool increase)
{
	for(int i=1;i<len;i++)
	{
		insert_increase(a,i,increase);//here
	}
}
void print(int *a,int len,bool)
{
	for(int i=0;i<len;i++)
		printf("%d ",a[i]);
	printf("\n");
}
int* create(int len)
{
	int *a=(int *)calloc(len,sizeof(int));
	for(int i=0;i<len;i++)
	{
		a[i]=rand()%100;
	}
	return a;
}
//void exercise()
//{
//	int *pb;
//	int *pe[10];
//	int (*pf)[10];
//	int (*pg)(int);
//	int (*ph[10])(int);
//
//	int (**pi1)(int)=ph;//equal
//	int (*(*pi2)[10])(int);
//	
//	void (*p(int,void(*)(int))) (int);
//	void (*pp(void))(int);
//	void* p2(int,void(*)(int))(int);
//	void(*p3(int,void(*)(int)))(int);
//	void* (*(*a)[10])(int)();
//	void (*(*(*a1)[10])(int))();
//
//	//问题i
//	int (*parr[10])(int);//1.一个数组有十个指针。每个指针指向一个函数，每个函数返回值为int参数为int
//	int (**tothisarr)(int)=parr;//一个指针,指向上边的数组，因为是函数指针必须类型匹配
//	int (**arrfist[10])(int);//那么如何一步定义这个指针？int ***(int)
//	int (*(*arrfty)[10])(int)=arrfist;
//	int **a[10];
//	int *(*b)[10];
//
//
//		int** a[10];
//	int* (*b)[10];
//	(*b)[5]=*a[6];
//}
int** insert(int len,bool increase)
{
	int **a=new int* [10];
	for(int i=0;i<10;i++)
		a[i]=create(len);
	void (*p[2])(int*,int,bool);
	p[0]=insertsort;
	p[1]=print;
	for(int j=0;j<10;j++)
	{
		for(int i=0;i<2;i++)
		{
			p[i](a[j],len,increase);
		}
	}
	return a;
}//函数封装在一起，可减少调用的步骤。而函数指针的用处在这样的情况下并不明显

int main(int argc,char *argv[])
{
	srand(time(NULL));
	int len=rand()%30;
	int** a=insert(len,1);
	free(a);
	a=NULL;


	return 0;
}
