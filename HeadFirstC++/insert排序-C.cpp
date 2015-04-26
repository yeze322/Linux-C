#include<stdio.h>
int main()
{
	int i,j,key,t;
	int A[8]={12,5,4,77,96,21,54,44};
	for(j=1;j<8;j++)
	{
		key=A[j];
		i=j-1;
		while(i>=0&&A[i]>key)
		{
			A[i+1]=A[i];
			i=i-1;
		}
		A[i+1]=key;

		/*for(t=0;t<8;t++)
		{
			printf("%d ",A[t]);
		}
		printf("\n");
		getchar();*/

	}

	for(t=0;t<8;t++)
		{
			printf("%d ",A[t]);
		}
		printf("\n");
		getchar();
	return 0;
}