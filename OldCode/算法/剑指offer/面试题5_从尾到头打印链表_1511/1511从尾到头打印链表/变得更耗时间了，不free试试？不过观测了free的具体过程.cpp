#include<stdio.h>
#include<stdlib.h>
typedef struct linklist{
	int data;
	struct linklist* father;
}linklist;

linklist* createNode(linklist *former,int number)
{
	struct linklist* p=(linklist*)malloc(sizeof(linklist));
	p->father=former;
	p->data=number;
	return p;
}

int main()
{
	linklist* head;
	head=(linklist*)malloc(sizeof(linklist));
	head->data=-1;
	head->father=NULL;
	int input;
	linklist* record=head;
	while(scanf("%d",&input)!=EOF)
	{
		if(input==-1)
		{

			break;
		}
		record=createNode(record,input);
	}
	//out put
	while(record!=NULL&&record!=head)
	{
		printf("%d\n",record->data);
		record=record->father;
	}
}