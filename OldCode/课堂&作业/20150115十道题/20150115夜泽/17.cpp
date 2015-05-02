/*写一个函数判断一个字符串是不是另一个字符串的子串。 */
#include<stdio.h>
#include<string.h>

bool ifstrstr(char str[],char son[])
{
	int lencmp=strlen(son);
	for(int i=0;i<strlen(str)-lencmp;i++)
	{
		if(str[i]==son[0])
		{
			for(int j=1;j<lencmp;j++)
			{
				if(str[i+j]!=son[j])
					goto jump;
			}
			return 1;
		}
		jump:;
	}
	return 0;
}

int main()
{
	char str[1000]="";
	printf("input a sentence :\n");
	gets(str);
	char find[1000]="";
	while(1)
	{
		printf("input the words you want to search:\n");
		gets(find);
		printf(ifstrstr(str,find)?"Yes\n":"No\n");
	}
	return 0;
}
