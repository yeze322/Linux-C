#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 10
void delaftersort(int a[],int len)
{
	int new_num=0,i;
	for(i=0;i<len;)
	{
		int flag=a[i++];
		a[new_num++]=flag;
		while(i<len&&a[i]==flag)
			i++;
	}
	for(i=new_num;i<len;i++)
		a[i]=0x80000000;
	printf("after delete a[ ]={");
	for(int j=0;j<new_num;j++)
		printf("%4d,",a[j]);
	printf("}\n");
}
void quicksort(int [],int,int);
int main()
{
	int a[N]={11,2,3,4,45,5,7,5,2,11};//ÓÃ0x80000000´ú±íÉ¾³ý
	quicksort(a,0,N-1);
	delaftersort(a,N);
	return 0;
}
void quicksort(int a[],int top,int end)
{
	if(top>end)
		return;
	int flag=a[top];
	int head=top,tail=end;	
	while(head<tail)
	{
		while(head<tail&&a[tail]>=flag)
			tail--;
		a[head]=a[tail];
		while(head<tail&&a[head]<=flag)
			head++;
		a[tail]=a[head];
	}
	a[tail]=flag;
	quicksort(a,top,tail-1);
	quicksort(a,tail+1,end);
}