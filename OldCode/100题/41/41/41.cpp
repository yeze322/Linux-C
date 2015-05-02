/*第41题 请编写函数fun，该函数的功能是：
将m行n列的二维数组中的字符数据
，按列的顺序依次放到一个字符串中。*/
#include<iostream>
using namespace std;
const int m=3,n=4;

void fun(char s[],char a[m][n])
{
	char *p = s;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			*p++=a[i][j];
	*p='\0';
}

int main()
{
	char s[m*n];
	char a[m][n]={{'a','b','c','d'},{'q','w','e','r'},{'z','x','c','v'}};
	fun(s,a);
	cout<<s;
	getchar();
}