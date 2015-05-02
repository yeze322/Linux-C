#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
char* copy(char a[])
{
	char *newc=(char *)malloc(/*strlen(a)*/sizeof(char));
	strcpy(newc,a);
	return newc;
}
void err(char a[],char b[])
{
	a=copy(a);b=copy(b);
	int *add=(int *)calloc(4,sizeof(int));//这里会触发断点
}
int main()
{
	char a[]="222222222222222222222222222222222222222222222222222";
	char b[]="111111111111111111111111111111111111111111111111111";
	
	/*char a[]="-1298749999";
	char b[]="9999999999999";*/

	err(a,b);
	return 0;
}