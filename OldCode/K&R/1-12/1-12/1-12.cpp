/*每行一个单词*/
#include<stdio.h>
#include<ctype.h>
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	char c;
	int count=0;
	while ((c=getchar())!=EOF)
	{
		if(c!='\n')
			continue;
		c=getchar();
		if(!isspace(c))
		putchar(c);
	}
	
	
	/*{
		if(c==' '&&count==0)
			putchar('\n');
		else if(c!=' ')
		{
			putchar(c);
			count=0;
		}
	}*/
}