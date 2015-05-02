/*************************************************************************
	> File Name: readfromfile.cpp
	> Author: Comst
	> Mail:750145240@qq.com 
	> Created Time: Mon 26 Jan 2015 13:06:05 UTC
 ************************************************************************/
#include "sitchart.h"
list* readfromfile()
{///home/pi/wd/sitchart/src/
	FILE *rd[4];
	rd[0]=fopen("col_0","rb");
	rd[1]=fopen("col_1","rb");
	rd[2]=fopen("col_2","rb");
	rd[3]=fopen("col_3","rb");
	list *p=createlist();
	for(int i=0;i<4;i++)
		readone(rd[i],p);
	return p;
}

void readone(FILE *fp,list *head)
{
	node *temp=createnode();
	while(fscanf(fp,"%s%d%d",temp->name,&temp->row,&temp->col)==3)
	{
		node *p=createnode();
		p->row=temp->row;
		p->col=temp->col;
		strcpy(p->name,temp->name);
		head->rowhead[p->row]->tail->right=p;
		head->rowhead[p->row]->tail=p;
		head->rowhead[p->row]->num++;

		head->colhead[p->col]->tail->down=p;
		head->colhead[p->col]->tail=p;
		head->colhead[p->col]->num++;
	
		head->stunum++;
	}
	delete(temp);
}
