struct Linklist
{
	int data;
	Linklist* next;
};//初始化

Linklist* Create()
{
	Linklist* p= new Linklist;
	p->next=nullptr;
	return p;
}//创建节点

void AddLink(Linklist *father,int value)
{
	Linklist* p=Create();
	father->next=p;
}//增加节点

Linklist* Search(Linklist *lhead,int value)
{
	while(lhead->next!=nullptr&&lhead->next->data!=value)
		lhead=lhead->next;
	return lhead->next;
}//查找节点

Linklist* SearchFather(Linklist *lhead,int value)
{
	while(lhead->next!=nullptr&&lhead->next->data!=value)
		lhead=lhead->next;
	return lhead;
}//查找值的父节点


void DelNode(Linklist *head,int value)
{
	Linklist *p=SearchFather(head,value);
	Linklist *record=p->next;
	p->next=p->next->next;
	delete(record);
}//删除节点