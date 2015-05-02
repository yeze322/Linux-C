#include "Linkedlist.h"

LinkInfo* CreateInfoFromArray(int a[],int size)
{
	LinkInfo *p=CreateLinkInfo();
	node* father=p->head;
	for(int i=0;i<size;i++)
	{
		p->tail=CreateSonNode(father,a[i]);
		p->listlen++;
		father=father->next;
	}
	return p;
}

int main()
{
	int a[10]={1,2,3,4,5,6,7,8,9,10};
	//创建链表
	LinkInfo *L=CreateInfoFromArray(a,10);
	//1-单链表反转
	ReverseList(L);
	ReverseList(L);
	//2-倒数第K个的验证
	node* last[11];
	for(int i=0;i<11;i++)
		last[i]=lastK(*L,i+1);
	//3-中间元素
	node* mid=FinMid(*L);
	//4-删除无头结点
	//DelNoHead(L->head->next);
	//5-有序链表合并
	int a1[5]={5,5,4,3,1};
	int b1[3]={7,4,2};
	LinkInfo *p=CreateInfoFromArray(a1,0);//测试案例: 1-p,q 递增 2-p,q递减 3-p为空 4-q为空 5-p,q均为空
	LinkInfo *q=CreateInfoFromArray(b1,3);
	MergeList(p,q);
	//6-判断链表是否有环（并返回环的起点node*）
	LinkInfo *circle=CreateInfoFromArray(a,6);//测试：有环、无环、空链表
	node *nocross=IfCircle(circle->head);
	circle->tail->next=circle->head->next->next->next;//构造一个环
	node *cross=IfCircle(circle->head);
	//7+8-两个单链表是否相交？求交点
	LinkInfo *A=CreateInfoFromArray(a1,5);//测试：1-不交叉 2- 交叉 3- 空链表
	LinkInfo *B=CreateInfoFromArray(b1,3);
	node *nointersection1=Intersection1(A->head,B->head);
	node *nointersection2=Intersection2(A->head,B->head);//NULL
	B->tail->next=A->head->next->next->next;//设置交叉点在4
	node *intersection1=Intersection1(A->head,B->head);
	node *intersection2=Intersection1(A->head,B->head);// 4
	//9-单链表排序
	int s[10]={54,41,32,1,6,4,54,32,658,2};
	LinkInfo *linksort=CreateInfoFromArray(s,10);
	LinkSortQ(linksort,0);
	//10-删除重复元素
	DelRepeated(linksort);
	//11-拆分链表
	LinkInfo *odd=CreateLinkInfo();
	LinkInfo *even=CreateLinkInfo();
	SplitList(L,odd,even);
	//12-大整数加法
	char numa[]="-7987465413213546465461111111111";
	char numb[]="-574968465216352468749611";
	char* result=BigNum(numa,numb);
	return 0;
}
