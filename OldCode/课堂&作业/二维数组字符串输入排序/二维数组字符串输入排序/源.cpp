#include<stdio.h>
#include<string.h>
#define ROW 5
#define LEN 20

int main()
{
	char st[ROW][LEN];
	char temp[LEN];
	for(int i=0;i<ROW;i++)//i是要插入的元素
	{
		gets(st[i]);
		for(int j=0;j<i;j++)//
		{
			if(strcmp(st[i],st[j])==-1)//插入位置j,st[i]>st[j]
			{
				strcpy(temp,st[i]);
				for(int k=i;k>j;k--)
				{
					strcpy(st[k],st[k-1]);
				}
				strcpy(st[j],temp);
			}
		}//insert_sort
	}//while(gets(st[i++])!=NULL&&i<ROW) { }

	return 0;
}
