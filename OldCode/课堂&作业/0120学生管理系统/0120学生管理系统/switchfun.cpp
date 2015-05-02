#include "_SIMS.h"
void fun1(int a,int b)
{
	printf("%d",a+b);
}

void fun2(int a,int b)
{
	printf("^^^^^^^^^^^^^^^");
}


void* dowswitch(char choose)
{
	void (*p)(int ,int);
	void (*q)(int ,int);
	p=fun1;
	q=fun2;

	switch (choose)
	{
	case 'a':return p;
	case 'b':return q;
	default:return NULL;
	}
}