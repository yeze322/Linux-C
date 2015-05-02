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

stack* createstack()
{
	stack* news=new stack;
	news->top=-1;
	return news;
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
	assert(s->top<100);
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
	int temp=pop(s1);
	push(s2,temp);
}
void printresult(stack *s)
{
	while(!ifempty(s))
		printf("%d\n",pop(s));
}

int main()
{
	freopen("input.txt","r",stdin);
	stack* s1=createstack();
	stack* s2=createstack();
	int n;
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
			readthecommand(s1,s2);
		printresult(s2);
	}
	delete(s1);s1=NULL;delete(s2);s2=NULL;
	return 0;
}
