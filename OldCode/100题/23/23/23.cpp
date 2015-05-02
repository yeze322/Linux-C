/* 第23题 请编写函数fun，该函数的功能是：
判断字符串是否为回文?
若是则函数返回1，主函数中输出yes，
否则返回0，主函数中输出no。
回文是指顺读和倒读都是一样的字符串。*/

#include<iostream>
using namespace std;

int fun(char *s)
{
	int value=1;
	char *p,*q;
	p=q=s;

	//while(*q) q++;
	//q--;
	while(*q++); q=q-2;

	while(p<=q)
	{
		if(*p!=*q)
		{
			value--;
			break;
		}
		p++;q--;
	}
	return value;
}

int main()
{
	char s[]="abjkhja";
	int value=fun(s);	
	cout<<(value?"YES":"NO")<<"~!!";
	getchar();
	return 0;
}