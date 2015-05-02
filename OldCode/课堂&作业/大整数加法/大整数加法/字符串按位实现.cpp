#include<stdio.h>
#include<string.h>
#include<ctype.h>
void rotate(char str[])
{
	int len=strlen(str);
	for(int i=0;i<len/2;i++)
	{
		char temp=str[i];
		str[i]=str[len-i-1];
		str[len-i-1]=temp;
	}
}
void cutsignfill0(char a[],char b[],char *&new_a,char *&new_b)
{
	int lenmax=(strlen(a)>strlen(b)?strlen(a):strlen(b))+1;
	char *newa=new char[lenmax];
	char *newb=new char[lenmax];
	strcpy(newa,a);
	strcpy(newb,b);
	for(int i=0;i<lenmax-strlen(a);i++)
		strcat(newa,"0");	
	for(int i=0;i<lenmax-strlen(b);i++)
		strcat(newb,"0");
	new_a=newa;
	new_b=newb;
}

void charadd(char *na,char *nb)
{
	int temp=0,add;
	for(int i=0;i<strlen(na);i++)
	{
		add=na[i]+nb[i]-'0'*2+temp;
		temp=add/10;
		add=add%10;
		na[i]=add+'0';
	}
}

void charminus(char *na,char *nb)
{
	int temp=0,add;
	for(int i=0;i<strlen(na);i++)
	{
		add=na[i]-nb[i]+temp;
		if(add<0)
		{
			add+=10;
			temp=-1;
			na[i]=add+'0';
		}
		else
		{
			na[i]=add+'0';
			temp=0;
		}		
	}
}
char* fillwithzerothenadd(char *a,char *b,bool neg)
{
//已经旋转过了
	char *na=NULL,*nb=NULL;
	cutsignfill0(a,b,na,nb);
	void (*p)(char*,char*);
	p=(neg?charminus:charadd);//是不是一正一副？
	p(na,nb);
	return na;
}
bool takeoffsign(char *a)
{
	rotate(a);
	int flag=strlen(a)-1;
	if(a[flag]=='+')
	{
		a[flag]='\0';
		return 0;
	}
	else if(a[flag]=='-')
	{
		a[flag]='\0';
		return 1;
	}
	return 0;
}
int main(int argc,char* argv[])
{
	char a[]="-7987465413213546465461111111111";
	char b[]="-574968465216352468749611";

	bool ifneg_a=takeoffsign(a);
	bool ifneg_b=takeoffsign(b);
	bool ifnegresult=0,swap=0;
	if(ifneg_a&&ifneg_b)//都是负的
		ifnegresult=1;
	else if(ifneg_a&&(strlen(a)>strlen(b))||ifneg_a&&strlen(a)==strlen(b)&&strcmp(a,b))//a是负的且绝对值大于b
	{
		ifnegresult=1;//只需要标负数不需要换
	}
	else if(ifneg_b&&(strlen(b)>strlen(a))||ifneg_b&&(strlen(b)==strlen(a))&&strcmp(b,a))//b是负的且绝对值大于a
	{
		ifnegresult=1;	
		swap=1;//要换
	}
	char* result;
	if(swap)
		result=fillwithzerothenadd(b,a,ifneg_a^ifneg_b);//异或
	else 
		result=fillwithzerothenadd(a,b,ifneg_a^ifneg_b);
	int i=strlen(result)-1;
	while(result[i]=='0')
		i--;
	if(ifnegresult)
	{
		result[i+1]='-';
		result[i+2]='\0';
	}
	rotate(result);
	return 0;
}