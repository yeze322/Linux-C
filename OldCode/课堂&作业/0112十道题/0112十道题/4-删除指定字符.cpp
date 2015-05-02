/*删除字符串中指定的字符。例如 “abcdaefaghiagkl“ 删除‘a’,以后： “bcdefghigkl” */
#include<stdio.h>
#include<string.h>
void deletech(char str[],char ch)
{
	int done=0;
	for(int i=0;i<strlen(str);i++)
	{
		while(str[i]==ch)
			i++;
		str[done++]=str[i];
	}
	str[done]='\0';
}
int main()
{
	char str[]="hello world again";
	printf("%s\n",str);
	deletech(str,'o');
	printf("%s\n",str);
	return 0;
}
