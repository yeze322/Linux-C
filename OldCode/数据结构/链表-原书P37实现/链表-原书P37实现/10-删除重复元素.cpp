#include "Linkedlist.h"

void DelRepeated(LinkInfo *L)
{
	if(L->listlen<=1)//head->next->next==NULL;
		return;
	node *start=L->head->next;
	while(start->next!=NULL)
	{
		node *record=start->next;
		while(start->data==record->data)
		{
			L->listlen--;
			record=record->next;
			delete(start->next);
			start->next=record;//还可以引入第三个指针记录要释放的地址，不过还是删除后立即连接比较安全
			if(record==NULL)
				return;//到达末尾直接结束
		}
		start=start->next;
	}
}