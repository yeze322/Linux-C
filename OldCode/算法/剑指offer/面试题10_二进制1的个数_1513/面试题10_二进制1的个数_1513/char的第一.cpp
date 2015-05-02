#include <cstdio>
inline int bitcount(unsigned int n)
{
	unsigned int tmp;
	tmp = n - ((n >> 1) & 0xDB6DB6DB)-((n >> 2) & 0x49249249);
	tmp = (tmp + (tmp >> 3)) & 0xC71C71C7;
	return tmp%63;
}

inline void In(int& res)
{
	int f=1,c;
	while(((c = getchar())<'0' || c>'9') && c!='-');
	c=='-' ? f=res=0 : res=c-'0';
	while((c = getchar())>='0' && c<='9')
		res = res*10 + c-'0';
	if(!f)   res=-res;
}
inline void writeln(int x)
{
	static char buf[10];
	static int l;
	for(l=0;x;buf[l++]='0'+x%10,x/=10);
	for(!l&&(buf[l++]='0');l;putchar(buf[--l]));
	putchar('\n');
}
int main(){

	int T , n;
	scanf("%d", &T);
	while(T--){
		In(n);
		writeln(bitcount(n));
	}
	return 0;
}