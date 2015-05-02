/*第38题 请编写函数fun，它的功能是：
求出ss所指字符串中指定字符的个数，并返回此值。*/
#include<iostream>
int fun(char s[],char a)
{
	char *p=s;
	int num=0;
	while(*p)
	{
		if(*p==a)
			num++;
		p++;
	}
	return num;
}

int main()
{
	char s[]="helloworld!";
	std::cout<<"input a char u want to count:";
	char a=getchar();
	std::cout<<fun(s,a);
	getchar();getchar();
}