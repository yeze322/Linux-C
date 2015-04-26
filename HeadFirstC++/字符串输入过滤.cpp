#include<stdio.h>
#include<string.h>
void print(char B[],int n)
{
	for(int i=0;i<n;i++)
		printf("%c",B[i]);
	printf("[end]\n");
}

void main()
{
	char a[100];
	printf("Input a,enter to end:");
	gets(a);
	printf("size of a:%d\n",strlen(a));
	char out[108];
	int count,length=0;
	for(int i=0;i<strlen(a);i++)
	{
		count=0;
		for(int j=0;j<i;j++)
		{
			//if (out[j]==a[i])
			//	count=1;
			count=count||(out[j]==a[i]);
		}
		if(count==0){
			out[length]=a[i];
			length++;
		}
	}
	printf("Result:");
	print(out,length);
	getchar();getchar();
}