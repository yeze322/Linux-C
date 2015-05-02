/*第44题 编写一个函数，该函数可以
统计一个长度为2的字符串在另一个字符串中出现的次数。*/
#include<iostream>
int fun(char s[],char a[2])
{
	char *p=s;
	int count=0;
	while(*p)
	{
		if(*p==a[0]&&*(p+1)==a[1])
			count++;
		p++;
	}
	return count;
}

int main()
{
	char s[]="hjhgdgffhfbdxghfdthyrds";
	char a[]="hg";
	std::cout<<fun(s,a);
	getchar();
}