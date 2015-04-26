#include<stdio.h>
void swap(int *m,int *n)
{
	int temp;
	temp=*m;*m=*n;*n=temp;//point here is important.
}

void bubble(int A[],int n)
{
	int temp;
	for(int i=0;i<n;i++)
		for(int j=n-1;j>i;j--)
		{
				if (A[j]<A[j-1])
				{
					swap(&A[j],&A[j-1]);//& here is necessary
		/*			temp=A[j];A[j]=A[j-1];A[j-1]=temp;*/
				}
		}
}

void print(int B[],int n)
{
	for(int i=0;i<n;i++)
		printf("%d ",B[i]);
	printf("\n");
}

void main()
{
	int A[8]={8,2,3,1,7,9,6,4};
	bubble(A,8);
	print(A,8);
	getchar();
}