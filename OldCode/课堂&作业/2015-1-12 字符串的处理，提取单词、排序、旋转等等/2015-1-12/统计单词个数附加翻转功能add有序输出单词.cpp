#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int turntonextalp(char buf[],int i)
{
	while(!isalpha(buf[i])&&buf[i]!='\0')
		i++;
	return i;
}
int countwords(char buf[])
{
	int count=0;
	for(int i=turntonextalp(buf,0);i<strlen(buf);i++)
	{
		while(isalpha(buf[i]))
			i++;	
		count++;
		i=turntonextalp(buf,i);
	}
	printf("%d\n",count);
	return count;
}
int extractword(char *buf,char **&s)//attention s
{
	int count=0,length=strlen(buf);
	char *flag=buf;
	char *tozero;
	for(int i=turntonextalp(buf,0);i<length;)//becaus we add '\0'into buf,so we cannot use strlen
	{
		flag=&buf[i];
		while(isalpha(buf[i]))
			i++;
		tozero=&buf[i];
		count++;
		s=(char **)realloc(s,sizeof(char*)*count);
		s[count-1]=flag;
		i=turntonextalp(buf,i);
		*tozero='\0';
	}
	/*for(int i=0;i<count;i++)
		printf("%s\n",s[i]);*/
	return count;
}
void swapvalue(char* p,char* q)
{
	char temp;
	temp=*p;*p=*q;*q=temp;
}
void rotate(char* p,char* q)
{
	if(p>=q)
		return;
	while(p<q)
	{
		swapvalue(p,q);
		p++;
		q--;
	}
}
void rotateonlywords(char buf[])
{
	char *p=buf,*q=buf;
	int i;
	for(i=turntonextalp(buf,0);i<strlen(buf);i=turntonextalp(buf,i))
	{
		p=&buf[i];
		while(isalpha(buf[i]))
			i++;
		q=&buf[i-1];
		rotate(p,q);
	}
}

void rotateall(char buf[])
{
	for(int i=0;i<strlen(buf);i++);

}

void sortword(char **&s,int n)
{
	for(int i=n-1;i>=0;i--)
	{
		for(int j=0;j<i;j++)
		{
			if(strcmp(s[j],s[j+1])==1)//if ==1 then s[i]>s[i+1],swap.
			{
				char *temp=s[j];
				s[j]=s[j+1];
				s[j+1]=temp;
			}
		}
	}//bubble
}
int main()
{
	char buf[10000];//="    hwel a dsa asd hello  asdas ewqe qw  helo asd nmcl kxvchj hello asdn    ";
	char copy[sizeof(buf)];
	gets(buf);//read a line
	strcpy(copy,buf);
	//rotateonlywords(buf);
	//printf("%s\n",buf);
	char ** word=NULL;
	int n=extractword(buf,word);//传参的时候，注意函数中word的格式，加了引用符号，不然的话word不会被改变的
	printf("the number of words is : %d\n\nsorted words:\n",n);
	sortword(word,n);
	for(int i=0;i<n;i++)
		printf("%s\n",word[i]);
	//rotateallword(buf);s
	//printf("\n%s\n",buf);
	return 0;
}
