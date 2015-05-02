/*第16题 请编写一个函数float fun(double h),
函数的功能使对变量h中的值保留2位小树，
并对第三位进行四舍五入(规定h中的值位正数)。*/
#include<iostream>
using namespace std;
float fun(double h)
{
	/*int last;
	last=int(10*(h*100-int(h*100)));
	if(last<5)
		h=int(100*h)/100.0;
	else
		h=(int(100*h)+1)/100.0;*/

	h=int((h*1000+5)/10)/100.0;

	return h;
}

int main()
{
	double h=1.2395;
	h=fun(h);
	cout<<h<<"~~~";
	getchar();
}