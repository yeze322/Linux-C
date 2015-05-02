#include<string.h>
#include<stdio.h>
void rotate(char str[])
{
	int len=strlen(str);
	for(int i=0;i<len/2;i++)
	{
		char temp;
		temp=str[i];
		str[i]=str[len-i-1];
		str[len-i-1]=temp;
	}
}

int main()
{
	char str[]="hello world!";
	printf("%s\n",str);
	rotate(str);
	printf("%s\n",str);
	return 0;
}

