/*将字符行内单字之间的空白符（空格、水平制表符（tab 键），
1 tab 键 = 8 个空格）平均 分配插入到单词之间*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void cutword(char str[],char newstr[])
{
	int BlankNum=0;
	int WordNum=0,i=0;
	while(1)
	{
		while(str[i]==' '||str[i]=='\t')
		{
			if(str[i]=='\t')
				BlankNum+=7;
			BlankNum++;
			i++;
		}
		if(str[i]!='\0')
			WordNum++;
		else break;
		while(str[i]!=' '&&str[i]!='\t'&&str[i]!='\0')
			i++;
		if(str[i]=='\0')
			break;
	}//统计空格数和字段数。
	//printf("word: %d\nblanK:%d\n",WordNum,BlankNum);
	int AverBlank=BlankNum/(WordNum-1);
	char *p=str,*head=str;
	char temp[100];
	while (true)
	{
		while(*p==' '||*p=='\t')
			p++;//到字母的头字符
		if(*p=='\0')
			break;
		while(*p!=' '&&*p!='\t'&&*p!='\0')
		{
			strncat(newstr,p,1);
			p++;
		}
		if(*p=='\0')
			break;
		if(--WordNum)
			for(int i=0;i<AverBlank;i++)
				strncat(newstr," ",1);
	}
}

int main()
{
	char str[1100]="";
	char newstr[1100]="";
	printf("input a character line:\n");
	gets(str);
	cutword(str,newstr);
	printf("after change:\n%s",newstr);
	return 0;
}
