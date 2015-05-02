#include <stdio.h>
void bubble(int a[],int head,int tail)
{
	if(head>=tail)
		return;
	int i,j;
	for(j=tail;j>=head;j--)
		for(i=head;i<j;i++)
			if(a[i]>a[i+1])
			{
				a[i]=a[i]^a[i+1];
				a[j]=a[i]^a[i+1];
				a[i]=a[i]^a[i+1];
			}

}

int main()
{
	int a[]={4,5,8,943,1,3,46,46,874,645,6341,8};
	int size=sizeof(a)/sizeof(int);
	bubble(a,0,size-1);
	for(int i=0;i<size;i++)
		printf("%d ",a[i]);
	getchar();
}