#include "Linkedlist.h"
node* lastK(LinkInfo L,int k)
{
	if(k>L.listlen||k<=0)
		return NULL;
	else if(k==1)
		return L.tail;
	int count=L.listlen;
	node *record=L.head;//record的下一个节点是倒数第K
	while(count-k)
	{
		if(record->next==NULL)
			return NULL;
		record=record->next;
		count--;
	}
	return record->next;
}

node* FinMid(LinkInfo L)
{
	int move=(L.listlen+1)/2;
	node *p=L.head;
	while(p&&move--)
		p=p->next;
	return p;
	//return lastK(L,L.listlen/2+1);
}
