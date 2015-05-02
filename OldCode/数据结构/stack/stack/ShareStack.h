#include "mystack.h"
#define Share 100
struct sharestack
{
	int data[Share];
	int top1;
	int top2;
}S_S;

void S_Initialize(sharestack &S)//初始化，栈顶指针不指向任何元素
{
	S.top1=-1;
	S.top2=Share;
}
bool S_StackEmpty(sharestack S)//判断栈是否为空
{
	if(S.top1==-1&&S.top2==Share)
		return true;
	else
		return false;
}
bool S_Push(sharestack &S,int a,bool choose)//将int a入栈,bool型为1则入左侧栈，为0则入右侧栈
//需要修改S，所以要用地址的形式。下同
{
	if(S.top2-S.top1==1)
		return false;
	if(choose)
		S.data[++S.top1]=a;
	else
		S.data[--S.top2]=a;
	return true;
}
bool S_Pop(sharestack &S,int &x,bool choose)
{
	if(choose)
	{
		if(S.top1==-1)
		return false;
		x=S.data[S.top1--];
		return true;
	}
	else
	{
		if(S.top2==Share)
		return false;
		x=S.data[S.top2++];
		return true;
	}
}