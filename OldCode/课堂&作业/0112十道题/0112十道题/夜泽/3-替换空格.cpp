/*将 字 符 串 中 的 空 格 替 换 成 “ %020” ， 
例如“hello   world   how    ” ->”hello%020%020%020world%020%020%020how%020%020%020%020” */
#include<stdio.h>
#include<string.h>
#define MAX 999
int main()
{
	char str[MAX]="hello   world  how are yo u  ";
	printf("%s\n",str);
	int space_num=0;
	for(int i=0;i<strlen(str);i++)
	{
		if(str[i]==' ')
			space_num++;
	}
	int new_len=strlen(str)+space_num*3;
	for(int i=strlen(str);i>=0;i--)
	{
		if(str[i]==' ')
		{
			str[new_len--]='0';
			str[new_len--]='2';
			str[new_len--]='0';
			str[new_len--]='%';
		}
		else
			str[new_len--]=str[i];
	}
	printf("%s\n",str);
	return 0;
}