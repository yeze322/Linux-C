#include<stdio.h>
#include<string.h>
void spaceaway(char str[])
{
	int len=strlen(str);
	int write=0,i=0;
	while(i<=len)
	{
		if(str[i]==' ')
		{
			str[write++]=str[i];
			while(i<len&&str[i]==' ')
				i++;
		}
		str[write++]=str[i++];
	}
}
int main()
{
	char str[]="  hello  wor  ld  .";
	printf("old str:\n%s\n",str);
	spaceaway(str);
	printf("after delete space:\n%s\n",str);
	return 0;
}
