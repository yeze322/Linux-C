#include<ctype.h>
#include<stdio.h>
int main()
{
	freopen("input.txt","r",stdin);
	freopen("lower.txt","w",stdout);
	char ch;
	while((ch=getchar())!=EOF)
	{
		if(isalpha(ch))
			ch=tolower(ch);
		putchar(ch);
	}

}
