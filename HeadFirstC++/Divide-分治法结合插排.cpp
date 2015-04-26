#include<stdio.h>
#include <string.h>

#define L 10

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

void divide(int list[],int left[], int right[])
{
	int i=0,j=0,t=0;
	while(!(left[i]==999&&right[j]==999))
	{
		if (left[i]<right[j])
		{
			list[t]=left[i];
			i++;
		}
		else
		{
			list[t]=right[j];
			j++;
		}
		t++;
	}
}

int main()
{
	int list[L];
	int left[6]={8,5,79,12,1,999};
	int right[6]={4,7,6,88,17,999};
	insert(left,6);
	insert(right,6);
		print(left,6);
		print(right,6);

		divide(list,left,right);

		print(list,10);
		getchar();
		return 0;
}