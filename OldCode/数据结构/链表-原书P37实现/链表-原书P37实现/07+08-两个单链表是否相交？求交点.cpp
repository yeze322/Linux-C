#include "Linkedlist.h"

//思路1：主要问题在于两个链表起点到交叉点可能距离不同。所以先把他们变成相同。
//		 于是从两个链表头开始访问，直到尾部。记录长度然后把长的那个移动相应的长度差
//       接下来循环，每次移动一个节点直到两个节点是同一个。Intersection1()
node* Intersection1(node * headA, node *headB)
{
	int count=0;
	node *p=headA;
	node *q=headB;
	while(headA!=nullptr)
	{
		count++;
		headA=headA->next;
	}
	while(headB!=nullptr)
	{
		count--;
		headB=headB->next;
	}
	headA=p;headB=q;
	if(count>0)//A is longer
		while(count--)
			headA=headA->next;
	else//B is longer
		while(count++)
			headB=headB->next;
	while(headA!=nullptr&&headB!=nullptr&&headA!=headB)
	{
		headA=headA->next;
		headB=headB->next;
	}
	return (headA==nullptr?headA:headB);
}

//思路2：更优化的解法。思路1要走接近2N步，
//		 而利用之前问题6中链表环的函数。相比思路1要少走许多步，最优为N步，最差为2N步。
node* Intersection2(node *headA,node *headB)
{
	node *p=headA,*q=headB;
	while(p->next!=NULL)
		p=p->next;
	node *record=p;
	p->next=q;//构造环
	node *intersection=IfCircle(headA);
	p->next=NULL;
	return intersection;
}
