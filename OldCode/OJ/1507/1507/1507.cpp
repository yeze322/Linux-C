#include<stdio.h>
int main()
{
	int a,b,a1,b1;
	while(scanf("%d %d",&a,&b)!=EOF)
	{
		while(1)
		{
			if(a>1000000||b>1000000||a<1||b<1)
				break;
			a1=a^b;
			b1=(a&b)<<1;
			a=a1;
			b=b1;
			if(a==0||b==0)
			{
				printf("%d\n",a|b);
				break;
			}
		}
	}
}
/*题目描述：
写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
输入：
输入可能包含多个测试样例。
对于每个测试案例，输入为两个整数m和n(1<=m,n<=1000000)。
输出：
对应每个测试案例，输出m+n的值。
样例输入：
3 4
7 9
样例输出：
7
16*/