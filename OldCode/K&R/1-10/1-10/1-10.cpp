/*制表符打出\r\n,/打出来*/
#include<stdio.h>
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	char c;
	while ((c=getchar())!=EOF)
	{
		if('\t'==c)
			printf("\\t");
		if('\n'==c)
			printf("\\n");
		if('\\'==c)
			printf("\\\\");
		putchar(c);
	}
}
