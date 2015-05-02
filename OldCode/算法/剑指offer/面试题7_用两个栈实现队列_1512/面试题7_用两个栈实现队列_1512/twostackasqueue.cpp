//#define NDEBUG
#include<assert.h>
#include<stdio.h>
#include<iostream>
using namespace std;
typedef struct stack
{
	int data[100];
	int top;
}stack;
//根本没我写的好，OJ都是扯淡
stack* createstack()
{
	stack* news=new stack;
	news->top=-1;
	return news;
}
void zerostack(stack* s)
{
	s->top=-1;
}

bool ifempty(stack* stk)
{
	if(stk->top==-1)
		return 1;
	else
		return 0;
}

void push(stack *s,int num)
{
	s->top++;
	s->data[s->top]=num;
}

int pop(stack *s)
{
	if(ifempty(s))
		return -1;
	s->top--;
	return s->data[s->top+1];
}
int queuepop(stack* s1,stack* s2)
{
	if(ifempty(s2))
	{
		if(ifempty(s1))
			return -1;
		while(!ifempty(s1))
		{
			int temp=pop(s1);
			push(s2,temp);
		}
	}
	return pop(s2);
}
void readthecommand(stack* s1,stack* s2)
{
	char c;
	int data;
	getchar();
	while((c=getchar())!='\n'&&c!=EOF)
	{
		if(c==' ')//PUSH data
		{
			cin>>data;
			push(s1,data);
			return;
		}
	}
	cout<<queuepop(s1,s2)<<"\n";
}

int main()
{
	int result[1000];
	//freopen("input.txt","r",stdin);
	stack* s1=createstack();
	stack* s2=createstack();
	int n;

	while(cin>>n)
	{
		if(n==0)
			continue;
		int *p=result;
		for(int i=0;i<n;i++)
			readthecommand(s1,s2);
		zerostack(s1);zerostack(s2);
	}

	delete(s1);s1=NULL;delete(s2);s2=NULL;
	return 0;
}
