//严蔚敏<数据结构> P37 链表实现
#include "Linkedlist.h"
node* NewNode()
{
	node* p=new node;
	p->next=nullptr;//NULL
	return p;
}

LinkInfo* CreateLinkInfo()
{
	LinkInfo *p=new LinkInfo;
	p->head=NewNode();
	p->tail=p->head;
	p->listlen=0;
	return p;
}

void AddNodeToInfo(LinkInfo *L,int data)
{
	node *p=NewNode();
	p->data=data;
	L->tail->next=p;
	L->tail=p;
	L->listlen++;
}

node* CreateSonNode(node *father,int num)//创建father的子节点,返回值为子节点
{
	if(father==NULL)
		return false;
	father->next=NewNode();
	father->next->data=num;
	return father->next;
}

void FreeNode(node *start)//free节点start所指的节点
{
	if(start==NULL)
		return;
	delete(start->next);
	start->next=NULL;
}


LinkInfo* InitListInfo(LinkInfo *L)//初始化info
{
	L->head=NewNode();
	L->tail=L->head;
	L->listlen=0;
	return L;
}

bool DestroyList(node *L)//销毁整个表
{
	while(L!=NULL)
	{
		node *record=L->next;
		delete(L);
		L=record;
	}
	return true;
}

bool ClearList(node *LHead)//把L置为空表，释放原节点空间
{
	if(LHead==NULL)//头结点为空，链表不存在
		return false;
	LHead=LHead->next;
	while(LHead!=NULL)
	{
		node *record=LHead->next;
		delete LHead;
		LHead=record;
	}
	return true;
}

bool InsertHead(node *head,node *add)//头插法
{
	if(head==NULL||add==NULL)
		return false;
	add->next=head->next;
	head->next=add;
	return true;
}

bool DeleteFirst(node *head)//删除头结点后第一个节点
{
	if(head==NULL||head->next==NULL)
		return false;
	node *record=head->next->next;
	delete(head->next);
	head->next=record;
	return true;
}

bool Append(LinkInfo *LInfo,node *s)//把s所指的一串节点加到L后面，并更新L的尾指针
{
	if(s==NULL||LInfo->head==NULL)
		return false;
	LInfo->tail->next=s;
	int add=1;
	while(s->next)
	{
		add++;
		s=s->next;
	}
	LInfo->tail=s;
	LInfo->listlen+=add;
	return true;
}

bool InsertBefore(LinkInfo *L,node *p,node *S)//在链表L的p节点前加入节点S
{
	node *start=L->head;
	if(start==NULL||p==NULL||S==NULL)
		return false;
	while(start->next!=p)
	{
		start=start->next;
		if(start==NULL)
			return false;//没有p节点，返回false
	}
	start->next=S;
	S->next=p;
	L->listlen++;
	return true;
}

bool InsertAfter(LinkInfo *L,node *p,node *S)//在链表L的p节点后加入节点S
{
	if(p==NULL||S==NULL||L->head==NULL)
		return false;
	node *rec=p->next;
	p->next=S;
	S->next=rec;
	L->listlen++;
	return true;
}

node* PrirorPos(node *head,node *p)//返回p的前驱节点的位置
{
	if(head==NULL||p==NULL)
		return NULL;
	while(head->next!=p)
	{
		head=head->next;
		if(head->next==NULL)
			return NULL;
	}
	return head;
}

node* Search(node *head,int value)//搜索节点
{
	if(head==NULL)
		return NULL;
	head=head->next;
	while(head!=NULL)
	{
		if(head->data==value)
			return head;
		head=head->next;
	}
	return NULL;
}
