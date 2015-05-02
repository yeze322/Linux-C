/*第15题 请编写一个函数unsigned fun(unsigned w)
w是一个大于10的无符号整数，
若w是n(n≥2)位的整数，则函数求出w后n－1位的数作为函数值返回。*/
#include<iostream>
#include<stdio.h>
using namespace std;

unsigned fun(unsigned w)
{
	if(w<10)
	{
		cout<<"ERROR!";
		return -1;
	}
	char a[64],b[64];
	itoa(w,a,10);//两种方式都可以！10表示的是十进制
	//sprintf(a,"%d",w);//sprintf函数！~！
	//itoa是只把整数转换成字符串, sprintf是按照指定格式输出一段目的字符串，明显sprintf功能更多..
	int i=0;
	while(a[i])1
	{
		b[i]=a[i+1];
		i++;
	}
	w=atoi(b);//atoi函数！！~！！
	return(w);
}

int main()
{
	unsigned w=815123;
	w=fun(w);
	cout<<w;
	getchar();
}