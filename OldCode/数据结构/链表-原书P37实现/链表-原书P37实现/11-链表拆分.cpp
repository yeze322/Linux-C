#include "Linkedlist.h"

void DelInfo(LinkInfo **L)
{
	delete(*L);
	*L=NULL;
}


void SplitList(LinkInfo *L,LinkInfo *odd,LinkInfo *even)//拆分后销毁原链表
{
	node *p=L->head->next;//第一个元素
	node *odd_add=odd->head;//奇数
	node *even_add=even->head;//偶数
	while(p!=NULL)
	{
		//首先添加偶数
		odd_add->next=p;
		odd->listlen++;
		odd_add=odd_add->next;
		p=p->next;
		//判断是否还有未添加额数
		if(p==NULL)
			break;
		//然后添加奇数
		even_add->next=p;
		even->listlen++;
		even_add=even_add->next;
		p=p->next;
	}
	odd->tail=odd_add;//填写尾节点信息
	odd_add->next=NULL;//并且把尾节点的下一个置零
	even->tail=even_add;
	even_add->next=NULL;

	InitListInfo(L);
}