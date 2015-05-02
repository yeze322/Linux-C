#include<iostream>
#include "mystack.h"
//#include "ShareStack.h"
using namespace std;
int main()
{
	stack S2;
	int a[10]={0,1,2,3,4,5,6,7,8,9};
	Initialize(S);
	Initialize(S2);
	for(int i=0;i<10;i++)
		Push(S,a[i]);
	int temp;
	for(int i=0;i<10;i++)
	{
		Pop(S,temp);
		Push(S2,temp);
	}//两个栈实现队列功能
	for(int i=0;i<10;i++)
	{
		Pop(S2,temp);
		cout<<temp<<"=";
	}
	getchar();
}