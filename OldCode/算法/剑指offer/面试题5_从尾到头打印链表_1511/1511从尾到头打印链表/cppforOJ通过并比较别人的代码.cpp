#include<stdio.h>
#include<stdlib.h>
typedef struct linklist{
	int data;
	struct linklist* next;
	struct linklist* father;
}linklist;

linklist* createNode(linklist *former,int number)
{
	struct linklist* p=(linklist*)malloc(sizeof(linklist));
	p->next=NULL;
	p->father=former;
	p->data=number;
	former->next=p;
	return p;
}

int main()
{
	linklist* head;
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
		free(record->next);
	}
}