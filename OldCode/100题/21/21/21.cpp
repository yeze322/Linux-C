/*第21题 请编写函数fun,对长度为7个字符的字符串，
除首尾字符外，将其余5个字符按ascii码降序排列。*/

#include<iostream>
using namespace std;

void fun(char s[])
{
	int i=1;
	for(int j=strlen(s)-2;j>1;j--)
	{
		for(i=1;i<j;i++)
		{
			if(s[i]<s[j])
			{
				char temp;
				temp=s[i];
				s[i]=s[j];
				s[j]=temp;
			}
		}
	}
}

int main()
{
	char s[]="hacdbfqiuwyrioquyo";
	fun(s);
	cout<<s;
	getchar();
}