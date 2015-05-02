#include<stdio.h>
#include<string.h>
void str(char source[],char newc[],char mother[],char search[])
{
	strcpy(newc,source);
	strcat(source,newc);//stick in the tail
	strlen(source);
	strcmp(source,newc);
	strstr(mother,search);
	fgets(newc,1024,stdin);
	gets(mother);//Ò»ÐÐ
}
void record1()
{
	char bigguy[]="hello world and don not make me sad";
	char add[]="whiuhrld";
	char find[]="worfld";
	char whole[10];
	char* s=strcat(find,add);
	//int cmp_bg=strcmp("zbcd","efgh");
	//int cmp_sm=strcmp("bcdddd","efgh");//strcmp[("ef","efgh")
	//int cmp_eq=strcmp("efgh","efgh");
	strcpy(whole,bigguy);
	int val=0x01020304;
	char buf[10];
	int cmp2=find>add?1:0;
/*
	gets(buf);
	puts(add);
	gets(whole);
	puts(whole);*/

	/*char buf[5]={'h','e','l','l','o'};
	printf("%s",buf);*/
}
void countthenumberofwords()
{
	char buf[10000];
	gets(buf);
	int length=strlen(buf);
	int count=0,i=0;
	while(buf[i]==' ')
		i++;
	while(i<length)
	{
		while(buf[i]!=' '&&buf[i]!='\0')
			i++;
		count++;
		while(buf[i]==' '||buf[i]=='\0')
			i++;
	}
}
int main()
{
	
	return 0;
}