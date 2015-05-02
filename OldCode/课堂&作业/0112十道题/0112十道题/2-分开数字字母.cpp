/* 将包含字符数字的字符串分开,使得分开后的字符串前一部分是数字后一部分是字母。
例 如“h1ell2o3” ->”123hello” */
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAX 100
void num_alpha(char str[])
{
	char alpha[MAX];
	char digit[MAX];
	char *alp=alpha;
	char *digi=digit;
	for(int i=0;i<strlen(str);i++)
	{
		if(isalpha(str[i])||isdigit(str[i]))
			isalpha(str[i])?*alp++=str[i]:*digi++=str[i];
	}
	*alp='\0';*digi='\0';
	strcpy(str,digit);
	strcat(str,alpha);
}
int main()
{
	char str[MAX]="h1ell2o3sdaas12341";//b把非字母、数字过滤了
	printf("%s\n",str);
	num_alpha(str);
	printf("%s\n",str);
	return 0;
}
