#include "arrcreate.h"
/*#define CRTDBG_MAP_ALLOC
#include <crtdbg.h>*/
#ifdef _DEBUG
#define DEBUG_CLIENTBLOCK new( _CLIENT_BLOCK, __FILE__, __LINE__)
#else
#define DEBUG_CLIENTBLOCK
#endif
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#ifdef _DEBUG
#define new DEBUG_CLIENTBLOCK
#endif

int findtwo(int *a,int len)
{
	if(a==NULL||len<=1)
		return -1;
	int big,small;
	int i=0;
	if(a[0]!=a[1])
	{
		big=a[0]>a[1]?a[0]:a[1];
		small=a[0]>a[1]?a[1]:a[0];
	}
	else
	{
		int i=2;
		while(a[i]==a[0])
			i++;
		big=a[0]>a[i]?a[0]:a[i];
		small=a[0]>a[i]?a[i]:a[0];
	}
	for(i;i<len;i++)
	{
		if(a[i]!=big&&(a[i]>small||a[i]>big))
		{
			if(a[i]>small&&a[i]>big)
			{
				small=big;
				big=a[i];
			}
			else
				small=a[i];
		}
	}
	return small;
}//重复元素计算在内

int findtwonorepeat(int *a,int len)
{
	int *p=new int;
	*p=10;
	if(a==NULL||len<=1)
		return -1;
	int big,small;
	big=a[0]>a[1]?a[0]:a[1];
	small=a[0]>a[1]?a[1]:a[0];
	for(int i=0;i<len;i++)
	{
		if(a[i]>small||a[i]>big)
		{
			if(a[i]>small&&a[i]>big)
			{
				small=big;
				big=a[i];
			}
			else
				small=a[i];
		}
	}
	delete(p);
	return small;
}//重复元素都会排序

int* maxk(int *a,int size,int k)
{
	if(k>size)
		return NULL;
	int *topk=(int *)calloc(k,sizeof(int));
	for(int i=0;i<k;i++)
		topk[i]=a[i];

	return topk;
}
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF|_CRTDBG_LEAK_CHECK_DF);
	int a[15];
	fill(a,15);
	int find = findtwonorepeat(a,15);

	return 0;
}
