/*18. 观察如下序列，找规律，找出下一个数字是多少：
(用程序实现)。 1, 11, 21 , 1211, 111221, 312211, */

/*1 
11--- 表示前一个数“1”是 1 个 1； 
21--- 表示前一个数“11”是 由 2 个 1 组成； 
1211--- 表示前一个数“21”是 由 1 个 2、1 个 1 组成； 
111221--- 即 11 12 21 ，表示前一个数“1211”是依次由 1 个 1，1 个 2， 
2 个 1组成； 
312211---即 31 22 11，表示前一个数“111221”是依次由 3 个 1，2 个 2， 
1 个 1 组成；*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* countit(char *str)
{
	char ch[2]="";
	char number[20]="";
	char* newchar=(char *)calloc(100,sizeof(char));
	for(int i=0;i<strlen(str);)
	{
		ch[0]=str[i];
		int count=0;
		while(str[i]==ch[0])
		{
			count++;i++;
		}
		strncat(newchar,itoa(count,number,10),1);//粘贴由几个组成
		strncat(newchar,ch,1);//粘贴组成的数字
		if(str[i]=='\0')
			break;
	}	
	printf("\nnext result is:\n%s",newchar);
	//free(str);
	return newchar;
}


int main()
{
	char str[1000]="1";
	char c;
	char* reload=str;
	for(int i=0;i<10;i++)
		reload=countit(reload);
	return 0;
}
