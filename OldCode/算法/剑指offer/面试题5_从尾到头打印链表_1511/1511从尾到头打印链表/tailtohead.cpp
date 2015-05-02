#include<stdio.h>
#include<stdlib.h>
struct linklist{
	int data;
	linklist* next;
	linklist* father;
}*head;

linklist* createNode(linklist *former,int number)
{
	linklist* p=(linklist*)malloc(sizeof(linklist));
	p->next=NULL;
	p->father=former;
	p->data=number;
	former->next=p;
	return p;
}

int main()
{
	head=(linklist*)malloc(sizeof(linklist));
	head->data=-1;
	head->father=NULL;
	head->next=NULL;
	int input;
	linklist* record=NULL;
	while(scanf("%d",&input)!=EOF)
	{
		if(input==-1)
		{
			record->next=NULL;
			break;
		}
		if(head->next==NULL)
			record=createNode(head,input);
		else
			record=createNode(record,input);
	}
	//out put
	while(record!=head)
	{
		printf("%d\n",record->data);
		record=record->father;
	}
	system("pause");
}