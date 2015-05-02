#include<string.h>
#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	char ch;
	char str[10000];
	while(cin>>str>>ch)
	{
		for(int i=0;i<strlen(str);i++)
		{
			if(str[i]!=ch)
				putchar(str[i]);
		}
		putchar('\n');
	}
}
