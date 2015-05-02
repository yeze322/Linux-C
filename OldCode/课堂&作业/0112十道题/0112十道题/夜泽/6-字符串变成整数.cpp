#include<stdio.h>
#include<string.h>
#include<ctype.h>
int chartodigi(char str[])
{
	int flag=1;
	int num=0;
	int i=0;
	if(str[i]=='+')
		i++;
	else if(str[i]=='-')
	{
		flag=-1;
		i++;
	}
	for(i=0;i<strlen(str);i++)
	{
		while(!isdigit(str[i]))
			i++;
		num=num*10+str[i]-'0';
	}
	num=flag*num;
	return num;
}

int main()
{
	char s1[]="132456";
	char s2[]="0";
	char s3[]="-123";
	printf("num is : %d\ns1 = %s\n",chartodigi(s1),s1);
	printf("num is : %d\ns2 = %s\n",chartodigi(s2),s2);
	printf("num is : %d\ns3 = %s\n",chartodigi(s3),s3);
	return 0;
}
