#include <stdio.h>
inline void printx(int x)
{
	x = (x&0x55555555) + ((x>>1)&0x55555555); 
	x = (x&0x33333333) + ((x>>2)&0x33333333); 
	x = (x&0x0f0f0f0f) + ((x>>4)&0x0f0f0f0f); 
	x = (x&0x00ff00ff) + ((x>>8)&0x00ff00ff); 
	x = (x&0x0000ffff) + ((x>>16)&0x0000ffff);
	if(x/10)
		putchar('0'+x/10);
	putchar(x%10+'0');putchar('\n');
}
int main()
{
	int n,x,i;
	scanf("%d\n",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		printx(x);
	}
}
