/*编写函数fun,功能是：
根据以下攻势计算s,计算结果作为函数值返回；
n通过形参传入。
S=1+1/(1+2)+1/(1+2+3)+…….+1/(1+2+3+4+……+n) */
#include<iostream>

float fun(int n)
{
	float S=0,P=0;
	for(int i=1;i<=n;i++)
	{
		P=P+i;
		S=S+1/P;
	}
	return S;
}

int main()
{
	int n=8;
	float t;
	t=fun(n);
	std::cout<<t;
	getchar();
}
