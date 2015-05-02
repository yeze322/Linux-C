#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
int main()
{
	char str[100];
	char copy[100];
	int choose;
	
	while(printf("choose case:"),fflush(stdin),scanf("%d",&choose)!=EOF)
	{
		fflush(stdin);
		switch(choose)
		{
		case 1:
			gets(str);
			puts(str);
			printf("case 1\n");
			break;
		case 2:
			puts(gets(str));
			printf("case 2\n");
			break;
		case 3:
			fgets(str,4,stdin);
			puts(str);
			printf("case 3\n");
			break;
		default:
			printf("no case\n");
			break;
		}
	}
	
	


	system("pause");
}