/*第26题 请编写一个函数fun，它的功能是：
根据以下公式求x的值(要求满足精度0.0005，即某项小于0.0005时停止迭代)：
x/2=1+1/3+1×2/3×5+1×2×3/3×5×7+1×2×3×4/3×5×7×9+…+1×2×3×…×n/3×5×7×(2n+1)
程序运行后，如果输入精度0.0005，则程序输出为3.14…。*/
#include<iostream>
using namespace std;

double fun(double accu)
{
	int top=1,bottom=1,i=1;
	double one=1,x=0;

	while(one>=accu)
	{
		x=x+one;
		top*=i;
		bottom*=(2*i+1);
		one=(double)top/bottom;
		i++;
	}
	return x;
}

int main()
{
	double accu;
	cin>>accu;
	cout<<2*fun(accu);
	getchar();getchar();
}