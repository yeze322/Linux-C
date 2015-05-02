#include<stdio.h>
#include "minus.h"
#define  lie 2
void print_month(int firstday[],int monthday[])
{
	int count[lie]={0};
	int first[lie]={0};
	for(int i=0;i<7;i++)
	{
		for(int k=0;k<lie;k++)
		{
			for(int j=0;j<7;j++)
			{
				if(first[k]<firstday[k])
				{
					first[k]++;
					printf("    ");
				}
				else
				{
					if(count[k]<monthday[k])
						printf("%4d",++count[k]);
					else
						printf("    ");
				}
			}
			printf("         ");
		}
		printf("\n");
	}
}

int main()
{
	//freopen("1.txt","w",stdout);
	int monthday[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	char* monthname[12]={"一月","二月","三月","四月","五月","六月","七月","八月","九月","十月","十一月","十二月"};
	int firstday[12],year;
	printf("Input a year:");
	scanf("%d",&year);
	printf("%36d\n",year);
	firstday[0]=betweendata(year)%7;
	for(int i=1;i<12;i++)
	{
		firstday[i]=(firstday[i-1]+monthday[i-1]%7)%7;
	}
	for(int i=0;i<12/lie;i++)
	{
		printf("%20s%36s\n",monthname[lie*i],monthname[lie*i+1]);
		printf("  [7] [1] [2] [3] [4] [5] [6]          [7] [1] [2] [3] [4] [5] [6]\n");
		print_month(firstday+lie*i,monthday+lie*i);
		printf("\n\n");
	}
	getchar();getchar();
}//加入计算某天为星期几的功能即可
//模块化思想！！！