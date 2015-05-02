#include<stdio.h>
#include<stdlib.h>
int* createarray()
{
	int* HeadOfArray;
	HeadOfArray=(int*) malloc(sizeof(int)*10);//a[10]
	for(int i=0;i<10;i++)
		HeadOfArray[i]=i;
	return HeadOfArray;
}
int* createarray_new()
{
	int* arrayhead;
	arrayhead=new int[sizeof(int)*10];
	for(int i=0;i<10;i++)
		arrayhead[i]=i;
	return arrayhead;
}

int main()
{	

	for(int i=0;i<10;i++)
		printf("%d ",createarray_new()[i]);

	system("pause");
}