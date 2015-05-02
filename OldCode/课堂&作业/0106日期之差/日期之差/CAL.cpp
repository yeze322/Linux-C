#include<stdio.h>
#include<stdlib.h>
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

int main()
{
	int year[2],month[2],day[2];
	scanf("%d %d %d",&year[0],&month[0],&day[0]);
	scanf("%d %d %d",&year[1],&month[1],&day[1]);
	int num=0;
	int flag=0;if(year[0]>year[1]) flag=1;
	for(int i=year[flag];i<=year[1-flag];i++)
	{
		num+=uptoday(i,month[flag],day[flag]);
		month[flag]=1;day[flag]=0;
	}//计算还有几天过元旦
	num-=uptoday(year[1-flag],month[1-flag],day[1-flag]);
	if(num<0)
		num*=-1;
	printf("%d",num);
	system("pause");

}