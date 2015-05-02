/*第19题 编写函数fun,该函数的功能是：
从字符中删除指定的字符，同一字母的大、小写按不同字符处理。*/
#include<iostream>
using namespace std;
void fun(char s[],char c)
{
	int i=0;
	char *p=s;//尝试过直接用s指针，事实证明不行，因为s指针变化的话，s[i]就会移位！
	while(*p)
	{
		if((*p)!=c)
			s[i++]=*p;
		p++;
	}
	s[i]='\0';
}

int main()
{
	char s[]="helloworld!";
	fun(s,'l');
	cout<<s;
	getchar();
}