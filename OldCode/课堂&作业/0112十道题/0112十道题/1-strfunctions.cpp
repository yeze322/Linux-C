#include<stdio.h>
#include<iostream>
#include<assert.h>
using namespace std;
//#include<stdlib.h>
/*void _strcpy(char,char);
int _strcmp(char,char);
char* _strcat(char*, char *);
int _strlen(char);*/
/*！！！！！！！！！！！！！！！！！！！！！！*/
int _strlen(char *str)
{
	int length=0;
	while(*str!='\0')
	{
		str++;
		length++;
	}
	return length;
}

void _strcpy(char *copy,char *source)
{
	if(copy==NULL||source==NULL)
		return;
	while(*source!='\0')
		*copy++=*source++;
	*copy=*source;
}

int _strcmp(char *str1,char *str2)
{
	if(str1==NULL||str2==NULL)
		return 0;
	//assert(str1!=NULL&&str2!=NULL);
	while(*str1==*str2)
	{
		str1++;str2++;
		if(*str1=='\0'&&*str2=='\0')
			return 0;
	}
	return *str1>*str2?1:-1;
}
char * _strcat(char *des,char *add)
{
	int addlen=strlen(add);
	int deslen=strlen(des);
	/*char * newchar=(char *)malloc(sizeof(char)*(addlen+deslen+1));
	int i;
	for(i=0;i<deslen;i++)
		newchar[i]=des[i];
	for(i=0;i<=addlen;i++)
		newchar[deslen+i]=add[i];
	des=newchar;*/
	for(int i=0;i<=addlen;i++)
		*(des+deslen+i)=add[i];
	return des;
}
/*！！！！！！！！！！！！！！！！！！！！！！*/
int main()
{
	char des1[]="hello ";
	char add[]="worlddddd";
	char* newchar=_strcat(des1,add);
	/*char *p=_strcat(des2,add);
	//char *q=_strcat(des1,des1);
	char s[]="sa";
	char *ns=fun(s);*/
	strcpy(des1,add);
	return 0;
}
