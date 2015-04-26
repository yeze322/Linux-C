#include<iostream>
//int ADD(int m, int n);
int main()
{
	int m,n,sum;
	std::cin>>m>>n;
	sum=ADD(m,n);
	std::cout<<sum<<std::endl;
	return 0;
}
int ADD(int m, int n)
{
	int sum;
	sum=m+n;
	return sum;
}