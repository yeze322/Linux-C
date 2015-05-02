#include<stdio.h>
#include<string.h>
#define N 1000
int main()
{
	char str[N];
	char *p=str;
	int count=0;
	char ch;
	while((ch=getchar())!='\n')
	{
		if(ch==' ')
			count++;
		*p++=ch;
	}
	*p='\0';
	int length=strlen(str)+count*2;//并非是这个原因。这句考虑了从0开始计数。、、忘记加‘ 、0’的空间导致越界
	for(int i=length;i>=0;i--)//i的方向也反了
	{
		if(*p!=' ')
		{
			str[i]=*p;
			p--;
		}
		else if(*p==' ')
		{
			str[i]='0';
			str[--i]='2';
			str[--i]='%';
			p--;
		}
	}
	printf("%s",str);
	getchar();
}