/*第36题 假定输入的字符串中只包含字母和*号。
请编写函数fun，它的功能是：
将字符串中的前导*号全部移到字符串的尾部。*/
#include<iostream>
using namespace std;
char* fun(char s[])
{
	char *p=s,*q=s;
	while(*q)
		q++;
	while(*p=='*')
	{
		*q++=*p++;
		s++;
	}
	*q='\0';
	return s;
}

int main()
{
	char s[]="*b**asdsa";
	cout<<fun(s);
	getchar();
}