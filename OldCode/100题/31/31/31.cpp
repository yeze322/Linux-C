/*第31题 请编写函数fun，其功能是：
将s所指字符串中除了下标为偶数、同时ascii值也为偶数的字符外，其余的全都删除；、
串中剩余字符所形成的一个新串放在*t所指的一个数组中。*/
#include<iostream>
using namespace std;

char* fun(char oldchar[],char *t)
{
	char *p=oldchar;
	char *q=t;
	int i=0;
	while(*p)
	{
		if(oldchar[i]%2==0&&i%2==0)
		{
			*q=*p;
			q++;
		}
		p++;i++;
	}
	*q='\0';
	return t;
}//不喜欢调用函数，可以调用strlen然后用for循环

int main()
{
	char oldchar[]="hello!world!!!";
	char *t=new char;
	t=fun(oldchar,t);
	cout<<t;
	getchar();
}