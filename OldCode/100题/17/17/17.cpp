/*第17题 请编写一个函数fun(char *s)，
该函数的功能使把字符串中的内容逆置。*/
#include<iostream>
using namespace std;
void fun(char *s)
{
	char *p,*q;
	p=q=s;
	while(*q)
		q++;
	q--;
	char temp;
	//cout<<*p<<" and "<<*q;
	while(p<=q)
	{
		temp=*p;
		*p=*q;//访问冲突？
		*q=temp;
		p++;q--;
	}
}

int main()
{
	char s[]="helloworld!";
	fun(s);
	cout<<s;
	getchar();
}