#include<cstdio>
void writeln(int x)
{
	static char buf[10];
	static int l;
	for(l=0;x;buf[l++]='0'+x%10,x/=10);
	for(!l&&(buf[l++]='0');l;putchar(buf[--l]));
	putchar('\n');
}
inline int count(int x)
{
	x=(x&0x55555555)+((x>>1)&0x55555555);
	x=(x&0x33333333)+((x>>2)&0x33333333);
	x=(x&0x0f0f0f0f)+((x>>4)&0x0f0f0f0f);
	x=(x&0x00ff00ff)+((x>>8)&0x00ff00ff);
	x=(x&0x0000ffff)+((x>>16)&0x0000ffff);//把1移动到一起
	return x;
}
int main()
{
	int t;
	scanf("%*d");
	while(scanf("%d\n",&t)==1)
		writeln(count(t));
}
/**************************************************************
Problem: 1513
User: llq6llq
Language: C++
Result: Accepted
Time:40 ms
Memory:1020 kb
****************************************************************/