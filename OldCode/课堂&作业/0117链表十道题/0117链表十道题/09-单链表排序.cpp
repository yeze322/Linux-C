#include "Linkedlist.h"

int cmpIncrease(const void *left,const void *right)
{
	//node **p=(node **)left;
	node *p=*(node **)left;//cmp函数两种访问方式
	node **q=(node **)right;
	if(p->data>(*q)->data)
		return 1;
	else
		return p->data==(*q)->data?0:-1;
}
int cmpDecrease(const void *left,const void *right)
{
	//node **p=(node **)left;
	node *p=*(node **)left;
	node **q=(node **)right;
	if(p->data<(*q)->data)
		return 1;
	else
		return p->data==(*q)->data?0:-1;
}

void LinkSortQ(LinkInfo *L,bool increase)
{
	if(L->listlen<=1)
		return;
	node* (*all)=new node* [L->listlen];
	all[0]=L->head->next;
	for(int i=1;i<L->listlen;i++)
		all[i]=(all[i-1])->next;
	qsort((node *)(all),L->listlen,sizeof(node *),increase?cmpIncrease:cmpDecrease);
	node *start=L->head;
	for(int i=0;i<L->listlen;i++)
	{
		start->next=all[i];
		start=start->next;
	}
	L->tail=all[L->listlen-1];
	L->tail->next=NULL;
	delete(all);
}
