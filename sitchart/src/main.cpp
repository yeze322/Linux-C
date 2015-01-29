/*************************************************************************
	> File Name: main.cpp
	> Author: Comst
	> Mail:750145240@qq.com 
	> Created Time: Mon 26 Jan 2015 12:43:07 UTC
 ************************************************************************/
#include"sitchart.h"

int main()
{
	list *head=readfromfile();
	rebuild(head);//排序重建
	int num;
	printf("演示————\n\n输入查找的列：");
	fflush(stdin);
	scanf("%d",&num);
	printcol(head,num);

	printf("\n\n输入查找的行：");
	fflush(stdin);
	scanf("%d",&num);
	printrow(head,num);
	int x,y;
	printf("\n\n输入查找的坐标(x y):");
	fflush(stdin);
	scanf("%d%d",&x,&y);
	printone(head,x,y);
	char name[20]="";
	printf("\n\n输入查找的人名:");
	fflush(stdin);
	scanf("%s",name);
	printaperson(head,name);
	//查找就那么遍历链表就行了，没写。
	
	printsitchart(head);
	return 0;
}
