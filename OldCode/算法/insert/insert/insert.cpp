#include<stdio.h>
//const int N=10;

void insert(int a[],int size)
{
	int tail;//asuming that:we have a increasing array
	//tail++£¬new element -> newdata
	int newdata;
	for(tail=0;tail<size;tail++)
	{	//for i 0 to tail, find place of newdata
		newdata=a[tail];
		for(int i=0;i<tail;i++)
		{
			if(newdata<a[i])
			{
				newdata=newdata+a[i];
				a[i]=newdata-a[i];
				newdata=newdata-a[i];
			}//from place+1 to tail, move right
			a[tail]=newdata;
		}
	}//until tail == size
}
int main()
{
	int a[]={6,5,4,3,1,123,12};
	int size=sizeof(a)/sizeof(int);
	insert(a,size);
	for(int i=0;i<size;i++)
		printf("%d ",a[i]);
	getchar();
}