#include<stdio.h>
#define  lie 2

int monthday[12]={0,31,28,31,30,31,30,31,31,30,31,30};
int uptoday(int year,int month,int day)
{
	int count=0;
	bool addyear=false;
	if(year%400==0||(year%4==0&&year%100!=0))
		addyear=true;
	int whole=365+addyear;
	for(int i=1;i<month;i++)
		count=count+monthday[i];
	if(month>=3)
		count+=addyear;
	count+=day;
	return whole-count;
}
int betweendata(int year_num)//,int month_num,int day_num)
{
	int year[2],month[2],day[2];
	year[0]=1900,month[0]=1,day[0]=7;
	year[1]=year_num,month[1]=1,day[1]=1;
	int num=0;
	int flag=0;if(year[0]>year[1]) flag=1;
	for(int i=year[flag];i<=year[1-flag];i++)
	{
		num+=uptoday(i,month[flag],day[flag]);
		month[flag]=1;day[flag]=0;
	}//计算还有几天下一年
	num-=uptoday(year[1-flag],month[1-flag],day[1-flag]);
	if(num<0)
		num*=-1;
	return num;
}

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