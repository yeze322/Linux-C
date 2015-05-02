#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
#include<time.h>
#define N 10000
#define K 5
void bubbledown(int a[])
{
	int swap=0;
	int read=0,donum=0;
	for(int i=N;i>=0;i--)
	{
		for(int j=0;j<i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				//swap++;
			}
			//read+=i;
			donum++;
		}
	}//单向冒泡，考虑双向冒泡，加入区间重合判断
	printf("swap = %d read = %d donumn= %d",swap,read,donum);
}

void bubbledownup(int a[])
{
	int swap=0;
	int read=0,donum=0;
	int bottom=N,top=-1;
	while(bottom>top)
	{
		for(int j=top+1;j<bottom-1;j++)
		{
			if(a[j]>a[j+1])
			{
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				//swap++;
			}
			//read+=bottom-1;
		}
		bottom--;
		if((N-bottom)==K)
			break;
	}
	printf("swap=%d read=%d 第K大=%d",swap,read,a[bottom]);
}
void create(int a[])
{
	for(int i=0;i<N;i++)
		a[i]=rand() %1000;
}

int main()
{
	int a[N];
	create(a);
	clock_t start1=clock();
	bubbledownup(a);//可见双向的次数变少了
	clock_t end1=clock();
	printf( "\nRunning time(1) is:%f ms",(float)(end1-start1));
	//bubbledownup(a);
	return 0;
}