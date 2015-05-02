#include "Linkedlist.h"

void DelNoHead(node *p)
{
	if(p==NULL||p->next==NULL)
	{
		p=NULL;
		return;
	}
	node *record=p->next;
	p->data=p->next->data;
	p->next=p->next->next;
	delete(record);
}//直接把下一个节点的值拷贝过来，转变成删除下一个节点

LinkInfo* MergeList(LinkInfo *M,LinkInfo *N)//合并两个链表，返回值为合并后头结点
{
	node *p=M->head->next,*q=N->head->next;
	M->listlen+=N->listlen;
	if(p==NULL||q==NULL)
	{
		if(p==NULL)
		{
			M->head->next=q;
			M->tail=N->tail;
		}
		goto merge_end;
	}//p为空链，指向q即可。而q为空链则无所谓
	bool increase=M->head->next->data<=M->tail->data&&N->head->next->data<=N->tail->data;//1则代表递增序列，0代表递减序列
	//确定尾节点
	M->tail=(M->tail->data>=N->tail->data?increase:!increase)?M->tail:N->tail;
	//归并部分
	node *headrecord=M->head;
	while(p!=NULL&&q!=NULL)
	{
		if(p->data>=q->data)
		{
			headrecord->next=(increase?q:p);
			increase?q=q->next:p=p->next;
		}
		else
		{
			headrecord->next=(increase?p:q);
			increase?p=p->next:q=q->next;
		}
		headrecord=headrecord->next;
	}
	headrecord->next=(p==NULL?q:p);

merge_end:
	delete(N->head);
	delete(N);
	return M;
}
