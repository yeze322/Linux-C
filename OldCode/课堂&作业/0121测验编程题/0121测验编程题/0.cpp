#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SQR(x) (x*x)
char* gg()
{
	char p[]="helloo";
	return p;
}

int main()
{
	char str[]="jass";
	char *p=gg();
	*p='a';
	//*(p+1)='\0';
	//char *q=p+1;
	//*q='\0';
	//str=gg();
	printf("%c",*p);
	return 0;
}
