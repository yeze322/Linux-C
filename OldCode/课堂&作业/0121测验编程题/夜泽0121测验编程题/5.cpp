#include<stdio.h>
#include<stdlib.h>
void sort(int *arr,int len)
{
	int p=0,q=len-1;
	int temp;
	while(p<q)
	{
		while(p<q&&arr[p]%2==1)
			p++;
		while(p<q&&arr[q]%2==0)
			q--;
		temp=arr[p];arr[p]=arr[q];arr[q]=temp;
	}

}

int main()
{
	int a[10];int circle=10;
	while(--circle)
	{
		for(int i=0;i<10;i++)
		{
			a[i]=rand()%100;
			printf("%d ",a[i]);
		}
		printf("\nÅÅÐòºó:");
		sort(a,10);
		for(int i=0;i<10;i++)
			printf("%d ",a[i]);
		putchar('\n');
	}
	return 0;
}
