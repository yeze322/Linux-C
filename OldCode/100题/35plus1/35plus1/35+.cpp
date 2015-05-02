/* 第35题 请编写一个函数，用来删除字符串中的所有空格*/
//现在我想要去重了
#include<iostream>
void dele(char *s)
{
	char *p=s,*write=s;
	while(*p)
	{
		char *q=s;
		int count=0;
		//寻找有没有重复的，有的话count=1否则为0
		while(q<p)
		{
			if(*p==*q)
			{
				count++;
				break;
			}
			q++;
		}
		
		if(count==0)
			*write++=*p;
		p++;
	}
	*write='\0';
}

int main()
{
	char s[]="hell osad s dsdas as";
	dele(s);
	std::cout<<s;
	getchar();
}