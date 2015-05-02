/*************************************************************************
	> File Name: crosslist.cpp
	> Author: Comst
	> Mail:750145240@qq.com 
	> Created Time: Mon 26 Jan 2015 12:37:33 UTC
 ************************************************************************/

#include"sitchart.h"
node* createnode()
{
	node *p=new node;
	p->row=p->col=0;
	strcpy(p->name,"");
	p->right=NULL;
	p->down=NULL;
	return p;
}

nodehead* createnodehead()
{
	nodehead *p=new nodehead;
	p->num=0;
	p->head=createnode();
	p->tail=p->head;
	return p;
}

list* createlist()
{
	list* p=new list;
	p->stunum=0;
	for(int i=0;i<M;i++)
	p->rowhead[i]=createnodehead();

	for(int i=0;i<N;i++)
	p->colhead[i]=createnodehead();
	return p;
}
