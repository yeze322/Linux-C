#include<stdio.h>
#include<stdlib.h>
int main()
{
	int N;
	while(scanf("%d",&N)!=EOF)
	{
		int grade[101]={0};
		if(N==0)
			continue;
		int record;
		for(int i=0;i<N;i++)
		{
			scanf("%d",&record);
			grade[record]++;
		}
		int search;
		scanf("%d",&search);
		printf("%d\n",grade[search]);
	}
	return 0;
}
