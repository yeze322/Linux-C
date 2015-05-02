/*空格过滤+输入流复制到输出流*/
#include<stdio.h>
#include<ctype.h>
int main()
{
	freopen("input.txt","r",stdin);
	freopen("copy.txt","w",stdout);
	char c;
	int countblank=0;int count=0;
	while((c=getchar())!=EOF)
	{
		/*if(c=='\r'||c=='\t'||c=='\n'||c==10||c==32||c==13)
			putchar('a');
		if(c==' '&&countblank==0)
		{
			putchar(c);
			countblank++;
		}
		else if(c<='z'&&c>='a')
		{
			putchar('c');
			countblank=0;
		}
		putchar(c);
		printf("%d ",c);*/
		if(c==' '&&countblank==0)
		{
			countblank++;
			putchar(' ');
			count++;
		}//去空格功能
		else if(c==' '&&countblank)
			countblank=0;
		else if(isspace(c))
			;
		else
		{
			putchar(c);
			count++;
		}
		if(count>80&&isspace(c))
		{
			putchar('\n');
			count=0;//单词结束在换行
		}//自动换行功能
	}
}
/*
		if(c==' '&&countblank==0)
		{
			putchar(c);
			countblank++;
		}
		else if(c!=' ')
		{
			putchar(c);
			countblank=0;
		}

	*/