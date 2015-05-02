/*给定两个整数A和B，其表示形式是：从个位开始，每三位数用逗号","隔开。
现在请计算A+B的结果，并以正常形式输出。*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	//freopen("input.txt","r",stdin);
	char num1[15];
	char num2[15];
	char ch=0;

	int number[50];
	int count=0;
	int index;
	
	while(ch!=EOF)
	{
		index=0;
		while((ch=getchar())!=EOF)
		{
			if(ch==' ')
				break;
			if(ch==',')
				continue;
			num1[index++]=ch;
		}
		if(ch==EOF)
			break;
		num1[index]='\0';
		index=0;
		while((ch=getchar())!=EOF)
		{
			if(ch=='\n')
				break;
			if(ch==',')
				continue;
			num2[index++]=ch;
		}
		num2[index]='\0';
		long int a=atoi(num1);
		long int b=atoi(num2);

		number[count++]=a+b;
	}
	for(int i=0;i<count;i++)
	{
		printf("%d\n",number[i]);
	}

	return 0;
}
