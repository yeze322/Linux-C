/*第33题 假定输入的字符串中只包含字母和*号。
请编写函数fun，它的功能是：使字符串中尾部的*号不得多于n个；
若多于n个，则删除多于的*号；若少于或等于n个，则什么也不做，
字符串中间和前面的*号不删除。*/
#include<iostream>
#include<string>
using namespace std;

char* fun(char *old)
{
	char *p=old;
	int num=0;

	while(*p)
	{
		if(*p=='*')//=号和==真要命啊
			num++;
		p++;
	}
	//统计*个数
	if(num<=30)
		return old;//如果小于30个直接返回。
	else
	{
		p=old;
		char *dele=old;
		int count=0;

		while(*p&&count<(num-30))
		{
			*dele++=*p;
			if(*p=='*')
				count++;
			p++;
		}

		while(*p)
		{
			if(*p!='*')
				*dele++=*p;
			p++;
		}
		*dele='\0';
		return old;
	}
}

int main()
{
	char s[]="1234**************************************************5***6**7**8**9*";
	//我想用string类型做。
	cout<<fun(s);
	getchar();
}