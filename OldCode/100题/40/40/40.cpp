/*第40题 请编写函数fun，该函数的功能是
移动字符串中内容，移动的规则如下：
把第1到第m个字符，平移到字符串的最后，
把第m＋1到最后的字符移到字符串的前部。*/

#include<iostream>
using namespace std;

void move(char a[],int m)
{
	int n=strlen(a);

	for(int i=0;i<m;i++)//开始写的是while（*p），但是遇到了*p=0的时候，自动结束循环。这是一个值得注意的问题 
		*(a+n+i)=a[i];
	for(int i=0;i<n;i++)
		a[i]=a[i+m];//*newhead++;

	a[n/*strlen(a)//这时候strlen(a)改变了！所以不能再用这个最好用n*/]='\0';

}

int main()
{
	char a[]="123456789/*-";
	int m=5;
	move(a,m);
	for(int i=0;i<strlen(a);i++);
		cout<<a;
	getchar();
}