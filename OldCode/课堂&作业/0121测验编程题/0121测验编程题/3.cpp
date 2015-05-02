#include<stdio.h>

int sum1bits(int x)
{
	x=(x&0x55555555)+((x>>1)&0x55555555);
	x=(x&0x33333333)+((x>>2)&0x33333333);
	x=(x&0x0F0F0F0F)+((x>>4)&0x0F0F0F0F);
	x=(x&0x00FF00FF)+((x>>8)&0x00FF00FF);
	x=x&0xFFFF;
	return x;
}



int main()
{
	int x;
ff:	scanf("%d",&x);
	printf("Î»£º%d\n",sum1bits(x));

	goto ff;
	return 0;
}
