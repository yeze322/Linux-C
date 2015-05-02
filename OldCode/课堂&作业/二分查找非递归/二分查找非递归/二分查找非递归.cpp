#define N 14
#include<stdlib.h>

int binary_search(int a[],int size,int find)
{
	//忘记边界条件
	if(a==NULL||size<=0)
		return -1;
	int top=0 , end = size -1;
	int mid;
ag:
	if(top>end)
		return -1;
	mid=(top+end)/2;
	if(a[mid]==find)
		return mid;
	else if (a[mid]<find)
	{
		top=mid+1;
		goto ag;
	}
	else
	{
		end=mid-1;
		goto ag;
	}
}



int main()
{
	int a[N]={1,2,3,4,5,6,7,8,9,11,22,33,44,55};
	//sort a[]
	int find =binary_search(a,N,123);
	return 0;
}
