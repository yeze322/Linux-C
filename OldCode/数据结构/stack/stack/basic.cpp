#include<iostream>
using namespace std;
//#include<stack>
int a[10]={0};
int c=8;
int &b=c;
struct stack{
	int data[10];
}s;
void use_quote(stack &s)
{
	s.data[0]=2;
}
void use_direct(int a[])
{
	a[1]=4;
}
void use_point(stack *s)
{
	s->data[2]=6;
}


int main()
{
	use_quote(s);
	//use_direct(s);
	use_point(&s);
	cout<<s.data[0]<<"==="<<s.data[1]<<"==="<<c;
	getchar();
}