#include<stdio.h>
void print(int B[],int n)
{
	for(int i=1;i<=n;i++)
		printf("%d ",B[i]);
	printf("\n");
}

void swap(int *p,int *q)
{
	int temp;
	temp=*p;
	*p=*q;
	*q=temp;
}

void quicksort(int A[],int p,int r)
{
	if(p>r)
		return;//跳出函数这部分很关键啊。不然很容易进入死循环
	int i=p,j=r,q=p;
	while(i!=j)
	{
		while(A[j]>=A[q]&&i<j)//'=' here need to be considered carefully!
		{j--;}
		while(A[i]<=A[q]&&i<j)
		{i++;}
		if (i<j)
		{
				swap(&A[i],&A[j]);
		}
	}
	swap(&A[p],&A[i]);
	quicksort(A,p,i-1);
	quicksort(A,i+1,r);
}

void main()
{
	int A[11]={0,5,7,8,54,6,47,1,2,8,25};
	quicksort(A,1,10);
	print(A,10);
	getchar();
}