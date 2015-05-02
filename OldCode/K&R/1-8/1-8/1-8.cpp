/*统计空格、换行符、制表符的个数*/
#include<stdio.h>
#include<stdlib.h>
void more1()
{
	char c;
	int space,tab,enter;
	int alpha[26]={0};
	space=tab=enter=0;
	while((c=getchar())!=EOF)
	{
		if(' '==c)
			space++;
		else if('\t'==c)
			tab++;
		else if('\n'==c)
			enter++;
		else if(c>='A'&&c<='Z')
			alpha[c-'A']++;
		else if(c>='a'&&c<='z')
			alpha[c-'a']++;
	}
	printf("space %d tab %d enter %d\n",space,tab,enter);
	for(int i=0;i<26;i++)
		printf("the number of '%c' is %d\n",i+'a',alpha[i]);
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	char c;
	int space,tab,enter;
	space=tab=enter=0;
	int asc[126]={0};
	while((c=getchar())!=EOF)
	{
		if(c<=126)
			asc[c]++;
	}
	//printf("space %d tab %d enter %d\n",space,tab,enter);
	for(int i=0;i<126;i++)
		printf("the number of '%c' is %d\n",char(i),asc[i]);
}
/* 拓展。统计所有字母数*/
//拓展2，查找所有的ASCII字符。33-126为可打印ASCII码。很简单的
