/*第25题 请编写一个函数fun，它的功能是：
比较两个字符串的长度，(不得调用c语言提供的求字符串长度的函数)，
函数返回较长的字符串。若两个字符串长度相同，则返回第一个字符串。*/

#include<iostream>
using namespace std;

char* fun(char a[],char b[])
{
	char *p=a,*q=b;
	while(*p&&*q)
	{
		p++;
		q++;
	}
	return (*q)?b:a;//边界条件很重要，按照条件，返回第一个字符串，所以我要安排return的顺序。
}

int main()
{
	char a[]="123a46";
	char b[]="123456";
	cout<<fun(a,b);
	getchar();
}