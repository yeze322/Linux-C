#include<stdio.h>
#include<ctype.h>
int main()//想要纵向打印则建立一个二维数组。然后就迎刃而解了
{
	freopen("input.txt","r",stdin);
	freopen("chart.txt","w",stdout);
	char c;
	int alpha[26]={0};
	while((c=getchar())!=EOF)
	{
		if(isalpha(c))
		{
			if(c>='a'&&c<='z')
				alpha[c-'a']++;
			else if(c>='A'&&c<='Z')
				alpha[c-'A']++;
		}
	}
	int max=alpha[0];
	for(int j=0;j<26;j++)
	{
		if(alpha[j]>max)
			max=alpha[j];
	}
	for(int j=0;j<max/12+10;j++)
		printf("-");
	printf("\n");

	for(int line=0;line<26;line++)
	{
		printf("\n%c:",line+'A');
		for(int high=0;high<alpha[line]/12;high++)
			printf("%c",'-');
		printf("\n  ");
		for(int high=0;high<alpha[line]/12;high++)
			printf("%c",'|');
		printf("\n  ");
		for(int high=0;high<alpha[line]/12;high++)
			printf("%c",'-');
		printf("\n");
	}
}