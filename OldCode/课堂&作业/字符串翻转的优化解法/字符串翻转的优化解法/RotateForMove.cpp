#include<iostream>
#include<string>
using namespace std;

void rotate(char str[],int begin,int end)
{
	if(begin>end)
		return;
	char temp;
	char *p=str+begin;
	char *q=str+end;
	while(p<q)
	{
		temp=*q;*q=*p;*p=temp;
		p++;q--;
	}
}

int main()
{
	char str[1000];
	cin.getline(str,1000);
	int flag=0;
	while(str[flag]==' ')
		flag++;//到第一个非空格
	int i=flag;
	while(++i<strlen(str))
	{
		if(str[i]==' ')
		{
			rotate(str,flag,i-1);
			while(str[i]==' '&&i<strlen(str))
				i++;
			flag=i;
		}
	}
	rotate(str,flag,strlen(str)-1);//在末尾加次旋转
	cout<<str;
	return 0;
}