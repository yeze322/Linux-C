/*第24题 请编写一个函数fun，它的功能是：
将一个字符串转换为一个整数
(不得调用c语言提供的将字符串转换为整数的函数)。*/
#include<iostream>
using namespace std;
int fun(char *s)
{
	char *p=s;
	int num=0,count=1;

	if(*p=='+')//你忘了==了。。。
	{
		count=1;
		p++;
	}
	else if(*p=='-')
	{
		count=-1;
		p++;
	}

	while(*p)
	{
		if(*p<48||*p>57)
		{
			cout<<"ERROR!NOT A NUMBER!";
			getchar();
			exit(0);
		}
		num=num*10+(*p-48);
		p++;
	}
	num=num*count;
	return num;
}

int main()
{
	char s[]="-1241512363";
	int num=fun(s);
	cout<<num<<"===";
	getchar();
}