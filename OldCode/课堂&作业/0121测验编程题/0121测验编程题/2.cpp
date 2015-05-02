#include<stdio.h>
#include<string.h>
void reverse(char *start,char *end);
int main()
{
	char str[100];
ff:	gets(str);
	char *p=str,*q=str;
	while(1)
	{
		if(*p=='\0')
			break;
		while(*p!='\0'&&*p==' ')
			p++;
		q=p;
		while(*q!='\0'&&*q!=' ')
			q++;
		q--;
		reverse(p,q);
		p=q+1;
	}

	puts(str);
	goto ff;
	return 0;
}

void reverse(char *start,char *end)
{
	char temp;
	while(start<end)
	{
		temp=*start;
		*start=*end;
		*end=temp;
		start++;
		end--;
	}
}
