/*第6题 请编写一个函数void fun(char a[],charb[],int n) 其功能是：
删除以各字符串中指定下标的字符。 
其中，a指向原字符串，
删除后的字符串存放在b所指的数组中，
n中存放指定的下标。*/
#include<string.h>
#include<iostream>
void fun(char a[],char b[],int n)
{
	int j;
	for(int i=0;i<strlen(a);i++)
		if(i!=n)
			b[j++]=a[i];
	b[j]='\0';//字符末尾是空字符！
}