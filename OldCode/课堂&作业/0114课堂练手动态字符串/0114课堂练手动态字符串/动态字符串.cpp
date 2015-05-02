#include<stdlib.h>
#include<stdio.h>
int main()
{
	char *s=NULL;
	char c;int lenth=1;
	while((c=getchar())!=EOF)
	{
		s=(char *)realloc(s,sizeof(char)*lenth+1);
		s[lenth++-1]=c;
	}
	s[lenth]='\0';
	printf("%s",s);
	return 0;
}
