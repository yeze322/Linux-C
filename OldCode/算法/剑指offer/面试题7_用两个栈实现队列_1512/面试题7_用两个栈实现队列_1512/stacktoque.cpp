#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define N 100
typedef struct stack
{
	int a[N];
	int* top;
}stack;
stack* createstack()
{
	stack* s=new stack;
	s->top=s->a;
	return s;
}
int pop(stack* a)
{
	if(a->top==a->a)
		return -1;
	else
	{
		a->top--;
		return(*a->top);
	}
}
void push(stack* a,int data)
{
	*a->top=data;
	a->top++;
}
void destroy(stack* stk)
{
	stk->top=stk->a;
}
void pushatob(stack *stka,stack *stkb)

void readthecommand(stack* s)
{
	char c;
	int data;
	bool ifpush=false;
	while((c=getchar())!='\n'&&c!=EOF)
	{
		if(c==' ')
		{
			scanf("%d",&data);
			getchar();
			push(s,data);
			ifpush=true;
		}
	}
	if(!ifpush)
		pop(s);
}
int main()
{
	freopen("input.txt","r",stdin);
	int n;
	stack* st1=createstack();
	stack* st2=createstack();
	while(scanf("%d",&n)!=EOF)
	{
		getchar();
		for(int i=0;i<n;i++)
		{
			readthecommand(st1);
		}
		destroy(st1);
	}	
	/*while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
		{
			readthecomman();
		}
	}*/
	return 0;
}