/*第91题 请编写函数fun，其功能是：
将两个两位数的正整数a b合并形成一个整数放在c中。
合并的方式是：
将a数的十位和个位数依次放在c的十位和千位上，
b数的十位和个位数依次放在c数的个位和百位上。*/
#include<iostream>
int fun(int a,int b,int c)
{
	int a1,a2,b1,b2;
	a1=a-a/10*10;
	a2=a/10;
	b1=b-b/10*10;
	b2=b/10;
	c=a1*1000+a2*10+b1*100+b2;
	return c;
}

int main()
{
	int a,b,c=0;//在这里c,不初始化那么会形成空指针！
	a=12,b=34;
	c=fun(a,b,c);
	std::cout<<c;
	getchar();
}
/*指针版本！，因为C需要赋值才能被函数调用。
int* fun(int a,int b,int *c)
{
	int a1,a2,b1,b2;
	a1=a-a/10*10;
	a2=a/10;
	b1=b-b/10*10;
	b2=b/10;
	*c=a1*1000+a2*10+b1*100+b2;
	return c;
}

int main()
{
	int a,b,c;
	a=12,b=34;
	c=*fun(a,b,&c);
	std::cout<<c;
	getchar();
}
*/