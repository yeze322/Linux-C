#include "Linkedlist.h"
void ReverseList(LinkInfo *L)//中间变量实现
{
	node *son,*grandson;
	node *headrecord=L->head;
	son=headrecord->next;
	L->head=NULL;
	L->tail=son;
	while(son!=NULL)
	{
		grandson=son->next;
		son->next=L->head;
		L->head=son;
		son=grandson;
	}
	headrecord->next=L->head;
	L->head=headrecord;
}

//递归实现（待补充）