#include "sitchart.h"
void printanode(node *start)
{
	printf("%-8s%3d  %3d\n",start->name,start->row,start->col);
}

void printrow(list *head,int row)
{
	if(row>=M) return;
	printf("姓名     行   列     \n");
	node *visit=head->rowhead[row]->head->right;
	while(visit)
	{
		printanode(visit);
		visit = visit->right;
	}
}

void printcol(list *head,int col)
{
	if(col>=N) return;
	printf("姓名     行   列     \n");
	node *visit=head->colhead[col]->head->down;
	while(visit)
	{
		printanode(visit);
		visit = visit->down;
	}
}

void printone(list *head,int row,int col)
{
	//printf("姓名     行   列     \n");
	if(row>=M||col>=N) return;
	node *visit=head->colhead[col]->head->down;
	while(visit)
	{
		if(visit->row==row)
			break;
		visit = visit->down;
	}
	printanode(visit);
}

void printaperson(list *head,char *name)
{
	printf("姓名     行   列     \n");
	node *visit;
	for(int i=0;i<M;i++)
	{
		visit=head->rowhead[i]->head->right;
		while(visit)
		{
			if(strstr(visit->name,name))
				printanode(visit);
			visit=visit->right;
		}
	}
}

void printsitchart(list *head)
{
	printf("\n\n	===========================座次表==========================\n\n");
	for(int i=0;i<M;i++)
	{
		node *visit=head->rowhead[i]->head->right;
		for(int j=0;j<N&&visit;j++)
		{	
			if(visit->col==j){
				printf("%-8s|",visit->name);
				visit=visit->right;
			}
			else
				printf("      |");

		}
		printf("\n\n");
	}
}
