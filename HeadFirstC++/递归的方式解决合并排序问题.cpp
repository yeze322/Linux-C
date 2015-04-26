#include<stdio.h>
#include <string.h>
# define L 16

void insert(int A[],int n)
{
	int i,j,key,t;
	for(j=1;j<n;j++)
	{
		key=A[j];
		i=j-1;
		while(i>=0&&A[i]>key)
		{
			A[i+1]=A[i];
			i=i-1;
		}
		A[i+1]=key;
	}
}

void print(int B[],int n)
{
	for(int i=0;i<n;i++)
		printf("%d ",B[i]);
	printf("\n");
}

void givevalue(int A[], int B[], int m, int n)//[m,n]
{
	int i,j=0;
	i=m-1;
	while(i<n)
	{
		B[j]=A[i];
		i++;j++;
	}
}

void merge(int A[],int p,int r)//split list[] into left[] and right[], nodes is p, q, r, then merge it.
{
	//list[L]={8,5,79,12,14,4,7,6,/* */88,17,1,17,11,21,48,65};
	int left[L],right[L];
	int q;
	q=(p+r-1)/2;
	givevalue(A,left,p,q);
	givevalue(A,right,q+1,r);
	left[q-p+1]=999;
	right[r-q]=999;
	int i=0,j=0,t=p-1;//t here puzzeled me for a long time, i wrote zero here, i made a mistake
	while(!(left[i]==999&&right[j]==999))
	{
		if (left[i]<right[j])
		{
			A[t]=left[i];
			i++;
		}
		else
		{
			A[t]=right[j];
			j++;
		}
		t++;
	}
}

void mergesort(int A[],int p,int r)
{
	int q;
	q=(p+r-1)/2;
	if(p<r)
	{
			mergesort(A,p,q);
			mergesort(A,q+1,r);
			merge(A,p,r);
			
	}
}

int main()
{
	int list[L]={8,5,79,12,14,4,7,6,/* */88,17,1,17,11,21,48,65};
	mergesort(list,1,16);
	print(list,16);
	getchar();
	return 0;
}