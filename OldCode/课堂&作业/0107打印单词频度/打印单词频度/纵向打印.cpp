#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<windows.h>
HANDLE consolenhwnd=GetStdHandle(STD_OUTPUT_HANDLE);

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
	
	int stand[130][22]={0};
	for(int i=0;i<26;i++)
	{
		int high=0;
		high=20*alpha[i]/max;
		int j;
		for(j=0;j<high;j++)
		{
			stand[i*5+1][j]=1;
			stand[i*5+2][j]=1;
			stand[i*5+3][j]=1;
		}
		stand[i*5+2][j]=i+'A';
	}
	for(int k=21;k>=0;k--)
	{
		for(int i=0;i<130;i++)
		{
			if(stand[i][k]==0)
				putchar(' ');
			else if(stand[i][k]==1)
			{
				//SetConsoleTextAttribute(consolenhwnd,i/3*3);
				putchar('#');
				//SetConsoleTextAttribute(consolenhwnd,247);
			}
			else
				printf("%c",stand[i][k]);
		}
		putchar('\n');
	}
	for(int i=2;i<130;i=i+5)
		printf("%4d ",alpha[i/5]);
	printf("\n");
}